#pragma once
#include <stdint.h>
#include <stdbool.h>

/* pointer */
typedef uintptr_t ptr;

struct ctx {
    ptr env;
};

int k(struct ctx* state);
