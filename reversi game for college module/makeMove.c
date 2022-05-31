//
// Created by Yulia Soldatkina on 18/05/2021.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "functions.h"

int is_game_over = 0;



void takeMove() {
    //
    char a_move[3];

    validMoves();

    if (strlen(valid_moves) == 0) {
        printf("There are no valid moves available for you, %s.\n", the_board.nextplayer - 1 ? p1.name : p2.name);
        the_board.nextplayer = (the_board.nextplayer+1)%2;
        is_game_over += 1;
        if (is_game_over >= 2) {
            resultOfGame();
            return;
        }
        takeMove();
        return;
    }


    printf("%s's ", the_board.nextplayer - 1 ? p1.name : p2.name);
    printf("(%s's) move:\n", the_board.nextplayer - 1 ? "Black" : "White");
    //while (fgets(a_move, 3, stdin) == NULL) {
    while(!scanf("%2s", a_move)) {// || strlen(a_move) > 3) {
        printf("Please try again.\n");
    }

    if (a_move[0] == 'p') {
        if (strlen(valid_moves) != 0) {
            printf("You may not Pass if there are still valid moves available.\n");
            printf("Please enter another move.\n");
            takeMove();
            return;
        }

    }


    for (int i = 0; i < 60 || valid_moves[i] == '\0'; i+=2) {
        if (valid_moves[i] == a_move[0] && valid_moves[i+1] == a_move[1]) {
            enactMove(a_move);
            is_game_over = 0;
            printBoard();
            the_board.nextplayer = (the_board.nextplayer+1)%2;
            takeMove();
            return;
        }
    }
    printf("You have entered an invalid move, please try again.\n");
    takeMove();

}





char traverseBoard (int d, int l, int direction, int multiplier) {
    int modifier_dl[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
    int final_d = d+modifier_dl[0][direction]*multiplier;
    int final_l = l+modifier_dl[1][direction]*multiplier;
    //printf("t: %c%d in %d, %d steps, is %c%d\n", l+97, d+1, direction, multiplier, final_l+97, final_d+1);
    if (final_d >= 0 && final_d < BOARD_SIZE && final_l >= 0 && final_l < BOARD_SIZE) {
        return the_board.boardstate[final_d][final_l];
    }
    return '\n';
}

void editBoard (int d, int l, int direction, int multiplier, char value) {
    int modifier_dl[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
    int final_d = d+(modifier_dl[0][direction]*multiplier);
    int final_l = l+(modifier_dl[1][direction]*multiplier);
    //printf("e: %c%d in %d, %d steps, is %c%d\n", l+97, d+1, direction, multiplier, final_l+97, final_d+1);
    if (final_d >= 0 && final_d < BOARD_SIZE && final_l >= 0 && final_l < BOARD_SIZE) {
        if (the_board.boardstate[final_d][final_l] == getOpponent()) {
            the_board.scorep[(the_board.nextplayer+1)%2] -= 1;
        }
        if (the_board.boardstate[final_d][final_l] != getPlayer()) {
            the_board.scorep[the_board.nextplayer] += 1;
        }
        the_board.boardstate[final_d][final_l] = value;
        return;
    }
    printf("\nOh no, something's gone wrong!\n");
}



void enactMove(char a_move[3]) {
    char directions[9];
    //directions[8] = '\0';
    int i = 0;

    int l = a_move[0] - 97;
    int d = a_move[1] - 1 - '0';

    for (int j = 0; j < 8; ++j) {
        //if ((*direction_arr[j])(d, l, 0) == getOpponent()) {
        if (traverseBoard (d, l, j, 1) == getOpponent()) {
            directions[i++] = j + '0';
        }
    }

    directions[i] = '\0';


    for (int j = 0; directions[j] != '\0'; ++j) {
        i = 1;
        if (directions[j] - '0' > 7) {
            continue;
        }
        int direction = directions[j] - '0';
        while (traverseBoard(d, l, direction, i) == getOpponent()) {
            i++;
            //printf("%c", traverseBoard(d, l, direction, i-1));
        }
        if (traverseBoard(d, l, direction, i) != getPlayer()) {
            directions[j] = '9';
        }
        if (traverseBoard(d, l, direction, i) == getPlayer()) {
            for (int k = 0; k <= i; k++) {
                editBoard(d, l, direction, k, getPlayer());
            }
        }

    }


}

void resultOfGame() {
    int did_p1_win = the_board.scorep[0] > the_board.scorep[1];
    printf("Both players have no more valid moves.\n");
    printf("Player %s has won ", did_p1_win ? p1.name : p2.name);
    printf("with a score of %d:", did_p1_win ? the_board.scorep[0] : the_board.scorep[1]);
    printf("%d!\n", did_p1_win ? the_board.scorep[1] : the_board.scorep[0]);

    printBoard();

    FILE * fp;
    fp = fopen("othello-results.txt", "w+");

    time_t now = time(0);
    struct tm * tm_info;

    tm_info = localtime(&now);
    fprintf(fp, "A game was played at the following time: ");
    fprintf(fp,"%04d-%02d-%02d %02d:%02d:%02d",
            tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
            tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

    fprintf(fp, ", with %s winning %d:%d against %s.",
            did_p1_win ? p1.name : p2.name,
            did_p1_win ? the_board.scorep[0] : the_board.scorep[1],
            did_p1_win ? the_board.scorep[1] : the_board.scorep[0],
            did_p1_win ? p2.name : p1.name);


    fclose(fp);

}
