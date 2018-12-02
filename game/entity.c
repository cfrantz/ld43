#include <stdint.h>
#include "entity.h"
#include "util/nesutil.h"
#include "levels/level.h"


const uint8_t meta_sprites[] = {
    // player left 1
    0x00, 0x00, 0x1a, 0x40,
    0x08, 0x00, 0x18, 0x40, 0x80,
    // player left 2
    0x00, 0x00, 0x1e, 0x40,
    0x08, 0x00, 0x1c, 0x40, 0x80,
    // player right 1
    0x00, 0x00, 0x18, 0x00,
    0x08, 0x00, 0x1a, 0x00, 0x80,
    // player right 2
    0x00, 0x00, 0x1c, 0x00,
    0x08, 0x00, 0x1e, 0x00, 0x80,
    // player up 1
    0x00, 0x00, 0x14, 0x00,
    0x08, 0x00, 0x16, 0x00, 0x80,
    // player up 2
    0x00, 0x00, 0x16, 0x40,
    0x08, 0x00, 0x14, 0x40, 0x80,
    // player down 1
    0x00, 0x00, 0x10, 0x00,
    0x08, 0x00, 0x12, 0x00, 0x80,
    // player down 2
    0x00, 0x00, 0x12, 0x40,
    0x08, 0x00, 0x10, 0x40, 0x80,
};

const uint8_t * const ids[] = {
    &meta_sprites[0*9],
    &meta_sprites[1*9],
    &meta_sprites[2*9],
    &meta_sprites[3*9],
    &meta_sprites[4*9],
    &meta_sprites[5*9],
    &meta_sprites[6*9],
    &meta_sprites[7*9],
};

const uint8_t bbx0[] = { 0, 3, 0, 0, 0, 0, 0, 0, };
const uint8_t bby0[] = { 0, 1, 0, 0, 0, 0, 0, 0, };
const uint8_t bbx1[] = { 0, 12, 0, 0, 0, 0, 0, 0, };
const uint8_t bby1[] = { 0, 14, 0, 0, 0, 0, 0, 0, };

#define NUM_ENTITIES 9
uint8_t entity_id[NUM_ENTITIES];
uint8_t entity_facing[NUM_ENTITIES];
uint8_t entity_subpixx[NUM_ENTITIES];
uint8_t entity_subpixy[NUM_ENTITIES];
uint16_t entity_posx[NUM_ENTITIES];
uint16_t entity_posy[NUM_ENTITIES];
int16_t entity_vx[NUM_ENTITIES];
int16_t entity_vy[NUM_ENTITIES];
uint16_t scrollx, scrolly;
uint8_t screenx, screeny;
uint8_t tmp;

uint16_t xx, yy;
int16_t sx, sy;

void entity_move(void) {
    static uint8_t i, id, a, b;
    static int16_t vx, vy;

    for(i=0; i<NUM_ENTITIES; ++i) {
        id = entity_id[i];
        if (!id) continue;

        xx = entity_posx[i];
        yy = entity_posy[i];
        vx = entity_vx[i];
        vy = entity_vy[i];

        if (vx < 0) {
            // left
            sx = entity_subpixx[i] + vx;
            xx += (sx >> 8);
            a = get_screen((xx+bbx0[id])/ 16, (yy+bby0[id]) / 16);
            b = get_screen((xx+bbx0[id])/ 16, (yy+bby1[id]) / 16);
        } else if (vx > 0) {
            // right
            sx = entity_subpixx[i] + vx;
            xx += (sx >> 8);
            a = get_screen((xx+bbx1[id])/ 16, (yy+bby0[id]) / 16);
            b = get_screen((xx+bbx1[id])/ 16, (yy+bby1[id]) / 16);
        }
        if (vy < 0) {
            // up
            sy = entity_subpixy[i] + vy;
            yy += (sy >> 8);
            a = get_screen((xx+bbx0[id])/ 16, (yy+bby0[id]) / 16);
            b = get_screen((xx+bbx1[id])/ 16, (yy+bby0[id]) / 16);
        } else if (vy > 0) {
            // down
            sy = entity_subpixy[i] + vy;
            yy += (sy >> 8);
            a = get_screen((xx+bbx0[id])/ 16, (yy+bby1[id]) / 16);
            b = get_screen((xx+bbx1[id])/ 16, (yy+bby1[id]) / 16);
        }
        if ((a|b) & 16) continue;

        entity_subpixx[0] = sx;
        entity_posx[0] = xx;
        entity_subpixy[0] = sy;
        entity_posy[0] = yy;
    }
}

void player_input(void) {
    entity_vx[0] = 0;
    entity_vy[0] = 0;
    if (player_pad & PAD_LEFT) {
        entity_facing[0] = 0;
        entity_vx[0] = -0x100;
    } else if (player_pad & PAD_RIGHT) { 
        entity_facing[0] = 1;
        entity_vx[0] = 0x100;
    } else if (player_pad & PAD_UP) {
        entity_facing[0] = 2;
        entity_vy[0] = -0x100;
    } else if (player_pad & PAD_DOWN) { 
        entity_facing[0] = 3;
        entity_vy[0] = 0x100;
    }
}    

void player_display(void) {
    if (entity_posx[0] < 128) {
        scrollx = 0;
    } else if (entity_posx[0] > 383) {
        scrollx = 255;
    } else {
        scrollx = entity_posx[0] - 128;
    }
    if (entity_posy[0] < 96) {
        scrolly = 0;
    } else if (entity_posy[0] > 335) {
        scrolly = 239;
    } else {
        scrolly = entity_posy[0] - 96;
    }
    scroll0(scrollx, scrolly);

    screenx = entity_posx[0] - scrollx;
    screeny = entity_posy[0] - scrolly;

    tmp = ((uint8_t)entity_posx[0] + (uint8_t)entity_posy[0]) & 1;
    tmp += entity_facing[0]*2;
    spridx = oam_meta_spr(screenx, screeny, spridx, ids[tmp]);
    writereg8(0x401a, spridx);
}   

void player_init(void) {
    entity_id[0] = 1;
    entity_posx[0] = 64;
    entity_posy[0] = 64;
    entity_facing[0] = 3;
}
