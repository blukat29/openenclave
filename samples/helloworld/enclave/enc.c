// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#define _GNU_SOURCE
#include <dlfcn.h>
#include <link.h>

#include "helloworld_t.h"

#include "foo.h"
#include "compat.h"

void* fptrs[] = {
    ftell,
    getrusage,
    puts,
    fseek,
    select,
    gettimeofday,
    fopen,
    srandom,
    getpid,
    sprintf,
    fread,
    dl_iterate_phdr,
    clock,
    strcpy,
    strtok,
    srand,
    getuid,
    dladdr,
    fclose,
    random,
    rand,
};

void enclave_helloworld()
{
    printf("Hello world from the enclave\n");

#if 0
    int x = 7;
    int y = foo_square(x);
    printf("foo_square(%d) = %d\n", x, y);
#endif
}
