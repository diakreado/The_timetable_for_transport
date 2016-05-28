#include "dialogaboutdeletingroute.h"
#include "ui_dialogaboutdeletingroute.h"

DialogAboutDeletingRoute::DialogAboutDeletingRoute(CoreOfInfoAboutMetro *core, int *index_out_of, QMainWindow *m_window, QWidget *parent) :
    core(core),
    index_out_of(index_out_of),
    QDialog(parent),
    ui(new Ui::DialogAboutDeletingRoute)
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

    this->setFixedSize(250,150);
    this->setWindowTitle("Удаление маршрута");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), Qt::white);
    this->setPalette(pal);

    for(int i = 0; i < core->howManyRoutes(); i++)
    {
        std::stringstream print_int;
        print_int << i + 1;
        ui->comboBox->addItem((print_int.str()).c_str());
    }

    connect(this,SIGNAL(deleteRouteSignal()),m_window,SLOT(deleteRouteSlot()));
}

DialogAboutDeletingRoute::~DialogAboutDeletingRoute()
{
    delete ui;
}

void DialogAboutDeletingRoute::on_comboBox_activated(int index)
{
    *index_out_of = index;
    ui->pushButton->setEnabled(true);
}

void DialogAboutDeletingRoute::on_pushButton_clicked()
{
    emit deleteRouteSignal();
    close();
}
