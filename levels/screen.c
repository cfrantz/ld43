#include <stdint.h>
#include "level.h"
#include "util/nesutil.h"

#pragma bss-name(push, "WRAM")
uint8_t screen[1024];
uint8_t screen_exit_x0[8];
uint8_t screen_exit_y0[8];
uint8_t screen_exit_x1[8];
uint8_t screen_exit_y1[8];
uint8_t screen_exit_dmap[8];
uint8_t screen_exit_dx[8];
uint8_t screen_exit_dy[8];
#pragma bss-name(pop)

const uint16_t ppu_dests[] = { 0x2000, 0x2400, 0x2800, 0x2c00 };
uint8_t * const screens[] = {
    &screen[0], &screen[256], &screen[512], &screen[768],
};

void screen_copy_to_ram(uint8_t n) {
    static uint8_t x, y, i;
    static uint8_t *dst;
    static const uint8_t *src;

    src = levels[n].data;
    for(y=0; y<(15+15+12+12); ++y) {
        switch(y) {
            case 0:  dst = screens[0]; break;
            case 15: dst = screens[1]; break;
            case 30: dst = screens[2]; break;
            case 42: dst = screens[3]; break;
            default: ; 
        }
        for(x=0; x<16; ++x, ++dst, ++src) {
            *dst = *src;
        }
    }
    for(i=0; i<8; i++) {
        x = levels[n].exits[i*4+0];
        y = levels[n].exits[i*4+1];
        screen_exit_x0[i] = x & 0x1f;
        screen_exit_y0[i] = y & 0x1f;
        screen_exit_x1[i] = (x & 0x1f) + (x >> 5) + 1;
        screen_exit_y1[i] = (y & 0x1f) + (y >> 5) + 1;
        screen_exit_dmap[i] = levels[n].exits[i*4+2];
        screen_exit_dx[i] = (levels[n].exits[i*4+3] & 0xf) << 1;
        screen_exit_dy[i] = (levels[n].exits[i*4+3] & 0xf0) >> 3;
    }
}

void screen_load_one(uint8_t scrn) {
    static uint8_t x, y, i, a, h, t;
    static uint8_t *p;

    h = (scrn < 2) ? 15 : 12;
    p = screens[scrn];
    vram_put_addr(ppu_dests[scrn]);
    for(y=0;y<h; ++y) {
        for(i=0; i<2; ++i) {
            for(x=0; x<16; ++x) {
                t = y*16+x;
                a = p[t] * 4;
                vram_put_data(objset[a + i + 0]);
                vram_put_data(objset[a + i + 2]);
            }
        }
    }

    vram_put_addr(ppu_dests[scrn] | 0x3c0);
    for(y=0;y<h; y+=2) {
        for(x=0; x<16; x+=2) {
            t = y*16+x;
            a = ((p[t+0] & 0xC0) >> 6) |
                ((p[t+1] & 0xC0) >> 4) |
                ((p[t+16] & 0xC0) >> 2) |
                ((p[t+17] & 0xC0) >> 0);
            vram_put_data(a);
        }
    }
}

void screen_load(uint8_t id) {
    static uint8_t n, i;
    set_mmc3_low_bank(id >> 3);
    pal_all(levels[id].palette);
    n = id & 7;
    screen_copy_to_ram(n);
    for(i=0; i<4; i++) {
        screen_load_one(i);
    }
    for(i=0; i<6; i++) {
        mmc3_reg(i, levels[id].chrbanks[i]);
    }
}

uint8_t* screen_get_spawns(uint8_t id) {
    id &= 7;
    return levels[id].spawn;
}
