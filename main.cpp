#include "mainwindow.h"
#include "splashwindow.h"

#include <QApplication>
#include <QFont>
#include <QFontDatabase>

SplashWindow *sw;

int main(int argc, char *argv[])
{
   // qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    return a.exec();
}
