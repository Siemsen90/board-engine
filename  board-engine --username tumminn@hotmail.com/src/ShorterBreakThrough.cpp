#include "ShorterBreakThrough.h"

Board ShorterBreakThrough::doInitilizeBoard()
{
    Board startingBoard(4,3);

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

//This is shorter to demonstrate you can  use the legalMoves function to check for validity of move, however you give up control for finding what exactly you did wrong
void ShorterBreakThrough::doExecuteMove(Move move, Board &currentBoard)
{
    std::vector<Move> moves = legalMoves();
    bool legal = false;

    for(int index = 0; index < static_cast<int>(moves.size()); ++index)
    {
        if(moves[index] == move)
        {
            legal = true;
        }
    }

    if(!legal)
    {
        throw GameException("Illegal move\n");
    }

    currentBoard.movePiece(move);//Basic implementation, no side effects
}


std::vector< Move > ShorterBreakThrough::legalMoves()
{
    std::vector<Move> moves;

    Board currentBoard = getCurrentBoard();
    std::vector< std::pair<int,int> > myPieces = currentBoard.getPieceForPlayer(getTurn());

    for(int pieceIndex = 0; pieceIndex < static_cast<int>(myPieces.size()) ; ++pieceIndex)
    {
        Piece piece = currentBoard.getPiece(myPieces[pieceIndex]);

        if(piece.getName() == "p" || piece.getName() == "P")
        {
            std::pair<int,int> pos = myPieces[pieceIndex];
            std::pair<int,int> newPos = myPieces[pieceIndex];

            std::vector< std::pair<int,int> > availableMoves;

            if(piece.getOwner() == 0)
            {
                availableMoves.push_back(std::pair<int,int> (pos.first-1,pos.second));
                availableMoves.push_back(std::pair<int,int>(pos.first-1,pos.second-1));
                availableMoves.push_back(std::pair<int,int>(pos.first-1,pos.second+1));
            }
            else if(piece.getOwner() == 1)
            {
                availableMoves.push_back(std::pair<int,int>(pos.first+1,pos.second));
                availableMoves.push_back(std::pair<int,int>(pos.first+1,pos.second+1));
                availableMoves.push_back(std::pair<int,int>(pos.first+1,pos.second-1));
            }

            for(int index = 0; index < static_cast<int>(availableMoves.size()); ++index)
            {
                std::pair<int,int> newPos = availableMoves[index];

                if( newPos.first >= currentBoard.getRowSize() || newPos.second >= currentBoard.getColumnSize() || newPos.first < 0 || newPos.second < 0)
                {
                    continue;
                }

                Piece newPiece = currentBoard.getPiece(newPos);

                if(newPiece.getOwner() == piece.getOwner())
                {
                    continue;
                }

                if(newPiece.getOwner() != -1)
                {
                    if(piece.getOwner() == 0)
                    {
                        if((newPos.first == pos.first-1 && newPos.second == pos.second+1)
                            || (newPos.first == pos.first-1 && newPos.second == pos.second-1))
                        {
                            Move move(pos.first,pos.second,newPos.first,newPos.second);
                            moves.push_back(move);
                        }
                    }
                    else if(piece.getOwner() == 1)
                    {
                        if((newPos.first == pos.first+1 && newPos.second == pos.second+1)
                            || (newPos.first == pos.first+1 && newPos.second == pos.second-1))
                        {
                            Move move(pos.first,pos.second,newPos.first,newPos.second);
                            moves.push_back(move);
                        }
                    }

                }
                else if(newPiece.getOwner() == -1)
                {
                    Move move(pos.first,pos.second,newPos.first,newPos.second);
                    moves.push_back(move);
                }
            }
        }
    }

    return moves;
}

bool ShorterBreakThrough::isTerminalState(int &state)
{
    state = -1;
    if(getTotalMoves() == 100)
    {
        state = 2;//2 means draw
        return true;
    }

    Board currentBoard = getCurrentBoard();

    for(int multi = 0; multi <= 1; ++multi)
    {
        for(int column = 0; column < currentBoard.getColumnSize(); ++column)
        {
            std::pair<int,int> position(multi*(currentBoard.getRowSize()-1),column);
            Piece piece = currentBoard.getPiece(position);

            if(piece.getOwner() != -1)
            {
                if(piece.getOwner() == 0 && position.first == 0)
                {
                    state = 0;
                    return true;
                }
                else if(piece.getOwner() == 1 && position.first == currentBoard.getRowSize()-1)
                {
                    state = 1;
                    return true;
                }
            }
        }
    }

    return false;
}

std::string ShorterBreakThrough::debugInfo()
{
    std::ostringstream info;
    info << "No debug info";
    return  info.str();
}

int ShorterBreakThrough::userDefinedEvaluation()
{
    return evaluate();
}
