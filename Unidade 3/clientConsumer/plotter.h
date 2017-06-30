#ifndef PLOTTER_H
#define PLOTTER_H


#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QDebug>
#include <QMouseEvent>

class Plotter : public QWidget{
  Q_OBJECT
private:
  QColor fundo;

public:
  explicit Plotter(QWidget *parent = 0);
  void paintEvent(QPaintEvent *e);
  void timerEvent(QTimerEvent *e);
  void setFundo(int r, int g, int b);

signals:
  void posicao(int, int);


};

#endif // PLOTTER_H
