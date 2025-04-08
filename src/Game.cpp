#include "Game.h"
#include "Board.h"
#include <iostream>


shared_ptr<Game> Game::gameInstance = nullptr;
mutex Game::mtx;
Game::Game(int boardDim, int diceMaxValue)
{
    board = make_shared<Board>(boardDim);
    dice = make_shared<Dice>(diceMaxValue);
    status = GameStatus::NOT_STARTED;
}

shared_ptr<Game> Game::GetInstance(int boardDim, int diceMaxValue)
{
    if(gameInstance == nullptr)
    {
        lock_guard<mutex> lock(mtx);
        if(gameInstance == nullptr)
        {
            gameInstance = make_shared<Game>(boardDim, diceMaxValue);
        }
    }

    return gameInstance;
}

void Game::AddPlayer(string name)
{
    if(status == GameStatus::RUNNING)
    {
        cout<<"Failed to add player\n";
    }
    int size = players.size();
    shared_ptr<Player> newPlayer = make_shared<Player>(size, name);

    players.push(newPlayer);
}

void Game::AddPlayer(vector<string>& players)
{
    if(status == GameStatus::RUNNING)
    {
        cout<<"Failed to add player\n";
    }
    for(string& player_name : players)
    {
        AddPlayer(player_name);
    }
}

void Game::AddEntity(shared_ptr<Entity> entity)
{
    if(entity == nullptr || status == GameStatus::RUNNING)
    {
        cout<<"Failed to add entity\n";
    }

    if(board != nullptr)
    {
        board->AddEntity(entity);
    }
    else
    {
        cout<<"Failed to add "<<entity->GetType()<<endl;
    }
}

// void Game::RemoveEntity(shared_ptr<Entity> entity)
// {
//     //need to implement in board
// }

void Game::StartGame()
{
    status = GameStatus::RUNNING;
    int rank = 0;
    while(players.size() > 1)
    {
        shared_ptr<Player> currPlayer = players.front();
        players.pop();

        bool isWon = MakeMove(currPlayer);

        if(isWon)
        {
            rank++;
            cout<<"Player: "<<currPlayer->GetPlayer()<<" is won: Rank = "<<rank<<endl;
        }
        else
        {
            players.push(currPlayer);
        }
    }

    if(!players.empty())
    {
        shared_ptr<Player> lastPlayer = players.front();
        players.pop();

        cout<<"Player: "<<lastPlayer->GetPlayer()<<" is lost\n";
    }

    status = GameStatus::FINISHED;
}

bool Game::MakeMove(shared_ptr<Player> player)
{
    if(player != nullptr)
    {
        int currentPosition = player->Position();

        int diceRoll = dice->Roll();

        int nextPosition = currentPosition + diceRoll;

        int totalCells = board->GetTotalCells();

        if(nextPosition > totalCells)
        {
            return false;
        }

        if(board->HasEntity(nextPosition) == true)
        {
            nextPosition = board->GetEntity(nextPosition)->GetEnd();
        }

        player->Position() = nextPosition;

        if(nextPosition == totalCells)
        {
            return true;
        }
    }

    return false;
}

shared_ptr<const Board> Game::GetBoard() const
{
    return board;
}
