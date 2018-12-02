#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "util/nesutil.h"
#include "levels/screen.h"
#include "game/entity.h"
#include "game/lfsr.h"

uint8_t framenum;
uint8_t player_pad;
uint8_t player_pad_changed;
uint8_t spridx;


const char kHex[] = "0123456789ABCDEF";

const char kHud0[] =    "\2\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\4";
const char kHud1[] =    "\7                         B  A \7";
const char kHud2[] =    "\7                              \7";
const char kHud3[] =    "\7                              \7";
const char kHud4[] =    "\3\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\5";

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

    vram_puts(0, 32*2+24, kHud0);
    vram_puts(0, 32*2+25, kHud1);
    vram_puts(0, 32*2+26, kHud2);
    vram_puts(0, 32*2+27, kHud3);
    vram_puts(0, 32*2+28, kHud4);
    vram_puts(5, 32*2+26, "Health & Stuff");

    entity_load_screen(0);

    ppu_on_all();
    set_split(24*8);
    player_init(6, 20);
    lfsr_val[0] = 0x55;

    for(framenum=0;;++framenum) {
        ppu_waitnmi();
        lfsr_clock();
        oam_clear();
        spridx = 0;
        scroll1(0, 240+24*8);

        player_pad_changed = pad_trigger(0);
        player_pad = pad_state(0);
        entity_all();
        player_check_exit();
    }
}
