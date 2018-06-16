#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard()
{
    renderBoard();
}

void GameBoard::renderBoard()
{
    //print column numbers
    cout << "  "; //two spaces before all numbers for alignment
    for (int y = 0; y < 3; y++)
    {
        cout << y+1 << "   "; //three spaces after each number for alignment
    }
    cout << endl; //ensures board will be on the next line


    for (int x = 0; x < 3; x++)
    {
        cout << x+1 << " "; //print row numbers whilst trying to align
        for (int y = 0; y < 3; y++)
        {
            cout << _board[x][y];
            //If on last column, no need to draw lines!
            if (y != 2)
            {
                cout << " | "; //spaces help with alignment
            }
        }
        cout << endl;
        //If on last row, not need to draw lines, OR, while not on the last row, draw lines!
        if (x != 2)
        {
            cout << "   -  -  -  " << endl; //three spaces before, 2 spaces b\t, and 2 spaces after help with alignment
        }
    }
    cout << endl;
}

void GameBoard::setBoard(char symbol)
{
    bool occupied = false;
    int x;
    int y;

    cout << "Choose a row number and a column number between 1 and 3..." << endl;
    cout << "Row: ";
    cin >> x;
    while (x < 1 || x > 3)
    {
        cout << "Your row bounds is invalid! Enter a new row: ";
        cin >> x;
    }

    cout << "Column: ";
    cin >> y;
    while (y < 1 || y > 3)
    {
        cout << "Your column bounds is invalid! Enter a new column: ";
        cin >> y;
    }

    if (_board[x-1][y-1] != ' ')
    {
        occupied = true;
    }

    while (occupied)
    {
        cout << "That space is occupied. Select a different row and column" << endl;
        cout << "New row number: ";
        cin >> x;

        cout << "New column number: ";
        cin >> y;

        if (_board[x-1][y-1] == ' ')
        {
            occupied = false;
        }
    }
    _board[x-1][y-1] = symbol;

    cout << endl;
}

//Used for AI
void GameBoard::setBoard(int x, int y, char symbol)
{
    _board[x][y] = symbol;
}

char GameBoard::getVal(int x, int y)
{
    return _board[x][y];
}

bool GameBoard::checkWin()
{
    bool allMatch;
    //Check each column
    for (int i = 0; i < 3; i++)
    {
        //assume there is the same symbol in each column
        allMatch = true;
        for (int j = 0; j < 2; j++)
        {
            //allMatch will be false if any of the spaces are empty or if the current space doesn't match the next space
            if ((_board[j][i] == ' ' || _board[j+1][i] == ' ') || (_board[j][i] != _board[j+1][i]))
            {
                allMatch = false;
            }
        }
        if (allMatch == true)
        {
            return true;
        }
    }

    //Check each row
    for (int i = 0; i < 3; i++)
    {
        //assume there is the same symbol in each row
        allMatch = true;
        for (int j = 0; j < 2; j++)
        {
            if ((_board[i][j] == ' ' || _board[i][j+1] == ' ') || (_board[i][j] != _board[i][j+1]))
            {
                allMatch = false;
            }
        }
        if (allMatch == true)
        {
            return true;
        }
    }

    //Check the two diagonals

    //Store each diagonal in separate arrays and iterate through those arrays
    char leftDiagonal[3];
    char rightDiagonal[3];

    //leftmost diagonal
    for (int i = 0; i < 3; i++)
    {
        leftDiagonal[i] = _board[i][i];
    }

    //rightmost diagonal
    //Starting from the bottom left and going to the top right, row # will decrease while column # increases
    for (int i = 2, j = 0; i >= 0 && j < 3; i--, j++)
    {
        rightDiagonal[j] = _board[i][j];
    }


    //assume diagonal equal
    allMatch = true;
    for (int i = 0; i < 2; i++)
    {

        if ((leftDiagonal[i] == ' ' || leftDiagonal[i+1] == ' ') || (leftDiagonal[i] != leftDiagonal[i+1]))
        {
            allMatch = false;
        }
    }
    if (allMatch == true)
    {
        return true;
    }

    //else we must check the rightmost diagonal
    //assume diagonal equal
    allMatch = true;
    for (int i = 0; i < 2; i++)
    {

        if ((rightDiagonal[i] == ' ' || rightDiagonal[i+1] == ' ') || (rightDiagonal[i] != rightDiagonal[i+1]))
        {
            allMatch = false;
        }
    }
    if (allMatch == true)
    {
        return true;
    }

    return false;
}

bool GameBoard::checkTie()
{
    //Check if board is completely filled. If not, then return false. If full, check value of checkWin()
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (_board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    if (checkWin() == false)
    {
        return true;
    }
    else{
        return false;
    }
}

void GameBoard::cleanBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            _board[i][j] = ' ';
        }
    }
    renderBoard();
}

bool GameBoard::notEmpty()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (_board[i][j] != ' ')
            {
                return true;
            }
        }
    }
    return false;

}
