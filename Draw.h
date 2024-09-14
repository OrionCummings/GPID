#pragma once
#ifndef H_DRAW
#define H_DRAW

#include <raylib.h>
#include "Debug.h"
#include "Constants.h"
#include "Signal.h"
#include "Helpers.h"

#define COLOR_BACKGROUND ((Color){80, 80, 80, 255})
#define COLOR_GRID ((Color){127, 127, 127, 180})
#define COLOR_AXIS ((Color){49, 56, 76, 180})
#define COLOR_SETPOINT ((Color){30, 30, 240, 180})

typedef enum GridType {
    NONE = 0,
    LINES = 1,
    DOTS = 2,
    DOTS_AND_LINES = 3
} GridType;

/// @brief A drawing function that displays pixels to the window. Called every frame.
/// @param 
/// @return An non zero integer indicating failure or zero indicating success.
int Draw(void);

/// @brief Clears the screen to the background color.
void DrawBackground();

/// @brief Draws columns (as part of a grid).
/// @param H The height of the columns.
/// @param W The width of the columns.
/// @param GridSize The size (spacing) of the grid.
/// @param Offset The grid offset vector.
void DrawColumns(int H, int W, int GridSize, Vector2 Offset);

/// @brief Draws rows (as part of a grid).
/// @param H The height of the rows.
/// @param W The width of the rows.
/// @param GridSize The size (spacing) of the grid.
/// @param Offset The grid offset vector.
void DrawRows(int H, int W, int GridSize, Vector2 Offset);

/// @brief Draws dots (as part of a grid).
/// @param H The height of the grid.
/// @param W The width of the grid.
/// @param R The radius of the dots.
/// @param GridSize The size (spacing) of the grid.
/// @param Offset The grid offset vector.
void DrawDots(int H, int W, float R, int GridSize, Vector2 Offset);

/// @brief Draws a grid.
/// @param GridSize Determines the size of the grid.
/// @param Type Determines the type of grid.
void DrawGrid2D(int GridSize, GridType Type);

/// @brief Draws a transparent circle with an solid outline.
/// @param X The X coordinate of the circle.
/// @param Y The Y coordinate of the circle.
/// @param R The radius coordinate of the circle.
/// @param C The color coordinate of the circle.
void DrawCircleOutline(int X, int Y, float R, Color C);

/// @brief Draws a set of axis.
/// @param OffsetOrigin The offset origin to use while drawing axis.
void DrawAxis(Vector2 OffsetOrigin);

/// @brief Draws a circle around the current mouse position.
/// @param M The mouset to act on.
void DrawMouse(Mouse M);

#endif