#include <stdio.h>
#include "k.h"

int k(struct keel_ctx* ctx) {
    fwrite(ctx->src, ctx->len, 1, stdout);
    return 0;
}
