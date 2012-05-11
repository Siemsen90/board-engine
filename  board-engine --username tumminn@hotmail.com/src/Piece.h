#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <cctype>

/** \brief A class for handeling the pieces.
 *
 * A class for each piece that the board class uses for pieces on the board.
 */
class Piece
{
public:
    /** \brief The piece constructor.
     *
     * Constructs a Piece with the given parameters
     * @param name string argument that has a default value "."
     * @param owner int argument that has a default value -1
     */
    Piece(std::string name = ".", int owner = -1)
        :m_name(name),m_owner(owner)
    {};
    virtual ~Piece();

    /** \brief Getter for the owner variable.
     *
     * Normal getter function which returns an int variable that denotes which player
     * owns the piece. 0 for player 1 and 1 for player 2.
     * @return: owner of the piece
     */
    int getOwner();

    /** \brief Getter for the name variable.
     *
     * Getter for the variable string name, turns it to lower case and returns it.
     * @return: name of piece, always a lower case.
     */
    std::string getName();

protected:
private:
    std::string m_name; /**< name of the piece, pawn, king etc. */
    int m_owner; /**< owner of the piece, 0 for player 1 and 1 for player 2. */
};

#endif // PIECE_H
