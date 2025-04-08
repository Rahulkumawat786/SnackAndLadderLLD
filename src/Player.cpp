#include "Player.h"

Player::Player(int id_, string name_) : id(id_), name(name), position(0){}

int& Player::Position()
{
    return position;
}

string Player::GetPlayer()
{
    return to_string(position) + ": " + name;
}