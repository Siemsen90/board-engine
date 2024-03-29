#include "Game.h"

Game::Game(std::string name)
{
    this->name = name;
    difficulty = 0;
    turn = 0;
    totalMoves = 0;
    debug = false;
}

void Game::changeTurn()
{
    if(turn == 0)
    {
        turn = 1;
    }
    else if(turn == 1)
    {
        turn = 0;
    }
}

int Game::evaluate()
{
    Board currentBoard = getCurrentBoard();
    int player1Pieces = currentBoard.getPieceForPlayer(0).size();
    int player2Pieces = currentBoard.getPieceForPlayer(1).size();

    return 0;
/*
    if(turn == 0)
    {
        return player2Pieces-player1Pieces;
    }

    return player2Pieces-player1Pieces;*/
}

void Game::initilizeBoard()
{
    gameBoards.push_back(doInitilizeBoard());
}

Board Game::doInitilizeBoard()
{
    Board startingBoard(8,8);

    Piece pawn0 = Piece("P",0);
    Piece pawn1 = Piece("p",1);

    for(int row = 0; row < startingBoard.getRowSize(); ++row)
    {
        for(int column = 0; column < startingBoard.getColumnSize(); ++column)
        {
            if(row == 0)
            {
                std::pair<int,int> place(row,column);
                startingBoard.addPieceToBoard(pawn1,place);
            }
            else if(row == startingBoard.getRowSize()-1)
            {
                std::pair<int,int> place(row,column);
                startingBoard.addPieceToBoard(pawn0,place);
            }
        }
    }
    return startingBoard;
}

void Game::executeMove(Move move)
{
    Board currentBoard = getCurrentBoard();

    doExecuteMove(move,currentBoard);

    gameBoards.push_back(currentBoard);
    ++totalMoves;
    changeTurn();
}

//You modify the currentBoard which will become the new board that you play off
void Game::doExecuteMove(Move move, Board &currentBoard)
{
    std::pair<int,int> from = move.getFromPair();
    std::pair<int,int> to = move.getToPair();

    if(from.first >= currentBoard.getRowSize() || from.second >= currentBoard.getColumnSize() || from.first < 0 || from.second < 0)
    {
        throw GameException("Out Of Bounds, for from piece\n");
    }
    else if(to.first >= currentBoard.getRowSize() || to.second >= currentBoard.getColumnSize() || to.first < 0 || to.second < 0)
    {
        throw GameException("Out Of Bounds, for to piece\n");
    }

    Piece fromPiece = currentBoard.getPiece(move.getFromPair());
    Piece toPiece = currentBoard.getPiece(move.getToPair());

    if(fromPiece.getOwner() != getTurn() || fromPiece.getOwner() == -1)
    {
        throw GameException("Trying to move opponent piece or non-existing piece\n");
    }
    if(toPiece.getOwner() == getTurn())
    {
        throw GameException("Trying to capture your own piece\n");
    }

    currentBoard.movePiece(move);//Basic implementation, no side effects
}

void Game::restart()
{
    Board originalBoard = gameBoards[0];

    gameBoards.clear();
    gameBoards.push_back(originalBoard);

    totalMoves = 0;
    turn = 0;
}

std::string Game::display()
{
    std::ostringstream gameInfo;

    Board currentBoard = getCurrentBoard();

    int player1Pieces = currentBoard.getPieceForPlayer(0).size();
    int player2Pieces = currentBoard.getPieceForPlayer(1).size();

    gameInfo << currentBoard;

    gameInfo << turn << '\n';
    gameInfo << player1Pieces;
    gameInfo << ' ';
    gameInfo << player2Pieces << '\n';

    if(debug)
    {
        gameInfo << debugInfo() << '\n';
    }

    return gameInfo.str();
}

void Game::undoMove()
{
    if(gameBoards.size() <= 1)
    {
        return;
    }

    gameBoards.pop_back();
    --totalMoves;
    changeTurn();
}

Board Game::getCurrentBoard()
{
    return gameBoards.back();
}

void Game::changeDebug()
{
    debug = !debug;
}

int Game::getTurn()
{
    return turn;
}

int Game::getTotalMoves()
{
    return totalMoves;
}

void Game::setDifficulty(int diff)
{
    difficulty = diff;
}

int Game::getDifficulty()
{
    return difficulty;
}

std::string Game::getName()
{
    return name;
}

Game::~Game()
{
}
