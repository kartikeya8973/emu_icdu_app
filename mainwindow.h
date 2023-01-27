#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QFont>
#include <QFontDatabase>
#include <QStateMachine>
#include "WidgetMarqueeLabel.h"
#include <QtNetwork>
#include "common.h"
#include "splashwindow.h"
#include "rinfo.h"
#include "station.h"
#include "gpio_utils.h"
#include <QMediaPlayer>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int x=0;
    QTcpServer *tcpServer = nullptr;
    QTcpSocket *clientConnection = nullptr;
    void read_rinfo();
    void parse_rinfo(QJsonObject &json);
    void render_rinfo();
    void render_route();
    void render_position(double km);

    void update_mpu(QString ip);
    void showImages();
    void playVideo();

private slots:
//    void gpio_timeout();
    void timer_timeout();
    void client_connected();
    void server_ready_read();
    void showAd();

private:
    QList<QByteArray> imagesData;
    QTimer *imagesTimer;
    int imageIndex=0;
    QByteArray img1;
    QByteArray img2;
    QByteArray img3;
    QByteArray img4;
    QByteArray img5;

    double valueOfX=0;
    double totalPixel;
    QLabel *qLabel_p;
    QLabel *qLabel_p2;
    QLabel *qLabel_p3;
    QLabel *dotLabel_p1;
    QLabel *dotLabel_p2;
    QLabel *dotLabel_p3;

    QMediaPlayer *player;
    QVideoWidget *video;
    gpio_utils gpio;
    Ui::MainWindow *ui;

    QTimer *gpioTimer;
    unsigned int gpio_val=1;
    bool disp_on=true;
    QTimer *slide_timer;
    WidgetMarqueeLabel *ml;
    int currentSlide=0;

    bool bootup=true;
    rinfo r_info;

    bool top=true;

    int id;
    QString family;
    bool boot=true;

    bool route_clear=false;

    QString io_log="";

};
#endif // MAINWINDOW_H
