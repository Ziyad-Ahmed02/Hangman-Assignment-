
#include <iostream>
using namespace std;

void endgame()
{
    int score = 0, hangMancounter=0, normalLives = 7, hardcoreLives = 60;
    string inputWord, randWord;
    string gameMode, oneWord, normal, hardcore, survival;
    if(inputWord == randWord)
    {
        if(gameMode == oneWord)
        {
            cout<<"Congratulations, you won!";
        }
        else if(gameMode == normal)
        {
            score++;
            if(score < 10)
            {
                hangMancounter=0;
            }
            else
            {
                 cout<<"Congratulations, you won!";
            }
        }
        else if(gameMode == hardcore)
        {
            score++;
            if(score == 20)
            {
                 cout<<"Congratulations, you won!";
            }
        }
        else if(gameMode == survival)
        {
            score++;
        }
    }
    else{
        "You lost";

    }
}

int main()
{

}
