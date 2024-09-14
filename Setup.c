#include "Setup.h"

extern Vector2 Origin;
extern Camera2D C;
extern Signal Setpoint;

int InitCamera(Camera2D* Ca) {
    Ca->target = Origin;
    Ca->offset = (Vector2){ (WINDOW_WIDTH / 2.0f), (WINDOW_HEIGHT / 2.0f) };
    Ca->rotation = 0.0f;
    Ca->zoom = 1.0f;
}

int Setup(void) {

    // Initialize the window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "");

    // Set window properties
    SetTraceLogLevel(LOG_ERROR);
    SetTargetFPS(60);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    DisableCursor();

    // Initialize the camera
    InitCamera(&C);

    // PIDInit(&P);
    // PIDPrint(P);

    SignalInit(&Setpoint);
    // ApplyFunction(&Setpoint, TestFunctionBigSine);

    // DEBUG: Initialize the setpoint and print it
    // DefaultSignal(&Setpoint);
    // SignalPrint(Setpoint);

    return 0;
}
