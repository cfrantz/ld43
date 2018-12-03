#ifndef LD43_LEVELS_SCREEN_H
#define LD43_LEVELS_SCREEN_H

#include <stdint.h>

extern void screen_load(uint8_t id);
extern uint8_t __fastcall__ get_screen(uint8_t x, uint8_t y);
extern uint8_t* __fastcall__ screen_get_spawns(uint8_t id);
extern uint8_t* __fastcall__ screen_get_items(uint8_t id);

extern uint8_t screen_exit_x0[8];
extern uint8_t screen_exit_y0[8];
extern uint8_t screen_exit_x1[8];
extern uint8_t screen_exit_y1[8];
extern uint8_t screen_exit_dmap[8];
extern uint8_t screen_exit_dx[8];
extern uint8_t screen_exit_dy[8];


#endif // LD43_LEVELS_SCREEN_H
