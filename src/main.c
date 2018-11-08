#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

#include "alloc.h"
#include "grow-array.h"
#include "k.h"

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

    char *content = 0;
    uint32_t len = 0;
    uint32_t offset = 0;
    while (true) {
        content = grow_array(content, &len, (size_t)len + 256);
        uint32_t n = (uint32_t) fread(content + offset, 1, len - offset, fp);
        if (n < len - offset) {
            content[offset + n] = '\0';
            break;
        }
        offset += n;
    }

    fwrite(content, len, 1, stdout);
    free(content);
    fclose(fp);
    return EXIT_SUCCESS;
}
