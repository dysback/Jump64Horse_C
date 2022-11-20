#ifndef HEADER_TABLE
#define HEADER_TABLE

#define TABLE_SIZE 8

typedef struct STable {
    int table[TABLE_SIZE + 4][TABLE_SIZE + 4];
} Table;

Table *initialize_table();

int table_jump(Table *, int, int, int);

void table_print(Table *, char *);
void table_print2(Table *, char *, int);

#endif