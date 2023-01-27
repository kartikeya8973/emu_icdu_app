/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QFrame *frame_route;
    QStackedWidget *stackedWidget;
    QWidget *page_message;
    QLabel *label_message;
    QWidget *page_route;
    QStackedWidget *stackedWidget_2;
    QWidget *routePage1;
    QWidget *routePage2;
    QWidget *routePage3;
    QWidget *page_alert;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_t1;
    QLabel *label_t3;
    QLabel *label_t2;
    QLabel *label_t4;
    QWidget *page;
    QLabel *label;
    QFrame *frame;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *labelLayout_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *labelLayout;
    QLabel *label_train_no;
    QLabel *label_message_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1920, 360);
        MainWindow->setWindowTitle(QStringLiteral("MainWindow"));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 50, 50));
        graphicsView->setStyleSheet(QLatin1String("border-image: url(:/images/ir_logo_100x100.png);\n"
""));
        frame_route = new QFrame(centralwidget);
        frame_route->setObjectName(QStringLiteral("frame_route"));
        frame_route->setGeometry(QRect(10, 60, 1901, 281));
        frame_route->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        frame_route->setFrameShape(QFrame::Panel);
        frame_route->setFrameShadow(QFrame::Plain);
        frame_route->setLineWidth(0);
        frame_route->setMidLineWidth(0);
        stackedWidget = new QStackedWidget(frame_route);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 1900, 281));
        page_message = new QWidget();
        page_message->setObjectName(QStringLiteral("page_message"));
        label_message = new QLabel(page_message);
        label_message->setObjectName(QStringLiteral("label_message"));
        label_message->setGeometry(QRect(0, 10, 1800, 281));
        label_message->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(60);
        label_message->setFont(font);
        label_message->setStyleSheet(QStringLiteral(""));
        label_message->setAlignment(Qt::AlignCenter);
        label_message->setWordWrap(true);
        stackedWidget->addWidget(page_message);
        page_route = new QWidget();
        page_route->setObjectName(QStringLiteral("page_route"));
        page_route->setStyleSheet(QStringLiteral(""));
        stackedWidget_2 = new QStackedWidget(page_route);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 0, 1300, 281));
        routePage1 = new QWidget();
        routePage1->setObjectName(QStringLiteral("routePage1"));
        stackedWidget_2->addWidget(routePage1);
        routePage2 = new QWidget();
        routePage2->setObjectName(QStringLiteral("routePage2"));
        stackedWidget_2->addWidget(routePage2);
        routePage3 = new QWidget();
        routePage3->setObjectName(QStringLiteral("routePage3"));
        stackedWidget_2->addWidget(routePage3);
        stackedWidget->addWidget(page_route);
        page_alert = new QWidget();
        page_alert->setObjectName(QStringLiteral("page_alert"));
        label_2 = new QLabel(page_alert);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 20, 320, 50));
        QFont font1;
        font1.setPointSize(25);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_alert);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(620, 20, 320, 50));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(page_alert);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(960, 20, 320, 50));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(page_alert);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1300, 20, 320, 50));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_t1 = new QLabel(page_alert);
        label_t1->setObjectName(QStringLiteral("label_t1"));
        label_t1->setGeometry(QRect(280, 80, 320, 180));
        label_t1->setStyleSheet(QStringLiteral("image: url(:/images/icon_ok.png);"));
        label_t3 = new QLabel(page_alert);
        label_t3->setObjectName(QStringLiteral("label_t3"));
        label_t3->setGeometry(QRect(960, 80, 320, 180));
        label_t3->setStyleSheet(QStringLiteral("image: url(:/images/icon_ok.png);"));
        label_t2 = new QLabel(page_alert);
        label_t2->setObjectName(QStringLiteral("label_t2"));
        label_t2->setGeometry(QRect(620, 80, 320, 180));
        label_t2->setStyleSheet(QLatin1String("image: url(:/images/icon_ok.png);\n"
""));
        label_t4 = new QLabel(page_alert);
        label_t4->setObjectName(QStringLiteral("label_t4"));
        label_t4->setGeometry(QRect(1300, 80, 320, 180));
        label_t4->setStyleSheet(QStringLiteral("image: url(:/images/icon_ok.png);"));
        stackedWidget->addWidget(page_alert);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        label = new QLabel(frame_route);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 10, 281));
        label->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 1901, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_3 = new QWidget(frame);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(290, 0, 1610, 41));
        labelLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        labelLayout_2->setObjectName(QStringLiteral("labelLayout_2"));
        labelLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(60, 0, 221, 48));
        labelLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        labelLayout->setObjectName(QStringLiteral("labelLayout"));
        labelLayout->setContentsMargins(0, 0, 0, 0);
        label_train_no = new QLabel(horizontalLayoutWidget_2);
        label_train_no->setObjectName(QStringLiteral("label_train_no"));
        label_train_no->setEnabled(true);
        QFont font2;
        font2.setPointSize(30);
        label_train_no->setFont(font2);
        label_train_no->setScaledContents(false);
        label_train_no->setAlignment(Qt::AlignCenter);

        labelLayout->addWidget(label_train_no);

        label_message_2 = new QLabel(centralwidget);
        label_message_2->setObjectName(QStringLiteral("label_message_2"));
        label_message_2->setGeometry(QRect(10, 340, 460, 20));
        QFont font3;
        font3.setPointSize(9);
        label_message_2->setFont(font3);
        label_message_2->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(238, 238, 236);"));
        label_message_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_message_2->setWordWrap(true);
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        frame_route->raise();
        label_message_2->raise();
        graphicsView->raise();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        label_message->setText(QApplication::translate("MainWindow", "Welcome to Indian Railways", 0));
        label_2->setText(QApplication::translate("MainWindow", "TOILET-1", 0));
        label_3->setText(QApplication::translate("MainWindow", "TOILET-2", 0));
        label_4->setText(QApplication::translate("MainWindow", "TOILET-3", 0));
        label_5->setText(QApplication::translate("MainWindow", "TOILET-4", 0));
        label_t1->setText(QString());
        label_t3->setText(QString());
        label_t2->setText(QString());
        label_t4->setText(QString());
        label->setText(QString());
        label_train_no->setText(QString());
        label_message_2->setText(QString());
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
