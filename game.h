#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QMainWindow
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();
    void HangmanDrawer();

private:
    Ui::game *ui;
    QGraphicsScene *background;
    QGraphicsEllipseItem *face;
    QGraphicsLineItem *base;
    QGraphicsLineItem *stand;
    QGraphicsLineItem *hanger;
    QGraphicsLineItem *rope;
    QGraphicsLineItem *torso;
    QGraphicsLineItem *arm1;
    QGraphicsLineItem *arm2;
    QGraphicsLineItem *leg1;
    QGraphicsLineItem *leg2;
    QPen green;
    QPen yellow;
    //QPen orange;
    QPen red;
    QPainter paint;
    int HangmanCounter=0;
};
#endif // GAME_H
