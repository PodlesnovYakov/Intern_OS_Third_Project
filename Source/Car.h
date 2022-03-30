#pragma once
#include "transport.h"
#include <iostream>

class Car : 
	public Transport
{
public:
	int engineSize;
	int horsepower;
	void printTransport() override;
	void fillBlank() override;
	void fileFillCar(std::vector<std::string>);
};

