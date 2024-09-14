#include "CircularBuffer.h"

int CircularBufferAddData(CircularBuffer* CB, float Data) {

    if (CB == NULL) ERROR("Cannot add data to null CircularBuffer!");

    uint16_t CurrentPointer = CB->Pointer;

    CB->Data[(CurrentPointer % 4096)] = Data;
    CB->Pointer += 1;
    CB->Pointer %= 4096;

    return 0;
}

int CircularBufferAddDataArray(CircularBuffer* CB, float* DataArray, uint16_t DataSize) {

    // TODO: This could be improved with memcpy()
    // A memcpy solution would need a bit more logic
    // to handle wrap arounds!

    if (CB == NULL) ERROR("Cannot add data to null CircularBuffer!");
    if (DataArray == NULL) ERROR("Cannot read data from null DataArray!");

    for (uint16_t Index = 0; Index < DataSize; Index++)
        CircularBufferAddData(CB, DataArray[Index]);

    return 0;
}