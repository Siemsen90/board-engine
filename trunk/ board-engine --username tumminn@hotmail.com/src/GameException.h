#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <stdexcept>
#include <string>
/** \brief A class for handeling exceptions being thrown
 *
 * A class that handles the exceptions thrown in the Game class and derived classes
 */
class GameException
{
public:

    /** \brief The piece constructor.
     *
     * Constructs an error message
     * @param msg string argument that is an error message that follows the exception
     */
    GameException(const std::string& msg);
    ~GameException( ) {}

    /** \brief Getter for the error message
     *
     * Normal getter function which returns a string variable.
     * @return: error message
     */
    std::string getMessage( ) const;
private:
    std::string message;/**< error message for the exception being thrown */
};

#endif // GAMEEXCEPTION_H
