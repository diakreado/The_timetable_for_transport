#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Информация о маршрутах и станциях");
    ui->textBrowser->setText("");
    ui->textBrowser->setStyleSheet("font-size: 16px;");
    this->setMinimumSize(800,400);

    QPalette pal_for_main_window;
    pal_for_main_window.setBrush(this->backgroundRole(), Qt::white);
    this->setPalette(pal_for_main_window);

    ui->statusBar->setStyleSheet("background: #f2d525; ");
    ui->menu->setStyleSheet("background: #f2d525; ");
    ui->menuBar->setStyleSheet("QMenuBar {"
                               "background: #f2d525; "
                               "font-size: 14px;"
                               "}"
                               "QMenuBar::item {"
                               "background: transparent;"
                               "}"
                               "QMenuBar::item:selected {"
                               "color: #ffffff"
                               "}"
                               "QMenuBar::item:pressed {"
                               "color: #ffffff"
                               "}");

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
        QTimer::singleShot(2000,file_does_not_exist,SLOT(show()));

        core.addRoute();
        core.addStationInRoute(1,"Парнас");
        core.addStationInRoute(1,"Вовсе не Парнас");
        core.addStationInRoute(1,"Супер Парнас");
        core.addInfoAboutStation("Супер Парнас","Это самый лучший Парнас в мире");
        core.addInfoAboutStation("Вовсе не Парнас","Это совсем не Парнас");
        core.addRoute();
        core.addStationInRoute(2,"Дыбенко");
        core.addStationInRoute(2,"Дыбенко");
        core.addStationInRoute(2,"Пацаны с Дыбенко");
        core.addInfoAboutStation("Пацаны с Дыбенко","ДЫБЕНКООООО");
        core.addInfoAboutStation("Дыбенко","Дыбена - это самый благоустроенный район города Санкт-Петербугр,"
                                           " в котором живёт элита общества");

        statusBar()->showMessage("Файлы не найдены");
    }

    stations_layout = new QVBoxLayout;
    QWidget* stations = new QWidget;

    routes_layout = new QVBoxLayout;
    QWidget* routes = new QWidget;


        for(int i = 0; i < core.howManyRoutes(); i++)
        {
            std::stringstream print_int_for_number_of_the_route;
            print_int_for_number_of_the_route << i + 1;

            std::string name_of_the_route = "Маршрут №" + print_int_for_number_of_the_route.str();

            QPushButton* route_button = new QPushButton(name_of_the_route.c_str());


            QString name_of_file_for_route = ":/img/img/button_for_routes";
            std::stringstream print_int_for_number_of_the_img;
            print_int_for_number_of_the_img << (i % 9) + 1;
            name_of_file_for_route = name_of_file_for_route + (print_int_for_number_of_the_img.str()).c_str() + ".jpg";

            QPixmap* pix_for_route = new QPixmap(name_of_file_for_route);
            route_button->setIcon(*pix_for_route);
            route_button->setIconSize(pix_for_route->size());

            route_button->setStyleSheet(button_style_for_route);

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

                QString name_of_file_for_station = ":/img/img/button_for_stations";
                name_of_file_for_station = name_of_file_for_station + (print_int_for_number_of_the_img.str()).c_str() + ".jpg";
                QPixmap* pix_for_stations = new QPixmap(name_of_file_for_station);
                station_button->setIcon(*pix_for_stations);
                station_button->setIconSize(pix_for_stations->size());
                station_button->setStyleSheet(button_style_for_station);


                stations_buttons.push_back(station_button);
                stations_buttons[j]->hide();
                stations_buttons[j]->setFixedHeight(25);
                stations_buttons[j]->setProperty("name",(route[j]).c_str());

                stations_layout->addWidget(stations_buttons[j]);

                connect(stations_buttons[j], SIGNAL(clicked()), this, SLOT(showInfoAboutStation()));
            }

            stations_buttons_vector.push_back(stations_buttons);
        }

        stations->setLayout(stations_layout);
        ui->scrollAreaForStations->setWidget(stations);

        routes->setLayout(routes_layout);
        ui->scrollAreaForRoutes->setWidget(routes);

        QPainter *p = new QPainter(this);
        p->drawLine(1,1,100,100);

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

    std::stringstream print_int;
    print_int << number_of_the_route;
    std::string new_name = "Маршрут №" + print_int.str();;
    statusBar()->showMessage(new_name.c_str());
}

void MainWindow::showInfoAboutStation()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant name = button->property("name");

    QString qt_name_of_the_stations = name.toString();
    std::string name_of_the_station = qt_name_of_the_stations.toStdString();


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

    ui->textBrowser->setText(name_of_the_label_qt);

    QString toStatusBar = "Станция:  " + qt_name_of_the_stations;

    statusBar()->showMessage(toStatusBar);
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

    QString name_of_file = ":/img/img/button_for_routes";
    std::stringstream print_int_for_number_of_the_img;
    print_int_for_number_of_the_img << (i % 9) + 1;
    name_of_file = name_of_file + (print_int_for_number_of_the_img.str()).c_str() + ".jpg";

    QPixmap* pix = new QPixmap(name_of_file);

    route_button->setIcon(*pix);
    route_button->setIconSize(pix->size());
    route_button->setStyleSheet(button_style_for_route);

    connect(route_button, SIGNAL(clicked()), this, SLOT(showStations()));

    QVector<QPushButton*> stations_buttons;
    stations_buttons_vector.push_back(stations_buttons);

    std::string new_name = "Добавлен:   ";
    new_name += name_of_the_route;
    statusBar()->showMessage(new_name.c_str());
}

void MainWindow::on_action_4_triggered()
{
    DialogAboutDeletingRoute* diallog_about_delete_route = new DialogAboutDeletingRoute(&core,&index,this);
    diallog_about_delete_route->show();
}

void MainWindow::deleteRouteSlot()
{
    std::vector<std::string> route = core.getRoute(index+1);
    for(unsigned int j = 0; j < route.size(); j++)
    {
        delete(stations_buttons_vector[index][j]);
    }

    delete(routes_buttons[core.howManyRoutes()-1]);

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

    core.deleteRoute(index+1);

    std::stringstream print_int;
    print_int << index + 1;
    std::string new_name = "Удалён:   Маршрут №" + print_int.str();;
    statusBar()->showMessage(new_name.c_str());
}

void MainWindow::on_action_6_triggered()
{
    DialogAboutChangingNameOfTheStations* dialog_about_changing_name_of_stations =
            new DialogAboutChangingNameOfTheStations(&core,&number_of_the_route,
                                                &number_of_the_station,&string_with_info,this);
    dialog_about_changing_name_of_stations->show();
}

void MainWindow::changeNameOfStation()
{
    core.changeStationInRoute(number_of_the_route + 1, number_of_the_station + 1,
                              string_with_info.toStdString());
    QString old_name = (stations_buttons_vector[number_of_the_route][number_of_the_station])->text();

    (stations_buttons_vector[number_of_the_route][number_of_the_station])->setText(string_with_info);
    stations_buttons_vector[number_of_the_route][number_of_the_station]->
            setProperty("name",string_with_info);

    QString new_name = "Станция: " + old_name + " переименована в " + string_with_info;
    statusBar()->showMessage(new_name);
}

void MainWindow::on_action_5_triggered()
{
     DialogAboutAddingStationInRoute* dialog_about_adding_station_in_route = new
             DialogAboutAddingStationInRoute(&core,&index,&string_with_info,this);
     dialog_about_adding_station_in_route->show();
}

void MainWindow::addStation()
{
    core.addStationInRoute(index+1,string_with_info.toStdString());

    QPushButton* station_button = new QPushButton(string_with_info, this);



    stations_buttons_vector[index].push_back(station_button);
    station_button->hide();
    station_button->setFixedHeight(25);
    station_button->setProperty("name",(string_with_info));
    stations_layout->addWidget(station_button);

    QString name_of_file_for_station = ":/img/img/button_for_stations";
    std::stringstream print_int_for_number_of_the_img;
    print_int_for_number_of_the_img << (index % 9) + 1;
    name_of_file_for_station = name_of_file_for_station + (print_int_for_number_of_the_img.str()).c_str() + ".jpg";
    QPixmap* pix_for_stations = new QPixmap(name_of_file_for_station);
    station_button->setIcon(*pix_for_stations);
    station_button->setIconSize(pix_for_stations->size());
    station_button->setStyleSheet(button_style_for_station);


    connect(station_button, SIGNAL(clicked()), this, SLOT(showInfoAboutStation()));


    QString new_name = "Добавлена станция:  ";
    new_name = new_name + string_with_info;
    statusBar()->showMessage(new_name);
}

void MainWindow::on_action_7_triggered()
{
    DialogAboutDeletingStation* dialog_about_deleting_station =
            new DialogAboutDeletingStation(&core,&number_of_the_route,
                                                &number_of_the_station,this);
    dialog_about_deleting_station->show();
}

void MainWindow::deletingStation()
{
    QString old_name = (stations_buttons_vector[number_of_the_route][number_of_the_station])->text();

    core.deleteStationFromRoute(number_of_the_route+1,number_of_the_station+1);

    delete(stations_buttons_vector[number_of_the_route][stations_buttons_vector[number_of_the_route].size()-1]);

    std::vector<std::string> route = core.getRoute(number_of_the_route+1);
    QString name_of_station;
    for(unsigned int j = 0; j < route.size(); j++)
    {
        name_of_station = (route[j]).c_str();
        stations_buttons_vector[number_of_the_route][j]->setText(name_of_station);
    }

    QString information_about_deleting = "Удалена станция:  ";
    information_about_deleting = information_about_deleting + old_name;
    statusBar()->showMessage(information_about_deleting);
}

void MainWindow::on_action_9_triggered()
{
    DialogAboutAddingInfoAboutStation* dialog_about_adding_info_about_station =
            new DialogAboutAddingInfoAboutStation(&core,&number_of_the_route,
                                                &number_of_the_station,&string_with_info,this);
    dialog_about_adding_info_about_station->show();
}

void MainWindow::addInformationAboutStation()
{
    core.addInfoAboutStation(number_of_the_route+1,number_of_the_station+1,string_with_info.toStdString());

    QString name_of_the_station = (stations_buttons_vector[number_of_the_route][number_of_the_station])->text();

    QString information_about_adding = "Добавленна информация о станции:  ";
    information_about_adding = information_about_adding + name_of_the_station;
    statusBar()->showMessage(information_about_adding);
}

void MainWindow::on_action_10_triggered()
{
    DialogAboutDeletingInfoAboutStation* dialog_about_deleting_info_about_station =
            new DialogAboutDeletingInfoAboutStation(&core,&number_of_the_station,this);
    dialog_about_deleting_info_about_station->show();
}

void MainWindow::deleteInfoAboutStation()
{
    std::vector<std::pair<std::string,std::string>> AllStaions = core.getAllStationsWhichHaveDescription();

    core.removeInfoAboutStation(number_of_the_station+1);

    QString information_about_deleting = "Добавленна информация о станции:  ";
    information_about_deleting = information_about_deleting + ((AllStaions[number_of_the_station]).first).c_str();
    statusBar()->showMessage(information_about_deleting);
}










