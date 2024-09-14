#include "Draw.h"

extern Vector2 Origin;
extern Signal Setpoint;
extern Camera2D C;
extern Mouse M;

/// @brief A drawing function that displays pixels to the window. Called every frame.
/// @param 
/// @return An non zero integer indicating failure or zero indicating success.
int Draw(void){

    // Initialize drawing mode. Everything drawn between this and the ending callse
    // will be rendered in coordinate space!
    BeginDrawing();
    BeginMode2D(C);

    // Draw the background
    DrawBackground();

    // Draw the grid
    DrawGrid2D(20, DOTS);

    // Draw the graph axis
    DrawAxis(Origin);

    // Draw the setpoint
    DrawSignal(Setpoint, Origin);

    // Draw debug origin
    DrawCircleOutline(0, 0, 4, MAGENTA);

    // End 2D mode. Everything drawn after this call will be
    // in screen space!
    EndMode2D();

    // Draw the mouse position
    DrawMouse(M);

    // End drawing mode.
    EndDrawing();

    return 0;
}

void DrawBackground() {
    ClearBackground(COLOR_BACKGROUND);
}

void DrawColumns(int H, int W, int GridSize, Vector2 Offset){
    for (int X = -W/2; X <= W/2; X += GridSize) {
        DrawLine(X + Offset.x, -W/2, X + Offset.x, W/2, COLOR_GRID);
    }
}

void DrawRows(int H, int W, int GridSize, Vector2 Offset){
    for (int Y = -H/2; Y <= H/2; Y += GridSize) {
        DrawLine(-H/2, Y + Offset.y, H/2, Y + Offset.y, COLOR_GRID);
    }
}

void DrawDots(int H, int W, float R, int GridSize, Vector2 Offset) {
    for (int X = -W; X <= W; X += GridSize) {
        for (int Y = -H/2; Y <= H/2; Y += GridSize) {
            DrawCircle(X + Offset.x, Y + Offset.y, R, COLOR_GRID);
        }
    }
}

void DrawGrid2D(int GridSize, GridType Type) {

    const int W = WINDOW_WIDTH;
    const int H = WINDOW_HEIGHT;
    const float R = 1.0f;
    Vector2 Offset = { .x = (WINDOW_WIDTH % GridSize) / 2, .y = (WINDOW_HEIGHT % GridSize) / 2 };

    switch(Type) {
        case(LINES): {
            DrawColumns(W, H, GridSize, Offset);
            DrawRows(W, H, GridSize, Offset);
            break;
        }
        case(DOTS): {
            DrawDots(W, H, R, GridSize, Offset);
            break;
        }
        case(DOTS_AND_LINES): {
            DrawColumns(W, H, GridSize, Offset);
            DrawRows(W, H, GridSize, Offset);
            DrawDots(W, H, R, GridSize, Offset);
            break;
        }
        case(NONE):{ break; }
        default: {
            INFO("Unknown GridType '%u' passed to DrawGrid2D()\n", Type);
            break;
        }
    };
}

void DrawCircleOutline(int X, int Y, float R, Color C) {
    DrawCircle(X, Y, R, ColorDim(C, 0.3));
    DrawCircleLines(X, Y, R, C);
    DrawCircleLines(X, Y, R * 0.99f, C); // TODO: this is bad lol
}

void DrawAxis(Vector2 OffsetOrigin){
    DrawLine(-WINDOW_WIDTH, 0, WINDOW_WIDTH, 0, COLOR_AXIS);
    DrawLine(0, -WINDOW_HEIGHT, 0, WINDOW_HEIGHT, COLOR_AXIS);
}

void DrawMouse(Mouse M) {
    DrawCircleOutline(M.Position.x, M.Position.y, 10, ORANGE);
}



