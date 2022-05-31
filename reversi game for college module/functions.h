//
// Created by podso on 18/05/2021.
//

#ifndef FINALASSIGNMENT_FUNCTIONS_H
#define FINALASSIGNMENT_FUNCTIONS_H

#define NAME_LEN_LIMIT 25
#define BOARD_SIZE 8

struct Board {
    char boardstate[BOARD_SIZE][BOARD_SIZE];
    //char * boardstate;
    int scorep[2];
    int nextplayer;
};

struct Player {
    char name[NAME_LEN_LIMIT+1];
    char letter;
};

struct Player p1;
struct Player p2;
struct Board the_board;
char valid_moves[121];

void newline_remover(char * string);
void playerLetters ();
void inputPlayers();

char getPlayer();
char getOpponent();

void defaultSetupBoard();
void printBoard();

void validMoves();
void lineOfLogic(int mode_toggle, int i, int j, int * i_store, int * j_store, char this, char prev, int * toggle1, int * toggle2, char * valid_moves);



void takeMove();

void enactMove(char a_move[3]);

char traverseBoard (int d, int l, int direction, int multiplier);
void editBoard (int d, int l, int direction, int multiplier, char value);

void resultOfGame();

#endif //FINALASSIGNMENT_FUNCTIONS_H
