#include "splashwindow.h"
#include "ui_splashwindow.h"

#include <QNetworkInterface>
#include <QFont>
#include <QFontDatabase>

SplashWindow::SplashWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SplashWindow)
{
    ui->setupUi(this);

    //set font
    int id = QFontDatabase::addApplicationFont(":/fonts/fSakalBharati_N_Ship.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontSB(family);

    fontSB.setPointSize(11);
    ui->label_pwr->setFont(fontSB);
    ui->label_ver->setFont(fontSB);
    ui->label_hwid->setFont(fontSB);

    fontSB.setPointSize(42);
    fontSB.setBold(true);
    ui->label_hin->setFont(fontSB);
    ui->label_eng->setFont(fontSB);

    fontSB.setPointSize(11);
    ui->label_hwidval->setFont(fontSB);
    ui->label_verval->setFont(fontSB);

//    //test network
//    QTextStream out(stdout);
//    QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();
//    QNetworkInterface eth;

//    foreach(eth, allInterfaces) {
//        QList<QNetworkAddressEntry> allEntries = eth.addressEntries();
//        QNetworkAddressEntry entry;
//        foreach (entry, allEntries) {
//            out << entry.ip().toString() << "/" << entry.netmask().toString();
//        }
//    }
}

SplashWindow::~SplashWindow()
{
    delete ui;
}
