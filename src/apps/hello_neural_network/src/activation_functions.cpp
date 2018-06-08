#include "hello_neural_network/activation_functions.h"

namespace hello_neural_network {

float activation_functions::roundToBoolean(float x)
{
    return x >= 0.5f ? 1.0f : 0.0f;
}

} // hello_neural_network
