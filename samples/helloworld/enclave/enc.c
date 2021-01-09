// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <stdio.h>
#include <string.h>

// Include the trusted helloworld header that is generated
// during the build. This file is generated by calling the
// sdk tool oeedger8r against the helloworld.edl file.
#include "helloworld_t.h"

void overflow() {
    char buf[10];
    memset(buf, 0xcc, 32);
}

uint64_t my_handler(oe_exception_record_t* record) {
    printf("hihihwwwwwww\n");
    printf("%lx %x %lx\n", record->code, record->flags, record->address);
    printf("%lx %lx\n", record->flags, record->context->rip);
    uint64_t i = 0;
    i--;
    while (i--);
    printf("hihihihi\n");
    //return OE_EXCEPTION_CONTINUE_EXECUTION;
}

void enclave_helloworld()
{
    fprintf(stdout, "Hello world from the enclave\n");

    oe_result_t oe_result = oe_add_vectored_exception_handler(true, my_handler);
    printf("added %d %s\n", oe_result, oe_result_str(oe_result));

    int x = 0;
    int y = 2;
    //int z = y / x;
    overflow();
    //*(int*)0xdeadbeef = 123;
    //*(int*)0xcccccccc = 3;
    return;
#if 0
    oe_abort();
#endif
#if 0
    void (*fn)(void) = (void(*)(void))(0x1234);
    fn();
#endif
#if 1
    void (*fn)(void) = (void(*)(void))(0xcccccccc);
    fn();
#endif
#if 0
    *(int*)0xfffffffffffffff0 = 123;
#endif
#if 0
    *(int*)0xdeadbeef = 123;
#endif


    // Call back into the host
    oe_result_t result = host_helloworld();
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "Call to host_helloworld failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
    }
}
