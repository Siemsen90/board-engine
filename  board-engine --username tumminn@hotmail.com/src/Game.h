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
        Game(std::string name);
        virtual std::vector< Move > legalMoves() = 0;
        virtual int userDefinedEvaluation()=0;
        virtual bool isTerminalState(int &state) = 0;
        virtual int evaluate();

        void executeMove(Move move);
        void initilizeBoard();
        void restart();
        std::string display();
        void undoMove();
        void changeDebug();
        void changeTurn();

        Board getCurrentBoard();
        int getTurn();
        int getTotalMoves();

        void setDifficulty(int diff);
        int getDifficulty();

        std::string getName();

        virtual ~Game();
    private:
        int totalMoves;
        bool debug;
        int turn;//Represents whose turn it is
        virtual std::string debugInfo() = 0;
        virtual void doExecuteMove(Move move, Board &currentBoard);
        virtual Board doInitilizeBoard();
        std::vector<Board> gameBoards;
        int difficulty;
        std::string name;
};

#endif // GAME_H
