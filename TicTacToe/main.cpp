#include <iostream>
#include <string>
#include "GameBoard.h"
#include "PlayerData.h"

using namespace std;

void initGame(PlayerData &player1, PlayerData &player2, GameBoard &board);
void simGame(PlayerData &player1, PlayerData &player2, GameBoard &board);

int main()
{
    cout << "**********************" << endl;
    cout << "WELCOME TO TIC-TAC-TOE" << endl;
    cout << "**********************\n" << endl;
    GameBoard board;
    PlayerData player1;
    PlayerData player2;

    initGame(player1, player2, board);

    simGame(player1, player2, board);

    return 0;
}

void initGame(PlayerData &player1, PlayerData &player2, GameBoard &board)
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

void simGame(PlayerData &player1, PlayerData &player2, GameBoard &board)
{
    bool win = false;
    //bool tie = false;
    char playAgain;

   while (1)
    {
        cout << player1.getName() << "'s Turn\n";
        board.setBoard(player1.getSymbol()); //player 1 goes first
        board.renderBoard();
        win = board.checkWin();
        if (win == true)
        {
            cout << "*** " << player1.getName() << " WINS!***" << endl;
            cout << "Play again? Enter Y for Yes or N for No: ";
            cin >> playAgain;
            while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
            {
                cout << "\nCould not understand that! Enter Y for Yes or N for No: ";
                cin >> playAgain;
            }
            if (playAgain == 'Y' || playAgain == 'y')
            {
                cout << "\nRestarting..." << endl << endl;
                board.cleanBoard();
                continue;
            }
            else
            {
                cout << "\nTHANKS FOR PLAYING\n";
                break;
            }

        }

        //Check for tie
        if (board.checkTie() == true)
        {
            cout << "\nLooks like a Draw!\n";
            cout << "Play again? Enter Y for Yes or N for No: ";
            cin >> playAgain;
            while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
            {
                cout << "\nCould not understand that! Enter Y for Yes or N for No: ";
                cin >> playAgain;
            }
            if (playAgain == 'Y' || playAgain == 'y')
            {
                cout << "\nRestarting..." << endl << endl;
                board.cleanBoard();
                continue;
            }
            else
            {
                cout << "\nTHANKS FOR PLAYING\n";
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
            cout << "Play again? Enter Y for Yes or N for No: ";
            cin >> playAgain;
            while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
            {
                cout << "\nCould not understand that! Enter Y for Yes or N for No: ";
                cin >> playAgain;
            }
            if (playAgain == 'Y' || playAgain == 'y')
            {
                cout << "\nRestarting..." << endl << endl;
                board.cleanBoard();
                continue;
            }
            else
            {
                cout << "\nTHANKS FOR PLAYING\n";
                break;
            }
        }

        //Check for tie
        if (board.checkTie() == true)
        {
            cout << "\nLooks like a Draw!\n";
            cout << "Play again? Enter Y for Yes or N for No: ";
            cin >> playAgain;
            while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
            {
                cout << "\nCould not understand that! Enter Y for Yes or N for No: ";
                cin >> playAgain;
            }
            if (playAgain == 'Y' || playAgain == 'y')
            {
                cout << "\nRestarting..." << endl << endl;
                board.cleanBoard();
                continue;
            }
            else
            {
                cout << "\nTHANKS FOR PLAYING\n";
                break;
            }
        }
    }

}
