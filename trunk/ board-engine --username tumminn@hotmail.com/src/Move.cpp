#include "Move.h"

Move::Move(int fromX,int fromY, int toX, int toY)
{
    from = std::pair<int,int>(fromX,fromY);
    to = std::pair<int,int>(toX,toY);
}

std::pair<int,int> Move::getFromPair() const
{
    return from;
}

std::pair<int,int> Move::getToPair() const
{
    return to;
}

std::ostream& operator<<(std::ostream& os, const Move& move)
{
    os  << "\t<"<< move.getFromPair().first << "," << move.getFromPair().second << ">";
    os  << " -> ";
    os  << "<"<< move.getToPair().first << "," << move.getToPair().second << ">";
    return os;
}

bool operator==(const Move& lhs, const Move& rhs)
{
    if(lhs.getFromPair() == rhs.getFromPair() && lhs.getToPair() == rhs.getToPair())
    {
        return true;
    }
    return false;
}
