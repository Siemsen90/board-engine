#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <cctype>

/** \brief A class that represents pieces on our game board.
 *
 * A class for each piece that the board contains, each belonging to a single player.
 */
class Piece
{
public:
    /** \brief The piece constructor.
     *
     * Constructs a Piece with the given parameters
     * @param inputName string argument that has a default value "."
     * @param inputOwner int argument that has a default value -1, indicating no ownership
     */
    Piece(std::string inputName = ".", int inputOwner = -1)
        : name(inputName), owner(inputOwner)
    {};

    /** \brief Getter for the owner variable.
     *
     * Normal getter function which returns an int variable that denotes which player
     * owns the piece. 0 for player 1 and 1 for player 2.
     * @return: owner of the piece
     */
    int getOwner();

    /** \brief Getter for the name variable.
     *
     * Getter for the variable string name.
     * @return: name of piece.
     */
    std::string getName();

protected:
private:
    std::string name; /**< name of the piece, pawn, king etc. */
    int owner; /**< owner of the piece, 0 for player 1 and 1 for player 2. */
};

bool operator==(const Piece& lhs,const Piece& rhs);

#endif // PIECE_H
