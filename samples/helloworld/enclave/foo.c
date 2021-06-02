// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include "foo.h"

#include <stdio.h>

int foo_div(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "libfoo: Cannot divide by zero\n");
        return 0;
    }
    else
    {
        return a / b;
    }
}
