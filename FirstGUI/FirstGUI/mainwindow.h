#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "speed.h"
#include "displacement.h"
#include "acceleration.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Displacement *displacement;
    Speed *speed;
    Acceleration *acceleration;
};

#endif // MAINWINDOW_H
