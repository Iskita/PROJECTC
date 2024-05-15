#ifndef INTRO_H
#define INTRO_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class intro : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    //constructor
    intro(QString name, QGraphicsItem* parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();


private:
    QGraphicsTextItem* text;
};



#endif // INTRO_H
