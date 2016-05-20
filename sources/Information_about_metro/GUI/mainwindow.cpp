#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Информация о маршрутах и станциях");
    ui->label->setText("");

    this->setMinimumSize(800,400);

    ui->scrollAreaForStations->setFixedWidth(250);

    ui->scrollAreaForRoutes->setFixedWidth(200);

    try
    {
        core.loadInfoFromFile("metro_Saint-Petersburg_route_info.txt", "metro_Saint-Petersburg_station_info.txt");
    }
    catch(MissingFile&)
    {
        QMessageBox* file_does_not_exist = new QMessageBox;
        file_does_not_exist->setWindowTitle("Отсутствуют Файлы");
        file_does_not_exist->setText("Не обнаруженны файлы с информацией, ожидались\n"
                                     "metro_Saint-Petersburg_route_info.txt и metro_Saint-Petersburg_station_info.txt");
        file_does_not_exist->show();

        statusBar()->showMessage("Файлы не найдены");
    }



//    core.addRoute();
//    core.addStationInRoute(1,"Парнас 228");
//    core.addStationInRoute(1,"Вовсе не Парнас");
//    core.addStationInRoute(1,"Супер Парнас");
//    core.addInfoAboutStation("Супер Парнас","Это самый лучший Парнас в мире");
//    core.addRoute();
//    core.addStationInRoute(2,"Парнас 228");
//    core.addStationInRoute(2,"Вовсе не Парнас");
//    core.addStationInRoute(2,"Супер Парнас");
//    core.addInfoAboutStation("Супер Парнас","Это самый лучший Парнас в мире");



    stations_layout = new QVBoxLayout;
    QWidget* stations = new QWidget;

    routes_layout = new QVBoxLayout;
    QWidget* routes = new QWidget;

        for(int i = 0; i < core.howManyRoutes(); i++)
        {
            std::stringstream print_int;
            print_int << i + 1;

            std::string name_of_the_route = "Маршрут №" + print_int.str();

            QPushButton* route_button = new QPushButton(name_of_the_route.c_str(), this);

            routes_buttons.push_back(route_button);

            routes_buttons[i]->setFixedSize(150,30);

            routes_layout->addWidget(routes_buttons[i]);

            routes_buttons[i]->show();

            routes_buttons[i]->setProperty("index", i);

            connect(routes_buttons[i], SIGNAL(clicked()), this, SLOT(showStations()));


            QVector<QPushButton*> stations_buttons;

            std::vector<std::string> route = core.getRoute(i + 1);

            for(unsigned int j = 0; j < route.size(); j++)
            {
                QPushButton* station_button = new QPushButton((route[j]).c_str(), this);


                stations_buttons.push_back(station_button);

                stations_buttons[j]->hide();

                stations_layout->addWidget(stations_buttons[j]);

                stations_buttons[j]->setFixedSize(175,25);

                stations_buttons[j]->setProperty("name",(route[j]).c_str());

                connect(stations_buttons[j], SIGNAL(clicked()), this, SLOT(showInfoAboutStation()));
            }

            stations_buttons_vector.push_back(stations_buttons);
        }

        stations->setLayout(stations_layout);
        ui->scrollAreaForStations->setWidget(stations);

        routes->setLayout(routes_layout);
        ui->scrollAreaForRoutes->setWidget(routes);

}

void MainWindow::showStations()
{
    for(int i = 0; i < core.howManyRoutes(); i++)
    {
        std::vector<std::string> route = core.getRoute(i + 1);

        for(unsigned int j = 0; j < route.size(); j++)
        {
            (stations_buttons_vector[i][j])->hide();
        }
    }

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant index = button->property("index");

    int number_of_the_route = index.toInt() + 1;

    std::vector<std::string> route = core.getRoute(number_of_the_route);

    for(unsigned int j = 0; j < route.size(); j++)
    {
        (stations_buttons_vector[number_of_the_route - 1][j])->show();
    }
}

void MainWindow::showInfoAboutStation()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant index = button->property("name");

    QString number_of_the_route = index.toString();
    std::string name_of_the_station = number_of_the_route.toStdString();


    std::string name_of_the_label_std =  "";

    QString name_of_the_label_qt;

    try
    {
        name_of_the_label_std += core.getInfoAboutStation(name_of_the_station);
        name_of_the_label_qt = name_of_the_label_std.c_str();
    }
    catch(StationDoesNotExist&)
    {
        name_of_the_label_qt = "Станция не найдена";
    }



    ui->label->setStyleSheet("font-size: 16px;");
    ui->label->setText(name_of_the_label_qt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_2_triggered()
{
    core.addRoute();
    int i = core.howManyRoutes() - 1;

    std::stringstream print_int;
    print_int << i + 1;
    std::string name_of_the_route = "Маршрут №" + print_int.str();
    QPushButton* route_button = new QPushButton(name_of_the_route.c_str(), this);
    route_button->setFixedSize(150,30);
    routes_buttons.push_back(route_button);
    routes_layout->addWidget(route_button);
    route_button->show();
    route_button->setProperty("index", i);
    connect(route_button, SIGNAL(clicked()), this, SLOT(showStations()));

    std::string new_name = "Добавлен:   ";
    new_name += name_of_the_route;
    statusBar()->showMessage(new_name.c_str());
}

void MainWindow::on_action_4_triggered()
{
    Dialog* diallog_about_delete_route = new Dialog(&core,&index,this);
    diallog_about_delete_route->show();
}

void MainWindow::deleteRouteSlot()
{
   delete(routes_buttons[core.howManyRoutes()-1]);
   routes_buttons.erase(routes_buttons.end()-1);

    for(int i = 0; i < core.howManyRoutes()-1; i++)
    {
        std::stringstream print_int;
        print_int << i + 1;
        std::string name_of_the_route = "Маршрут №" + print_int.str();
        routes_buttons[i]->setText(name_of_the_route.c_str());
        routes_buttons[i]->setProperty("index", i);
    }

    if (stations_buttons_vector.size() > index)
    {
        stations_buttons_vector.remove(index);
    }

    core.deleteRoute(index + 1);
}
