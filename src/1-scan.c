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
    uint8_t c = src[scanner->pos];

    switch ((uint32_t)c) { /* COMMENT_NEEDED: what is this sorcery ? */
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
