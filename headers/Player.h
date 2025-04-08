#include<string>
using namespace std;
class Player
{
    private:
        int id;
        string name;
        int position;

    public:
        Player(int id_, string name_);

        int& Position();

        string GetPlayer();
};