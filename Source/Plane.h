#pragma once
#include "transport.h"
#include <iostream>
class Plane:
	public Transport
{
public:
	int wingspan;
	int loadCapacity;
	void printTransport() override;
	void fillBlank() override;
	void fileFillPlane(std::vector<std::string>);
};

