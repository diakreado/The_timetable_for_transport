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

    this->setWindowTitle("Удаление информации о станции");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), Qt::white);
    this->setPalette(pal);

    QString name_of_station;
    std::vector<std::pair<std::string,std::string>> AllStaions = core->getAllStationsWhichHaveDescription();

    for(unsigned int i = 0; i < AllStaions.size(); i++)
    {
        name_of_station = ((AllStaions[i]).first).c_str();
        ui->comboBox_2->addItem(name_of_station);
    }

    ui->textBrowser->setStyleSheet("font-size: 16px;");

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
