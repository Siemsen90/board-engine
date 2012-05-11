#ifndef MOVE_H
#define MOVE_H

#include <utility>
#include <iostream>

/** \brief A class for handeling all move functunality
 *
 * A class that handles the move functunality and takes in X-Y coordinates that denotes
 * where the piece was coming from and where to move it on the board.
 */
class Move
{
public:
    /** \brief The Move constructor
     *
     * Takes in X-Y coordinates from where the piece was coming and where to put it.
     * @param fromX int parameter denoting the x value where the piece was coming
     * @param fromY int parameter denoting the y value where the piece was coming
     * @param toX int parameter denoting the x value where the piece is going
     * @param toY int parameter denoting the y value where the piece is going
     */
    explicit Move(int fromX,int fromY, int toX, int toY);

    /** \brief Getter for a pair of integers fromX and toX
     *
     * Getter for a pair of integers having x-y coordinates from where the piece was coming from
     * @return a pair of integers that has both the x and y coordinates where the pice is coming from
     */
    std::pair<int,int> getFromPair() const;

    /** \brief Getter for a pair of integers toX and toY
     *
     * Getter for a pair of integers having x-y coordinates from where the piece is going
     * @return a pair of integers that has both the x and y coordinates where the pice is going
     */
    std::pair<int,int> getToPair() const;

    virtual ~Move();
protected:
private:
    std::pair<int,int> from;/**< pair of integers fromX and fromY */
    std::pair<int,int> to;/**< pair of integers toX and toY */
};

std::ostream& operator<<(std::ostream& os, const Move& move);

bool operator==(const Move& lhs,const Move& rhs);

#endif // MOVE_H
