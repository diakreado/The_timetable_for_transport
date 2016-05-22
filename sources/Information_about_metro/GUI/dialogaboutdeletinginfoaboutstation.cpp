#include "dialogaboutdeletinginfoaboutstation.h"
#include "ui_dialogaboutdeletinginfoaboutstation.h"

DialogAboutDeletingInfoAboutStation::DialogAboutDeletingInfoAboutStation(CoreOfInfoAboutMetro* core,int *number_of_the_station,QMainWindow* m_window,
                                                                         QWidget *parent) :
    core(core),
    number_of_the_station(number_of_the_station),
    QDialog(parent),
    ui(new Ui::DialogAboutDeletingInfoAboutStation)
{
    ui->setupUi(this);

    this->setWindowTitle("Удаление информации о станции");

    QString name_of_station;
    std::vector<std::pair<std::string,std::string>> AllStaions = core->getAllStationsWhichHaveDescription();

    for(unsigned int i = 0; i < AllStaions.size(); i++)
    {
        name_of_station = ((AllStaions[i]).first).c_str();
        ui->comboBox_2->addItem(name_of_station);
    }

    connect(this,SIGNAL(deleteInfoAboutStation()),m_window,SLOT(deleteInfoAboutStation()));
}

DialogAboutDeletingInfoAboutStation::~DialogAboutDeletingInfoAboutStation()
{
    delete ui;
}

void DialogAboutDeletingInfoAboutStation::on_comboBox_2_activated(int index)
{
    *number_of_the_station = index;

    ui->textBrowser->clear();
    std::vector<std::pair<std::string,std::string>> AllStaions = core->getAllStationsWhichHaveDescription();
    QString info_about_station = ((AllStaions[index]).second).c_str();
    ui->textBrowser->setText(info_about_station);

    ui->pushButton->setEnabled(true);
}

void DialogAboutDeletingInfoAboutStation::on_pushButton_clicked()
{
    emit deleteInfoAboutStation();
    close();
}
