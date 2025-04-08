#include <iostream>
#include "Board.h"

Board::Board(int dimensions_)
{
    dimensions = dimensions_;
}

void Board::PrintBoard()
{
    //this will print the board
}

int Board::GetTotalCells()
{
    return dimensions*dimensions;
}

void Board::AddEntity(shared_ptr<Entity> entity)
{
    int startPosition = entity->GetStart();

    if(HasEntity(startPosition) == true)
    {
        cout<<"Invalid Entity\n";
        return;
    }

    entities[startPosition] = entity;
}

shared_ptr<Entity> Board::GetEntity(int position)
{
    if(HasEntity(position) == false)
    {
        cout<<"Not Found\n";
    }

    return entities[position];
}

bool Board::HasEntity(int position)
{
    if(entities.find(position) == entities.end())
    {
        return false;
    }
    return true;
}