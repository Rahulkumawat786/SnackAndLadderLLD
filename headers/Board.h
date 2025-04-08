#include <unordered_map>
#include <memory>
#include "Entity.h"

using namespace std;
class Board
{
    private:
        int dimensions;
        unordered_map<int, shared_ptr<Entity>> entities;

    public:
        Board(int dimensions_);

        void PrintBoard();

        int GetTotalCells();

        void AddEntity(shared_ptr<Entity> entity);

        shared_ptr<Entity> GetEntity(int position);

        bool HasEntity(int position);
};