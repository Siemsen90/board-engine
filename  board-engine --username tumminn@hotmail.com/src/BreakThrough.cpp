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
            Piece piece;
            std::pair<int,int> pos = myPieces[pieceIndex];
            std::pair<int,int> newPos = myPieces[pieceIndex];

            if(getTurn() == 0)
            {
                newPos.second = pos.second+1;
                piece = currentBoard.getPiece(newPos);
            }
            else
            {
                newPos.second = pos.second-1;
                piece = currentBoard.getPiece(newPos);
            }

            if(newPos.first >= currentBoard.getRowSize() || newPos.second >= currentBoard.getRowSize() || newPos.first < 0 || newPos.second < 0)
            {
                continue;
            }

            if(piece.getOwner() != getTurn())
            {
                Move move(pos.first,pos.second,newPos.first,newPos.second);
                moves.push_back(move);
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
