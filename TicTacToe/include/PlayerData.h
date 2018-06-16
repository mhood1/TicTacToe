#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include "GameBoard.h"
#include <string>


using namespace std;


class PlayerData
{
    public:
        PlayerData();

        void setAttributes(string name, char symbol);

        string getName();

        char getSymbol();

        void printAttributes();

    private:
        string _name;
        char _symbol;

};

#endif // PLAYERDATA_H
