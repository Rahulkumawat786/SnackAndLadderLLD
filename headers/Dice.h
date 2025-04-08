using namespace std;
class Dice
{
    private:
        int maxLimit;
    public:
        Dice(int maxLimit_);

        int Roll() const;
};