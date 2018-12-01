#include <stdint.h>
#include "entity.h"
#include "util/nesutil.h"
#include "levels/level.h"

uint8_t entity_id[16];
uint8_t entity_subpix[16];
uint16_t entity_posx[16];
uint16_t entity_posy[16];
uint16_t scrollx, scrolly;
uint8_t screenx, screeny;
uint8_t tmp;

void player_input(void) {
    if (player_pad_changed & PAD_LEFT) {
        entity_posx[0] -= 16;
    } else if (player_pad_changed & PAD_RIGHT) { 
        entity_posx[0] += 16;
    }
    if (player_pad_changed & PAD_UP) {
        entity_posy[0] -= 16;
    } else if (player_pad_changed & PAD_DOWN) { 
        entity_posy[0] += 16;
    }
    
    if (entity_posx[0] < 128) {
        scrollx = 0;
    } else if (entity_posx[0] > 383) {
        scrollx = 255;
    } else {
        scrollx = entity_posx[0] - 128;
    }
    if (entity_posy[0] < 120) {
        scrolly = 0;
    } else if (entity_posy[0] > 311) {
        scrolly = 239;
    } else {
        scrolly = entity_posy[0] - 120;
    }
    scroll0(scrollx, scrolly);

    screenx = entity_posx[0] - scrollx;
    screeny = entity_posy[0] - scrolly;

    spridx = oam_spr(screenx, screeny, 0, 0, spridx);
    spridx = oam_spr(screenx+8, screeny, 2, 0, spridx);

    if (player_pad_changed) {
        tmp = get_screen(entity_posx[0] / 16, entity_posy[0] / 16);
        writereg8(0x401a, tmp);
    }
}   
