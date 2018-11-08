#pragma once
#include <stdio.h>
#include <stdlib.h>

static inline void *checked_malloc(size_t size) {
    void *p = malloc(size);
    if (!p) {
        fputs("[!] critical error: out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    return p;
}

#define malloc checked_malloc
