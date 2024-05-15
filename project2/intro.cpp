#include "intro.h"
#include <QGraphicsTextItem>
#include <QBrush>

intro::intro(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //DRAW THE TEXT
    text = new QGraphicsTextItem(name,this);

    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text ->setPos(xPos, yPos);

    // allow responding to hover event
    setAcceptHoverEvents(true);

}


void intro :: mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();

}

void intro::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // change color to cyan

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void intro::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

