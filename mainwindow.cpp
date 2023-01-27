#include "mainwindow.h"
#include "ui_mainwindow.h"

extern SplashWindow *sw;

#define POWER_IO      6

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //set font
    id = QFontDatabase::addApplicationFont(":/fonts/fSakalBharati_N_Ship.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fontSB(family);
    fontSB.setPointSize(60);
    fontSB.setBold(true);
    ui->label_message->setText("Welcome to Indian Railways \n भारतीय रेल आपका स्वागत करती है");
    ui->label_message->setFont(fontSB);

    read_rinfo();

    ui->stackedWidget->setCurrentIndex(0);//currentSlide);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));

    //start tcp server

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,3669);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(client_connected()));

    ui->graphicsView->hide();
    update();

//    gpio.gpio_unexport(POWER_IO);
//    gpio.gpio_export(POWER_IO);
//    gpio.gpio_set_dir(POWER_IO, "in");

//    io_log="LCD_PIS Dislay On";

//    gpioTimer = new QTimer();
//    connect(gpioTimer, SIGNAL(timeout()), this, SLOT(gpio_timeout()));
//    gpioTimer->start(5000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::gpio_timeout()
//{
//    gpio_val=1;

//    //check for gpio press
//    gpio.gpio_get_value(POWER_IO,&gpio_val);
//    if(gpio_val==0)
//    {
//        disp_on^=true;
//    }
//    else
//    {

//    }

//    if(disp_on)
//    {
//     io_log="LCD_PIS Dislay On";
//    }
//    else
//    {
//     io_log="LCD_PIS Dislay Off";
//    }

////    system(QString("gst-launch-1.0 playbin uri=file:///home/root/sound/w_msg_en.mp3").toLocal8Bit());
//}

void MainWindow::client_connected()
{
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);

    ui->label_message_2->setText(" Incoming");
    connect(clientConnection,SIGNAL(readyRead()),this,SLOT(server_ready_read()));

    if(bootup)
    {
        ui->label_message->setText("INDIAN RAILWAYS WELCOMES YOU");
        bootup=false;
    }
}

void MainWindow::read_rinfo()
{
    QFile loadFile(QString("./rinfo.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        return;
    }
    else
    {
        QByteArray saveData = loadFile.readAll();
        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
        QJsonObject json = loadDoc.object();
        r_info.read(json);
        qDebug()<<QString("Read Info From JSON");
        render_rinfo();
        render_route();
    }
}

void MainWindow::parse_rinfo(QJsonObject &json)
{
    r_info.read(json);
    ui->label_message->setText("");
    render_rinfo();
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget->show();
    update();
    render_route();
}

void MainWindow::render_rinfo()
{
    QObjectList cList = ui->labelLayout_2->children();
    for(int idx=0;idx<cList.count();idx++)
    {
        delete cList.at(idx);
    }

//    QFont fontSB(family);
//    fontSB.setPointSize(30);
//    fontSB.setBold(true);

    ui->label_train_no->setStyleSheet("color: rgb(255, 255, 255);");
    ui->label_train_no->setText("");
//    ui->label_train_no->setFont(fontSB);
    ui->label_train_no->setText(r_info.tr_no_en);
    ui->label_train_no->show();


    if(boot)
    {
        boot=false;
    }
    else
    {
         ml->close();
    }
    ml = new WidgetMarqueeLabel(this);
    ml->setAlignment(Qt::AlignVCenter);
    ml->setStyleSheet("color: rgb(255, 255, 255);");
    ml->setText(r_info.tr_nm_en);
    ml->setFont(ui->label_train_no->font());
    ml->setSpeed(5);
    ml->setText(r_info.tr_nm_en);
    ui->labelLayout_2->addWidget(ml);
    ml->show();
    update();
}

void MainWindow::render_position(double km)
{
    if(r_info.st_list.count()>0)
    {
        double dist= totalPixel*km;

        qLabel_p->setStyleSheet("background-image: url(:/images/circle_yellow.png);background-color: rgb(255,0,0,0);");



        qLabel_p->setGeometry(100+totalPixel*km, 120, 48, 48);
        qLabel_p->setGeometry(100+km*totalPixel, 120, 48, 48);
        qLabel_p->show();





        if(qLabel_p->geometry().x()>=1200 && qLabel_p->geometry().x()<=2300){

            qLabel_p2->setStyleSheet("background-image: url(:/images/circle_yellow.png);background-color: rgb(255,0,0,0);");
            qLabel_p2->setGeometry(100+totalPixel*km-1100, 120, 48, 48);
            qLabel_p2->setGeometry(100+km*totalPixel-1100, 120, 48, 48);
            qLabel_p2->show();
            ui->stackedWidget_2->setCurrentIndex(1);

        }
        else if(qLabel_p->geometry().x()>2301 && qLabel_p->geometry().x()<=3400){

            qLabel_p3->setStyleSheet("background-image: url(:/images/circle_yellow.png);background-color: rgb(255,0,0,0);");
            qLabel_p3->setGeometry(100+totalPixel*km-2200, 120, 48, 48);
            qLabel_p3->setGeometry(100+km*totalPixel-2200, 120, 48, 48);
            qLabel_p3->show();
            ui->stackedWidget_2->setCurrentIndex(2);

        }

        update();
    }
}

void MainWindow::render_route()
{
    route_clear=false;
    ui->graphicsView->show();


    int totalNoOfStations=r_info.st_list.size();


    QLabel *labelForRoute1=new QLabel(ui->routePage1);
    labelForRoute1->setGeometry(100,140,1100,10);
    labelForRoute1->setStyleSheet("background-color: rgb(220, 220, 220);");
    labelForRoute1->show();
    int totalDistance;
    if(totalNoOfStations<=10){
        totalDistance=1100;

    }
    else if(totalNoOfStations>10 & totalNoOfStations<=20){
        totalDistance=2200;
        //route page label
        QLabel *labelForRoute2=new QLabel(ui->routePage2);
        labelForRoute2->setGeometry(100,140,1100,10);
        labelForRoute2->setStyleSheet("background-color: rgb(220, 220, 220);");
        labelForRoute2->show();

        dotLabel_p1=new QLabel (ui->routePage1);
        dotLabel_p2=new QLabel (ui->routePage1);
        dotLabel_p3=new QLabel (ui->routePage1);
        dotLabel_p1->setGeometry(1210,140,10,10);
        dotLabel_p2->setGeometry(1230,140,10,10);
        dotLabel_p3->setGeometry(1250,140,10,10);
        dotLabel_p1->setStyleSheet("background-color: rgb(0, 220, 220);");
        dotLabel_p2->setStyleSheet("background-color: rgb(0, 220, 220);");
        dotLabel_p3->setStyleSheet("background-color: rgb(0, 220, 220);");
        dotLabel_p1->show();
        dotLabel_p2->show();
        dotLabel_p3->show();

        dotLabel_p1=new QLabel (ui->routePage2);
        dotLabel_p2=new QLabel (ui->routePage2);
        dotLabel_p3=new QLabel (ui->routePage2);
        dotLabel_p1->setGeometry(80,260,10,10);
        dotLabel_p2->setGeometry(60,260,10,10);
        dotLabel_p3->setGeometry(40,260,10,10);
        dotLabel_p1->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p2->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p3->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p1->show();
        dotLabel_p2->show();
        dotLabel_p3->show();

    }
    else if(totalNoOfStations>20 & totalNoOfStations<=30){
        QLabel *labelForRoute2=new QLabel(ui->routePage2);
        labelForRoute2->setGeometry(100,140,1100,10);
        labelForRoute2->setStyleSheet("background-color: rgb(220, 220, 220);");
        labelForRoute2->show();
        QLabel *labelForRoute3=new QLabel(ui->routePage3);
        labelForRoute3->setGeometry(100,140,1100,10);
        labelForRoute3->setStyleSheet("background-color: rgb(220, 220, 220);");
        labelForRoute3->show();


        totalDistance=3300;
        dotLabel_p1=new QLabel (ui->routePage1);
        dotLabel_p2=new QLabel (ui->routePage1);
        dotLabel_p3=new QLabel (ui->routePage1);
        dotLabel_p1->setGeometry(1210,140,10,10);
        dotLabel_p2->setGeometry(1230,140,10,10);
        dotLabel_p3->setGeometry(1250,140,10,10);
        dotLabel_p1->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p2->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p3->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p1->show();
        dotLabel_p2->show();
        dotLabel_p3->show();

        dotLabel_p1=new QLabel (ui->routePage2);
        dotLabel_p2=new QLabel (ui->routePage2);
        dotLabel_p3=new QLabel (ui->routePage2);
        dotLabel_p1->setGeometry(80,140,10,10);
        dotLabel_p2->setGeometry(60,140,10,10);
        dotLabel_p3->setGeometry(40,140,10,10);
        dotLabel_p1->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p2->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p3->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p1->show();
        dotLabel_p2->show();
        dotLabel_p3->show();

        dotLabel_p1=new QLabel (ui->routePage2);
        dotLabel_p2=new QLabel (ui->routePage2);
        dotLabel_p3=new QLabel (ui->routePage2);
        dotLabel_p1->setGeometry(1210,140,10,10);
        dotLabel_p2->setGeometry(1230,140,10,10);
        dotLabel_p3->setGeometry(1250,140,10,10);
        dotLabel_p1->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p2->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p3->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p1->show();
        dotLabel_p2->show();
        dotLabel_p3->show();

        dotLabel_p1=new QLabel (ui->routePage3);
        dotLabel_p2=new QLabel (ui->routePage3);
        dotLabel_p3=new QLabel (ui->routePage3);
        dotLabel_p1->setGeometry(80,140,10,10);
        dotLabel_p2->setGeometry(60,140,10,10);
        dotLabel_p3->setGeometry(40,140,10,10);
        dotLabel_p1->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p2->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p3->setStyleSheet("background-color: rgb(220, 220, 220);");
        dotLabel_p1->show();
        dotLabel_p2->show();
        dotLabel_p3->show();
    }
    else{

    }


    totalPixel=(double)(totalDistance)/r_info.st_list[r_info.st_list.size()-1].dist_km;
    qDebug() << totalPixel;

    for(int index=0;index<r_info.st_list.size();index++){
        valueOfX=totalPixel * r_info.st_list[index].dist_km;
        QFont font;
        font.setPointSize(12);
        font.setBold(true);

        if(valueOfX<=1100){
            if(index%2==0){

                ui->stackedWidget_2->setCurrentIndex(0);
                QLabel *label=new QLabel (ui->routePage1);
                QLabel *engLabel =new QLabel(ui->routePage1);

                QLabel *hindiLabel=new QLabel (ui->routePage1) ;
                hindiLabel->setGeometry(valueOfX-20+100,230,120,20);
                hindiLabel->setStyleSheet("font-size:15px");
                hindiLabel->setText(r_info.st_list[index].st_name_hi);
                hindiLabel->setWordWrap(true);
//                hindiLabel->setAlignment(Qt::AlignCenter);
                hindiLabel->show();
                QLabel *regLabel=new QLabel(ui->routePage1);
                regLabel->setGeometry(valueOfX-20+100,260,120,20);
                regLabel->setStyleSheet("font-size:15px");
                regLabel->setText(r_info.st_list[index].st_name_rl);
                regLabel->setWordWrap(true);
//                regLabel->setAlignment(Qt::AlignCenter);
                regLabel->show();

                label->setStyleSheet("background-color: rgb(220, 220, 220);");
                label->setGeometry(valueOfX+100+10,140,5,50);

                engLabel->setGeometry(valueOfX-70+100,200,160,20);
                engLabel->setStyleSheet("font-size:12px");
                engLabel->setAlignment(Qt::AlignCenter);
                engLabel->setText( r_info.st_list[index].st_name_en);
                engLabel->setWordWrap(true);
//                engLabel->setStyleSheet("background-color:rgb(200,150,40);");
                engLabel->show();
                label->show();
                QLabel *qLabel_d = new QLabel(ui->routePage1);

                qLabel_d->setStyleSheet("background-image: url(:/images/circle_green.png);background-color: rgb(255,0,0,0);");
                qLabel_d->setGeometry(100+valueOfX-10, 120, 48, 48);
                qLabel_d->show();



            }

            else{


                ui->stackedWidget_2->setCurrentIndex(0);
                QLabel *label=new QLabel (ui->routePage1);
                QLabel *engLabel =new QLabel(ui->routePage1);

                QLabel *hindiLabel=new QLabel (ui->routePage1) ;
                hindiLabel->setGeometry(valueOfX-20+100,30,120,20);
                hindiLabel->setStyleSheet("font-size:15px");
                hindiLabel->setText(r_info.st_list[index].st_name_hi);
                hindiLabel->setWordWrap(true);
//                hindiLabel->setAlignment(Qt::AlignCenter);
                hindiLabel->show();
                QLabel *regLabel=new QLabel(ui->routePage1);
                regLabel->setGeometry(valueOfX-20+100,0,120,20);
                regLabel->setStyleSheet("font-size:15px");
                regLabel->setText(r_info.st_list[index].st_name_rl);
                regLabel->setWordWrap(true);
//                regLabel->setAlignment(Qt::AlignCenter);
                regLabel->show();

                engLabel->setStyleSheet("background-color:rgb(200,50,50);");
                engLabel->setGeometry(valueOfX-70+100,60,160,20);
                engLabel->setAlignment(Qt::AlignCenter);
                engLabel->setText( r_info.st_list[index].st_name_en);
                engLabel->setWordWrap(true);
                engLabel->setStyleSheet("font-size:12px");
//                engLabel->setStyleSheet("background-color:rgb(200,150,40);");
                engLabel->show();
                label->setStyleSheet("background-color: rgb(220, 220, 220);");
                label->setGeometry(valueOfX+100+10,100,5,50);
                label->show();
                QLabel *qLabel_d = new QLabel(ui->routePage1);
                qLabel_d->setStyleSheet("background-image: url(:/images/circle_green.png);background-color: rgb(255,0,0,0);");
                qLabel_d->setGeometry(100+valueOfX-10, 120, 48, 48);
                qLabel_d->show();

            }


        }
        else if(valueOfX>1100 & valueOfX<=2200){
            if(index%2==0){


                ui->stackedWidget_2->setCurrentIndex(0);
                QLabel *label=new QLabel (ui->routePage2);
                QLabel *engLabel =new QLabel(ui->routePage2);

                QLabel *hindiLabel=new QLabel (ui->routePage2) ;
                hindiLabel->setGeometry(valueOfX-50+100-1100,230,120,20);
                hindiLabel->setStyleSheet("font-size:15px");
                hindiLabel->setText(r_info.st_list[index].st_name_hi);
                hindiLabel->setWordWrap(true);
                hindiLabel->setAlignment(Qt::AlignCenter);
                hindiLabel->show();
                QLabel *regLabel=new QLabel(ui->routePage2);
                regLabel->setGeometry(valueOfX-50+100-1100,260,120,20);
                regLabel->setStyleSheet("font-size:15px");
                regLabel->setText(r_info.st_list[index].st_name_rl);
                regLabel->setWordWrap(true);
                regLabel->setAlignment(Qt::AlignCenter);
                regLabel->show();

                label->setGeometry(valueOfX+100+10-1100,140,5,50);

                engLabel->setGeometry(valueOfX-70+100-1100,200,160,20);

                engLabel->setStyleSheet("background-color:rgb(200,150,40);");

                engLabel->setStyleSheet("font-size:12px");
                engLabel->setAlignment(Qt::AlignCenter);
                engLabel->setText( r_info.st_list[index].st_name_en);
                engLabel->setWordWrap(true);
//                engLabel->setStyleSheet("background-color:rgb(200,150,40);");
                engLabel->show();
                label->setStyleSheet("background-color: rgb(220, 220, 220);");
                label->show();
                QLabel *qLabel_d = new QLabel(ui->routePage2);
                qLabel_d->setStyleSheet("background-image: url(:/images/circle_green.png);background-color: rgb(255,0,0,0);");
                qLabel_d->setGeometry(100+valueOfX-10-1100, 120, 48, 48);
                qLabel_d->show();
            }

            else{


                ui->stackedWidget_2->setCurrentIndex(0);
                QLabel *label=new QLabel (ui->routePage2);
                QLabel *engLabel =new QLabel(ui->routePage2);

                QLabel *hindiLabel=new QLabel (ui->routePage2) ;
                hindiLabel->setGeometry(valueOfX-20+100-1100,30,120,20);
                hindiLabel->setStyleSheet("font-size:15px");
                hindiLabel->setText(r_info.st_list[index].st_name_hi);
                hindiLabel->setWordWrap(true);
//                hindiLabel->setAlignment(Qt::AlignCenter);
                hindiLabel->show();
                QLabel *regLabel=new QLabel(ui->routePage2);
                regLabel->setGeometry(valueOfX-20+100-1100,0,120,20);
                regLabel->setStyleSheet("font-size:15px");
                regLabel->setText(r_info.st_list[index].st_name_rl);
                regLabel->setWordWrap(true);
//                regLabel->setAlignment(Qt::AlignCenter);
                regLabel->show();

                engLabel->setStyleSheet("background-color:rgb(200,50,50);");
                engLabel->setGeometry(valueOfX-70+100-1100,60,160,20);
                engLabel->setAlignment(Qt::AlignCenter);
                engLabel->setText( r_info.st_list[index].st_name_en);
                engLabel->setWordWrap(true);
                engLabel->setStyleSheet("font-size:12px");
//                engLabel->setStyleSheet("background-color:rgb(200,150,40);");
                engLabel->show();
                label->setStyleSheet("background-color: rgb(220, 220, 220);");
                label->setGeometry(valueOfX+100+10-1100,100,5,50);
                label->show();
                QLabel *qLabel_d = new QLabel(ui->routePage2);
                qLabel_d->setStyleSheet("background-image: url(:/images/circle_green.png);background-color: rgb(255,0,0,0);");
                qLabel_d->setGeometry(100+valueOfX-10-1100, 120, 48, 48);
                qLabel_d->show();

            }
        }
        else if(valueOfX>2200 & valueOfX<=3300){
            if(index%2==0){


                ui->stackedWidget_2->setCurrentIndex(0);
                QLabel *label=new QLabel (ui->routePage3);
                QLabel *engLabel =new QLabel(ui->routePage3);

                QLabel *hindiLabel=new QLabel (ui->routePage3) ;
                hindiLabel->setGeometry(valueOfX-50+100-2200,230,120,20);
                hindiLabel->setStyleSheet("font-size:15px");
                hindiLabel->setText(r_info.st_list[index].st_name_hi);
                hindiLabel->setWordWrap(true);
                hindiLabel->setAlignment(Qt::AlignCenter);
                hindiLabel->show();
                QLabel *regLabel=new QLabel(ui->routePage3);
                regLabel->setGeometry(valueOfX-50+100-2200,260,120,20);
                regLabel->setStyleSheet("font-size:15px");
                regLabel->setText(r_info.st_list[index].st_name_rl);
                regLabel->setWordWrap(true);
                regLabel->setAlignment(Qt::AlignCenter);
                regLabel->show();

                label->setGeometry(valueOfX+100+10-2200,140,5,50);

                engLabel->setGeometry(valueOfX-70+100-2200,200,160,20);

                engLabel->setStyleSheet("background-color:rgb(200,150,40);");

                engLabel->setStyleSheet("font-size:12px");
                engLabel->setAlignment(Qt::AlignCenter);
                engLabel->setText( r_info.st_list[index].st_name_en);
                engLabel->setWordWrap(true);
                label->setStyleSheet("background-color: rgb(220, 220, 220);");
//                engLabel->setStyleSheet("background-color:rgb(200,150,40);");
                engLabel->show();
                label->show();
                QLabel *qLabel_d = new QLabel(ui->routePage3);
                qLabel_d->setStyleSheet("background-image: url(:/images/circle_green.png);background-color: rgb(255,0,0,0);");
                qLabel_d->setGeometry(100+valueOfX-10-2200, 120, 48, 48);
                qLabel_d->show();
            }

            else{


                ui->stackedWidget_2->setCurrentIndex(0);
                QLabel *label=new QLabel (ui->routePage3);
                QLabel *engLabel =new QLabel(ui->routePage3);

                QLabel *hindiLabel=new QLabel (ui->routePage3) ;
                hindiLabel->setGeometry(valueOfX-20+110-2200,30,120,20);
                hindiLabel->setStyleSheet("font-size:15px");
                hindiLabel->setText(r_info.st_list[index].st_name_hi);
                hindiLabel->setWordWrap(true);
//                hindiLabel->setAlignment(Qt::AlignCenter);
                hindiLabel->show();
                QLabel *regLabel=new QLabel(ui->routePage3);
                regLabel->setGeometry(valueOfX-20+110-2200,0,120,20);
                regLabel->setStyleSheet("font-size:15px");
                regLabel->setText(r_info.st_list[index].st_name_rl);
                regLabel->setWordWrap(true);
//                regLabel->setAlignment(Qt::AlignCenter);
                regLabel->show();

                engLabel->setStyleSheet("background-color:rgb(200,50,50);");
                engLabel->setGeometry(valueOfX-70+110-2200,60,160,20);
                engLabel->setAlignment(Qt::AlignCenter);
                engLabel->setText( r_info.st_list[index].st_name_en);
                engLabel->setWordWrap(true);
                engLabel->setStyleSheet("font-size:12px");
//                engLabel->setStyleSheet("background-color:rgb(200,150,40);");
                engLabel->show();
                label->setStyleSheet("background-color: rgb(220, 220, 220);");
                label->setGeometry(valueOfX+110+10-2200,100,5,50);
                label->show();
                QLabel *qLabel_d = new QLabel(ui->routePage3);
                qLabel_d->setStyleSheet("background-image: url(:/images/circle_green.png);background-color: rgb(255,0,0,0);");
                qLabel_d->setGeometry(110+valueOfX-10-2200, 120, 48, 48);
                qLabel_d->show();

            }
        }
    }
        qLabel_p = new QLabel(ui->routePage1);

        qLabel_p2=new QLabel (ui->routePage2) ;
        qLabel_p3=new QLabel(ui->routePage3);

    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);




    update();
}

void MainWindow::update_mpu(QString ip)
{
    ip="192.168.0.108";
    QTcpSocket  *socket = new QTcpSocket();
    socket->connectToHost(ip,3700);
    socket->write(QString("log="+io_log).toLocal8Bit());
    socket->disconnect();
    socket->close();
}

void MainWindow:: showImages(){
    imagesTimer=new QTimer();
    imageIndex=0;
    connect(imagesTimer, SIGNAL(timeout()), this, SLOT(showAd()));
    imagesTimer->start(2000);

}

void MainWindow::showAd(){


    QPixmap p;
    if(p.loadFromData(imagesData[imageIndex],"PNG")){
        int w=ui->label->width();
        int h=ui->label->height();

         ui->label->setPixmap(p.scaled(w,h,Qt::IgnoreAspectRatio));


          imageIndex +=1;
          if(imageIndex>4){
              imageIndex=0;
//              imagesTimer->stop();
          }
    }

}
void MainWindow::playVideo(){

    player=new QMediaPlayer ();
    video=new QVideoWidget (ui->label) ;
    video->show();
    player->setVideoOutput(video);
    player->setMedia(QUrl("gst-pipeline: udpsrc port=9999 caps=\"application/x-rtp, media=(string)video, clock-rate=(int)90000, payload=(int)96, encoding-name=(string)H264\" ! rtph264depay ! identity silent=0 ! avdec_h264 ! videoconvert ! xvimagesink name=\"qtvideosink\""));

    video->setGeometry(0,0,ui->label->width(),ui->label->height());
    video->setAspectRatioMode(Qt::IgnoreAspectRatio);
    player->play();

}

void MainWindow::server_ready_read()
{
    QByteArray block = clientConnection->readAll();
    if(block.contains("id?"))
    {
        clientConnection->write(QByteArray("id_sjpsj"));

    }
    else if (block.contains("msg1=")) {
        block.remove(0,5);
        int i=0;
        while(i<block.size()){

            img1.append(block.at(i));
            i=i+1;

        }

        imagesData.append(img1);

    }

    else if (block.contains("msg2=")) {

        block.remove(0,5);
        int i=0;
        while(i<block.size()){
            img2.append(block.at(i));
            i=i+1;

        }
        imagesData.append(img2);

    }
    else if (block.contains("msg3=")) {

        block.remove(0,5);
        int i=0;
        while(i<block.size()){
            img3.append(block.at(i));
            i=i+1;

        }
        imagesData.append(img3);

    }
    else if (block.contains("msg4=")) {

        block.remove(0,5);
        int i=0;
        while(i<block.size()){
            img4.append(block.at(i));
            i=i+1;

        }
        imagesData.append(img4);

    }
    else if (block.contains("msg5=")) {

        block.remove(0,5);
        int i=0;
        while(i<block.size()){
            img5.append(block.at(i));
            i=i+1;

        }
        imagesData.append(img5);
        showImages();



    }
    else if(block.contains("play="))
    {


        playVideo();

    }


    else if(block.contains("log="))
    {
        QString str = QString::fromStdString(block.toStdString());
        update_mpu(str.split("=").last());
    }
    else
    if(block.contains("rinfo="))
    {
        block.remove(0,6);
//        qDebug()<<QString("Received rInfo: ") << block;
        ui->label_message_2->setText(" Received Route Info");
        QJsonDocument loadDoc(QJsonDocument::fromJson(block));
        QJsonObject json = loadDoc.object();
        parse_rinfo(json);
    }
    else
    if(block.contains("dist="))
    {
        ui->label_message_2->setText(" Dist Updated");
        QString str = QString::fromStdString(block.toStdString());
        ui->stackedWidget->setCurrentIndex(1);
        render_position(str.split("=").last().toDouble());
    }
    else
    if(block.contains("msg="))
    {
        ui->label_message_2->setText(" Message Updated");
        QString str = QString::fromStdString(block.toStdString()).split("=").last();
        QJsonDocument doc=QJsonDocument::fromJson(str.toUtf8());

        ui->stackedWidget->setCurrentIndex(0);
        //ui->label_message->setText(doc["msg"].toString());
        ui->stackedWidget->show();
        update();
    }
    else
    if(block.contains("alert="))
    {
        ui->label_message_2->setText(" Alert Received");
        QString str = QString::fromStdString(block.toStdString());
        ui->stackedWidget->setCurrentIndex(2);
        str.split("=").last().toInt();

        switch(str.split("=").last().toInt())
        {
        case 1:

            ui->label_t1->setStyleSheet("image: url(:/images/icon_siren.png);");
//            system(QString("gst-launch-1.0 playbin uri=file:///home/root/papis/sounds/attention.mp3 &").toLocal8Bit());
            break;
        case 2:
            ui->label_t2->setStyleSheet("image: url(:/images/icon_siren.png);");
//            system(QString("gst-launch-1.0 playbin uri=file:///home/root/papis/sounds/attention.mp3 &").toLocal8Bit());
            break;
        case 3:
            ui->label_t3->setStyleSheet("image: url(:/images/icon_siren.png);");
//            system(QString("gst-launch-1.0 playbin uri=file:///home/root/papis/sounds/attention.mp3 &").toLocal8Bit());
            break;
        case 4:
            ui->label_t4->setStyleSheet("image: url(:/images/icon_siren.png);");
//            system(QString("gst-launch-1.0 playbin uri=file:///home/root/papis/sounds/attention.mp3 &").toLocal8Bit());
            break;
        }

        ui->label_t1->show();
        ui->label_t2->show();
        ui->label_t3->show();
        ui->label_t4->show();
        ui->stackedWidget->show();
        update();
    }
    else
    if(block.contains("clear="))
    {
        QString str = QString::fromStdString(block.toStdString());
        ui->stackedWidget->setCurrentIndex(2);
        str.split("=").last().toInt();

        switch(str.split("=").last().toInt())
        {
        case 1:

            ui->label_t1->setStyleSheet("image: url(:/images/icon_ok.png);");
            break;
        case 2:
            ui->label_t2->setStyleSheet("image: url(:/images/icon_ok.png);");
            break;
        case 3:
            ui->label_t3->setStyleSheet("image: url(:/images/icon_ok.png);");
            break;
        case 4:
            ui->label_t4->setStyleSheet("image: url(:/images/icon_ok.png);");
            break;
        }

        ui->label_t1->show();
        ui->label_t2->show();
        ui->label_t3->show();
        ui->label_t4->show();
        ui->stackedWidget->show();
        update();
    }
    else
    if(block.contains("mode="))
    {
        QString str = QString::fromStdString(block.toStdString());
        if(str.split("=").last()=="n")
        {
//#ifdef  LCD_18
//    system("echo 1 > /sys/class/backlight/backlight/brightness");
//#else
//     system("echo 6 > /sys/class/backlight/backlight/brightness");
//#endif
        }
        else
        {
//#ifdef  LCD_18
//    system("echo 7 > /sys/class/backlight/backlight/brightness");
//#else
//     system("echo 1 > /sys/class/backlight/backlight/brightness");
//#endif
        }
    }
    else
    if(block.contains("return"))
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_message->setText("");
        ui->graphicsView->hide();
        ui->stackedWidget->show();
        update();
    }
    else
    if(block.contains("err"))
    {
        if(!route_clear)
        {
//            QObjectList cList = ui->frame_2->children();
//            for(int idx=0;idx<cList.count();idx++)
//            {
//                delete cList.at(idx);
//            }
            route_clear=true;
        }

        QString str = QString::fromStdString(block.toStdString());
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_train_no->setText("");
        ml->setText("");
        ui->label_message->setText("Welcome to Indian Railways \n भारतीय रेल आपका स्वागत करती है");
        ui->graphicsView->hide();
        ui->stackedWidget->show();
        update();
    }
}

void MainWindow::timer_timeout()
{
    currentSlide++;
    if(currentSlide>=ui->stackedWidget->count())
    {
        currentSlide=0;
    }
    ui->stackedWidget->setCurrentIndex(currentSlide);
}




