#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    displacement = new Displacement(this);
    acceleration = new Acceleration(this);
    speed = new Speed(this);

    connect(displacement,
            SIGNAL(changed(double)),
            speed,
            SLOT(onDisplacementChanged(double)));

    connect(speed,
            SIGNAL(changed(double)),
            acceleration,
            SLOT(onSpeedChanged(double)));

    ui->setupUi(this);

    connect(speed,
            SIGNAL(changed(double)),
            ui->lcdNumberSpeed,
            SLOT(display(double)));

    connect(acceleration,
            SIGNAL(changed(double)),
            ui->lcdNumberAcceleration,
            SLOT(display(double)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double v = ui->lineEdit->text().toDouble();
    displacement->set(v);
}
