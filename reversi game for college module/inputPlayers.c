//
// Created by Yulia Soldatkina on 18/05/2021.
//

#include <stdio.h>
#include <string.h>

#include "functions.h"


void newline_remover(char * string) {//[NAME_LEN_LIMIT+1]
    int i = 0;
    while (*(string+i) != '\0') {
        if (*(string+i) == '\n') {
            *(string+i) = '\0';
        }
        i++;
    }
}

void playerLetters () {
    p1.letter = 'B';
    p2.letter = 'W';
}


void inputPlayers () {
    char name_temp[NAME_LEN_LIMIT+1];
    char * name_temp_ptr;//[NAME_LEN_LIMIT+1]

    playerLetters();

    printf("Enter name of Player 1 (%s):\n", p1.letter == 'B' ? "Black" : "White");
    while (fgets(name_temp, NAME_LEN_LIMIT+1, stdin) == NULL) {
        //while(!scanf("%25s", name_temp) || strlen(name_temp) > NAME_LEN_LIMIT) {
        printf("Please try again.\n");
    }

    name_temp_ptr = (char *) &name_temp;
    newline_remover(name_temp_ptr);
    strcpy(p1.name, name_temp);

    printf("Enter name of Player 2 (%s):\n", p2.letter == 'W' ? "White" : "Black");
    while (fgets(name_temp, NAME_LEN_LIMIT+1, stdin) == NULL) {
        printf("Please try again.\n");
    }

    name_temp_ptr = (char *) &name_temp;
    newline_remover(name_temp_ptr);
    strcpy(p2.name, name_temp);
}

