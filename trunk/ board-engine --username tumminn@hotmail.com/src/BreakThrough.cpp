#include "BreakThrough.h"

std::vector< Move > BreakThrough::legalMoves()
{
    std::vector<Move> moves;

    Board currentBoard = getCurrentBoard();
    std::vector< std::pair<int,int> > myPieces = currentBoard.getPieceForPlayer(getTurn());

    for(int pieceIndex = 0; pieceIndex < static_cast<int>(myPieces.size()) ; ++pieceIndex)
    {
        Piece piece = currentBoard.getPiece(myPieces[pieceIndex]);

        if(piece.getName() == "p")
        {
            std::pair<int,int> pos = myPieces[pieceIndex];
            std::pair<int,int> newPos = myPieces[pieceIndex];

            std::vector< std::pair<int,int> > availableMoves;

            availableMoves.push_back(std::pair<int,int> (pos.first-1,pos.second));
            availableMoves.push_back(std::pair<int,int>(pos.first,pos.second-1));
            availableMoves.push_back(std::pair<int,int>(pos.first-1,pos.second-1));
            availableMoves.push_back(std::pair<int,int>(pos.first+1,pos.second));
            availableMoves.push_back(std::pair<int,int>(pos.first,pos.second+1));
            availableMoves.push_back(std::pair<int,int>(pos.first+1,pos.second+1));
            availableMoves.push_back(std::pair<int,int>(pos.first-1,pos.second+1));
            availableMoves.push_back(std::pair<int,int>(pos.first+1,pos.second-1));

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
                    if((newPos.first == pos.first+1 && newPos.second == pos.second+1)
                            || (newPos.first == pos.first-1 && newPos.second == pos.second+1)
                            || (newPos.first == pos.first-1 && newPos.second == pos.second-1)
                            || (newPos.first == pos.first+1 && newPos.second == pos.second-1))
                    {
                        Move move(pos.first,pos.second,newPos.first,newPos.second);
                        moves.push_back(move);
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

bool BreakThrough::isUserDefinedTerminalState()
{
    Board currentBoard = getCurrentBoard();

    for(int multi = 0; multi <= 1; ++multi)
    {
        int player = multi;

        for(int column = 0; column < currentBoard.getColumnSize(); ++column)
        {
            std::pair<int,int> position(multi*(currentBoard.getRowSize()-1),column);
            Piece piece = currentBoard.getPiece(position);

            if(piece.getOwner() != -1 && piece.getOwner() == player)
            {
                return true;
            }
        }
    }

    return false;
}

void BreakThrough::doExecuteMove(Move move, Board &currentBoard)
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

    if((move.getToPair().first == move.getFromPair().first+1 && move.getToPair().second == move.getFromPair().second)
                            || (move.getToPair().first == move.getFromPair().first-1 && move.getToPair().second == move.getFromPair().second)
                            || (move.getToPair().first == move.getFromPair().first && move.getToPair().second == move.getFromPair().second-1)
                            || (move.getToPair().first == move.getFromPair().first && move.getToPair().second == move.getFromPair().second+1))
    {
        if(toPiece.getOwner() != -1)
        {
            throw GameException("Trying to kill a piece illegaly\n");
        }
    }

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

std::string BreakThrough::debugInfo()
{
    std::ostringstream info;
    info << "Terminal state: ";
    info << isTerminalState();
    return  info.str();
}

int BreakThrough::userDefinedEvaluation()
{
    return evaluate();
}

BreakThrough::~BreakThrough()
{
    //dtor
}