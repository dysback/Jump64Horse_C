#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "table.h"

void main () {
    struct timespec t0, t1;

    timespec_get(&t0, TIME_UTC);

    int table[TABLE_SIZE + 4][TABLE_SIZE + 4];
    initialize_table(table);
    table_print2(table, "Početak", 3);
    table_jump(table, 2, 2, 1);
    table_print2(table, "++:Kraj:++*", 3);

    timespec_get(&t1, TIME_UTC);

    double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    printf("Elapsed time: %lf\n", diff);
}

