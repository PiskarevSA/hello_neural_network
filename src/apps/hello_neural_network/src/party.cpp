#include "hello_neural_network/party.h"

#include <array>

#include "hello_neural_network/activation_functions.h"
#include "hello_neural_network/matrix.h"

namespace hello_neural_network {

namespace party {

bool predict(bool vodka, bool rain, bool friend_)
{
    auto fCast = [](bool value) {return static_cast<float>(value);};

    auto inputs = Matrix<1, 3, float>{fCast(vodka), fCast(rain), fCast(friend_)};
    auto hiddenLayerWeights = Matrix<3, 2, float>{0.25f, 0.5f,
                                                  0.25f, -0.4f,
                                                  0.0f, 0.9f};
    auto outputLayerWeights = Matrix<2, 1, float>{-1.0f,
                                                  1.0f};

    auto hidden = inputs * hiddenLayerWeights;
    for (float& value : hidden.values)
        value = activation_functions::roundToBoolean(value);

    auto output = hidden * outputLayerWeights;
    float outputValue = activation_functions::roundToBoolean(output.values[0]);
    bool result = outputValue >= 0.5;
    return result;
}

} // namespace party

} // namespace hello_neural_network

