#include <stdint.h>
#include "entity.h"
#include "lfsr.h"
#include "util/nesutil.h"
#include "levels/screen.h"


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
    // spider 1
    0x00, 0x00, 0x80, 0x01,
    0x08, 0x00, 0x82, 0x01, 0x80,
    // spider 2
    0x00, 0x00, 0x82, 0x41,
    0x08, 0x00, 0x80, 0x41, 0x80,
    // grump 1
    0x00, 0x00, 0x84, 0x01,
    0x08, 0x00, 0x86, 0x01, 0x80,
    // grump 2
    0x00, 0x00, 0x86, 0x41,
    0x08, 0x00, 0x84, 0x41, 0x80,
    // skull 1
    0x00, 0x00, 0x88, 0x01,
    0x08, 0x00, 0x8a, 0x01, 0x80,
    // skull 2
    0x00, 0x00, 0x8a, 0x41,
    0x08, 0x00, 0x88, 0x41, 0x80,

    // star 1
    0x00, 0x00, 0x70, 0x01,
    0x08, 0x00, 0x72, 0x01, 0x80,
    // star 2
    0x00, 0x00, 0x74, 0x01,
    0x08, 0x00, 0x76, 0x01, 0x80,
    // star 3
    0x00, 0x00, 0x78, 0x01,
    0x08, 0x00, 0x7a, 0x01, 0x80,
    // star 4
    0x00, 0x00, 0x7c, 0x01,
    0x08, 0x00, 0x7e, 0x01, 0x80,

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

#define SPR_SPIDER 8
    &meta_sprites[8*9],
    &meta_sprites[9*9],
#define SPR_GRUMP 10
    &meta_sprites[10*9],
    &meta_sprites[11*9],
#define SPR_SKULL 12
    &meta_sprites[12*9],
    &meta_sprites[13*9],
#define SPR_STAR 14
    &meta_sprites[14*9],
    &meta_sprites[15*9],
    &meta_sprites[16*9],
    &meta_sprites[17*9],
};

const uint8_t sword_meta_sprites[] = {
    // sword left
    0x00, 0x00, 0x24, 0x01,
    0x08, 0x00, 0x26, 0x01, 0x80,
    // sword right
    0x00, 0x00, 0x26, 0x41,
    0x08, 0x00, 0x24, 0x41, 0x80,
    // sword up
    0x00, 0x00, 0x20, 0x01, 0x80,
    // sword down
    0x00, 0x00, 0x20, 0x81, 0x80,
};
const uint8_t * const sword_ids[] = {
    &sword_meta_sprites[0],
    &sword_meta_sprites[9],
    &sword_meta_sprites[18],
    &sword_meta_sprites[23],
};

enum EntityID {
    Player = 0,
    Spider = 1,
    Grump = 2,
    Skull = 3,
};
enum EntityState {
    Normal = 0,
    Stun = 1,
    Dead = 2,
};


const uint8_t bbx0[] = { 3,  2,  2,  2,  0,  0,  0,  };
const uint8_t bby0[] = { 1,  2,  2,  2,  0,  0,  0,  };
const uint8_t bbx1[] = { 12, 14, 14, 14, 0,  0,  0,  };
const uint8_t bby1[] = { 14, 14, 14, 14, 0,  0,  0,  };
const uint8_t health[]={ 8,  4,  9,  16,  0,  0,  0,  };

#define NUM_ENTITIES 9
uint8_t entity_id[NUM_ENTITIES];
int8_t entity_hp[NUM_ENTITIES];
uint8_t entity_facing[NUM_ENTITIES];
uint8_t entity_timer[NUM_ENTITIES];
uint8_t entity_dmgtm[NUM_ENTITIES];
uint8_t entity_sprite[NUM_ENTITIES];
uint8_t entity_state[NUM_ENTITIES];
uint8_t entity_subpixx[NUM_ENTITIES];
uint8_t entity_subpixy[NUM_ENTITIES];
uint16_t entity_posx[NUM_ENTITIES];
uint16_t entity_posy[NUM_ENTITIES];
int16_t entity_vx[NUM_ENTITIES];
int16_t entity_vy[NUM_ENTITIES];
uint16_t scrollx, scrolly;
uint8_t screenx, screeny;
uint8_t tmp;
uint8_t index;

const uint8_t sword_frames[] = {0, 12, 12, 12, 10, 8, 6, 4, 2};
uint16_t swordx, swordy;
uint8_t sword_timer;
uint8_t sword_damage;
uint8_t ssx, ssy;
const uint8_t sbx0[] = { 0,  3,  1,  1 };
const uint8_t sby0[] = { 1,  1,  0,  3 };
const uint8_t sbx1[] = { 12, 15, 5,  5 };
const uint8_t sby1[] = { 5,  5,  12, 15};

uint16_t xx, yy;
int16_t sx, sy;
uint8_t on_screen;

void entity_move(void) {
    static uint8_t id, a, b;
    static int16_t vx, vy;

    id = entity_id[index];
    xx = entity_posx[index];
    yy = entity_posy[index];
    vx = entity_vx[index];
    vy = entity_vy[index];

    if (vx < 0) {
        // left
        sx = entity_subpixx[index] + vx;
        xx += (sx >> 8);
        a = get_screen((xx+bbx0[id])/ 16, (yy+bby0[id]) / 16);
        b = get_screen((xx+bbx0[id])/ 16, (yy+bby1[id]) / 16);
    } else if (vx > 0) {
        // right
        sx = entity_subpixx[index] + vx;
        xx += (sx >> 8);
        a = get_screen((xx+bbx1[id])/ 16, (yy+bby0[id]) / 16);
        b = get_screen((xx+bbx1[id])/ 16, (yy+bby1[id]) / 16);
    }
    if (vy < 0) {
        // up
        sy = entity_subpixy[index] + vy;
        yy += (sy >> 8);
        a = get_screen((xx+bbx0[id])/ 16, (yy+bby0[id]) / 16);
        b = get_screen((xx+bbx1[id])/ 16, (yy+bby0[id]) / 16);
    } else if (vy > 0) {
        // down
        sy = entity_subpixy[index] + vy;
        yy += (sy >> 8);
        a = get_screen((xx+bbx0[id])/ 16, (yy+bby1[id]) / 16);
        b = get_screen((xx+bbx1[id])/ 16, (yy+bby1[id]) / 16);
    }
    if ((a|b) & 16) return;

    entity_subpixx[index] = sx;
    entity_posx[index] = xx;
    entity_subpixy[index] = sy;
    entity_posy[index] = yy;
}


void player_input(void) {
    entity_vx[0] = 0;
    entity_vy[0] = 0;
    if (sword_timer) {
    } else if (player_pad_changed & PAD_A) {
        sword_timer = sizeof(sword_frames) - 1;
    } else if (player_pad & PAD_LEFT) {
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

void player_sword(void) {
    if (!sword_timer)
        return;
    swordx = entity_posx[0];
    swordy = entity_posy[0];
    if (entity_facing[0] == 0) {
        // left
        swordx -= sword_frames[sword_timer];
        swordy += 7;
    } else if (entity_facing[0] == 1) {
        // right
        swordx += sword_frames[sword_timer];
        swordy += 7;
    } else if (entity_facing[0] == 2) {
        // up
        swordx += 1;
        swordy -= sword_frames[sword_timer];
    } else if (entity_facing[0] == 3) {
        //down
        swordx += 9;
        swordy += sword_frames[sword_timer];
    }
    ssx = swordx-scrollx;
    ssy = swordy-scrolly;
    spridx = oam_meta_spr(ssx, ssy, spridx, sword_ids[entity_facing[0]]);
    sword_timer -= 1;
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
    if (entity_state[0] == Stun && entity_timer[0] & 1)
        return;
    spridx = oam_meta_spr(screenx, screeny, spridx, ids[tmp]);
    player_sword();
}   

void entity_display(void) {
    on_screen = 0;
    sx = entity_posx[index] - scrollx;
    if (sx < 0  || sx > 255) return;
    sy = entity_posy[index] - scrolly;
    if (sy < 0  || sy > 192) return;
    on_screen = 1;
    if (entity_state[index] == Stun && entity_timer[index] & 1)
        return;
    spridx = oam_meta_spr(sx, sy, spridx, ids[entity_sprite[index]]);
}


void entity_spawn(uint8_t *spawns) {
    tmp = 0;
    for(index=1; index<NUM_ENTITIES; ++index,tmp+=3) {
        entity_posx[index] = spawns[tmp+0] * 16;
        entity_posy[index] = spawns[tmp+1] * 16;
        entity_id[index] = spawns[tmp+2];
        entity_hp[index] = health[entity_id[index]];
        entity_subpixx[index] = 0;
        entity_subpixy[index] = 0;
        entity_vx[index] = 0;
        entity_vy[index] = 0;
        entity_timer[index] = 0;
        entity_dmgtm[index] = 0;
        entity_sprite[index] = 0;
        entity_state[index] = Normal;
    }
}

void entity_load_screen(uint8_t dmap) {
    screen_load(dmap);
    entity_spawn(screen_get_spawns(dmap));
}

uint8_t player_check_exit(void) {
    static uint8_t i, x, y;

    x = (entity_posx[0] + 8) / 16;
    y = (entity_posy[0] + 8) / 16;
    //writereg8(0x401a, x);
    for(i=0; i<8; ++i) {
        if (x >= screen_exit_x0[i] &&
            x < screen_exit_x1[i] &&
            y >= screen_exit_y0[i] &&
            y < screen_exit_y1[i]) {
            entity_posx[0] = screen_exit_dx[i]*16;
            entity_posy[0] = screen_exit_dy[i]*16;
            ppu_off();
            entity_load_screen(screen_exit_dmap[i]);

            ppu_on_all();
            return 1;
        }
    }
    return 0;
}

void player_init(uint8_t x, uint8_t y) {
    entity_id[0] = 0;
    entity_posx[0] = x*16;
    entity_posy[0] = y*16;
    entity_facing[0] = 3;
    sword_damage = 3;
}

void __fastcall__ entity_set_velocity(int16_t v) {
    switch(entity_facing[index]) {
        case 0: entity_vx[index] = -v; entity_vy[index] = 0; break;
        case 1: entity_vx[index] =  v; entity_vy[index] = 0; break;
        case 2: entity_vx[index] = 0; entity_vy[index] = -v; break;
        case 3: entity_vx[index] = 0; entity_vy[index] =  v; break;
    }
}

uint8_t entity_collide(void) {
    static uint8_t id, x0, y0, x1, y1;
    if (!on_screen)
        return 0;

    id = entity_id[index];
    x0 = sx + bbx0[id];
    y0 = sy + bby0[id];
    x1 = sx + bbx1[id];
    y1 = sy + bby1[id];

    if (sword_timer &&
        ssx+sbx0[entity_facing[0]] <= x1 &&
        ssx+sbx1[entity_facing[0]] >= x0 &&
        ssy+sby0[entity_facing[0]] <= y1 &&
        ssy+sby1[entity_facing[0]] >= y0) {
        if (entity_state[index] != Dead) {
            entity_state[index] = Stun;
            entity_timer[index] = 30;
            if (entity_dmgtm[index] == 0) {
                entity_set_velocity(0);
                entity_dmgtm[index] = sword_timer;
                entity_hp[index] -= sword_damage;
                if (entity_hp[index] <= 0)
                    entity_state[index] = Dead;
            }
        }
        return 2;
    }
    if (entity_state[0] == Stun || entity_state[index] == Stun) {
        return 0;
    }
    if (screenx+bbx0[0] <= x1 &&
        screenx+bbx1[0] >= x0 &&
        screeny+bby0[0] <= y1 &&
        screeny+bby1[0] >= y0) {
        entity_state[0] = Stun;
        entity_timer[0] = 30;
        return 1;
    }
    return 0;
}

void entity_ai(void) {
    static uint8_t timer, tick;
    timer = entity_timer[index];
    tick = timer / 4;
    if (timer) {
        entity_timer[index] -= 1;
    }
    if (entity_state[index] == Dead) {
        entity_sprite[index] = SPR_STAR + tick/2;
        if (entity_timer[index] == 0) entity_id[index] = 0;
        return;
    }
    if (entity_dmgtm[index]) {
        entity_dmgtm[index] -= 1;
    }

    switch(entity_id[index]) {
    case Player:
        if (timer == 0) {
            if (entity_state[index] == Stun) entity_state[index] = Normal;
        }
        player_input();
        break;
    case Spider:
        if (timer == 0) {
            if (entity_state[index] == Stun) entity_state[index] = Normal;
            entity_timer[index] = (lfsr_val[index] & 0x03f);
            entity_facing[index] = lfsr_val[index] >> 6;
            entity_set_velocity(0x200);
        }
        entity_collide();
        entity_sprite[index] = SPR_SPIDER + (tick & 1);
        break;
    case Grump:
        if (timer == 0) {
            if (entity_state[index] == Stun) entity_state[index] = Normal;
            entity_timer[index] = lfsr_val[index] & 0xc;
            entity_facing[index] = lfsr_val[index] & 3;
            entity_set_velocity(0xc0);
        }
        entity_collide();
        entity_sprite[index] = SPR_GRUMP + (tick & 1);
        break;
    case Skull:
        if (timer == 0) {
            if (entity_state[index] == Stun) entity_state[index] = Normal;
            entity_timer[index] = lfsr_val[index] & 0x3c;
            tmp = lfsr_val[index] & 3;
            entity_facing[index] = tmp;
            entity_vx[index] = (tmp&1) ? 0x100 : -0x100;
            entity_vy[index] = (tmp&2) ? 0x100 : -0x100;
        }
        entity_collide();
        entity_sprite[index] = SPR_SKULL + (tick & 1);
        break;
    }
}

void entity_all(void) {
    for(index=0; index<NUM_ENTITIES; ++index) {
        if (index && !entity_id[index]) continue;
        if (index) {
            entity_display();
        } else {
            player_display();
        }
        entity_ai();
        entity_move();
    }
}
