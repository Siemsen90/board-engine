#ifndef MINIMAX_H
#define MINIMAX_H

#include "Game.h"
#include <climits>
#include "Move.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

/** \brief This class encomposes the minimax algorithm.
 *
 * Minimax uses a game object and finds all the legal moves and executes the minimax algorithm on that to find the best move available.
 */
class MiniMax
{
    public:
        MiniMax() {};

        /** \brief Runs the minimax algorithm.
         *
         * Run uses a game object and finds all the legal moves, executes one and then runs the minimax algorithm on that to find the best move available.
         * @param *game pointer to a game object that minimax is to work on
         */
        void run(Game *game);

    protected:
    private:
        /** \brief The actual miniMax algorithm.
         *
         * The actual minimax algorithm that the run method calls.and takes in a variable denoting how deep the algorithm should go.
         * @param depth integer parameter denoting on what depth minimax should go
         * @param *game pointer to a game that minimax is performing on
         * @return integer value which has the best value.
         */
        int miniMax(int depth, Game *game);
};

#endif // MINIMAX_H
