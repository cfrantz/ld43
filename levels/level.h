#ifndef LD43_LEVELS_LEVEL_H
#define LD43_LEVELS_LEVEL_H
#include <stdint.h>

struct LevelData {
    uint8_t data[32*27];        // offset 0
    uint8_t chrbanks[6];        // offset 864
    uint8_t palette[32];        // offset 870
    uint8_t exits[8 * 4];       // offset 902
    uint8_t items[8 * 3];       // offset 934
    uint8_t spawn[16* 3];       // offset 958
    uint8_t pad[18];            // offset 1006
    // size = 1024
};

extern const uint8_t objset[256];
extern const struct LevelData levels[7];

#endif // LD43_LEVELS_LEVEL_H
