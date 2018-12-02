#pragma data-name(push, "CHARS")
#include "util/binary.h"

unsigned char sprites[256 * 8 * 2] = {
#include "resources/sprites.h"
};

// Main char is color 3, drop shadow color 1.
unsigned char unscii[256 * 8 * 2] = {

#include "resources/cchars.h"
#undef XCHR
#define XCHR(a, b, c, d, e, f, g, h) \
    a, b|(a>>1), c|(b>>1), d|(c>>1), e|(d>>1), f|(e>>1), g|(f>>1),  h|(g>>1), \
    a, b, c, d, e, f, g, h
#include "unscii/ascii-symdigit.h"
#include "unscii/ascii-upper.h"
#include "unscii/ascii-lower.h"

// 0x80 to 0xff
#include "resources/bgtiles.h"

};
#pragma data-name(pop)
