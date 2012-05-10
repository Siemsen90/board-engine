#include "BreakThrough.h"

BreakThrough::BreakThrough()
{
    //ctor
}

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

void BreakThrough::moveEffect(Move move)
{

}

bool BreakThrough::isUserDefinedTerminalState()
{
    return true;
}

std::string BreakThrough::debugInfo()
{
    return "No debug info";
}

BreakThrough::~BreakThrough()
{
    //dtor
}
