#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H

#include "Game.h"
#include "Move.h"

class BreakThrough:public Game
{
    public:
        BreakThrough(std::string name):Game::Game(name){};

        std::vector< Move > legalMoves();
        std::string debugInfo();
        int userDefinedEvaluation();
        void doExecuteMove(Move move, Board &currentBoard);
        bool isTerminalState(int &state);
    protected:
    private:
};

#endif // BREAKTHROUGH_H
