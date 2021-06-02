#include <stdio.h>

int foo_square(int x) {
    printf("hihi\n");
    fprintf(stderr, "errrrrr %d\n", x);
    if (x == 10) {
        abort();
    }
    return x * x;
}
