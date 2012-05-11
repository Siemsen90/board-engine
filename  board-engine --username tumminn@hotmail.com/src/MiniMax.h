#ifndef MINIMAX_H
#define MINIMAX_H

#include "Game.h"
#include <climits>
#include "Move.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

class MiniMax
{
    public:
        MiniMax();
        virtual ~MiniMax();

        void run(Game *game);

    protected:
    private:
        int miniMax(int depth, Game *game);
};

#endif // MINIMAX_H
