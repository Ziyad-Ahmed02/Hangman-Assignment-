#ifndef GAME_H
#define GAME_H
#include<QWidget>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>
#include <QGraphicsItem>
#include <QMainWindow>
#include<QMessageBox>
#include<QKeyEvent>
#include<cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QMainWindow
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();
void endgame(QString);
void HangmanDrawer();
void keyPressEvent(QKeyEvent *event)override;
void displayscore();
void setMode(QString);
private slots:


void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_pushButton_3_clicked();

void on_pushButton_4_clicked();
void reset();

void on_pushButton_5_clicked();

void on_pushButton_6_clicked();

private:
    Ui::game *ui;
    QString words[30]={"video","cat","name","banana","four","sale","red","exit","morning", "sky", "pen", "warm","mouse","lamp","orange","zero","head","bottle","friend","box","tiny","quick","jam","sun","light","duck","grey","smart","fan","glass" };
    QString ChosenWord,ChosenMode="oneWord";
    int HangmanCounter=0,score=0;
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
       QMessageBox msgBox;
};
#endif // GAME_H
