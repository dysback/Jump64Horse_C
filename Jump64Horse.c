#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "table.h"

void main () {
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);    
    
    Table *table = initialize_table();
    //table_print(table, "Početak");
    table_jump(table, 2, 2, 1);
    table_print2(table, "++:Kraj:++*", 3);

    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("Time taken %f\n",secs);
}

