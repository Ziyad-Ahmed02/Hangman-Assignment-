#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);
}

game::~game()
{
    delete ui;
}

void game::HangmanDrawer()
{
    switch (HangmanCounter++) // why y & x axis are inverted
        {  //addLine(qreal x1, qreal y1, qreal x2, qreal y2, const QPen &pen = QPen())
    case 1: base = background-> addLine(-500,2,-350,2,green);
        break;
    case 2: stand = background-> addLine(-425,2,-425,-150,green);
        break;
    case 3: hanger = background-> addLine(-425,-150,-300,-150,yellow);
        break;
    case 4: rope = background-> addLine(-300,-150,-300,-125,red);
        break;
    case 5: face = background-> addEllipse(-315,-125,30,30,red);
        break;
    case 6: torso = background-> addLine(-300,-95,-300,-45,red);
        break;
    case 7: arm1 = background-> addLine(-300,-75,-280,-65,red); arm2 = background-> addLine(-300,-75,-320,-65,red);
        break;
    case 8: leg1 = background-> addLine(-300,-45,-280,-35,red); leg2 = background-> addLine(-300,-45,-320,-35,red);
        break;
    }
