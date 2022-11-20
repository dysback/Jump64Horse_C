#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "table.h"

void main () {
    //struct timeb start, end;
    float secs = 0;

    //ftime(&start);    
    struct timespec t0, t1;

    if(timespec_get(&t0, TIME_UTC) != TIME_UTC) {
        printf("Error in calling timespec_get\n");
        exit(EXIT_FAILURE);
    }
    int table[TABLE_SIZE + 4][TABLE_SIZE + 4];
    initialize_table(table);
    table_print2(table, "Početak", 3);
    table_jump(table, 2, 2, 1);
    table_print2(table, "++:Kraj:++*", 3);

    if(timespec_get(&t1, TIME_UTC) != TIME_UTC) {
       printf("Error in calling timespec_get\n");
       exit(EXIT_FAILURE);
    }

    double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    printf("Elapsed time: %lf\n", diff);



    //ftime(&end);
    //secs = (end.time - start.time) + (float)(end.millitm - start.millitm);
    //printf("Time taken: %f\n",);
}

