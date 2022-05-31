//
// Created by Yulia Soldatkina on 18/05/2021.
//

#include <stdio.h>
#include <string.h>

#include "functions.h"

//the_board

void defaultSetupBoard() {

    //the_board.boardstate = {};

    /*for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            the_board.boardstate[i][j] = 'W';
        }
    }*/

    the_board.boardstate[3][3] = 'W';
    the_board.boardstate[4][4] = 'W';
    the_board.boardstate[3][4] = 'B';
    the_board.boardstate[4][3] = 'B';

    //the_board.scorep[0] = 3;
    the_board.scorep[0] = 2;
    the_board.scorep[1] = 2;

    the_board.nextplayer = 0;
    playerLetters();

    printBoard();

}

void printBoard() {
    char whitespace[] = "        ";
    printf("%s", whitespace);
    printf("Score: %s (%s) %d:", p1.name, "Black", the_board.scorep[0]);
    printf("%d %s (%s)", the_board.scorep[1], p2.name, "White");
    //maybe strcat it. it's annoying me
    printf("\n  ");
    printf("%s", whitespace);
    for (int j = 0; j < BOARD_SIZE; ++j) {
        printf(" ---");
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%s", whitespace);
        printf("%d |", i+1);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf(" %c |", the_board.boardstate[i][j]);
        }
        printf("\n  ");
        printf("%s", whitespace);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf(" ---");
        }
        printf("\n");
    }
    printf("%s", whitespace);
    printf("   ");
    for (int j = 0; j < BOARD_SIZE; ++j) {
        printf(" %c  ", 97+j);
    }
    printf("\n");
}