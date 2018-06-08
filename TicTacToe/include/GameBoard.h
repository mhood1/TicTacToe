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

        bool checkWin();

        bool checkTie();

    private:
        char _board[3][3] ={{' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '} };

};

#endif // GAMEBOARD_H
