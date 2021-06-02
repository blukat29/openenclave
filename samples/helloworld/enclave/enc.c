// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <stdio.h>

#include "helloworld_t.h"

#include "foo.h"

void enclave_helloworld()
{
    printf("Hello world from the enclave\n");

    int x = 7;
    int y = foo_square(x);
    printf("foo_square(%d) = %d\n", x, y);
}
