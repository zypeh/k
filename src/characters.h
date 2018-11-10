#pragma once
enum {
    NULLCHARACTER = 0,
    MAXASCIICHARACTER = 0x7F,

    LINEFEED = 0x0A, // \n
    CARRIAGERETURN = 0x0D, // \r
    LINESEPARATOR = 0x2028,
    PARAGRAPHSEPARATOR = 0x2029,
    NEXTLINE = 0x0085,

    // Unicode 3.0 space characters
    SPACE = 0x0020, // " "
    NONBREAKINGSPACE = 0x00A0, //
    ENQUAD = 0x2000,
    EMQUAD = 0x2001,
    ENSPACE = 0x2002,
    EMSPACE = 0x2003,
    THREEPEREMSPACE = 0x2004,
    FOURPEREMSPACE = 0x2005,
    SIXPEREMSPACE = 0x2006,
    FIGURESPACE = 0x2007,
    PUNCTUATIONSPACE = 0x2008,
    THINSPACE = 0x2009,
    HAIRSPACE = 0x200A,
    ZEROWIDTHSPACE = 0x200B,
    NARROWNOBREAKSPACE = 0x202F,
    IDEOGRAPHICSPACE = 0x3000,
    MATHEMATICALSPACE = 0x205F,
    OGHAM = 0x1680,

    UNDERSCORE = 0x5f,
    DOLLARSIGN = 0x24,

    AMPERSAND = 0x26, // &
    ASTERISK = 0x2A, // *
    AT = 0x40, // @
    BACKSLASH = 0x5C,
    BACKTICK = 0x60, // `
    BAR = 0x7C, // |
    CARET = 0x5E, // ^
    CLOSEBRACE = 0x7D, // }
    CLOSEBRACKET = 0x5D, // ]
    CLOSEPAREN = 0x29, // )
    COLON = 0x3A, // :
    COMMA = 0x2C, // ,
    DOT = 0x2E, // .
    DOUBLEQUOTE = 0x22, // "
    EQUALS = 0x3D, // =
    EXCLAMATION = 0x21, // !
    GREATERTHAN = 0x3E, // >
    HASH = 0x23, // #
    LESSTHAN = 0x3C, // <
    MINUS = 0x2D, // -
    OPENBRACE = 0x7B, // {
    OPENBRACKET = 0x5B, // [
    OPENPAREN = 0x28, // (
    PERCENT = 0x25, // %
    PLUS = 0x2B, // +
    QUESTION = 0x3F, // ?
    SEMICOLON = 0x3B, // ;
    SINGLEQUOTE = 0x27, // '
    SLASH = 0x2F, // /
    TILDE = 0x7E, // ~

    BACKSPACE = 0x08, // \b
    FORMFEED = 0x0C, // \f
    BYTEORDERMARK = 0xFEFF,
    TAB = 0x09, // \t
    VERTICALTAB = 0x0B, // \v
};
