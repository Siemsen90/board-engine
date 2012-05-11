#include <iostream>
#include <vector>
#include <map>

#include "Game.h"
#include "BreakThrough.h"
#include "ShorterBreakThrough.h"
#include "Move.h"
#include "GameException.h"
#include "MiniMax.h"

using namespace std;

void play()
{
    //�tti game a� hafa nafn?
    Game *current = NULL;
    bool gameRunning = false;

    Game *breakthrough = new BreakThrough("Breakthrough");
    Game *shorterBreakthrough = new ShorterBreakThrough("ShorterBreakthrough");
    /*std::map<int,string> listGames;
    listGames[0] = "Breakthrough";
    listGames[1] = "ShorterBreakthrough";*/

    MiniMax search;

    vector<Game*> gameList;
    gameList.push_back(breakthrough);
    gameList.push_back(shorterBreakthrough);



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
        else if ( word == "list" )
        {
            for(int index = 0; index < static_cast<int>(gameList.size()); ++index)
            {
                cout << gameList[index]->getName() << '\n';
            }

        }
        else if ( word == "game" )
        {
            cin >> number;

            if(number < static_cast<int>(gameList.size()))
            {
                if(gameRunning)
                {
                    delete current;
                }
                current = gameList[number];
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
        }
        else if (word == "display")
        {
            cout << current->display();
        }
        else if (word == "evaluate")
        {
            cout << current->evaluate() << '\n';
        }
        else if (word == "go")
        {
            search.run(current);
            //TODO computer generates a move
        }
        else if (word == "level")
        {
            string level;
            cin >> level;

            if(level == "random")
            {
                current->setDifficulty(0);
            }
            else if (level == "easy")
            {
                current->setDifficulty(1);
            }
            else if (level == "medium")
            {
                current->setDifficulty(2);
            }
            else if (level == "hard")
            {
                current->setDifficulty(3);
            }

        }
        else if(word == "debug")
        {
            current->changeDebug();
        }
        cout << "\n> ";
    }
}

int main()
{
    play();
    return 0;
}
