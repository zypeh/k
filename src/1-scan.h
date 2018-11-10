#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct tokenRange {
    uint8_t tokenType;
    uint32_t start;
    uint32_t end;
} tokenRange;

typedef struct srcFile {
    uint8_t* filepath;
    uint8_t* buf;
    uint32_t len;
} srcFile;

typedef struct srcScanner {
    srcFile* src;
    uint32_t pos;
    uint32_t line;
    uint32_t col;
    tokenRange* token;
} srcScanner;

void new_scanner(srcScanner* scanner, srcFile* source);
int scan(srcScanner* scanner);
