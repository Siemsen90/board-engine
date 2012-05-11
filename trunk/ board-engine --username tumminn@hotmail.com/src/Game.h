#ifndef GAME_H
#define GAME_H

#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <map>

#include "GameException.h"
#include "Board.h"
#include "Move.h"

/** \brief The Game class is the central API which all other games inherit
 *
 * A class that is made abstract for others to create games from this class by defining virtual functions (both pure and not).
 * Has a default implementation for creating a board and moving pieces, as unrestricting as possible.
 */
class Game
{
public:
    /** \brief The Game constructor.
     *
     * The constructor creates a new instance of a user specific games in derived classes takes in a string name which is the name of the game
     * @param name string parameter containing the name of the game
     */
    Game(std::string name);

    /** \brief Finds all legal moves.
     *
     * A pure virtual function that is implemented in derived Game classes to find all legal
     * moves after the user specifies the rules and returns a vector of Move objects.
     * @return vector of a Move class that has all the legal moves
     */
    virtual std::vector< Move > legalMoves() = 0;

    /** \brief User defined evaluation function
     *
     * A pure virtual function that is implemented in derived Game classes and is used if the user wants to use their own evalution.
     * MiniMax class uses this function if it is set to hard
     * @return integer variable denoting the states value
     */
    virtual int userDefinedEvaluation()=0;
    /** \brief Denotes if it is a winning/terminal position.
     *
     * A pure virtual function that is implemented in derived Game classes and finds out the current state of the Game is terminal, e.g. draw or either player wins.
     * @param state integer refference parameter that is 0 or 1 if player 1 or 2 have won, 2 if there is a draw but -1 if there is no winner.
     * @return bool variable that determines whether it is a terminal state.
     */
    virtual bool isTerminalState(int &state) = 0;

    /** \brief simple evaluation function
     *
     * Retuns the difference between the number of opponents and your pieces.
     * @return integer variable containing the difference between your and opponents pieces.
     */
    virtual int evaluate();

    /** \brief executes a move on the board
     *
     * Gets current board and calls doExecuteMove which performs the move on the board.
     * This function follows the NVI pattern so it will always call the doExecuteMove function in the derived classes or its default implementation
     * @param move the move that is to be performed on the current board
     */
    void executeMove(Move move);

    /** \brief Initializes the board.
     *
     * Calls doInitializeBoard function and pushes the result of that onto the gameBoards vector.
     * This function is made to create the initial board but to disallow access to gameBoards vector.
     */
    void initilizeBoard();

    /** \brief Restarts the game.
     *
     * Creates a new board and gets the original board, clears the board vector and pushes on the new board.
     * Starting with a fresh board.
     */
    void restart();

    /** \brief Creates a string that displays the table.
     *
     * Loops through the board and puts all the pieces and empty squares in a string that can be displayed.
     * @return string that can be used to display the board.
     */
    std::string display();

    /** \brief Undoes the last move made.
     *
     * Pops the current board of the stack thus making the previous board the current board.
     */
    void undoMove();

    /** \brief Turns debug mode on/off
     *
     * turns the bool variable debug to on/off, which determines whether the program should be in debug mode or not
     */
    void changeDebug();

    /** \brief changes whose turn it is
     *
     * changes from player1 to player2 or vice versa.
     */
    void changeTurn();

    /** \brief getter for the current board
     *
     * gets the current board and returns it from the top of the boards vector, note that it is not a reference
     */
    Board getCurrentBoard();

    /** \brief getter for the current turn
     *
     * gets the current turn and returns it
     */
    int getTurn();

    /** \brief getter for total moves
     *
     * @return the total moves that have been played in the current game.
     */
    int getTotalMoves();

    /** \brief Setter for difficulty
     *
     * Sets the difficulty of the game, in our case it is: random = 0, easy = 1, medium = 2, hard = 3
     * @param diff integer parameter used to denote difficulty
     */
    void setDifficulty(int diff);

    /** \brief getter for the dificulty level
     *
     * gets the current difficulty of the game, which is random by default.
     */
    int getDifficulty();

    /** \brief getter for the name of the game
     *
     * gets the name of the game and returns it
     */
    std::string getName();

    virtual ~Game();
private:
    int totalMoves;/**< integer denoting how many moves have been played in the game*/
    bool debug;/**< bool variable denotin if debug mode is on/off */
    int turn;/**< Represents whose turn it is */

    /** \brief For displaying debug info.
     *
     * Pure virtual function for displaying debug info, that user can define as they want.
     */
    virtual std::string debugInfo() = 0;

    /** \brief Executes the move on board
     *
     * virtual function for executing moves, it contains the logic of how pieces move since it is different how pieces move in different games.
     * @param move includes the from coordinates and to coordinates for a square in the board
     * @param the current board being played on, note that it is reference and will be pushed on the gameBoards stack when you are done
     */
    virtual void doExecuteMove(Move move, Board &currentBoard);

    /** \brief initializes the board
     *
     * virtual function for initialising the board, needs to be virtual since it is different how boards are initialized but has a simple default implementation.
     * @return Board that is initialized according to the game.
     */
    virtual Board doInitilizeBoard();
    std::vector<Board> gameBoards;/**< contains all the boards that have been in a game */
    int difficulty;/**< 0=random, 1=easy, 2=medium, 3=hard*/
    std::string name;/**< name of the game that is being played */
};

#endif // GAME_H
