#include <stdio.h>
#include <string.h>


#include "functions.h"

#define NAME_LEN_LIMIT 25
#define BOARD_SIZE 8


char getPlayer() {
    return the_board.nextplayer - 1 ? p1.letter : p2.letter;
}

char getOpponent() {
    return the_board.nextplayer ? p1.letter : p2.letter;
}


int main() {
    //int scan_number = NAME_LEN_LIMIT;
    //char scan_str[] =

    printf("        ");
    printf("*** Welcome to Othello! ***\n");
    // printf("Hello, and welcome to Othello!\n");

    //defaultSetupBoard();
    //resultOfGame();
    //validMoves();



    inputPlayers();
    defaultSetupBoard();
    takeMove();


    return 0;
}
