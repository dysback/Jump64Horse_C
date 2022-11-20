#ifndef HEADER_TABLE
#define HEADER_TABLE

#define TABLE_SIZE 8

//int table[TABLE_SIZE + 4][TABLE_SIZE + 4];
void initialize_table(int table[TABLE_SIZE + 4][TABLE_SIZE + 4]);


int table_jump(int [TABLE_SIZE + 4][TABLE_SIZE + 4], int, int, int);

void table_print(int [TABLE_SIZE + 4][TABLE_SIZE + 4], char *);
void table_print2(int [TABLE_SIZE + 4][TABLE_SIZE + 4], char *, int);

#endif