#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QTimer>
#include <QListWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    void tcpConnect();
    void tcpDisconnect();
    void getData();
    void prefCor();
    void update();
    void selecIP(QListWidgetItem* item);
    void setIntervalo();
    void startTemp();
    void stopTemp();

private:
    Ui::MainWindow *ui;
    QTimer *clockWizard = new QTimer(this);
    int dados[20];
    QTcpSocket *socket;

    int r=0,g=0,b=0;
};

#endif // MAINWINDOW_H
