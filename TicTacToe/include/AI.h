#ifndef AI_H
#define AI_H

#include "GameBoard.h"
#include "PlayerData.h"
#include <string>

using namespace std;

struct AiMove
{
    AiMove () {};
    AiMove(int Score) : score(Score) {};
    int x;
    int y;
    int score;
};


class AI
{
    public:
        AI();

        string getName();

        void setAttributes(string name, char symbol);

        AiMove getBestMove(GameBoard &board, int player);

    private:
        string _name;
        char _symbol;
        int _human;
        int _ai;
};

#endif // AI_H
