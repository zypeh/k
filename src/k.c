#include <stdio.h>
#include "k.h"

int k(struct ctx* state) {
    printf("%lu", state->env);
    return 0;
}
