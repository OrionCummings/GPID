#pragma once
#ifndef H_SIGNAL
#define H_SIGNAL

#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include "Constants.h"

typedef struct Signal {
    float Data[WINDOW_WIDTH]; // TODO: Fix this magic number!
} Signal;

/// @brief Creates a default flat Signal.
/// @param S The Signal.
void SignalInit(Signal* S);

/// @brief Draws the given Signal.
/// @param S A Signal.
/// @param O The origin.
void DrawSignal(const Signal S, Vector2 O);

/// @brief Prints the given Signal.
/// @param S The Signal to be printed.
void SignalPrint(const Signal S);

/// @brief Applies a function to the given Signal.
/// @param S The Signal.
/// @param F The function from double -> double.
void ApplyFunction(Signal* S, double (F(double)));

/// @brief 100 * sin(x / 100)
/// @param x 
/// @return 
double TestFunctionBigSine(double x);

#endif