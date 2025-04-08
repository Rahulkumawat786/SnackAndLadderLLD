#include <memory>
#include <queue>
#include <vector>
#include <mutex>

#include "Board.h"
#include "Dice.h"
#include "Player.h"

using namespace std;
class Game
{
    private:
        enum GameStatus{
            NOT_STARTED = 0,
            RUNNING = 1,
            FINISHED = 2
        };
        shared_ptr<Board> board;
        shared_ptr<Dice> dice;
        queue<shared_ptr<Player>> players;
        GameStatus status;

        static shared_ptr<Game> gameInstance;
        static mutex mtx;

        Game(int boardDim, int diceMaxValue);

        bool MakeMove(shared_ptr<Player> player);
    public:
        Game(const Game&) = delete; //copy constructor

        Game& operator=(const Game&) = delete; // assignment operator

        static shared_ptr<Game> GetInstance(int boardDim, int diceMaxValue);

        void AddPlayer(string name);

        void AddPlayer(vector<string>& names);

        void AddEntity(shared_ptr<Entity> entity);

        //void RemoveEntity(shared_ptr<Entity> entity);

        void StartGame();

        shared_ptr<const Board> GetBoard() const;
};