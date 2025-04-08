#include <stdlib.h>
#include "Dice.h"

Dice::Dice(int maxLimit_)
{
    maxLimit = maxLimit_;
}

int Dice::Roll() const
{
    //return a random number from 1 to maxLimit
    return rand()%maxLimit + 1;
}