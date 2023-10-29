#include <iostream>
using namespace std;

void gameboard(char *space){
    //cout << " | |" << endl;
    cout << space[0] << "|" << space[1] << "|" << space[2] << endl;
    cout << "_|_|_" << endl;
    cout << space[3] << "|" << space[4] << "|" << space[5] << endl;
    cout << "_|_|_" << endl;
    cout << space[6] << "|" << space[7] << "|" << space[8] << endl;
    cout << " | | " << endl;
}

void round_p1(char *space, char player1){
    int move;
    cout << "Enter ur move, 0-8 (x):";
    cin >> move;
    space[move] = player1;
    gameboard(space);
}

void round_p2(char *space, char player2){
    int move;
    cout << "Enter ur move, 0-8 (o):";
    cin >> move;
    space[move] = player2;
    gameboard(space);
}

bool checkwinner(char *space){
    if (space[0] != ' ' && (space[0] == space[1] && space[0] == space[3])){
        //cout << "Player " << space[0] << " wins!" << endl;
    }else if(space[3] != ' ' && (space[3] == space[4] && space[3] == space[5])){
        //cout << "Player " << space[3] << " wins!" << endl;
    }else if(space[6] != ' ' && (space[6] == space[7] && space[6] == space[8])){
        //cout << "Player " << space[6] << " wins!" << endl;
    }else if(space[0] != ' ' && (space[0] == space[3] && space[0] == space[6])){
        //cout << "Player " << space[0] << " wins!" << endl;
    }else if(space[1] != ' ' && (space[1] == space[4] && space[1] == space[7])){
        //cout << "Player " << space[1] << " wins!" << endl;
    }else if(space[2] != ' ' && (space[2] == space[5] && space[2] == space[8])){
        //cout << "Player " << space[2] << " wins!" << endl;
    }else if(space[0] != ' ' && (space[0] == space[4] && space[0] == space[8])){
        //cout << "Player " << space[0] << " wins!" << endl;
    }else if(space[2] != ' ' && (space[2] == space[4] && space[2] == space[6])){
        //cout << "Player " << space[2] << " wins!" << endl;
    }else{return false;}

    return true;
}

bool checktie(char *space){
    if(space[0]!= ' ' && space[1]!= ' ' && space[2]!= ' ' && space[3]!= ' ' && space[4]!= ' ' && space[5]!= ' ' && space[6]!= ' ' && space[7]!= ' ' && space[8] != ' '){
    }else{return false;}

    return true;
}

int main(){
    char space[9] = {' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' '};
    char player1 = 'x';
    char player2 = 'o';   

    gameboard(space);

    while(true){
        round_p1(space, player1);
        if (checkwinner(space)==true){
            cout << "Player 1 wins!" << endl;
            break;
        };
        if (checktie(space)==true){
            cout << "Draw!" << endl;
            break;
        };
        round_p2(space, player2);
        if (checkwinner(space)==true){
            cout << "Player 2 wins!" << endl;
            break;
        };
        if (checktie(space)==true){
            cout << "Draw!" << endl;
            break;
        };
    }
    //cout << "done" << endl; 
}

