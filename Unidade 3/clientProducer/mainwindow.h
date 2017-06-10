#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QString>

enum idioma{
    PT, EN
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //slots do servidor
    void putData();
    void tcpCon();
    void tcpDiscon();

    //slots do timer
    void setIntervalo();
    void startTemp();
    void stopTemp();

    //slots do idioma
    void portug();
    void english();

    //slots variados
    void clear();
    void Sair();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *temp = new QTimer(this); //temporizador
    idioma i = PT;
    QString dados;
    void atualizaDados(QString s);
};

#endif // MAINWINDOW_H

