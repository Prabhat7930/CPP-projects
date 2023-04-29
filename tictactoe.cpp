#include<bits/stdc++.h>

/**
function name: display
parameters:char tic[4][4]
return type:void
use: displays the tic-tac-toe matrix
**/
void display(char tic[4][4]) {
    for(int i=1;i<4;i++) {
        std::cout<<"\t\t\t\t\t\t      ";
        for(int j=1;j<4;j++) {
            std::cout<<" "<<tic[i][j];
        if(j<3)
            std::cout<<(" |");
    }
        std::cout<<("\n");
        if(i<3)
            std::cout<<"\t\t\t\t\t\t      ---+---+---\n";
    }
    std::cout<<"------------------------------------------------------------------------------------------------------------------------\n";
}

/**
function name: wincheck
parameters:char tic[4][4]
return type:int
use: core logic of the game which computes the winner or a draw
     total 8 ways to check the game
**/
int wincheck(char tic[4][4]) {

    for(int i=1;i<4;i++) {
        if(tic[i][1] != ' ' && tic[i][1] == tic[i][2] && tic[i][2] == tic[i][3]){       // column checking
            return tic[i][0] == 'X' ? 1:2;
        }
    }
    for(int j=1;j<4;j++) {
        if(tic[1][j] != ' ' && tic[1][j] == tic[2][j] && tic[2][j] == tic[3][j]){       // row checking
            return tic[1][j] == 'X' ? 1:2;
        }
    }
    if(tic[1][1] != ' ' && tic[1][1] == tic[2][2] && tic[2][2] == tic[3][3])            // diagonal checking
        return tic[1][1] == 'X'? 1:2;

    if(tic[1][3] != ' ' && tic[1][3] == tic[2][2] && tic[2][2] == tic[3][1])            // diagonal checking
        return tic[1][3] == 'X'? 1:2;

}

/**
function name: play
parameters:tic[4][4], userinput[2]
return type:void
use: takes the input from both players and display the result of the game at the end
**/
void play(char tic[4][4], int userinput[2]) {
    int move=1, winner;

    while(move<10) {
        std::cout<<"move:"<<move<<"\n";

        if(move%2==1)
            std::cout<<"1st player's move:\n";
        else
            std::cout<<"2nd player's move:\n";

        for(int i = 0; i<2; i++)
            std::cin>>userinput[i];

        if(tic[userinput[0]][userinput[1]] != ' '){
            std::cout<<"Move already made\n------------------------------------------------------------------------------------------------------------------------\n";
            continue;
        }

        if(move % 2 == 1)
            tic[userinput[0]][userinput[1]] = 'X';
        else
            tic[userinput[0]][userinput[1]] = 'O';

        display(tic);
        move++;
        
        if(move > 4) {
            winner = wincheck(tic);
            if(winner == 1){
                std::cout<<"Player 1 wins\n";
                return;
            }
            else if(winner == 2) {
                std::cout<<"Player 2 wins\n";
                return;
            }
            else if(move==10)
                std::cout<<"Game ends in a draw\n";
        }
    }
}

int main() {
    int choice = 0;
    char tic [4][4] = {{' ',' ',' ',' '},
                       {' ',' ',' ',' '},
                       {' ',' ',' ',' '},
                       {' ',' ',' ',' '}};

    int userinput[2] = {0,0};

    std::cout<<"                                                      TIC-TAC-TOE\n\n\n";
    display(tic);
    std::cout<<"Draw your moves as by giving matrix path x y\n";
    play(tic, userinput);
    
    return 0;
}

