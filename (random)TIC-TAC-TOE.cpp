#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void drawBoard(char spaces[]){

    cout << "   |   |   \n";
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " \n"; 
    cout << "___|___|___\n";

    cout << "   |   |   \n";
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " \n"; 
    cout << "___|___|___\n";    

    cout << "   |   |   \n";
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " \n"; 
    cout << "   |   |   \n"; 
};
void compMarker(char spaces[]){

    srand(time(0));
    
    while(true){

    int randNum = rand()%9;
    if(spaces[randNum] == ' '){
        spaces[randNum] = 'O';
        break;
        }else{
            continue;
        }
    }
}
void playerMark(char spaces[]){
    int mark;
    while(true){
    cout << "Choose a place to mark X(1-9) :";
    cin >> mark;
    if(mark > 0 && mark < 10){
        if(spaces[mark-1] == ' '){
            spaces[mark-1] = 'X';
            break;
        }else{
            continue;
        }
    }else{
        cout << "Enter a valid number.\n";
        continue;
    }
}
}
bool result(char spaces[], bool running){

    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
            if(spaces[0] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
            if(spaces[3] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[6] != ' ' && spaces[7] == spaces[8] && spaces[6] == spaces[7]){
            if(spaces[6] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
            if(spaces[0] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
            if(spaces[1] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
            if(spaces[2] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[0] == spaces[8]){
            if(spaces[0] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
            if(spaces[2] == 'X'){
                drawBoard(spaces);
                cout << "YOU WIN!\n";
                running = false;
                //break;
            } else{
                cout << "YOU LOSE!\n";
                running = false;
                //break;
                }
        }

      
    return running;
}
bool tieChecker(char spaces[]){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    return true;
}

int main(){

    char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char comp = 'O';

    bool running = true;
    char playagain;

    while(running){
                
        playerMark(spaces);
        running = result(spaces, running);
        
        if(tieChecker(spaces) && running == true){
            drawBoard(spaces);
            cout << "IT'S A TIE!\n";  
            running = false;

        }else{

            if(running){
            compMarker(spaces);
            drawBoard(spaces);
            running = result(spaces, running);
            }
        }

    if(running == false){ 
     do{
            cout << "Would you like to play again? (y/n): ";
            cin >> playagain;
            switch(playagain){
                case 'y' : running = true; 
                           for(int i = 0; i < 9; i++){
                                spaces[i] = ' ';
                            }
                            break;
                case 'n' : 
                            break;
                default :  cout << "Please enter a valid response.\n";
                           continue;
            }
            break;
        }while(true);
    }
    
}
    return 0;
}
