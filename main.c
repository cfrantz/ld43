#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "util/nesutil.h"
#include "levels/screen.h"
#include "game/entity.h"

uint8_t framenum;
uint8_t player_pad;
uint8_t player_pad_changed;
uint8_t spridx;


const char kHex[] = "0123456789ABCDEF";

const char kHud0[] =    "+------------------------------+";
const char kHud1[] =    "|                              |";

void dobrk(void) {
    asm("brk");
    asm("nop");
}

void main(void)
{
    bank_bg(1);
    bank_spr(0);
    ppu_off();
    oam_size(1);

    vram_puts(0, 32*2+25, kHud0);
    vram_puts(0, 32*2+26, kHud1);
    vram_puts(0, 32*2+27, kHud1);
    vram_puts(0, 32*2+28, kHud1);
    vram_puts(0, 32*2+29, kHud0);
    vram_puts(5, 32*2+27, "Health & Stuff");

    set_mmc3_low_bank(0);
    screen_load(0);

    ppu_on_all();
    set_split(24*8);
    player_init();

    for(framenum=0;;++framenum) {
        ppu_waitnmi();
        oam_clear();
        spridx = 0;
        scroll1(0, 240+24*8);

        player_pad_changed = pad_trigger(0);
        player_pad = pad_state(0);
        player_input();
        entity_move();
        player_display();


    }
}
