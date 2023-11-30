#include <iostream>
using namespace std;

int space[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
int row;
int column;
char token = 'x';

void gameSetup() {
    string player1;
    string player2;

    cout<<"Enter the name of first player : \n";
    getline(cin, player1);

    cout<<"Enter the name of Second player : \n";
    getline(cin, player2);

    cout<<player1<<" is player 1 so, he/she will play first \n";
    cout<<player2<<" is player 2 so, he/she will play second \n";
    cout<<"\n";

    cout<<"    |    |     \n";
    cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"  | "<<space[0][2]<<"\n";
    cout<<"____|____|____ \n";
    cout<<"    |    |     \n";
    cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"  | "<<space[2][2]<<"\n";
    cout<<"____|____|____ \n";
    cout<<"    |    |     \n";
    cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"  | "<<space[2][2]<<"\n";
    cout<<"    |    |     \n";
}

void gameLogic(string player1, string player2) {
    int digit;

    if (token == 'x') {
        cout<<player1<<"Please enter";
        cin>>digit;
    }
    if (token == '0') {
        cout<<player2<<"Please enter";
        cin>>digit;
    }

    switch (digit) {
        case 1:
            row = 0;
            column = 0;
        case 2:
            row = 0;
            column = 1;
        case 3:
            row = 0;
            column = 2;
        case 4:
            row = 1;
            column = 0;
        case 5:
            row = 1;
            column = 1;
        case 6:
            row = 1;
            column = 2;
        case 7:
            row = 2;
            column = 0;
        case 8:
            row = 2;
            column = 1;
        case 9:
            row = 2;
            column = 2;
        default:
            cout<<"Invalid entry"<<endl;
    }

    if(token == 'x' && space[row][column] != 'x' && space [row][column] != '0') {
        space[row][column] = 'x';
    }
}

int main() {
    gameSetup();
}