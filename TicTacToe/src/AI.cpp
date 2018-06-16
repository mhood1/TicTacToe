#include "AI.h"

#include <vector>

AI::AI()
{
    //ctor
}

string AI::getName()
{
    return _name;
}

void AI::setAttributes(string name, char symbol)
{
    _name = name;
    _symbol = symbol;
}

AiMove AI::getBestMove(GameBoard &board, int player)
{
    //Base case: check for end game
    /*
    if (board.checkWin() == true && player._isAI == true)
    {
        return AiMove(10);
    }
    else if (board.checkWin() == true && player._isAI == false)
    {
        return AiMove(-10);
    }
    else if (board.checkTie() == true)
    {
        return AiMove(0);
    }

    vector<AiMove> moves;

    //Recursion + moves vector construction
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board.getVal(x, y) == ' ')
            {
                AiMove move;
                move.x = x;
                move.y = y;

                board.setBoard(x, y, player.getSymbol());

                //By default

                move.score = getBestMove(board, player).score;

                moves.push_back(move);
                board.setBoard(x, y, ' '); //Must make sure to reset the AI move to blank to avoid AI from changing the board
            }
        }
    }

    //Pick the best move for current player
    int bestMove = 0;
    if (player._isAI == true)
    {
        int bestScore = -10000000;
        for (unsigned int i = 0; i < moves.size(); i++)
        {
            if (moves[i].score > bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    else
    {
        int bestScore = 10000000;
        for (unsigned int i = 0; i < moves.size(); i++)
        {
            if (moves[i].score < bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    //Return the best move
    return moves[bestMove];
    */
}
