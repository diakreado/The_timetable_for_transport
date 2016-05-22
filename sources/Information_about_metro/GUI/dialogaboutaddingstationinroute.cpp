#include "dialogaboutaddingstationinroute.h"
#include "ui_dialogaboutaddingstationinroute.h"

DialogAboutAddingStationInRoute::DialogAboutAddingStationInRoute(CoreOfInfoAboutMetro *core,int *index_out_of,QString* name_of_adding_station,QMainWindow *m_window, QWidget *parent) :
    core(core),
    index_out_of(index_out_of),
    name_of_adding_station(name_of_adding_station),
    QDialog(parent),
    ui(new Ui::DialogAboutAddingStationInRoute)
{
    ui->setupUi(this);

    this->setFixedSize(300,200);
    this->setWindowTitle("Удаление маршрута");

    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::stringstream print_int;
        print_int << i + 1;
        ui->comboBox->addItem((print_int.str()).c_str());
    }

    connect(this,SIGNAL(addStationSignal()),m_window,SLOT(addStation()));
}

DialogAboutAddingStationInRoute::~DialogAboutAddingStationInRoute()
{
    delete ui;
}

void DialogAboutAddingStationInRoute::on_comboBox_activated(int index)
{
    *index_out_of = index;
    ui->textEdit->setEnabled(true);
}

void DialogAboutAddingStationInRoute::on_pushButton_clicked()
{
    *name_of_adding_station = ui->textEdit->toPlainText();

    emit addStationSignal();
    close();
}

void DialogAboutAddingStationInRoute::on_textEdit_textChanged()
{
    ui->pushButton->setEnabled(true);
}
