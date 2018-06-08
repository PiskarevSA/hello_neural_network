#include <iostream>

#include "hello_neural_network/party.h"

int main(int /*argc*/, char */*argv*/[])
{
    std::cout << "Hello neural network project" << std::endl;

    for (int i = 0; i < 8; ++i)
    {
        bool vodka = i & 1;
        bool rain = i & 2;
        bool friend_ = i & 4;
        bool prediction = hello_neural_network::party::predict(vodka, rain, friend_);
        std::cout << "vodka: " << vodka << ", rain: " << rain << ", friend: " << friend_ <<
                     "  --->  prediction: " << prediction << std::endl;
    }

    return 0;
}
