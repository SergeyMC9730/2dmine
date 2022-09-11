#include "../include/screen.h"

Texture2D screenTileset;
bool screenTilesetLoaded = false;
// uint16_t oam[30][28] = {};
screenSet_t ScreenSet = {};

void __screen_loadTileset(const char *filename) {
    screenTileset = LoadTexture(filename);
    screenTilesetLoaded = true;
}
void __screen_init(void) {
    ScreenSet.main = (screen_t *)MemAlloc(sizeof(screen_t));
    ScreenSet.main->texture = LoadRenderTexture(256, 224);
    ScreenSet.up = (screen_t *)MemAlloc(sizeof(screen_t));
    ScreenSet.up->texture = LoadRenderTexture(256, 224);
    ScreenSet.down = (screen_t *)MemAlloc(sizeof(screen_t));
    ScreenSet.down->texture = LoadRenderTexture(256, 224);
    ScreenSet.left = (screen_t *)MemAlloc(sizeof(screen_t));
    ScreenSet.left->texture = LoadRenderTexture(256, 224);
    ScreenSet.right = (screen_t *)MemAlloc(sizeof(screen_t));
    ScreenSet.right->texture = LoadRenderTexture(256, 224);

    ScreenSet.pipeline = LoadRenderTexture(256, 224);
    SetTargetFPS(60);
}
void __screen_onExit(void) {
    if(ScreenSet.down) {
        UnloadRenderTexture(ScreenSet.down->texture);
        MemFree(ScreenSet.down);
    }
    if(ScreenSet.up) {
        UnloadRenderTexture(ScreenSet.up->texture);
        MemFree(ScreenSet.up);
    }
    if(ScreenSet.left) {
        UnloadRenderTexture(ScreenSet.left->texture);
        MemFree(ScreenSet.left);
    }
    if(ScreenSet.right) {
        UnloadRenderTexture(ScreenSet.right->texture);
        MemFree(ScreenSet.right);
    }
    if(ScreenSet.main) {
        UnloadRenderTexture(ScreenSet.main->texture);
        MemFree(ScreenSet.main);
    }
    if(screenTilesetLoaded) UnloadTexture(screenTileset);
    UnloadRenderTexture(ScreenSet.pipeline);
}

float ttx = 0;
float tty = 0;

void __screen_render(void) {
    BeginDrawing();

    BeginTextureMode(ScreenSet.main->texture);
    ClearBackground(RED);
    DrawText("hi", 0, 0, 10, LIGHTGRAY);
    EndTextureMode();
    if(ScreenSet.down) {
        BeginTextureMode(ScreenSet.down->texture);
        ClearBackground(GREEN);
        DrawText("hi", 0, 0, 10, LIGHTGRAY);
        EndTextureMode();
    }
    if(ScreenSet.down) {
        BeginTextureMode(ScreenSet.up->texture);
        ClearBackground(BLUE);
        DrawText("hi", 0, 0, 10, LIGHTGRAY);
        EndTextureMode();
    }
    if(ScreenSet.right) {
        BeginTextureMode(ScreenSet.down->texture);
        ClearBackground(WHITE);
        DrawText("hi", 0, 0, 10, LIGHTGRAY);
        EndTextureMode();
    }
    if(ScreenSet.left) {
        BeginTextureMode(ScreenSet.down->texture);
        ClearBackground(BROWN);
        DrawText("hi", 0, 0, 10, LIGHTGRAY);
        EndTextureMode();
    }

    if(IsKeyDown(KEY_A)) ttx += 1;
    if(IsKeyDown(KEY_D)) ttx -= 1;
    if(IsKeyDown(KEY_W)) tty -= 1;
    if(IsKeyDown(KEY_S)) tty += 1;

    BeginTextureMode(ScreenSet.pipeline);
    ClearBackground(BLACK);
    DrawTextureEx(ScreenSet.main->texture.texture, (Vector2){ttx, tty}, 0.f, 1.f, WHITE);
    if(ScreenSet.down) {
        DrawTextureEx(ScreenSet.down->texture.texture, (Vector2){(int)ttx, (int)(224 + tty)}, 0.f, 1.f, WHITE);
    }
    if(ScreenSet.up) {
        DrawTextureEx(ScreenSet.up->texture.texture, (Vector2){(int)ttx, (int)(-224 + tty)}, 0.f, 1.f, WHITE);
    }
    if(ScreenSet.left) {
        DrawTextureEx(ScreenSet.left->texture.texture, (Vector2){(int)(224 + ttx), (int)tty}, 0.f, 1.f, WHITE);
    }
    if(ScreenSet.right) {
        DrawTextureEx(ScreenSet.right->texture.texture, (Vector2){(int)(-224 + ttx), (int)tty}, 0.f, 1.f, WHITE);
    }
    EndTextureMode();

    DrawTextureEx(ScreenSet.pipeline.texture, (Vector2){0, 0}, 0.f, 4.f, WHITE);

    EndDrawing();
}