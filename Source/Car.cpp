#include "Car.h"
void Car::printTransport() {
	Transport::printTransport();
	std::cout << "����� ���������:" << engineSize << std::endl;
	std::cout << "���������� ��������� ���:" << horsepower << std::endl;
}
void Car::fillBlank(){
	Transport::fillBlank();
	std::cout << "������� ����� ��������� ����������:";
	std::cin >> engineSize;
	std::cout << "������� ���������� ��������� ��� ����������:";
	std::cin >> horsepower;
}
void Car::fileFillCar(std::vector<std::string> vec) {
	typeTransport = vec[1];
	weight = std::stoi(vec[2]);
	yearManufacture = std::stoi(vec[3]);
	brand = vec[4];
	model = vec[5];
	engineSize = std::stoi(vec[6]);
	horsepower = std::stoi(vec[7]);
}
