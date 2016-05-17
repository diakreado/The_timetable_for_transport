#include "routeswindow.h"

RoutesWindow::RoutesWindow(CoreOfInfoAboutMetro* core) : core(core)
{
    this->setWindowTitle("Информация о маршрутах и станциях");
    this->setMinimumSize(800,500);

    try
    {
        core->loadInfoFromFile("metro_Saint-Petersburg_route_info.txt", "metro_Saint-Petersburg_station_info.txt");
    }
    catch(MissingFile&)
    {
        QMessageBox* messsge_about_error = new QMessageBox;

        messsge_about_error->setWindowTitle("Отсутствуют Файлы");

        messsge_about_error->setText("Не обнаруженны файлы с информацией, ожидались \n"
                       "metro_Saint-Petersburg_route_info.txt и metro_Saint-Petersburg_station_info.txt");

        messsge_about_error->show();
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *routesLayout = new QHBoxLayout;
    QGridLayout *grid = new QGridLayout;


    QHBoxLayout* labelLayout = new QHBoxLayout;

    label = new QLabel("");
    labelLayout->addSpacing(300);
    labelLayout->addWidget(label);


    QVector<QPushButton*> routes_buttons;

    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::stringstream print_int;
        print_int << i + 1;

        std::string name_of_the_route = "Route №" + print_int.str();

        QPushButton* route_button = new QPushButton(name_of_the_route.c_str(), this);

        routes_buttons.push_back(route_button);

        routes_buttons[i]->setFixedSize(150,30);

        routes_buttons[i]->show();

        routesLayout->addWidget(routes_buttons[i]);

        routes_buttons[i]->setProperty("index", i);

        connect(routes_buttons[i], SIGNAL(clicked()), this, SLOT(showStations()));


        QVector<QPushButton*> stations_buttons;

        std::vector<std::string> route = core->getRoute(i + 1);

        for(unsigned int j = 0; j < route.size(); j++)
        {
            QPushButton* station_button = new QPushButton((route[j]).c_str(), this);


            stations_buttons.push_back(station_button);


            stations_buttons[j]->hide();

            grid->addWidget(stations_buttons[j],j/4,j%4,1,1);

            stations_buttons[j]->setFixedSize(175,25);

            stations_buttons[j]->setProperty("index",(route[j]).c_str());

            connect(stations_buttons[j], SIGNAL(clicked()), this, SLOT(showInfoAboutStation()));
        }

        stations_buttons_vector.push_back(stations_buttons);
    }
    mainLayout->addSpacing(30);
    mainLayout->addLayout(routesLayout);
    mainLayout->addSpacing(150);
    mainLayout->addLayout(grid);
    mainLayout->addLayout(labelLayout);
    this->setLayout(mainLayout);
}

void RoutesWindow::showStations()
{
    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::vector<std::string> route = core->getRoute(i + 1);

        for(unsigned int j = 0; j < route.size(); j++)
        {
            (stations_buttons_vector[i][j])->hide();
        }
    }

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant index = button->property("index");


    int number_of_the_route = index.toInt() + 1;


    std::vector<std::string> route = core->getRoute(number_of_the_route);

    for(unsigned int j = 0; j < route.size(); j++)
    {
        (stations_buttons_vector[number_of_the_route - 1][j])->show();
    }
}

void RoutesWindow::showInfoAboutStation()
{

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QVariant index = button->property("index");

    QString number_of_the_route = index.toString();
    std::string name_of_the_station = number_of_the_route.toStdString();


    std::string name_of_the_label =  "";

    QString polka;

    try
    {
        name_of_the_label += core->getInfoAboutStation(name_of_the_station);
        polka = name_of_the_label.c_str();
    }
    catch(StationDoesNotExist&)
    {
        polka = "<h4> Station does no exist";
    }


    label->setStyleSheet("font-size: 21px;");
    label->setText(polka);
}





