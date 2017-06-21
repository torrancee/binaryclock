#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QPalette>
#include <QLineEdit>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateTime();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    QVector<QLineEdit*> hoursElements;
    QVector<QLineEdit*> minutesElements;
    QVector<QLineEdit*> secondsElements;

    QPalette green, white;
    void setTime(QString time, QVector<QLineEdit *> &timeElements);
};

#endif // MAINWINDOW_H
