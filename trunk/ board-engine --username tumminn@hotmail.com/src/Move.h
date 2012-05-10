#ifndef MOVE_H
#define MOVE_H

#include <utility>


class Move
{
    public:
        explicit Move(int fromX,int fromY, int toX, int toY);

        std::pair<int,int> getFromPair();
        std::pair<int,int> getToPair();

        virtual ~Move();
    protected:
    private:
        std::pair<int,int> from;
        std::pair<int,int> to;
};

#endif // MOVE_H
