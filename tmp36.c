#include "tmp36.h"

float TMP36_GetTemperature(uint16_t adc)
{
    float Vref = 3.3f;
    float V = (adc * Vref) / 1023.0f;

    float T = (V - 0.485714f) / 0.009714f;

    return T;
}
