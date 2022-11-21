#ifndef HEADER_HELPERS
#define HEADER_HELPERS

#define MOVES 64
#define INIT_X 2
#define INIT_Y 5
// 0 - nothing is logged
#define LOG_LEVEL 2

void logStr(char *value, int severity);
void logInt(int value, int severity);

#endif