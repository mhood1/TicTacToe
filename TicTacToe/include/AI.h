#ifndef AI_H
#define AI_H

#include "GameBoard.h"
#include "PlayerData.h"
#include <string>

using namespace std;

struct AiMove
{
    AiMove () {};
    AiMove(int Score) : score(Score) {}
    int x;
    int y;
    int score;
};

class AI
{
    public:
        AI();

        string getName();

        //char getSymbol();

        void setAttributes(string name, char aiSymbol, char humanSymbol);

        void performMove(GameBoard &board);

        AiMove getBestMove(GameBoard &board, char player);

    private:
        string _name;
        char _human; //symbol that human chose for the game
        char _ai; //AI's board symbol
};

#endif // AI_H
