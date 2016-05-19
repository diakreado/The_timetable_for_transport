#include "timetablegui.h"

TimetableGUI::TimetableGUI(int argc, char *argv[]) : argc(argc), argv(argv)
{
    core = new CoreOfInfoAboutMetro;

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
}

int TimetableGUI::startGUI()
{
    QApplication app(argc, argv);

    MainWindow window(core);
    window.show();

    return app.exec();
}

TimetableGUI::~TimetableGUI()
{
    delete core;
}
