#pragma once
#ifndef H_INPUT
#define H_INPUT

#include <stdint.h>
#include <raylib.h>
#include "Debug.h"
#include "Constants.h"

/// @brief Handles user input.
/// @return An non zero integer indicating failure or zero indicating success.
int Input(void);

/// @brief Update mouse information.
/// @param M The mouse to update.
void UpdateMouse(Mouse* M);

/// @brief Detects a double click with the given interval and reports the location.
/// @param Interval The double click interval.
/// @param TouchPosition The position of the double click.
/// @return True if a double click was detected.
bool DoubleClick(uint16_t Interval, Vector2* TouchPosition);

#endif