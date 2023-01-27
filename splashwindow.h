#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H

#include <QMainWindow>

namespace Ui {
class SplashWindow;
}

class SplashWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SplashWindow(QWidget *parent = nullptr);
    ~SplashWindow();

private:
    Ui::SplashWindow *ui;
};

#endif // SPLASHWINDOW_H
