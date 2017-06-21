#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(QTime::currentTime().toString());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    green.setColor(QPalette::Base, Qt::darkGreen);
    ui->h0->setPalette(green);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QTime currentTime =  QTime::currentTime();
    QString currentTimeString =  currentTime.toString();
    ui->label->setText(currentTimeString);
}
