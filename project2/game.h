#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "HexBoard.h"
#include <QObject>
#include <QMouseEvent>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Game(QWidget* parent=NULL);

    //public methods

    void displayMainMenu();
    QString getWhosTurn();
    void setWhosTurn(QString player);
    void pickUpCard(Hex* card);
    void placeCard(Hex* hexToReplace);
    void nextPlayersTurn();
    void removeFromDeck(Hex* card,QString player);
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);

    // events
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);

    //public attributes
    QGraphicsScene* scene;

    HexBoard* hexBoard;
    //QString whosTurn;
    Hex* cardToPlace;
    QPointF originalPos;
    int numCardsPlaced;

public slots:
    void start();
    void restartGame();


private :
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void createNewCard(QString player);
    void createInitialCards();
    void drawCards();

    QList<Hex* > player1Cards;
    QList<Hex* > player2Cards;
    QString whosTurn_;
    QGraphicsTextItem* whosTurnText;
};

#endif // GAME_H
