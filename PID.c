#include "PID.h"

const float PID_MIN = -100.0f;
const float PID_MAX = 100.0f;
const float PID_INT_MIN = -10.0f;
const float PID_INT_MAX = 10.0f;

int PIDInit(PID* P) {
    
    // Initialize the gains.
    P->Kp = 0.0f;
    P->Ki = 0.0f;
    P->Kd = 0.0f;

    // Initialize the min/max values.
    P->Min = PID_MIN;
    P->Max = PID_MAX;

    // Initialize the integrator values.
    P->Int = 0.0f;
    P->IntMin = PID_INT_MIN;
    P->IntMax = PID_INT_MAX;
    P->PreviousError = 0.0f;

    // Initialize the differentiator values.
    P->Diff = 0.0f;
    P->PreviousMeasurement = 0.0f;

    // Initialize the output to zero.
    P->Output = 0.0f;

    return 0;
}

int PIDStep(PID* P, float Setpoint, float Measurement) {

    float Error = Setpoint - Measurement;

    float ProportialTerm = P->Kp * Error;


    float IntegralTerm = P->Ki * Error;// * Dt;


    float DerivativeTerm = (Error - P->PreviousError);// / Dt;


    // Update the PID

    P->PreviousMeasurement = ProportialTerm + IntegralTerm + DerivativeTerm;
    P->PreviousError = Error;
    P->Output = P->PreviousMeasurement;

    return 0;
}

void PIDPrint(const PID P) {
    printf("[%.2f, %.2f, %.2f] ", P.Kp, P.Ki, P.Kd);
    printf("[%.2f <%.2f> %.2f] ", P.Min, P.Output, P.Max);
    printf("[%.2f <%.2f> %.2f] (%.2f) ", P.IntMin, P.Int, P.IntMax, P.PreviousError);
    printf("[%.2f] %.2f\n", P.Diff, P.PreviousMeasurement);
}
