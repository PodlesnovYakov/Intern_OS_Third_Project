#pragma once
#include "transport.h"
class Spaceship :
    public Transport
{
public:
    std::string fuelType;
    void printTransport() override;
    void fillBlank() override;
    void fileFillSpaceship(std::vector<std::string>);
};

