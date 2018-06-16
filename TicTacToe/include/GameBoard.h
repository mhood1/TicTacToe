#ifndef GAMEBOARD_H
#define GAMEBOARD_H

using namespace std;

class GameBoard
{
    public:
        GameBoard();

        void cleanBoard();

        void renderBoard();

        void setBoard(char symbol);

        void setBoard(int x, int y, char symbol);

        char getVal(int x, int y);

        bool checkWin();

        bool checkTie();

        bool notEmpty();

    private:
        char _board[3][3] ={{' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '} };

};

#endif // GAMEBOARD_H
