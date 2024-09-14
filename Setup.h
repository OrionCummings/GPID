#pragma once
#ifndef H_SETUP
#define H_SETUP

#include <raylib.h>
#include "Signal.h"
#include "Constants.h"

/// @brief A setup function that initializes everything the program needs to operate smoothly.
/// @return An non zero integer indicating failure or zero indicating success.
int Setup(void);

#endif