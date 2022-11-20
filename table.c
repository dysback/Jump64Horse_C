#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"
#include "helpers.h"
int moves[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

Table *initialize_table() {
    Table *table = (Table *)malloc(sizeof(Table));

    for(int i = 0; i < TABLE_SIZE + 4; i++) {
        for (int j = 0; j < TABLE_SIZE + 4; j++) {
            table->table[i][j] = -1;
        }
    }
   for(int i = 2; i < TABLE_SIZE + 2; i++) {
        for (int j = 2; j < TABLE_SIZE + 2; j++) {
            table->table[i][j] = 0;
        }
    }
 
    //table->move = 0;
    //table->posx = 2;
    //table->posy = 2;
    //table->direction = 0;
    table->table[2][2] = 1;
    return table;
}

void table_print2(Table *table, char *descr, int severity) {
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
                    printf("%*d",4, table->table[i][j]);
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

void table_print(Table *table, char *descr) {
    table_print2(table, descr, 5);
}


int canMove(Table *table, int x, int y, int direction) {
    return !table->table[x + moves[direction][0]][y + moves[direction][1]];
}

void setMove(Table *table, int x, int y, int direction, int value) {
    table->table[x + moves[direction][0]][y + moves[direction][1]] = value;
}

int table_jump(Table *table, int x, int y, int move) {
    int lastMove = -1;
    char text[100], number[5], number2[5];
    //strcpy(text, "Potez: ");
    sprintf(text, "%s %d","Potez: ", move);
    //strcat(text, number);
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
                //printf(" ");
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
        //printf(" ");
    }
    // logInt(table->move, 3);
    return 0;
}
