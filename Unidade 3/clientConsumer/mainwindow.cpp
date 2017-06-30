#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){

  ui->setupUi(this);
  socket = new QTcpSocket(this);
  //tcpConnect();

  connect(ui->btnConectar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));

  connect(ui->btnDesconectar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));
  connect(ui->btnAtualizar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(update()));
  connect(ui->listIP,
          SIGNAL(itemDoubleClicked(QListWidgetItem*)),
          this,
          SLOT(selecIP(QListWidgetItem*)));

  connect(ui->btnIniciar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(startTemp())); //iniciar temporizador

   connect(ui->btnParar,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stopTemp())); //pausar temporizador

   connect(clockWizard,
          SIGNAL(timeout()),
          this,
          SLOT(getData())); //enviar dados quando o temporizador apitar

   connect(ui->hsliderIntervalo,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(setIntervalo()));

    ui->lblValorIntervalo->setNum(ui->hsliderIntervalo->value());
    ui->listIP->addItem("127.0.0.1");
}

void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  QDateTime datetime;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      socket->write("get 127.0.0.1\r\n");
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << "bytes disponíveis: " <<socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          datetime.fromString(list.at(0),Qt::ISODate);
          str = list.at(1);
          qDebug() << datetime << ": " << str;
        }
      }
    }
  }
}

void MainWindow::tcpConnect(){
  socket->connectToHost(ui->leditIP->text(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::tcpDisconnect(){
  socket->disconnectFromHost();
  if(socket->waitForConnected(3000)){
    qDebug() << "Could not Disconnect";
  }
  else{
    qDebug() << "Disconnected";
    stopTemp();
  }
}

void MainWindow::prefCor(){
    QColorDialog colordialog;
    colordialog.exec();

    r = colordialog.selectedColor().red();
    g = colordialog.selectedColor().green();
    b = colordialog.selectedColor().blue();
    ui->widgetPlotter->setFundo(r,g,b);
}

void MainWindow::update(){
    QString str = ui->leditIP->text();
    if(str != "") ui->listIP->addItem(str);
}

void MainWindow::startTemp(){
    if(socket->waitForConnected(0)) clockWizard->start(ui->hsliderIntervalo->value()*1000);
}

void MainWindow::stopTemp(){
    clockWizard->stop();
}

void MainWindow::setIntervalo(){
    clockWizard->setInterval(ui->hsliderIntervalo->value()*1000);
}

void MainWindow::selecIP(QListWidgetItem* item){
    ui->leditIP->setText(item->text());
}

MainWindow::~MainWindow()
{
    delete socket;
    delete clockWizard;
    delete ui;
}
