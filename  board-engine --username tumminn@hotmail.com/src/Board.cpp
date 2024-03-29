#include "Board.h"

Board::Board(int n, int m)
    :board(n)
{
    row = n;
    column = m;

    for(int i = 0; i < row; ++i)
    {
		board[i] = std::vector< Piece >(column);
    }
}

void Board::movePiece(Move move)
{
    board[move.getToPair().first][move.getToPair().second] = board[move.getFromPair().first][move.getFromPair().second];
    board[move.getFromPair().first][move.getFromPair().second] = Piece();
}

void Board::addPieceToBoard(Piece piece, std::pair<int, int> move)
{
    board[move.first][move.second] = piece;
}

int Board::getRowSize() const
{
    return row;
}

int Board::getColumnSize() const
{
    return column;
}

Piece Board::getPiece(std::pair<int, int> move) const
{
    return board[move.first][move.second];
}

std::vector< std::pair<int,int> > Board::getPieceForPlayer(int player)
{
    std::vector< std::pair<int,int> > pieces;

    for(int rowIndex = 0; rowIndex < row; ++rowIndex)
    {
        for(int columnIndex = 0; columnIndex < column; ++columnIndex)
        {
            Piece piece = board[rowIndex][columnIndex];
            if(player == piece.getOwner())
            {
                pieces.push_back(std::pair<int,int>(rowIndex,columnIndex));
            }
        }
    }

    return pieces;
}

void Board::removePieceFromBoard(std::pair<int,int> position)
{
    board[position.first][position.second] = Piece();
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    for(int row = 0; row < board.getRowSize(); ++row)
    {
        for(int column = 0; column < board.getColumnSize(); ++column)
        {
            std::pair<int,int> place(row,column);
            Piece piece = board.getPiece(place);
            os << piece.getName();
        }
        os << '\n';
    }
    return os;
}
