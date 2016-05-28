#include "dialogaboutdeletingstation.h"
#include "ui_dialogaboutdeletingstation.h"

DialogAboutDeletingStation::DialogAboutDeletingStation(CoreOfInfoAboutMetro *core, int *number_of_the_route, int *number_of_the_station, QMainWindow *m_window, QWidget *parent) :
    core(core),
    number_of_the_route(number_of_the_route),
    number_of_the_station(number_of_the_station),
    QDialog(parent),
    ui(new Ui::DialogAboutDeletingStation)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("QPushButton "
                                  "{"
                                  "background: #fde910;"
                                  "border: 1px solid 000000;"
                                  "border-radius: 9px;"
                                  "}"
                                  "QPushButton:hover "
                                  "{"
                                  "background: #ffd919;"
                                  "}"
                                  "QPushButton:pressed "
                                  "{"
                                  "background: #e6bf00;"
                                  "}");
    ui->comboBox->setStyleSheet("QComboBox "
                                "{"
                                "background: #fced3f;"
                                "border-radius: 1px;"
                                "}"
                                "QComboBox:editable"
                                "{"
                                "background: white;"
                                "}"
                                "QComboBox QAbstractItemView {"
                                "background: #fcf172;"
                                "selection-color: black;"
                                "selection-background-color: #fced3f;"
                                "}");
    ui->comboBox_2->setStyleSheet("QComboBox "
                                "{"
                                "background: #fced3f;"
                                "border-radius: 1px;"
                                "}"
                                "QComboBox:editable"
                                "{"
                                "background: white;"
                                "}"
                                "QComboBox QAbstractItemView {"
                                "background: #fcf172;"
                                "selection-color: black;"
                                "selection-background-color: #fced3f;"
                                "}");

    this->setWindowTitle("Удаление станции");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), Qt::white);
    this->setPalette(pal);

    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::stringstream print_int;
        print_int << i + 1;
        ui->comboBox->addItem((print_int.str()).c_str());
    }

    connect(this,SIGNAL(deletingStation()),m_window,SLOT(deletingStation()));
}

DialogAboutDeletingStation::~DialogAboutDeletingStation()
{
    delete ui;
}

void DialogAboutDeletingStation::on_comboBox_activated(int index)
{
    *number_of_the_route = index;

    ui->comboBox_2->clear();
    ui->comboBox_2->setEnabled(true);
    std::vector<std::string> route = core->getRoute(index + 1);
    for(unsigned int i = 0; i < route.size(); i++)
    {
        ui->comboBox_2->addItem(route[i].c_str());
    }
}

void DialogAboutDeletingStation::on_comboBox_2_activated(int index)
{
    *number_of_the_station = index;

    ui->pushButton->setEnabled(true);
}

void DialogAboutDeletingStation::on_pushButton_clicked()
{
    emit deletingStation();
    close();
}
