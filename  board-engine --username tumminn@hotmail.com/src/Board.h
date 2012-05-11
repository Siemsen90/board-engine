#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <map>
#include <utility>
#include "Move.h"

/** \brief The Board class
 *
 * The Board class has a vector of vectors of Pieces and an integer value row and column.
 * It denotes the size of the board and which pieces are on it.
 * The Game class calls the Board class methods to initialize the board.
 */
class Board
{
public:
    /** \brief The Board constructor
      *
      * Creates a board of size n*m and initializes it with the default pieces
      * @param n integer value that denotes the rows on the board
      * @param m integer value that denotes the columns on the board
      */
    Board(int n, int m);

    /** \brief Moves a pice from one square to another
      *
      * Takes in a Move object and uses it to uppdate the board using the from pair and to pair inside the Move object.
      * @param move has two pairs of x-y coordinates from where the piece is and where the piece should go
      */
    void movePiece(Move move);

    /** \brief Add pice to a square on the board
      *
      * Takes in a Piece object and a places it on the board corresponding to the Move object.
      * @param piece the piece that is to be placed on the board
      * @param move pair of integers that denotes the place on the board
      */
    void addPieceToBoard(Piece piece, std::pair<int, int> move);

    /** \brief removes a piece from the board
      *
      * Finds a piece and a removes it from the board and replaces it with an empty piece.
      * @param move pair of integers that denotes the place on the board where the piece is being deleted
      */
    void removePieceFromBoard(std::pair<int,int> position);

    /** \brief gets a pice on a particular square on the board
      *
      * Finds a piece and a returns it from the board using a pair of ints.
      * @param move pair of integers that denotes the place on the board where the piece is.
      * @return returns a pice
      */
    Piece getPiece(std::pair<int, int> move);

    /** \brief gets the row size
      *
      * returns the number of rows in the board
      * @return integer value which denotes how many rows the board has
      */
    int getRowSize();

    /** \brief gets the column size
      *
      * returns the number of columns in the board
      * @return integer value which denotes how many columns the board has
      */
    int getColumnSize();

    /** \brief finds all pieces for a given player
      *
      * Loops through the board and finds all pieces for either player and puts their position in a vector and returns it.
      * @param player integer parameter denoting for which player to get the pieces.
      * @return vector of pairs that have in them the position for each piece.
      */
    std::vector< std::pair<int,int> > getPieceForPlayer(int player);
protected:
private:
    std::vector< std::vector< Piece > > board; /**< vector of vectors of pieces,this represents the board */
    int row; /**< integer denoting how many rows there are on the board */
    int column; /**< integer denoting how many columns there are on the board */
};

#endif // BOARD_H
