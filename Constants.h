#pragma once
#ifndef H_CONSTANTS
#define H_CONSTANTS

#include <raylib.h>

#define TAU (6.283185307)

#define MS_PER_UPDATE (16) // 60 FPS -> 16.66

#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (800)
#define DELTA_T (0.001f)


typedef struct Mouse {
    Vector2 Position;
    
} Mouse;

#endif