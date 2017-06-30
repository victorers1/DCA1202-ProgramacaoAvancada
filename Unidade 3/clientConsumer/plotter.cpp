#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QDebug>
#include <QMouseEvent>

using namespace std;

Plotter::Plotter(QWidget *parent) :
  QWidget(parent){
  fundo.setRgb(255,255,0);
}

void Plotter::timerEvent(QTimerEvent *e){
  repaint();
}

void Plotter::setFundo(int r, int g, int b){
  fundo.setRgb(r,g,b);
  repaint();
}

void Plotter::paintEvent(QPaintEvent *e){
    int x1, y1, x2, y2;
    // cria um objeto pintor
    QPainter p(this);
    // faz com que a linha seja desenhada com tracos suaves
    p.setRenderHint(QPainter::Antialiasing);
    // cria um objeto da classe caneta
    QPen pen;
    // cria um objeto da classe pincel
    QBrush brush;
    // define a cor da caneta
    pen.setColor(QColor(255,0,0));
    pen.setWidth(2);
    // informa ao painter qual a caneta a ser usada
    p.setPen(pen);
    // define a cor e o estilo do pincel
    brush.setColor(fundo);
    brush.setStyle(Qt::SolidPattern);
    // informa ao painter qual o pincel a ser
    // usado
    p.setBrush(brush);
}
