#include "Boat.h"
void Boat::printTransport() {
	Transport::printTransport();
	std::cout << "������� ���������� �����:" << screwInmmersionDepth << std::endl;
}
void Boat::fillBlank() {
	Transport::fillBlank();
	std::cout << "������� ������� ���������� ����� ����������:";
	std::cin >> screwInmmersionDepth;
}
void Boat::fileFillBoat(std::vector<std::string>vec) {
	typeTransport = vec[1];
	weight = std::stoi(vec[2]);
	yearManufacture = std::stoi(vec[3]);
	brand = vec[4];
	model = vec[5];
	screwInmmersionDepth = std::stoi(vec[6]);
}
