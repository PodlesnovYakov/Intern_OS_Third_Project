#include "Spaceship.h"
void Spaceship::printTransport() {
	Transport::printTransport();
	std::cout << "Тип топлива:" << fuelType << std::endl;
}
void Spaceship::fillBlank() 
{
	Transport::fillBlank();
	std::cout << "Введите тип топлива транспорта:";
	std::cin >> fuelType;
}
void Spaceship::fileFillSpaceship(std::vector<std::string> vec) {
	typeTransport = vec[1];
	weight = std::stoi(vec[2]);
	yearManufacture = std::stoi(vec[3]);
	brand = vec[4];
	model = vec[5];
	fuelType = vec[6];
}