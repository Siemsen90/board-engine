#ifndef SHORTERBREAKTHROUGH_H
#define SHORTERBREAKTHROUGH_H

#include "Game.h"

class ShorterBreakThrough: public Game
{
    public:
        ShorterBreakThrough(std::string name):Game::Game(name){};

        std::vector< Move > legalMoves();
        bool isUserDefinedTerminalState();
        std::string debugInfo();
        Board doInitilizeBoard();
        void doExecuteMove(Move move, Board &currentBoard);
        int userDefinedEvaluation();

        virtual ~ShorterBreakThrough();
    protected:
    private:
};

#endif // SHORTERBREAKTHROUGH_H
