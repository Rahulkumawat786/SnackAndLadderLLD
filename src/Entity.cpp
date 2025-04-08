#include "Entity.h"

Entity::Entity(int start, int end)
{
    startPos = start;
    endPos = end;
}

int Entity::GetStart()
{
    return startPos;
}

int Entity::GetEnd()
{
    return endPos;
}

Snake::Snake(int start, int end) : Entity(start, end){}

string Snake::GetType()
{
    return "Snake";
}

Ladder::Ladder(int start, int end) : Entity(start, end){}

string Ladder::GetType()
{
    return "Ladder";
}