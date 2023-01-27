/********************************************************************************
** Form generated from reading UI file 'splashwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHWINDOW_H
#define UI_SPLASHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SplashWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label_eng;
    QLabel *label_pwr;
    QGraphicsView *graphicsView_2;
    QLabel *label_hwid;
    QLabel *label_hwidval;
    QLabel *label_verval;
    QLabel *label_ver;
    QLabel *label_hin;

    void setupUi(QMainWindow *SplashWindow)
    {
        if (SplashWindow->objectName().isEmpty())
            SplashWindow->setObjectName(QStringLiteral("SplashWindow"));
        SplashWindow->setWindowModality(Qt::NonModal);
        SplashWindow->resize(1280, 768);
        QFont font;
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        SplashWindow->setFont(font);
        SplashWindow->setWindowTitle(QStringLiteral(""));
        SplashWindow->setAutoFillBackground(false);
        SplashWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(SplashWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(440, 50, 400, 400));
        graphicsView->setStyleSheet(QLatin1String("border-image: url(:/images/ir_logo_400x400.png);\n"
""));
        label_eng = new QLabel(centralwidget);
        label_eng->setObjectName(QStringLiteral("label_eng"));
        label_eng->setGeometry(QRect(0, 460, 1280, 100));
        QFont font1;
        font1.setPointSize(42);
        font1.setBold(true);
        font1.setWeight(75);
        label_eng->setFont(font1);
        label_eng->setAlignment(Qt::AlignCenter);
        label_eng->setTextInteractionFlags(Qt::NoTextInteraction);
        label_pwr = new QLabel(centralwidget);
        label_pwr->setObjectName(QStringLiteral("label_pwr"));
        label_pwr->setGeometry(QRect(980, 700, 121, 40));
        QFont font2;
        font2.setPointSize(11);
        label_pwr->setFont(font2);
        label_pwr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_pwr->setTextInteractionFlags(Qt::NoTextInteraction);
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(1110, 700, 140, 40));
        graphicsView_2->setStyleSheet(QLatin1String("border-image: url(:/images/rtv_logo_small.png);\n"
""));
        label_hwid = new QLabel(centralwidget);
        label_hwid->setObjectName(QStringLiteral("label_hwid"));
        label_hwid->setGeometry(QRect(10, 700, 61, 40));
        label_hwid->setFont(font2);
        label_hwid->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_hwid->setTextInteractionFlags(Qt::NoTextInteraction);
        label_hwidval = new QLabel(centralwidget);
        label_hwidval->setObjectName(QStringLiteral("label_hwidval"));
        label_hwidval->setGeometry(QRect(70, 700, 121, 40));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_hwidval->setFont(font3);
        label_hwidval->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_hwidval->setTextInteractionFlags(Qt::NoTextInteraction);
        label_verval = new QLabel(centralwidget);
        label_verval->setObjectName(QStringLiteral("label_verval"));
        label_verval->setGeometry(QRect(290, 700, 121, 40));
        label_verval->setFont(font3);
        label_verval->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_verval->setTextInteractionFlags(Qt::NoTextInteraction);
        label_ver = new QLabel(centralwidget);
        label_ver->setObjectName(QStringLiteral("label_ver"));
        label_ver->setGeometry(QRect(220, 700, 61, 40));
        label_ver->setFont(font2);
        label_ver->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ver->setTextInteractionFlags(Qt::NoTextInteraction);
        label_hin = new QLabel(centralwidget);
        label_hin->setObjectName(QStringLiteral("label_hin"));
        label_hin->setGeometry(QRect(0, 560, 1280, 100));
        label_hin->setFont(font1);
        label_hin->setAlignment(Qt::AlignCenter);
        label_hin->setTextInteractionFlags(Qt::NoTextInteraction);
        SplashWindow->setCentralWidget(centralwidget);

        retranslateUi(SplashWindow);

        QMetaObject::connectSlotsByName(SplashWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SplashWindow)
    {
        label_eng->setText(QApplication::translate("SplashWindow", "Indian Railways Welcomes You", 0));
        label_pwr->setText(QApplication::translate("SplashWindow", "Powered by", 0));
        label_hwid->setText(QApplication::translate("SplashWindow", "HW ID", 0));
        label_hwidval->setText(QApplication::translate("SplashWindow", "RTV2101AB123", 0));
        label_verval->setText(QApplication::translate("SplashWindow", "00.00.001", 0));
        label_ver->setText(QApplication::translate("SplashWindow", "SW Ver.", 0));
        label_hin->setText(QApplication::translate("SplashWindow", "\340\244\255\340\244\276\340\244\260\340\244\244\340\245\200\340\244\257 \340\244\260\340\245\207\340\244\262 \340\244\206\340\244\252\340\244\225\340\244\276 \340\244\270\340\245\215\340\244\265\340\244\276\340\244\227\340\244\244 \340\244\225\340\244\260\340\244\244\340\245\200 \340\244\271\340\245\210", 0));
        Q_UNUSED(SplashWindow);
    } // retranslateUi

};

namespace Ui {
    class SplashWindow: public Ui_SplashWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHWINDOW_H
