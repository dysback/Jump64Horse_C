#include <stdio.h>
#include "helpers.h"

void logStr(char *value, int severity) {
    if(severity >= LOG_LEVEL) {
        printf("-%s------\n", value);
    }

}

void logInt(int value, int severity) {
    if(severity >= LOG_LEVEL) {
        printf("-%d------\n", value);
    }

}