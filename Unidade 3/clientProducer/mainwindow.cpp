#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(ui->btnConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpCon())); //conectar através do botão

    connect(ui->btnDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDiscon())); //desconectar através do botão

    connect(ui->btnStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(startTemp())); //iniciar temporizador

    connect(ui->btnStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopTemp())); //pausar temporizador

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

    connect(ui->hsliderTiming,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setIntervalo()));

    ui->lblTiming->setNum(ui->hsliderTiming->value());//faz lblTiming começar no valor correto
    ui->lcdMax->display(ui->hsliderMax->value()); //faz o lcdMax começar o valor correto
    //valor do hsliderMax é usado em uma divisão, logo, nunca pode assumir valor 0
}

void MainWindow::startTemp(){
    if(socket->waitForConnected(0)) temp->start(ui->hsliderTiming->value()*1000);
}
void MainWindow::stopTemp(){
    temp->stop();
}

void MainWindow::putData(){
    QDateTime date;
    QString s;
    if(socket->state() == QAbstractSocket::ConnectedState){
        int min = ui->hsliderMin->value();
        int max = ui->hsliderMax->value();

        if(max < min){
            int aux = min;
            min = max;
            max = aux;
        }
        date = QDateTime::currentDateTime();
        s = "set" +
                date.toString(Qt::ISODate) +
                " " +
                QString::number((qrand()%(1+max-min)) + min) + "\r\n";
        //gera valores aleatórios dentro do intervalo FECHADO de [valor no lcdMin, valor no lcdMax]
    }

    dados.append(s); //atualiza string com dados
    ui->txtBoxDados->setText(dados); //imprime tudo novamente no textBrowser
    QScrollBar *qsb = ui->txtBoxDados->verticalScrollBar(); //declara um ponteiro para a barra de rolagem vertical do textBrowser
    qsb->setValue(qsb->maximum()); //define seu valor para: máximo que puder


    qDebug() <<s;
    qDebug()<<socket->write(s.toStdString().c_str()) << " bytes writen";
    if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
    }
}

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
    socket->disconnectFromHost();
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";

    } else {
        qDebug() <<"Not connected";
    }
    temp->stop();
}

void MainWindow::setIntervalo(){
    temp->setInterval(ui->hsliderTiming->value()*1000);
}

MainWindow::~MainWindow(){
    delete ui;
    delete socket;
    delete temp;
}
