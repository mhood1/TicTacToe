#include "PlayerData.h"
#include <iostream>
#include <vector>

PlayerData::PlayerData()
{
    _name = "NULL";
    _symbol = '\0';

}

void PlayerData::setAttributes(string name, char symbol)
{
    _name = name;
    _symbol = symbol;
}

void PlayerData::printAttributes()
{
    cout << "Player name: " << _name << endl;
    cout << "Player symbol: " << _symbol << endl;
}

string PlayerData::getName()
{
    return _name;
}

char PlayerData::getSymbol()
{
    return _symbol;
}






