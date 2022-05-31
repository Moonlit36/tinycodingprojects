//
// Created by Yulia Soldatkina on 18/05/2021.
//

#include <stdio.h>
#include <string.h>

#include "functions.h"

void lineOfLogic(int mode_toggle, int i, int j, int * i_store, int * j_store, char this, char prev, int * toggle1, int * toggle2, char * valid_moves) {
    char store_string[3];
    char player = getPlayer();
    char opponent = getOpponent();

    int mod_i = mode_toggle ? 1 : 97;
    int mod_j = mode_toggle ? 97 : 1;

    //we check for availability of chains like [ ][o]+[p]
    // where o stands for opponent, + represents there being one or more such square
    // and p stands for player

    //this happens by switching on toggle1 whenever there's a chain [ ][o]
    // and storing the coordinates at which the empty space was
    if (this == opponent && j > 0 && prev == ' ') {
        *toggle1 = 1;
        *i_store = mode_toggle == 2 ? i-1 : (mode_toggle == 3 ? i+1 : i);
        //complicated stuff to handle the two diagonals
        *j_store = j-1;//j is the direction we're scanning in,
        // that is, the thing that changes every time we call the function
    }
    //this gets called when toggle1 is on and the chain is [o][p]
    // we add the stored coordinates as a valid move
    if (*toggle1 == 1 && prev == opponent && this == player) {
        if (mode_toggle) {
            sprintf(store_string,"%c%d", mod_j+*j_store, mod_i+*i_store);
        }
        else {
            sprintf(store_string,"%c%d", mod_i+*i_store, mod_j+*j_store);
        }
        strcat(valid_moves, store_string);
        *toggle1 = 0;
    }
    //this gets called when toggle1 is on and the next thing is not the opponent
    if (*toggle1 == 1 && this != opponent) {
        *toggle1 = 0;
        *i_store = -1;
        *j_store = -1;
    }

    //the opposite direction, we check for chains like [p][o]+[ ]
    // switch on toggle2 whenever there is [p][o]
    if (this == opponent && j > 0 && prev == player) {
        *toggle2 = 1;
        //l and d of valid move not known yet
    }
    //and then if toggle2 is on and we see [o][ ]
    // the coordinates of this empty space are a valid move
    if (*toggle2 == 1 && prev == opponent && this == ' ') {
        if (mode_toggle) {
            sprintf(store_string,"%c%d", mod_j+j, mod_i+i);
        }
        else {
            sprintf(store_string,"%c%d", mod_i+i, mod_j+j);
        }
        strcat(valid_moves, store_string);
        *toggle2 = 0;
    }
}



void validMoves() {

    //number of uncovered squares = 64
    //64-4(already covered)=60
    //120 for one move being two chars
    strcpy(valid_moves, "");

    char curr_scan[9];

    int toggle1 = 0;
    int toggle2 = 0;

    int l_stored = -1;
    int d_stored = -1;

    char prev = '\n';
    char this;

    //
    curr_scan[BOARD_SIZE] = '\0';

    int num_p1 = 0;
    int num_p2 = 0;

    //printf("%c player %c opponent\n", player, opponent);

    //horizontal scan
    for (int d = 0; d < BOARD_SIZE; ++d) {
        for (int l = 0; l < BOARD_SIZE; ++l) {
            curr_scan[l] = the_board.boardstate[d][l] == '\0' ? ' ' : the_board.boardstate[d][l];
            if (l > 0) {
                prev = curr_scan[l-1];
            }
            this = curr_scan[l];
            if (this == p1.letter) {num_p1++;}
            if (this == p2.letter) {num_p2++;}
            lineOfLogic(1, d, l, &d_stored, &l_stored, this, prev, &toggle1, &toggle2, valid_moves);
        }
        toggle1 = 0;
        toggle2 = 0;
        //printf("Line %d: :%s:\n", d+1, curr_scan);
    }
    //vertical scan
    for (int l = 0; l < BOARD_SIZE; ++l) {
        for (int d = 0; d < BOARD_SIZE; ++d) {
            curr_scan[d] = the_board.boardstate[d][l] == '\0' ? ' ' : the_board.boardstate[d][l];
            if (d > 0) {
                prev = curr_scan[d-1];
            }
            this = curr_scan[d];
            lineOfLogic(0, l, d, &l_stored, &d_stored, this, prev, &toggle1, &toggle2, valid_moves);
        }
        toggle1 = 0;
        toggle2 = 0;
        //printf("Line %c: :%s:\n", l+97, curr_scan);
    }
    //diagonal pi/4
    for (int k = 2; k <= 12; ++k) {
        int a = k < BOARD_SIZE ? k : BOARD_SIZE-1;
        int b = k < BOARD_SIZE ? 0 : k - a;
        int c = 0;
        while (a >= 0 && b < BOARD_SIZE && a+b <= k) {
            curr_scan[c] = the_board.boardstate[a][b] == '\0' ? ' ' : the_board.boardstate[a][b];
            if (c > 0) {
                prev = curr_scan[c-1];
            }
            this = curr_scan[c];
            lineOfLogic(3, a, b, &d_stored, &l_stored, this, prev, &toggle1, &toggle2, valid_moves);
            a--;
            b++;
            c++;
        }
        toggle1 = 0;
        toggle2 = 0;
        prev = '\n';
        curr_scan[c] = '\0';
        //printf("Line %d: :%s:\n", k, curr_scan);
    }
    //diagonal 3*pi/4
    for (int k = 2; k <= 12; ++k) {
        int a = k < BOARD_SIZE ? k : BOARD_SIZE-1;
        int b = k < BOARD_SIZE ? 0 : k - a;
        int c = 0;
        while (a >= 0 && b < BOARD_SIZE) {
            curr_scan[c] = the_board.boardstate[7-a][b] == '\0' ? ' ' : the_board.boardstate[7-a][b];
            if (c > 0) {
                prev = curr_scan[c-1];
            }
            this = curr_scan[c];
            lineOfLogic(2, 7-a, b, &d_stored, &l_stored, this, prev, &toggle1, &toggle2, valid_moves);
            a--;
            b++;
            c++;
        }
        toggle1 = 0;
        toggle2 = 0;
        prev = '\n';
        curr_scan[c] = '\0';
        //printf("Line %d: :%s:\n", k, curr_scan);
    }

    //printf("%s\n", valid_moves);

    the_board.scorep[0] = num_p1;
    the_board.scorep[1] = num_p2;

}