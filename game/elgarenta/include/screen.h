#pragma once

#include <stdint.h>

#include "../raylib/src/raylib.h"

#pragma pack(push, 1)
typedef struct {
    uint16_t tileList[30][28];
} oamBackground_t;
typedef struct {
    uint8_t x;
    uint8_t y;
    uint16_t tileID;
} oamSprite_t;
typedef struct {
    oamSprite_t tileList[30][28];
} oamForeground_t;
typedef struct {
    RenderTexture2D texture;
    oamBackground_t background;
    oamForeground_t foreground;
} screen_t;
typedef struct {
    screen_t *main;
    screen_t *up;
    screen_t *left;
    screen_t *down;
    screen_t *right;
    RenderTexture2D pipeline;
} screenSet_t;
#pragma pack(pop)

void __screen_loadTileset(const char *filename);
void __screen_init(void);
void __screen_onExit(void);
void __screen_render(void);