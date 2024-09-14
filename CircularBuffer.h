#pragma once
#ifndef H_CIRCULARBUFFER
#define H_CIRCULARBUFFER

#include <stdint.h>
#include "Debug.h"

typedef struct CircularBuffer
{
    uint16_t Pointer;
    float Data[4096];
} CircularBuffer;

/// @brief Adds a single data point to the given CircularBuffer.
/// @param CB The CircularBuffer to edit.
/// @param Data The data point.
/// @returns 0 on success. Non-zero on failure.
int CircularBufferAddData(CircularBuffer* CB, float Data);

/// @brief Adds an array of data points to the given CircularBuffer.
/// @param CB The CircularBuffer to edit.
/// @param DataArray The data array to add to CB.
/// @param DataSize The number of data points in Data.
/// @returns 0 on success. Non-zero on failure.
int CircularBufferAddDataArray(CircularBuffer* CB, float* DataArray, uint16_t DataSize);

#endif