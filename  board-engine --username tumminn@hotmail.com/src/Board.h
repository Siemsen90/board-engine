#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <map>
#include <utility>
#include "Move.h"

class Board
{
    public:
        Board(int n, int m);
        void addPieceToBoard(Piece piece, std::pair<int, int> move);
        void movePiece(Move move);
        virtual ~Board();

        Piece getPiece(std::pair<int, int> move);
        void removePieceFromBoard(std::pair<int,int> position);
        int getRowSize();
        int getColumnSize();

        std::vector< std::pair<int,int> > getPieceForPlayer(int player);
    protected:
    private:
        std::vector< std::vector< Piece > > board;
        int row;
        int column;
};

#endif // BOARD_H
