#include "Signal.h"

void SignalInit(Signal* S) {

	// TODO: Fix magic number!
	for (uint16_t Index = 0; Index < WINDOW_WIDTH; Index++) {
		S->Data[Index] = 0.0f;
	}

	// memset(S->Data, 100.0f, sizeof(*S->Data) * 4096); // TODO: Fix this magic number!
}

void SignalPrint(const Signal S) {

	printf("Signal: {");
	for (uint16_t Index = 0; Index < WINDOW_WIDTH; Index++) {
		if (Index % 100 == 0) {
			if (Index != 0) printf(", ");
			if (Index % 64 == 0) printf("\n");
			printf("%.2f", S.Data[Index]);
		}
	}
	printf("}\n");
}


void DrawSignal(const Signal S, Vector2 Origin) {

	//BeginMode2D((Camera){});

	// TODO: Remove magic number!
	for (uint32_t Index = 0; Index < WINDOW_WIDTH; Index++) {
		DrawPixel(Index + (3 * Origin.x), S.Data[Index] + Origin.y, GREEN);
	}
}

void ApplyFunction(Signal* S, double(F(double))) {

	// TODO: Remove magic number!
	for (uint32_t Index = 0; Index < WINDOW_WIDTH; Index++) {
		S->Data[Index] = F(Index);
	}
}

double TestFunctionBigSine(double x) {
	return 100 * sin(x / 100);
}