#include <stdio.h>
#include "k.h"

int k(struct keel_ctx* state) {
    printf("The content is :\n%s", state->src);
    return 0;
}
