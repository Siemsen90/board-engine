#include <iostream>
#include <vector>
#include <map>

#include "Game.h"
#include "BreakThrough.h"
#include "Move.h"
#include "GameException.h"

using namespace std;

void play()
{
    Game *current = NULL;
    bool gameRunning = false;

    Game *breakthrough = new BreakThrough();
    std::map<int,Game*> listGames;
    listGames[0] = breakthrough;

    cout << "Board-game \n" << "'list' to display the games list \n" << "'game n' instructs to play game number n \n"
    << " 'restart' restarts the game \n" << " 'legal' display legal moves \n"
    << "'make from_col from_row to_col to_row' \n" << "'retract' undos last move \n"
    << "'display' shows the board 0 is player 1(uppercase) and 1 is player 2(lowercase), last lines shows piece-count 1 first then 2\n"
    << "'evaluate' evaluates from the current board state \n" << "'go' computer makes a move\n"
    << "'level[random|easy|medium|hard]' choose dificulty level \n" << "'quit' quits the program \n";
    cout << "> ";
    string word;
    int number;
    while ( cin >> word) {
        if ( word == "quit" ) {
            break;
        }
        else if ( word == "list" ) {

            for(std::map<int,Game*>::iterator it = listGames.begin(); it != listGames.end(); ++it)
            {
                cout << it->first << '\n';
            }

        }
        else if ( word == "game" )
        {
            cin >> number;

            if(number < static_cast<int>(listGames.size()))
            {
                if(gameRunning)
                {
                    delete current;
                }
                current = listGames[number];
                current->initilizeBoard();
                gameRunning = true;
            }
        }
        else if (word == "restart")
        {
            if(gameRunning)
            {
                current->restart();
            }
            //TODO restart the game
        }
        else if (word == "legal")
        {
            vector<Move> moveList = current->legalMoves();

            for(int index = 0; index < static_cast<int>(moveList.size()); ++index)
            {
                cout << moveList[index] << '\n';
            }
        }
        else if (word == "make")
        {
            int fromX,fromY,toX,toY;
            cin >> fromX;
            cin >> fromY;
            cin >> toX;
            cin >> toY;

            //cout << fromX << '#' << fromY << '-' << toX << '#' << toY << '\n';

            try
            {
                Move move(fromX,fromY,toX,toY);
                current->executeMove(move);
            }
            catch(GameException ex)
            {
                cout << ex.getMessage();
            }
        }
        else if (word == "retract")
        {
            current->undoMove();
            //TODO undo
        }
        else if (word == "display")
        {
            cout << current->display();
            //TODO display the board
        }
        else if (word == "evaluate")
        {
            cout << current->evaluate() << '\n';
        }
        else if (word == "go")
        {
            //TODO computer generates a move
        }
        else if (word == "level")
        {
            string level;
            while (cin >> level)
            {
                if(level == "random")
                {
                    //TODO make level random
                }
                else if (word == "easy"){
                    //TODO easy
                }
                else if (word == "medium"){
                    //TODO medium
                }
                else if (word == "hard"){
                    //TODO hard
                }
            }
            //TODO get next string easy, med, etc...
        }
        else if(word == "debug")
        {
            current->changeDebug();
        }
        cout << "> ";
    }
}

int main()
{
    play();
    return 0;
}
