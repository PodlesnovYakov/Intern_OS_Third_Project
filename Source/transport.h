#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Transport
{
public:
	std::string typeTransport;
	int weight;
	int yearManufacture;
	std::string brand;
	std::string model;
	virtual void printTransport();
	virtual void fillBlank();
	
};

