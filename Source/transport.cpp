#include "transport.h"

void Transport::printTransport()
{
		std::cout << "Тип транспорта:" << typeTransport << std::endl;
		std::cout << "Вес транспорта:" << weight << std::endl;
		std::cout << "Год выпуска транспорта:" << yearManufacture << std::endl;
		std::cout << "Марка транспорта:" << brand << std::endl;
		std::cout << "Модель транспорта:" << model << std::endl;
}
void Transport::fillBlank() {
	std::cout << "Введите вес транспорта:";
	std::cin >> weight;
	std::cout << "Введите год выпуска:";
	std::cin >> yearManufacture;
	std::cout << "Введите марку транспорта:";
	std::cin >> brand;
	std::cout << "Введите модель транспорта:";
	std::cin >> model;
}

