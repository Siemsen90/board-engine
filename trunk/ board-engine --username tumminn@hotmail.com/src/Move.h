#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <iostream>


class Move
{
    public:
        explicit Move(int fromX,int fromY, int toX, int toY);

        std::pair<int,int> getFromPair() const;
        std::pair<int,int> getToPair() const;

        virtual ~Move();
    protected:
    private:
        std::pair<int,int> from;
        std::pair<int,int> to;
};

std::ostream& operator<<(std::ostream& os, const Move& move);

#endif // MOVE_H
