#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <iostream>

/** \brief A class for encapsulating movement
 *
 * A class that encapsulating movement to allow for easier use of our API.
 * It takes in two X-Y coordinates that indicates where the piece was and where to move it on the board.
 */
class Move
{
public:
    /** \brief The Move constructor
     *
     * Takes in X-Y coordinates from where the piece was and where to put it.
     * @param fromX int parameter denoting the x value where the piece was
     * @param fromY int parameter denoting the y value where the piece was
     * @param toX int parameter denoting the x value where the piece is going
     * @param toY int parameter denoting the y value where the piece is going
     */
    Move(int fromX,int fromY, int toX, int toY);

    /** \brief Getter for the pair of integers fromX and toX
     *
     * Getter for a pair of integers having x-y coordinates which says where the piece was
     * @return a pair of integers that has both the x and y coordinates where the pice was
     */
    std::pair<int,int> getFromPair() const;

    /** \brief Getter for a pair of integers toX and toY
     *
     * Getter for a pair of integers having x-y coordinates from where the piece is going
     * @return a pair of integers that has both the x and y coordinates where the pice is going
     */
    std::pair<int,int> getToPair() const;
protected:
private:
    std::pair<int,int> from;/**< pair of integers fromX and fromY */
    std::pair<int,int> to;/**< pair of integers toX and toY */
};

//A simple overloaded << to print out the class in the form of < fromX, fromY > <toX,toY>
std::ostream& operator<<(std::ostream& os, const Move& move);

//Just checks whether both pairs in move objects are the same
bool operator==(const Move& lhs,const Move& rhs);

#endif // MOVE_H
