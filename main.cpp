#include <iostream>
using namespace std;

char space[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int row;
int column;
char token = 'x';
int inputEntered = 0;

void printSpace() {
    cout<<"    |    |     \n";
    cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"  | "<<space[0][2]<<"\n";
    cout<<"____|____|____ \n";
    cout<<"    |    |     \n";
    cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"  | "<<space[1][2]<<"\n";
    cout<<"____|____|____ \n";
    cout<<"    |    |     \n";
    cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"  | "<<space[2][2]<<"\n";
    cout<<"    |    |     \n";
}

bool checkDone() {
    int i;
    for(i=0; i < 3; i++){
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2] && space[i][0] != ' ') {
            return true;
        }
    }
    for(i=0; i < 3; i++){
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]  && space[0][i] != ' '){
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]  && space[0][0] != ' ') || (space[0][2] == space[1][1] && space[1][1] == space[2][0]  && space[0][2] != ' '))  {
        return true;
    }
    return false;
}

void gameLogic(string player1, string player2) {
    int digit;

    if (token == 'x') {
        cout<<player1<<" please enter: ";
        cin>>digit;
    }
    if (token == '0') {
        cout<<player2<<" please enter: ";
        cin>>digit;
    }

    inputEntered++;

    switch (digit) {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
        default:
            cout<<"Invalid entry"<<endl;
            break;
    }

    if(token == 'x' && space[row][column] != 'x' && space [row][column] != '0') {
        space[row][column] = 'x';
        token = '0';
        printSpace();
        if (!checkDone()) {
            gameLogic(player1, player2);
        } else {
            cout<<player1<<" won!";
        }
    } else if(token == '0' && space[row][column] != 'x' && space [row][column] != '0') {
        space[row][column] = '0';
        token = 'x';
        printSpace();
        if (!checkDone()) {
            gameLogic(player1, player2);
        } else {
            cout<<player2<<" won!";
        }
    } else {
        printSpace();
        if (inputEntered > 9) {
            cout<<"No empty space left!\n";
            cout<<"Match Draw";
            return;
        } else {
            cout<<"Space already filled!\n";
            inputEntered--;
            gameLogic(player1, player2);
        }
    }
}

void gameSetup() {
    string player1;
    string player2;

    cout<<"Enter the name of first player : ";
    getline(cin, player1);

    cout<<"Enter the name of Second player : ";
    getline(cin, player2);

    cout<<player1<<" is player 1 so, he/she will play first \n";
    cout<<player2<<" is player 2 so, he/she will play second \n";
    cout<<"\n";

    printSpace();
    gameLogic(player1, player2);
}

int main() {
    gameSetup();
    return 0;
}