#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game)
{
    srand(time(0));
    ChosenWord = words[rand() % 30];

    ui->setupUi(this);
    for (int i = 0; i < ChosenWord.size(); i++)
    {
        ui->label->setText(ui->label->text() + '-');
    }
    ui->setupUi(this);
    darkGreen=QPen(Qt::darkGreen);
    darkBlue=QPen(Qt::darkBlue);

    darkGreen.setWidth(7); darkBlue.setWidth(7);
}

game::~game()
{
    delete ui;
}

void game::HangmanDrawer()
{
    switch (HangmanCounter++) // why y & x axis are inverted
        {  //addLine(qreal x1, qreal y1, qreal x2, qreal y2, const QPen &pen = QPen())
    case 1: base = background-> addLine(-500,2,-350,2,darkGreen);
        break;
    case 2: stand = background-> addLine(-425,2,-425,-150,darkGreen);
        break;
    case 3: hanger = background-> addLine(-425,-150,-300,-150,darkGreen);
        break;
    case 4: rope = background-> addLine(-300,-150,-300,-125,darkGreen);
        break;
    case 5: face = background-> addEllipse(-315,-125,30,30,darkBlue);
        break;
    case 6: torso = background-> addLine(-300,-95,-300,-45,darkBlue);
        break;
    case 7: arm1 = background-> addLine(-300,-75,-280,-65,darkBlue); arm2 = background-> addLine(-300,-75,-320,-65,darkBlue);
        break;
    case 8: leg1 = background-> addLine(-300,-45,-280,-35,darkBlue); leg2 = background-> addLine(-300,-45,-320,-35,darkBlue);
        break;
    }
}
