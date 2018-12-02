#include "level.h"
#pragma rodata-name(push, "LVLDAT1")
const uint8_t objset1[256] = {
0x00,0x00,0x00,0x00,
0x80,0x80,0x80,0x80,
0x81,0x81,0x81,0x81,
0x98,0x99,0x9a,0x9b,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x90,0x91,0x92,0x93,
0x94,0x95,0x96,0x97,
0x98,0x99,0x9a,0x9b,
0x00,0x00,0x00,0x00,
0xa0,0xa1,0xa2,0xa3,
0xa4,0xa5,0xa6,0xa7,
0xa8,0xa9,0xaa,0xab,
0xac,0xad,0xae,0xaf,
};
const struct LevelData levels1[7] = {
{}, // map 08
{  // map 09
{  // data
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,0x91,0x91,0x91,0x91,
0x91,0x91,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,0x91,0x91,0x91,0x91,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x91,0x91,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,
0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,0x91,
},
{  // chrbanks
0x00,0x02,0x04,0x05,0x06,0x07
},
{  // palette
0x0f,0x12,0x16,0x30,0x0f,0x37,0x1a,0x2a,0x0f,0x37,0x07,0x17,0x0f,0x00,0x10,0x30,
0x0f,0x17,0x26,0x12,0x0f,0x0f,0x12,0x30,0x0f,0x37,0x07,0x17,0x0f,0x00,0x10,0x30
},
{  // exits
0x00,0xc4,0x0a,0x3f,0x00,0x94,0x0a,0xbf,0x1f,0x95,0x06,0xc0,0x82,0x1a,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{  // items
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{  // spawns
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
},
{  // map 0a
{  // data
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd6,0xd6,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd4,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd5,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd6,0xd6,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd4,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd5,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd6,0xc2,0xc2,0xc2,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xd6,0xd6,0xd6,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd1,0xd1,
0xc2,0xc2,0xd4,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xd5,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd6,0xd6,0xd6,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xd4,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xd5,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xd7,0xc2,0xc2,0xc2,0xc2,
0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xd6,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xd1,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xc2,0xd1,0xd1,
},
{  // chrbanks
0x00,0x02,0x04,0x05,0x06,0x07
},
{  // palette
0x0f,0x12,0x16,0x30,0x0f,0x37,0x1a,0x2a,0x0f,0x37,0x07,0x17,0x0f,0x00,0x10,0x30,
0x0f,0x17,0x26,0x12,0x0f,0x0f,0x12,0x30,0x0f,0x37,0x07,0x17,0x0f,0x00,0x10,0x30
},
{  // exits
0xe2,0x1a,0x05,0x02,0xf7,0x1a,0x05,0x0c,0x1f,0xc4,0x09,0x30,0x1f,0x94,0x09,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{  // items
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{  // spawns
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
},
{}, // map 0b
{}, // map 0c
{}, // map 0d
{}, // map 0e
};
#pragma rodata-name(pop)
