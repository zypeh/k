#pragma once
#include <stdint.h>
#include <stdbool.h>

/* pointer */
typedef uintptr_t ptr;

typedef struct keel_ctx {
    uint8_t* src;
    uint32_t len;
    ptr env;
} keel_ctx;

int k(struct keel_ctx* ctx);
