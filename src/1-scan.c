#include <stdio.h>
#include "1-scan.h"
#include "characters.h"

enum Token {
    ENDOFFILE,
    NEWLINE,
};

void new_scanner(srcScanner* scanner, srcFile* source) {
    scanner->src = source;
    scanner->pos = 0;
    scanner->line = 0;
    scanner->col = 0;
    // fwrite(scanner->src->buf, scanner->src->len, 1, stdout);
}

void next(srcScanner* scanner, int step) {
    scanner->pos += step;
    scanner->col += step;
}

int token(srcScanner* scanner, int token, uint32_t len) {
    uint8_t startpos = scanner->pos;
    next(scanner, len);
    tokenRange tok = {
        .tokenType = NEWLINE,
        .start = startpos,
        .end = scanner->pos + 1,
    };
    scanner->token = &tok;
    return token;
}

int scan(srcScanner* scanner) {
    /* End of file */
    if (scanner->pos >= scanner->src->len) {
        return ENDOFFILE;
    }

    uint8_t* src = scanner->src->buf;
    uint32_t c = (uint32_t)src[scanner->pos];

    switch (c >> 6) {
        // c is ordinary ASCII, skip processing
        case 0: 
        case 1:
        break;

        // c is longer than a byte
        case 3:
            if ((c >> 5) == 0b110)  {
                // c is 2-bytes long
                c = (c << 8) | src[++scanner->pos]; 
            } else if ((c >> 4) == 0b1110) {
                // c is 3-bytes long
                c = (c << 8) | src[++scanner->pos]; 
                c = (c << 8) | src[++scanner->pos];
            } else if ((c >> 3) == 0b11110) {
                // c is 4-bytes long
                c = (c << 8) | src[++scanner->pos]; 
                c = (c << 8) | src[++scanner->pos];
                c = (c << 8) | src[++scanner->pos]; 
            } else {
                // unreachable
            }
        break;

        case 2:
            // TODO: error handling
            // this should not happen with well-formed utf-8 files
        default:
            // unreachable
    }

    switch (c) {
        case LINEFEED:
        case LINESEPARATOR:
        case PARAGRAPHSEPARATOR:
            return token(scanner, NEWLINE, 1);
        default:
            printf("%c", src[scanner->pos]);
    }
    scanner->pos++;
    return 1;
}
