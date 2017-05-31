#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool estado=false; //estado do temporizador (ligado ou desligado)


public slots:
    //slots do servidor
    void putData();
    void tcpCon();
    void tcpDiscon();

    //slots do timer
    void setIntervalo();
    void temporizador();

    //slots variados
    void Sair();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *temp = new QTimer(this); //temporizador
};

#endif // MAINWINDOW_H
