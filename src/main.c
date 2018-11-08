#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

#include "k.h"

struct ctx state = {
    .env = 0
};

int main(int argc, const char **argv) {
    if (argc != 2) {
        fputs("Usage: k0 <filename>", stderr);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (ferror(fp)) {
        fputs("I/O error when reading", stderr);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t linecap = 0;
    int linelen = 0;
    while((linelen = getline(&line, &linecap, fp)) != -1) {
        if (linelen && (line[linelen-1] == '\n' || line[linelen-1] == '\r'))
            line[--linelen] = '\0';
        printf("%s\n", line);
    }
    
    free(line);
    fclose(fp);

    return k(&state);
}
