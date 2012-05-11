#include "MiniMax.h"

MiniMax::MiniMax()
{
    //ctor
}

MiniMax::~MiniMax()
{
    //dtor
}

void MiniMax::run(Game *game)
{
    std::vector<Move> moves = game->legalMoves();

    if(game->getTotalMoves() == 100)
    {
        std::cout << "Player to move ties \n";
        return;
    }


    if(moves.size() == 0)
    {
        std::cout << "No moves\n";
        return;
    }

     /* initialize random seed: */
    srand ( time(NULL) );

    if(game->getDifficulty() == 0)
    {
        game->executeMove(moves[rand()%moves.size()]);
        return;
    }

    int depth = 0;
    if(game->getDifficulty() == 1)
    {
        depth = 1;
    }
    else
    {
        depth = 3;
    }

    int bestValue = INT_MIN;
    Move bestMove(0,0,0,0);

    for(int index = 0; index < static_cast<int>(moves.size()); ++index)
    {
        game->executeMove(moves[index]);

        int checkValue = miniMax(depth-1,game);

        if(checkValue > bestValue)
        {
            bestValue = checkValue;
            bestMove = moves[index];
        }
        game->undoMove();
    }

    game->executeMove(bestMove);
    std::cout << "move " << bestMove << '\n';
}

int MiniMax::miniMax(int depth,Game *game)
{
    if(game->isTerminalState() || depth <= 0)
    {
        if(game->getDifficulty() != 3)
        {
            return game->evaluate();
        }
        return game->userDefinedEvaluation();
    }

    int bestValue = INT_MIN;

    std::vector<Move> moves = game->legalMoves();

    for(int index = 0; index < static_cast<int>(moves.size()); ++index)
    {
        game->executeMove(moves[index]);
        int value = -miniMax(depth-1,game);
        bestValue = std::max(value,bestValue);
        game->undoMove();
    }

    return bestValue;
}
