#ifndef HEADER_TABLE
#define HEADER_TABLE

#define TABLE_SIZE 8

typedef struct STable {
    int table[20][20];
    int size;
    int moves;
    int max_move;
    int max_move_direction;
} Table;

void initialize_table(Table *, int, int, int, int);
int  table_jump(Table *, int, int, int);
void table_print(Table *, char *);
void table_print2(Table *, char *, int);


#endif