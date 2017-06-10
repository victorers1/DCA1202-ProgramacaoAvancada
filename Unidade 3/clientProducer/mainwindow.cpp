#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QScrollBar>
#include <QString>

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

    connect(ui->actionPortugu_s,
            SIGNAL(triggered(bool)),
            this,
            SLOT(portug()));
    connect(ui->actionIngl_s,
            SIGNAL(triggered(bool)),
            this,
            SLOT(english()));
    connect(ui->actionLimpar_dados,
            SIGNAL(triggered(bool)),
            this,
            SLOT(clear()));

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

void MainWindow::portug(){
    i = PT;
    ui->btnConnect->setText("Conectar");
    ui->btnDisconnect->setText("Desconectar");
    ui->btnStart->setText("Começar");
    ui->btnStop->setText("Parar");
    ui->leditEndereco->setText("Endereço IP...");
    ui->actionConectar->setText("Conectar");
    ui->actionDesconectar->setText("Desconectar");
    ui->actionSair->setText("Sair");
    ui->label->setText("Intervalo:");
}

void MainWindow::english(){
    i = EN;
    ui->btnConnect->setText("Connect");
    ui->btnDisconnect->setText("Disconnect");
    ui->btnStart->setText("Start");
    ui->btnStop->setText("Stop");
    ui->leditEndereco->setText("IP Address...");
    ui->actionConectar->setText("Connect");
    ui->actionDesconectar->setText("Disconect");
    ui->actionSair->setText("Exit");
    ui->label->setText("Timing:");
}

void MainWindow::clear(){
   dados = "";
   atualizaDados(dados);
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

    atualizaDados(s);

    qDebug() <<s;
    qDebug()<<socket->write(s.toStdString().c_str()) << " bytes writen";
    if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
    }
}



void MainWindow::atualizaDados(QString s){
    dados.append(s); //atualiza string com dados
    ui->txtBoxDados->setText(dados); //imprime tudo novamente no textBrowser
    QScrollBar *qsb = ui->txtBoxDados->verticalScrollBar(); //declara um ponteiro para a barra de rolagem vertical do textBrowser
    qsb->setValue(qsb->maximum()); //define seu valor para: máximo que puder
}

void MainWindow::Sair(){
    tcpDiscon();
    close();
}

void MainWindow::tcpCon(){
    socket->connectToHost(ui->leditEndereco->text(), 1234);
    if(socket->waitForConnected(3000)){
        if(i == PT){
            atualizaDados("Conectado\n");
            qDebug() << "Conectado";
        } else {
            atualizaDados("Connected\n");
            qDebug() << "Connected";
        }

    } else {
        if(i == PT){
            atualizaDados("Não conectado\n");
            qDebug() << "Não conectado";
        } else {
            atualizaDados("Not connected\n");
            qDebug() <<"Not connected";
        }

    }
}

void MainWindow::tcpDiscon(){
    socket->disconnectFromHost();
    if(socket->waitForConnected(3000)){
        if(i == PT){
            atualizaDados("Conectado\n");
            qDebug() << "Conectado";
        } else {
            atualizaDados("Connected\n");
            qDebug() <<"Connected";
        }
    } else {
        if(i == PT){
            atualizaDados("Desconectado\n");
            qDebug() << "Desconectado";
        } else {
            atualizaDados("Disconnected\n");
            qDebug() <<"Disconnected";
        }
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
