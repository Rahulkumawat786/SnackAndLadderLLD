#include <string>
using namespace std;
class Entity
{
    protected:
        int startPos;
        int endPos;

    public:
        Entity(int start, int end);

        int GetStart();
        int GetEnd();

        virtual string GetType() = 0;
};

class Snake : public Entity
{
    public:
        Snake(int start, int end);

        string GetType();
};

class Ladder : public Entity
{
    public:
        Ladder(int start, int end);

        string GetType();
};