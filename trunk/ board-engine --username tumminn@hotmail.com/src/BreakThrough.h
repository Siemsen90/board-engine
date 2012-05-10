#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H

#include "Game.h"
#include "Move.h"

class BreakThrough:public Game
{
    public:
        BreakThrough();

        std::vector< Move > legalMoves();
        void moveEffect(Move move);
        bool isUserDefinedTerminalState();
        std::string debugInfo();

        virtual ~BreakThrough();
    protected:
    private:
};

#endif // BREAKTHROUGH_H
