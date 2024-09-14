#pragma once
#ifndef H_PID
#define H_PID

#include <stdio.h>

/// @brief A PID controller.
/// @param Kp The proportional gain.
/// @param Ki The integral gain.
/// @param Kd The derivative gain.
/// @param Min The minimum output (to prevent windup).
/// @param Max The maximum output (to prevent windup).
/// @param Int The integrator value.
/// @param IntMin The minimum integrator value.
/// @param IntMax The maximum integrator value.
/// @param PreviousError The previous error.
/// @param Diff The differentiator value.
/// @param PreviousMeasurement The prvious measurement.
/// @param Output The PID output.
typedef struct PID {
    float Kp;
    float Ki;
    float Kd;
    float Min;
    float Max;
    float Int;
    float IntMin;
    float IntMax;
    float PreviousError;
    float Diff;
    float PreviousMeasurement;
    float Output;
} PID;

int PIDInit(PID* P);
int PIDStep(PID* P, float Setpoint, float Measurement);
void PIDPrint(const PID P);

#endif