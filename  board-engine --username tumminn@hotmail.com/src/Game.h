#ifndef GAME_H
#define GAME_H

#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <map>

#include "GameException.h"
#include "Board.h"
#include "Move.h"

class Game
{
    public:
        Game();
        virtual std::vector< Move > legalMoves() = 0;
        virtual int evaluate();
        virtual void executeMove(Move move);
        virtual void initilizeBoard();

        bool isTerminalState();
        void restart();
        std::string display();
        void undoMove();
        void changeDebug();
        void changeTurn();

        Board getCurrentBoard();
        int getTurn();

        virtual ~Game();
    protected:

    private:
        int totalMoves;
        bool debug;
        int turn;//Represents whose turn it is
        virtual void moveEffect(Move move) = 0;
        virtual bool isUserDefinedTerminalState() = 0;
        virtual std::string debugInfo() = 0;
        std::vector<Board> gameBoards;
};

#endif // GAME_H
