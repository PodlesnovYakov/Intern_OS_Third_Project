#include "Plane.h"
void Plane::printTransport() {
	Transport::printTransport();
	std::cout << "Размах крыла:" << wingspan << std::endl;
	std::cout << "Грузоподъёмность:" << loadCapacity << std::endl;
}
void Plane::fillBlank() {
	Transport::fillBlank();
	std::cout << "Введите грузоподъмность транспорта:";
	std::cin >> loadCapacity;
	std::cout << "Введите размах крыла транспорта:";
	std::cin >> wingspan;
}
void Plane::fileFillPlane(std::vector<std::string> vec) {
	typeTransport = vec[1];
	weight = std::stoi(vec[2]);
	yearManufacture = std::stoi(vec[3]);
	brand = vec[4];
	model = vec[5];
	wingspan = std::stoi(vec[6]);
	loadCapacity = std::stoi(vec[7]);
}
