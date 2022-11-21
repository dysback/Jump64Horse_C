#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "table.h"
#include "helpers.h"

int main(int argc, char **argv) {
    struct timespec t0, t1;
    int table_size, moves;
    int init_pos_x = 2, init_pos_y = 2;
    if(argc > 4) {
        init_pos_x = atoi(argv[3]);
        init_pos_y = atoi(argv[4]);
    } else {
        init_pos_x = INIT_X;
        init_pos_y = INIT_Y;
    }

    if(argc > 2) {
        moves = atoi(argv[2]);
    } else {
        moves = MOVES;
    }

    if(argc > 1) {
        table_size = atoi(argv[1]);
    } else {
        table_size = TABLE_SIZE;
    }
    printf("Command usage:\n $Jump64Horse <table_size>, <number_of_moves>, <init_pos_x>, init_pos_y>\n");
    printf("Default values:\n");
    printf("  - table_size: %d\n", TABLE_SIZE);
    printf("  - number_of_moves: %d\n", MOVES);
    printf("  - init_pos_x: %d\n", INIT_X);
    printf("  - init_pos_y: %d\n", INIT_Y);
    printf("------------------------------\n");

    printf("Table %d x %d\n", table_size, table_size);
    printf("Number of moves: %d\n", moves);


    timespec_get(&t0, TIME_UTC);    

    Table table;
    initialize_table(&table, table_size, moves, init_pos_x, init_pos_y);
    //table_print2(table, "Start", 3);
    if(table_jump(&table, init_pos_x, init_pos_y, 1)) {
        table_print2(&table, "Solved", 3);
    } else {
        printf("No solution");
    }

    timespec_get(&t1, TIME_UTC);

    double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    printf("Elapsed time: %lf\n", diff);

    return 0;
}

