#ifndef LD43_GAME_ENTITY_H
#define LD43_GAME_ENTITY_H

extern uint8_t framenum;
extern uint8_t player_pad;
extern uint8_t player_pad_changed;
extern uint8_t spridx;

extern void entity_move(void);
extern void player_input(void);
extern void player_display(void);
extern void player_init(void);

#endif // LD43_GAME_ENTITY_H
