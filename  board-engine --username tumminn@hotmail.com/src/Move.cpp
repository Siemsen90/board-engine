#include "Move.h"

Move::Move(int fromX,int fromY, int toX, int toY)
{
    from = std::pair<int,int>(fromX,fromY);
    to = std::pair<int,int>(toX,toY);
}

std::pair<int,int> Move::getFromPair()
{
    return from;
}

std::pair<int,int> Move::getToPair()
{
    return to;
}


Move::~Move()
{
    //dtor
}
