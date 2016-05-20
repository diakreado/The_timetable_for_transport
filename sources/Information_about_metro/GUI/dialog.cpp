#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(CoreOfInfoAboutMetro* core, int* index_out_of, QMainWindow* m_window, QWidget *parent) :
    core(core),
    index_out_of(index_out_of),
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setFixedSize(250,150);
    this->setWindowTitle("Удаление маршрута");

    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::stringstream print_int;
        print_int << i + 1;
        ui->comboBox->addItem((print_int.str()).c_str());
    }

    connect(this,SIGNAL(deleteRouteSignal()),m_window,SLOT(deleteRouteSlot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_comboBox_activated(int index)
{
    this->index = index;
    ui->pushButton->setEnabled(true);
}

void Dialog::on_pushButton_clicked()
{
    *index_out_of = index;


            emit deleteRouteSignal();

    this->hide();
}
