#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(ui->btnConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpCon())); //conectar através do botão

    connect(ui->btnStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(temporizador())); //iniciar temporizador

    connect(ui->btnStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(temporizador())); //pausar temporizador

    connect(ui->actionSair,
            SIGNAL(triggered(bool)),
            this,
            SLOT(Sair())); //sair do programa através da ação do menu do topo

    connect(ui->actionConectar,
            SIGNAL(triggered(bool)),
            this,
            SLOT(tcpCon())); //conectar através da ação do menu do topo

    connect(ui->actionDesconectar,
            SIGNAL(triggered(bool)),
            this,
            SLOT(tcpDiscon())); //desconectar atravás da ação no menu do topo

    connect(temp,
            SIGNAL(timeout()),
            this,
            SLOT(putData())); //enviar dados quando o temporizador apitar


    ui->lblTiming->setNum(ui->hsliderTiming->value());
    //temp->start(ui->hsliderTiming->value()*500);
}

void MainWindow::putData(){
    QDateTime date;
    QString s;
    if(socket->state() == QAbstractSocket::ConnectedState){
        date = QDateTime::currentDateTime();
        s = "set" +
                date.toString(Qt::ISODate) +
                " " +
                QString::number((ui->hsliderMin->value() + qrand())%ui->hsliderMax->value()) + "\r\n";
    }
    qDebug() <<s;
    qDebug()<<socket->write(s.toStdString().c_str()) << " bytes writen";
    if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
    }
}

void setIntervalo();

void MainWindow::Sair(){
    //desconectar do servidor antes de fechar
    close();
}

void MainWindow::tcpCon(){
    socket->connectToHost(ui->leditEndereco->text(), 1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";

    } else {
        qDebug() <<"Not connected";
    }
}

void MainWindow::tcpDiscon(){

}

void MainWindow::setIntervalo(){
    temp->setInterval(ui->hsliderTiming->value()*1000);
}

void MainWindow::temporizador(){
    if(estado){
        temp->stop();
        estado = !estado;
    } else{
        temp->start(ui->hsliderTiming->value()*1000);
        estado = !estado;
    }
}

MainWindow::~MainWindow(){
    delete ui;
    delete socket;
}
