#include <iostream>
#include <vector>

using namespace std;

void play()
{
    String = allGames[2];
    allGames[0] = "Breakthrough"
    bool debug = false;
    cout << "Board-game \n" << "'list' to display the games list \n" << "'game n' instructs to play game number n \n"
    << " 'restart' restarts the game \n" << " 'legal' display legal moves \n"
    << "'make from_col from_row to_col to_row' \n" << "'retract' undos last move \n"
    << "'display' shows the board 0 is player 1(uppercase) and 1 is player 2(lowercase), last lines shows piece-count 1 first then 2\n"
    << "'evaluate' evaluates from the current board state \n" << "'go' computer makes a move\n"
    << "'level[random|easy|medium|hard]' choose dificulty level \n" << "'quit' quits the program \n";
    cout << "> ";
    string word;
    int number, counter = 0;
    int num[4];
    while ( cin >> word) {
        if ( word == "quit" ) {
            break;
        }
        else if ( word == "list" ) {
            for (i=0; i < allGames.size(); i++){
                cout << " " << allGames[i]<< " "<< i << "\n";
            }
        }
        else if ( word == "game" ) {
            while ( cin >> number) {
                if(number <= allGames.size()){
                    if(number==0)
                    {
                        BreakThrough breakThrough;
                    }
                }
                else break;
            }
        }
        else if (word == "restart"){
            //TODO restart the game
        }
        else if (word == "legal"){
            //TODO display legal moves
        }
        else if (word == "make"){
            while ( cin >> number) {
                if(counter < 4){
                    num[counter]=number;
                }
                for(int i = 0; i<4;++i){cout<<num[i];}
                //game.excecuteMove(num[0],num[1],num[2],num[3]);
                break;
            }
            //TODO get from_col, from_row
            //to_col & to_row and make the move
        }
        else if (word == "retract"){
            //TODO undo
        }
        else if (word == "display"){
            //TODO display the board
        }
        else if (word == "evaluate"){
            //TODO call evaluate
        }
        else if (word == "go"){
            //TODO computer generates a move
        }
        else if (word == "level"){
            string level;
            while (cin >> level)
            {
                if(level == "random"){
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
        cout << "> ";
    }
}

int main()
{
    play();
    cout << "Hello world!" << endl;
    return 0;
}
