#include "window.h"
#include "screen.h"
#include "../raylib/src/raylib.h"

#include <stddef.h>

void (* onFrameTick)(void);

void __window_init(const char *title) {
    InitWindow(256 * 4, 224 * 4, title);
}

void __window_start(void) 
{
    __screen_init();
    SetTraceLogLevel(LOG_DEBUG);
    while (!WindowShouldClose()) {
        __screen_render();
    }

    __screen_onExit();

    CloseWindow();
}