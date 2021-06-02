#include "compat.h"

int getrusage(int who, struct rusage *usage) {
    return -1;
}

clock_t clock(void) {
    return 0;
}
