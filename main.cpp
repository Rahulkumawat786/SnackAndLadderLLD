#include<iostream>
#include "headers/Game.h"

using namespace std;
int main()
{
    cout<<"****************************************************************************\n";
    cout<<"                    Welcome to the Snack Game v1.0.0                        \n";
    cout<<"****************************************************************************\n\n\n";

    cout<<"Setting up the games....";
    shared_ptr<Game> game = Game::GetInstance(6, 6);

    //adding special entity
    game->AddEntity(make_shared<Snake>(15, 8));
    game->AddEntity(make_shared<Snake>(23, 12));
    game->AddEntity(make_shared<Snake>(28, 19));

    game->AddEntity(make_shared<Ladder>(9, 18));
    game->AddEntity(make_shared<Ladder>(7, 13));
    game->AddEntity(make_shared<Ladder>(21, 31));
    //adding snakes and ladders
    
    game->AddPlayer({"Rahul", "Rohit"});

    game->StartGame();

    return 0;
}