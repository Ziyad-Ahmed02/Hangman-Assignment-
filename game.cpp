#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game)
{
    srand(time(0));
    ChosenWord=words[rand()%30];

    ui->setupUi(this);
    for(int i=0;i<ChosenWord.size();i++)
    {
        ui->label->setText(ui->label->text()+'-');
    }
       background = new QGraphicsScene(this);
       ui->graphicsView->setScene(background);
       QPen green(Qt::green);
       QPen yellow(Qt::yellow);
       //QPen orange(Qt::orange);
       QPen red(Qt::red);
       green.setWidth(10);yellow.setWidth(10); red.setWidth(10);
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
}
void game::endgame(QString word)
{
    //int score = 0, hangMancounter=0, normalLives = 7, hardcoreLives = 60;

    if(ChosenWord == word)
    {
        if(ChosenMode == "oneWord")
        {
            msgBox.setText("Congratulations, you won!");
               msgBox.exec();
            exit(0);
        }
        else if(ChosenMode == "normal")
        {

            if(score < 10)
            {
                score++;
                displayscore();
                HangmanCounter=0;
                background->clear();
                srand(time(0));
                ChosenWord=words[rand()%30];
                 ui->label->setText("");
                for(int i=0;i<ChosenWord.size();i++)
                {
                    ui->label->setText(ui->label->text()+'-');
                }
            }
            else
            {
                msgBox.setText("Congratulations, you won!");
                   msgBox.exec();
                 exit(0);
            }
        }
        else if(ChosenMode == "hardcore")
        {
            score++;
            displayscore();
            ui->label->setText("");
           for(int i=0;i<ChosenWord.size();i++)
           {
               ui->label->setText(ui->label->text()+'-');
           }
            if(score == 20)
            {
                msgBox.setText("Congratulations, you won!");
                   msgBox.exec();
                 exit(0);
            }
        }
        else if(ChosenMode == "survival")
        {
            ui->label->setText("");
           for(int i=0;i<ChosenWord.size();i++)
           {
               ui->label->setText(ui->label->text()+'-');
           }
            score++;
        }
    }
    else if(HangmanCounter==9){
      {    msgBox.setText("you lost");
            msgBox.exec();
        exit(0);
}
    }

}
void game::keyPressEvent(QKeyEvent *event)
{
    int t=0;
    for(int i=0;i<ChosenWord.size();i++)
       { if(ChosenWord.at(i)==event->text())
           { ui->label->setText(ui->label->text().replace(i,1,event->text()));
             t=1;
              endgame(ui->label->text());
           }
    if((i==ChosenWord.size()-1)&&(t==0))
        HangmanDrawer();
    endgame(ui->label->text());
}

}
void game::displayscore()
{
    ui->label_2->setText("Score : " + QString::number(score));
}
void game::setMode(QString n)
{
ChosenMode=n;
}


void game::on_pushButton_2_clicked()
{
    ChosenMode="normal";
    reset();
}

void game::on_pushButton_3_clicked()
{
    ChosenMode="hardcore";
    reset();
}

void game::on_pushButton_4_clicked()
{
    ChosenMode="survival";
    reset();
}

void game::on_pushButton_clicked()
{
    ChosenMode="oneWord";
    reset();
}
void game::reset()
{
    score=0;
    HangmanCounter=0;
    background->clear();
    ChosenWord=words[rand()%30];
     ui->label->setText("");
    for(int i=0;i<ChosenWord.size();i++)
    {
        ui->label->setText(ui->label->text()+'-');
    }
}
void game::on_pushButton_5_clicked()
{
    reset();
}

void game::on_pushButton_6_clicked()
{
    msgBox.setText("Ziyad Ahmed\nMohammed Fikry\nMalek Elhosainy\nNadia Mahran");
       msgBox.exec();
}
