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

/** \brief The Game class is abstract class that handles the game logic
 *
 * A class that is made abstract for others to create games from this class by defining virtual functions.
 * Has a default implementation for creating a board and moving pieces.
 */
class Game
{
public:
    /** \brief The Game constructor.
     *
     * The constructor creates a new instance of a user specific games in derived classes
     * takes in a string name which is the name of the game
     * @param name string parameter containing the name of the game
     */
    Game(std::string name);

    /** \brief Finds all legal moves.
     *
     * A pure virtual function that is implemented in derived Game classes and finds all legal
     * moves after user specific rules.
     * @return vector of a Move class that has all the legal moves
     */
    virtual std::vector< Move > legalMoves() = 0;

    /** \brief User defined evaluation function for specific evaluation.
     *
     * A pure virtual function that is implemented in derived Game classes and is used if the user
     * wants to have more difficult game. MiniMax class uses this function if it is set to hard
     * @return integer variable denoting if it is a good move or not
     */
    virtual int userDefinedEvaluation()=0;
    /** \brief Denotes if it is a winning/terminal position.
     *
     * A pure virtual function that is implemented in derived Game classes and finds out if there is
     * a winning position or terminal position.
     * @param state integer refference parameter that is 0 or 1 if player 1 or 2 have won but -1 if there is no winner.
     * @return bool variable that determines whether it is a terminal state.
     */
    virtual bool isTerminalState(int &state) = 0;

    /** \brief simple evaluation function
     *
     * evaluate counts the pieces on the board and returns an integer number that gives you the difference of pices
     * from player1 and player2 if you are player1 and the other way around if you are player2.
     * @return integer variable containing the points you have.
     */
    virtual int evaluate();

    /** \brief executes a move on the board
     *
     * Gets current board and calls doExecuteMove which performs the move on the board. This function follows the NVI
     * pattern so it will always call the doExecuteMove function in the derived classes unless that is not overridden
     * then it will call the original doExecuteMove wich has some default behaviour.
     * @param move that is the move being performed
     */
    void executeMove(Move move);

    /** \brief Initializes the board.
     *
     * Calls doInitializeBoard function and pushes the result on the gameBoards vector.
     * This function is made to create the initial board.
     */
    void initilizeBoard();

    /** \brief Restarts the game.
     *
     * creates a new board and gets the original board, clears the board vector and pushes on the new board.
     * Starting with a fresh table.
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

    /** \brief turns debug mode on and off
     *
     * turns the bool variable debug to on/off , determine wheter the program should be in debug mode or not
     */
    void changeDebug();

    /** \brief changes players turns
     *
     * changes from player1 to player2 or wice versa.
     */
    void changeTurn();

    /** \brief getter for the current board
     *
     * gets the current board and returns it from the top of the boards vector
     */
    Board getCurrentBoard();

    /** \brief getter for the current turn
     *
     * gets the current turn and returns it
     */
    int getTurn();

    /** \brief getter for total moves
     *
     * gets the moves that have been played in a single game.
     */
    int getTotalMoves();

    /** \brief setter for dificulty
     *
     * sets the dificulty to random = 0, easy = 1, medium = 2, hard = 3
     * @param diff integer parameter used to denote dificulty
     */
    void setDifficulty(int diff);

    /** \brief getter for the dificulty level
     *
     * gets the dificulty that user has chosen. 0 = default value.
     */
    int getDifficulty();

    /** \brief getter for the name of the game
     *
     * gets the current name and returns it
     */
    std::string getName();

    virtual ~Game();
private:
    int totalMoves;/**< integer denoting how many moves have been played in a single game*/
    bool debug;/**< bool variable denotin if debug mode is on/off */
    int turn;/**< Represents whose turn it is */

    /** \brief For displaying debug info.
     *
     * Pure virtual function for displaying debug info, that user can define as they want.
     */
    virtual std::string debugInfo() = 0;

    /** \brief Executes the move on board
     *
     * virtual function for making a move it needs to be user defined since it is different how
     * pieces move in different games.
     * @param move includes the from coordinates and to coordinates
     * @param the current board being played on
     */
    virtual void doExecuteMove(Move move, Board &currentBoard);

    /** \brief initializes the board
     *
     * virtual function for initialising the board, needs to be virtual since it is different how
     * boards are initialized in different games.
     * @return Board that is initialized according to the game.
     */
    virtual Board doInitilizeBoard();
    std::vector<Board> gameBoards;/**< contains all the boards that have been in a game */
    int difficulty;/**< 0=random, 1=easy, 2=medium, 3=hard*/
    std::string name;/**< name of the game that is being played */
};

#endif // GAME_H
