#include "BreakThrough.h"

std::vector< Move > BreakThrough::legalMoves()
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

void BreakThrough::doExecuteMove(Move move, Board &currentBoard)
{
    std::pair<int,int> from = move.getFromPair();
    std::pair<int,int> to = move.getToPair();

    if(legalMoves().size() == 0)
    {
        throw GameException("There are no legal moves available\n");
    }

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

    if((move.getToPair().first == move.getFromPair().first && move.getToPair().second == move.getFromPair().second-1)
            || (move.getToPair().first == move.getFromPair().first && move.getToPair().second == move.getFromPair().second+1))
    {
        throw GameException("Can't move pieces horizontally\n");
    }

    if(fromPiece.getOwner() == 0)
    {
        if((move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second)
            || (move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second+1)
            || (move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second-1))
        {
            throw GameException("Can't go backwards\n");
        }
    }
    else if(fromPiece.getOwner() == 1)
    {

    }

    if((move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second)
                            || (move.getToPair().first == move.getFromPair().first-1 && move.getToPair().second == move.getFromPair().second))
    {
        if(toPiece.getOwner() != -1)
        {
            throw GameException("Trying to kill a piece without going diagonally\n");
        }
    }

    if(toPiece.getOwner() != -1)
    {
        if(fromPiece.getOwner() == 0)
        {
            if(!((move.getToPair().first == move.getFromPair().first-1 && move.getToPair().second == move.getFromPair().second+1)
                || (move.getToPair().first == move.getFromPair().first-1 && move.getToPair().second == move.getFromPair().second-1)))
            {
                throw GameException("Trying to kill a piece by going diaoganaly backwards\n");
            }
        }
        else if(fromPiece.getOwner() == 1)
        {
            if(!((move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second+1)
                || (move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second-1)))
            {
                throw GameException("Trying to kill a piece by going diaoganaly backwards\n");
            }
        }
    }

    currentBoard.movePiece(move);//Basic implementation, no side effects
}

std::string BreakThrough::debugInfo()
{
    std::ostringstream info;
    info << "No debug info";
    return  info.str();
}

int BreakThrough::userDefinedEvaluation()
{
    return evaluate();
}

bool BreakThrough::isTerminalState(int &state)
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
