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
    white.setColor(QPalette::Base, Qt::white);

    hoursElements.push_back(ui->h0);
    hoursElements.push_back(ui->h1);
    hoursElements.push_back(ui->h2);
    hoursElements.push_back(ui->h3);
    hoursElements.push_back(ui->h4);
    hoursElements.push_back(ui->h5);

    minutesElements.push_back(ui->m0);
    minutesElements.push_back(ui->m1);
    minutesElements.push_back(ui->m2);
    minutesElements.push_back(ui->m3);
    minutesElements.push_back(ui->m4);
    minutesElements.push_back(ui->m5);

    secondsElements.push_back(ui->s0);
    secondsElements.push_back(ui->s1);
    secondsElements.push_back(ui->s2);
    secondsElements.push_back(ui->s3);
    secondsElements.push_back(ui->s4);
    secondsElements.push_back(ui->s5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    //digital clock
    QTime currentTime =  QTime::currentTime();
    QString currentTimeString =  currentTime.toString();
    ui->label->setText(currentTimeString);

    //binaryTime
    QString hours = currentTime.toString("hh");
    QString minutes = currentTime.toString("mm");
    QString seconds = currentTime.toString("ss");

    QString secBin = QString::number(seconds.toInt(), 2);
    setTime(secBin, secondsElements);

    QString minBin = QString::number(minutes.toInt(), 2);
    setTime(minBin, minutesElements);

    QString houBin = QString::number(hours.toInt(), 2);
    setTime(houBin, hoursElements);

}

void MainWindow::setTime(QString time, QVector<QLineEdit *> &timeElements)
{
      QString reverse = "";
      //reverse string
      for(int i = time.size() - 1; i >= 0; i--)
          reverse += time[i];

      //set green palette for "1" and white for "0" in labels
      for(int stringCounter = 0; stringCounter < reverse.size(); stringCounter++){
          if(reverse.at(stringCounter) == "1")
              timeElements[stringCounter]->setPalette(green);
          else
              timeElements[stringCounter]->setPalette(white);
      }

      //fell-in unused label whit white palette
      for(int i = reverse.size(); i < timeElements.size(); i++)
          timeElements[i]->setPalette(white);
}
