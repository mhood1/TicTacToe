#include <iostream>
#include <string>
#include "GameBoard.h"
#include "PlayerData.h"
#include "AI.h"

using namespace std;

void initSingleplayer(PlayerData &player1, AI &aiPlayer, GameBoard &board);
void initMultiplayer(PlayerData &player1, PlayerData &player2, GameBoard &board);
void simSingleplayer(PlayerData &player1, AI &aiPlayer, GameBoard &board);
void simMultiplayer(PlayerData &player1, PlayerData &player2, GameBoard &board);
bool rematch();

int main()
{
    cout << "**********************" << endl;
    cout << "WELCOME TO TIC-TAC-TOE" << endl;
    cout << "**********************\n" << endl;

    GameBoard board;
    PlayerData player1;

    char cpu;
    cout << "Do you want to play against the CPU? Enter Y or y if yes: ";
    cin >> cpu;

    if (cpu == 'Y' || cpu == 'y')
    {
        AI aiPlayer;
        initSingleplayer(player1, aiPlayer, board);
        simSingleplayer(player1, aiPlayer, board);
    }
    else
    {
        PlayerData player2;
        initMultiplayer(player1, player2, board);
        simMultiplayer(player1, player2, board);
    }

    return 0;
}

void initSingleplayer(PlayerData &player1, AI &aiPlayer, GameBoard &board)
{
    string p1Name;
    char p1Symbol;
    string aiName;
    char aiSymbol;

    cout << "Enter a name for player 1: ";
    cin >> p1Name;
    cout << "Choose a symbol for player 1: ";
    cin >> p1Symbol;
    player1.setAttributes(p1Name, p1Symbol);
    cout << endl;

    cout << "Enter a name for the CPU: ";
    cin >> aiName;
    cout << "Choose a symbol for player 2: ";
    cin >> aiSymbol;
    aiPlayer.setAttributes(aiName, aiSymbol);
    cout << endl << endl;

}

void initMultiplayer(PlayerData &player1, PlayerData &player2, GameBoard &board)
{
    string p1Name;
    char p1Symbol;
    string p2Name;
    char p2Symbol;

    cout << "Enter a name for player 1: ";
    cin >> p1Name;
    cout << "Choose a symbol for player 1: ";
    cin >> p1Symbol;
    player1.setAttributes(p1Name, p1Symbol);
    cout << endl;

    cout << "Enter a name for player 2: ";
    cin >> p2Name;
    cout << "Choose a symbol for player 2: ";
    cin >> p2Symbol;
    player2.setAttributes(p2Name, p2Symbol);
    cout << endl << endl;

}

//FIXME
void simSingleplayer(PlayerData &player1, AI &aiPlayer, GameBoard &board)
{
    bool win = false;

    while (true)
    {
        cout << player1.getName() << "'s Turn\n";
        board.setBoard(player1.getSymbol()); //player 1 goes first
        board.renderBoard();
        win = board.checkWin();
        if (win == true)
        {
            cout << "*** " << player1.getName() << " WINS!***" << endl;
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }

        //Check for tie
        if (board.checkTie() == true)
        {
            cout << "\nDRAW!\n";
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }

        cout << aiPlayer.getName() << "'s Turn\n";
        /** FIXME
        AiMove bestMove = player2.getBestMove(board, player2);
        board.setBoard(bestMove.x, bestMove.y, player2.getSymbol());
        **/
        board.renderBoard();
        win = board.checkWin();
        if (win == true)
        {
            cout << "*** " << aiPlayer.getName() << " WINS!***" << endl;
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }

        //Check for tie
        if (board.checkTie() == true)
        {
            cout << "\nDRAW!\n";
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }
    }

}

void simMultiplayer(PlayerData &player1, PlayerData &player2, GameBoard &board)
{
    bool win = false;

    while (true)
    {
        cout << player1.getName() << "'s Turn\n";
        board.setBoard(player1.getSymbol()); //player 1 goes first
        board.renderBoard();
        win = board.checkWin();
        if (win == true)
        {
            cout << "*** " << player1.getName() << " WINS!***" << endl;
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }

        //Check for tie
        if (board.checkTie() == true)
        {
            cout << "\nDRAW!\n";
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }

        cout << player2.getName() << "'s Turn\n";
        board.setBoard(player2.getSymbol()); //player 2's turn
        board.renderBoard();
        win = board.checkWin();
        if (win == true)
        {
            cout << "*** " << player2.getName() << " WINS!***" << endl;
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }

        //Check for tie
        if (board.checkTie() == true)
        {
            cout << "\nDRAW!\n";
            if (rematch() == true)
            {
                board.cleanBoard();
                continue;
            }
            else{
                break;
            }
        }
    }

}

bool rematch()
{
    char playAgain;
    cout << "\nPlay again? Enter Y for Yes or N for No: ";
    cin >> playAgain;
    while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
    {
        cout << "\nCould not understand that! Enter Y for Yes or N for No: ";
        cin >> playAgain;
    }
    if (playAgain == 'Y' || playAgain == 'y')
    {
        cout << "\nRestarting..." << endl << endl;
        return true;
    }
    else
    {
        cout << "\nTHANKS FOR PLAYING\n";
        return false;
    }
}
