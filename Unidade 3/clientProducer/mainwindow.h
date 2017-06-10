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
    /**
    * @brief putData envia dados aleatórios pelo socket criado com o IP digitado na caixa de texto
    */
    void putData();
    /**
    * @brief tcpCon estabelece conexão na porta 1234 do servidor cujo IP está na caixa de texto
    */
    void tcpCon();
    /**
     * @brief tcpDiscon desfaz a conexão ativa
     */
    void tcpDiscon();

    //slots do timer
    /**
     * @brief setIntervalo muda o intervalo entre as emissões do sinal timeout(), do temporizador
     */
    void setIntervalo();
    /**
     * @brief startTemp dá o comando para o temporizador funcionar
     */
    void startTemp();
    /**
     * @brief stopTemp dá o comando para o temporizador parar de funcionar
     */
    void stopTemp();

    //slots do idioma
    /**
     * @brief portug altera o idioma para português
     */
    void portug();
    /**
     * @brief english altera o idioma para inglês
     */
    void english();

    //slots variados
    /**
     * @brief clear apaga conteúdo da caixa com os dados enviados
     */
    void clear();
    /**
     * @brief Sair fecha o programa
     */
    void Sair();

private:
    /**
     * @brief ui ponteiro para a janela principal
     */
    Ui::MainWindow *ui;
    /**
     * @brief socket ponteiro para o
     */
    QTcpSocket *socket;
    /**
     * @brief temp temporizador
     */
    QTimer *temp = new QTimer(this); //temporizador
    /**
     * @brief i é o idioma do programa
     */
    idioma i = PT;
    /**
     * @brief dados guarda tudo o que será impresso na caixa de texto
     */
    QString dados;
    /**
     * @brief atualizaDados reescreve na caixa de texto o conteúdo da QString recebida
     * @param s valor a ser impresso na caixa de texto
     */
    void atualizaDados(QString s);
};

#endif // MAINWINDOW_H

