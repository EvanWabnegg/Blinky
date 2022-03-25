#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"


class QTimer;   //example: if we use a a pointer or a refrence in a member declaration it is better to use forward declaration of the class

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_frequencySlider_valueChanged(int value);

    void on_timeout();

    void restart();

private:
    int m_led_handle;
    QTimer* m_timer;            //example
};

#endif // MAINWINDOW_H
