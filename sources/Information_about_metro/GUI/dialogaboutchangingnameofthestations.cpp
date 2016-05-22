#include "dialogaboutchangingnameofthestations.h"
#include "ui_dialogaboutchangingnameofthestations.h"

DialogAboutChangingNameOfTheStations::DialogAboutChangingNameOfTheStations(CoreOfInfoAboutMetro *core, int *number_of_the_route, int *number_of_the_station, QString *new_name, QMainWindow *m_window, QWidget *parent) :
    core(core),
    number_of_the_route(number_of_the_route),
    number_of_the_station(number_of_the_station),
    new_name(new_name),
    QDialog(parent),
    ui(new Ui::DialogAboutChangingNameOfTheStations)
{
    ui->setupUi(this);

    this->setWindowTitle("Изменение названия станции");

    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::stringstream print_int;
        print_int << i + 1;
        ui->comboBox->addItem((print_int.str()).c_str());
    }

    connect(this,SIGNAL(changeNameOfStation()),m_window,SLOT(changeNameOfStation()));
}

DialogAboutChangingNameOfTheStations::~DialogAboutChangingNameOfTheStations()
{
    delete ui;
}

void DialogAboutChangingNameOfTheStations::on_comboBox_activated(int index)
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

void DialogAboutChangingNameOfTheStations::on_comboBox_2_activated(int index)
{
    *number_of_the_station = index;

    ui->textEdit->setEnabled(true);
}

void DialogAboutChangingNameOfTheStations::on_pushButton_clicked()
{
    *new_name = ui->textEdit->toPlainText();

    emit changeNameOfStation();
    close();
}

void DialogAboutChangingNameOfTheStations::on_textEdit_textChanged()
{
    ui->pushButton->setEnabled(true);
}
