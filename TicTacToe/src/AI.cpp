#include "AI.h"

#include <vector>
#include <limits>

AI::AI()
{
    //ctor
}

string AI::getName()
{
    return _name;
}

void AI::setAttributes(string name, char aiSymbol, char humanSymbol)
{
    _name = name;
    _ai = aiSymbol;
    _human = humanSymbol;
}

void AI::performMove(GameBoard &board)
{
    AiMove best = getBestMove(board, _ai);
    board.setBoard(best.x, best.y, _ai);
}

//In the end, this function does not physically change the board after recursing.
//It predicts the AI's best move based on theoretical AI and human placements
AiMove AI::getBestMove(GameBoard &board, char player)
{
    //Base case: check for end game
    /**This is a little confusing, but here is an explanation:
        If it is discovered that there was a win and it is
        for example the human's "turn", then that means the AI (from the previous recursive call)
        must have placed a piece that resulted in him winning, and thus a +10 on the AI's behalf
        Conversely, if it is the AI's turn and it is discovered that there is a win, then the
        human player must have placed a piece that resulted in him/her winning, and thus a -10 on the
        AI's behalf.
    **/
    if (board.checkWin() == true && player == _human)
    {
        return AiMove(10);
    }
    else if (board.checkWin() == true && player == _ai)
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

                board.setBoard(x, y, player);

                if (player == _ai)
                {
                    move.score = getBestMove(board, _human).score;
                }
                else
                {
                    move.score = getBestMove(board, _ai).score;
                }

                moves.push_back(move);
                board.setBoard(x, y, ' '); //Must make sure to reset the AI move to blank to avoid AI from changing the board
            }
        }
    }

    //Pick the best move for current player
    //For the AI player, any score greater than the smallest possible int will do
    //For the human player, any score less than the biggest possible int is appropriate
    int bestMove = 0;
    if (player == _ai)
    {
        int bestScore = numeric_limits<int>::min();
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
        int bestScore = numeric_limits<int>::max();
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

}
