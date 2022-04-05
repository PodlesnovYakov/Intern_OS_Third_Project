#pragma once
#include "transport.h"
class Boat :
    public Transport
{
public:
    int screwInmmersionDepth;
    void printTransport() override;
    void fillBlank() override;
    void fileFillBoat(std::vector<std::string>);
};

