#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"
#include "helpers.h"
int moves[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

void initialize_table(int table[TABLE_SIZE + 4][TABLE_SIZE + 4]) {
    //int table[TABLE_SIZE + 4][TABLE_SIZE + 4];

    for(int i = 0; i < TABLE_SIZE + 4; i++) {
        for (int j = 0; j < TABLE_SIZE + 4; j++) {
            table[i][j] = -1;
        }
    }
   for(int i = 2; i < TABLE_SIZE + 2; i++) {
        for (int j = 2; j < TABLE_SIZE + 2; j++) {
            table[i][j] = 0;
        }
    }
 
    table[2][2] = 1;
}

void table_print2(int table[TABLE_SIZE + 4][TABLE_SIZE + 4], char *descr, int severity) {
    if(severity <= LOG_LEVEL || *descr == '*') {
        printf("\n%s\n", descr);
        if(severity <= LOG_LEVEL) {
            printf("   x | y      ");
            for(int i = 0; i < TABLE_SIZE; i++) {
                printf("%*d", 4, i + 1);
            }
            
            printf("\n-----+-----------");
            for(int i = 0; i < TABLE_SIZE; i++) {
                printf("----");
            }
            printf("------+\n");

            for(int i = 0; i < TABLE_SIZE + 4; i++) {
                if(i > 1 && i < TABLE_SIZE + 2) {
                    printf("%*d |", 4, i - 1);
                } else {
                    printf("     |");
                }
                for (int j = 0; j < TABLE_SIZE + 4; j++) {
                    printf("%*d",4, table[i][j]);
                }
                printf(" |\n");
            }
            printf("-----+-----------");
            for(int i = 0; i < TABLE_SIZE; i++) {
                printf("----");
            }
            printf("------+\n");
        }
    }

}

void table_print(int table[TABLE_SIZE + 4][TABLE_SIZE + 4], char *descr) {
    table_print2(table, descr, 5);
}


int canMove(int table[TABLE_SIZE + 4][TABLE_SIZE + 4], int x, int y, int direction) {
    return !table[x + moves[direction][0]][y + moves[direction][1]];
}

void setMove(int table[TABLE_SIZE + 4][TABLE_SIZE + 4], int x, int y, int direction, int value) {
    table[x + moves[direction][0]][y + moves[direction][1]] = value;
}

int table_jump(int table[TABLE_SIZE + 4][TABLE_SIZE + 4], int x, int y, int move) {
    int lastMove = -1;
    char text[100];
    //, number[5], number2[5];
    sprintf(text, "%s %d","Potez: ", move);
    table_print2(table, text, 7);
    if(move >= MOVES) {
        return 1;
    }

    for(int i = 0; i < 8; i++) {
        if(canMove(table, x, y, i)) {
            setMove(table, x, y, i, move + 1);
            if(lastMove > -1) {
                setMove(table, x, y, lastMove, 0);
                sprintf(text, "%s %d %s %d, %s %d", "Brisanje:", move, "Direction:", i, "Last move,", lastMove);
                table_print2(table, text, 6);
            }
            lastMove = i;
            if(table_jump(table, x + moves[i][0], y + moves[i][1], move + 1)) {
                table_print(table, "Kraj:");
                return 1;
            }
            
        }
    }
    if(lastMove > -1) {
        setMove(table, x, y, lastMove, 0);
        sprintf(text, "%s %d", "Kraj poteza:", move);
        table_print2(table, text, 6);
    }
    return 0;
}
