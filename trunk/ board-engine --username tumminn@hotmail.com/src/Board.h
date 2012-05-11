#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <map>
#include <utility>
#include "Move.h"

/** \brief The Board class
 *
 * The Board class has a vector of a vector of pieces and an integer value row and column.
 * That denotes the size of the board and which pieces are on it. The Game class calls the
 * Board class and initializes the board.
 */
class Board
{
public:
    /** \brief The Board constructor
      *
      * Creates the board of size n*m and initializes that with the default pieces
      * @param n integer value that denotes the rows on the board
      * @param m integer value that denotes the columns on the board
      */
    Board(int n, int m);

    /** \brief Moves a pice from one square to another
      *
      * takes an instance of a move and executes it on the board. Move has a pair of
      * x-y coordinates and movePiece finds the from coordinates on the board and if
      * there is a piece there it moves it to the to-coordinates. and replaces the old
      * old square with a default peace(empty square).
      * @param move has a pair of x-y coordinates from where the piece is and to put him
      */
    void movePiece(Move move);

    /** \brief add pice to a square on the board
      *
      * Takes in a piece and a place on the board. puts the piece on the board or in
      * the board vector in the place where the move is.
      * @param piece the piece that is to be placed on the board
      * @param move pair of integers that denotes the place on the board
      */
    void addPieceToBoard(Piece piece, std::pair<int, int> move);

    /** \brief removes a pice on a square on the board
      *
      * Finds a piece and a removes it from the board and replaces it with an empty piece.
      * @param move pair of integers that denotes the place on the board where the piece is being deleted
      */
    void removePieceFromBoard(std::pair<int,int> position);

    /** \brief gets a pice on a square on the board
      *
      * Finds a piece and a returns it from the board.
      * @param move pair of integers that denotes the place on the board where the piece is.
      * @return returns a pice
      */
    Piece getPiece(std::pair<int, int> move);

    /** \brief gets the row size
      *
      * returns the rows of the board
      * @return integer value which denotesthe rows of the board
      */
    int getRowSize();

    /** \brief gets the column size
      *
      * returns the columns of the board
      * @return integer value which denotesthe columns of the board
      */
    int getColumnSize();

    virtual ~Board();

    /** \brief finds all pieces of a player
      *
      * Loops through the board and finds all pieces for either player and puts there position
      * in a vector and returns it.
      * @param player integer parameter dentoing for which player to get the peaces.
      * @return vector of pairs that have in them the position for each peace.
      */
    std::vector< std::pair<int,int> > getPieceForPlayer(int player);
protected:
private:
    std::vector< std::vector< Piece > > board; /**< vector of vectors of pieces, has the size of row and column, it is the board */
    int row; /**< integer denoting how many rows there are on the board */
    int column; /**< integer denoting how many columns there are on the board */
};

#endif // BOARD_H
