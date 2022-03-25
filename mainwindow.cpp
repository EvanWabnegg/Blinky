#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <lgpio.h>
#include <QTimer>

const int OUT = 18;
int TSLEEP = 500 ;// milliseconds   don't forget to add the const next time

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
   ,m_timer(new QTimer(this))
{
    setupUi(this);



    int lFlags = 0; /* default line flags */

    m_led_handle = lgGpiochipOpen(0); /* get a handle to the GPIO */
    lgGpioClaimOutput(m_led_handle, lFlags, OUT, 0); /* initial level 0 */

    connect(m_timer, &QTimer::timeout, this, &MainWindow::on_timeout);

    frequencyLabel->setNum(frequencySlider->value());


}

MainWindow::~MainWindow()
{
    delete m_timer;
}

void MainWindow::on_startButton_clicked()
{
   // int frequency
    m_timer->start(TSLEEP);
}

void MainWindow::on_stopButton_clicked()
{
    m_timer->stop();
}

void MainWindow::on_frequencySlider_valueChanged(int value)
{


    TSLEEP = 1000/value;
    MainWindow::restart();

}

void MainWindow::restart()
{
    MainWindow::on_stopButton_clicked();
    MainWindow::on_startButton_clicked();
}
void MainWindow::on_timeout()
{
    led->toggle();
}
