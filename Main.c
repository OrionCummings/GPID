#include <stdio.h>
#include <stdint.h>
#include <raylib.h>
#include "Setup.h"
#include "Input.h"
#include "Update.h"
#include "Draw.h"
#include "Debug.h"
#include "Constants.h"
#include "Signal.h"
#include "Animation.h"
#include "PID.h"
#include "Graphics.h"

Vector2 Origin = { .x = -200, .y = 0 };
Camera2D C;
Mouse M;

PID P;
Signal Setpoint;
Signal Output;

/// @brief The main function of the program. Initializes the window and contains the main event loop.
/// @param argc The number of arguments passed to the program beginning with the program name.
/// @param argv A list containing the arguments passed to the program.
/// @return An non zero integer indicating failure or zero indicating success.
int Main(int argc, char** argv) {

	// Set up everything. If this fails, then abort!
	if (Setup()) ERROR("Setup failed!");

	// Set up the timing variables
	double PreviousTime = GetTime();
	double CurrentTime = 0.0;
	double Lag = 0.0;

	// If the window is still open
	while (!WindowShouldClose()) {

		// Save the current time since window creation
		CurrentTime = GetTime();

		// Calculate the elapsed and update lag
		Lag += CurrentTime - PreviousTime;

		// Handle inputs
		if (Input()) ERROR("Input failed");

		// If the lag is greater than the allowable time step between updates
		while (Lag >= MS_PER_UPDATE) {

			// Update
			if (Update()) ERROR("Update failed");

			// Update lag
			Lag -= MS_PER_UPDATE;
		}

		// Draw
		if (Draw()) ERROR("Draw failed");

		// Update the timing variables
		PreviousTime = CurrentTime;
	}

	// Close the window and exit the program
	CloseWindow();
	printf("Exiting program\n");
	return 0;
}

/// @brief The entry point for the program.
/// @param argc The number of arguments passed to the program beginning with the program name.
/// @param argv A list containing the arguments passed to the program.
/// @return An non zero integer indicating failure or zero indicating success.
int main(int argc, char** argv) {
	return Main(argc, argv);
}