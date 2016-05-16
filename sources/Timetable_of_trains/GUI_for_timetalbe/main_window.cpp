#include "main_window.h"

//MainWindow::MainWindow(QWidget *parent, CoreOfInfoAboutMetro* core)
//{
//    this->setFixedSize(WINDOW_SIZE);
//    this->setWindowTitle("Информация о маршрутах и станциях");
//    this->core = core;


//    QVBoxLayout* layout = new QVBoxLayout;

//    label = new QLabel("", this);

//    layout->addWidget(label);

//    layout->setContentsMargins(400,400,200,150);

//    this->setLayout(layout);


//    QVector<QPushButton*> routes_buttons;

//    for(int i = 0; i < core->howManyRoutes(); i++)
//    {
//        std::stringstream print_int;
//        print_int << i + 1;

//        std::string name_of_the_route = "Route №" + print_int.str();

//        QPushButton* route_button = new QPushButton(name_of_the_route.c_str(), this);
//        routes_buttons.push_back(route_button);

//        routes_buttons[i]->resize(BUTTON_SIZE);
//        routes_buttons[i]->move(WINDOW_SIZE.width() - 950 + i * 200,
//                                WINDOW_SIZE.height() - 550);



//        routes_buttons[i]->setProperty("index", i);

//        connect(routes_buttons[i], SIGNAL(clicked()), this, SLOT(showStations()));


//        QVector<QPushButton*> stations_buttons;

//        std::vector<std::string> route = core->getRoute(i + 1);

//        for(unsigned int j = 0; j < route.size(); j++)
//        {
//            QPushButton* station_button = new QPushButton((route[j]).c_str(), this);


//            stations_buttons.push_back(station_button);

//            stations_buttons[j]->resize(BUTTON_SIZE);
//            stations_buttons[j]->move(WINDOW_SIZE.width() - 950 + j * 200,
//                                         WINDOW_SIZE.height() - 350);

//            stations_buttons[j]->hide();

//            stations_buttons[j]->setProperty("index",(route[j]).c_str());

//            connect(stations_buttons[j], SIGNAL(clicked()), this, SLOT(showInfoAboutStation()));
//        }

//        stations_buttons_vector.push_back(stations_buttons);
//    }
//}

//void MainWindow::showStations()
//{
//    for(int i = 0; i < core->howManyRoutes(); i++)
//    {
//        std::vector<std::string> route = core->getRoute(i + 1);

//        for(unsigned int j = 0; j < route.size(); j++)
//        {
//            (stations_buttons_vector[i][j])->hide();
//        }
//    }

//    QPushButton *button = qobject_cast<QPushButton*>(sender());
//    QVariant index = button->property("index");


//    int number_of_the_route = index.toInt() + 1;


//    std::vector<std::string> route = core->getRoute(number_of_the_route);

//    for(unsigned int j = 0; j < route.size(); j++)
//    {
//        (stations_buttons_vector[number_of_the_route - 1][j])->show();
//    }
//}

//void MainWindow::showInfoAboutStation()
//{

//    QPushButton *button = qobject_cast<QPushButton*>(sender());
//    QVariant index = button->property("index");

//    QString ssss = index.toString();
//    std::string name_of_the_station = ssss.toStdString();


//    std::string lolka =  "<h3>";

//    lolka += core->getInfoAboutStation(name_of_the_station);

//    QString polka = lolka.c_str();


//    label->setText(polka);
//}





