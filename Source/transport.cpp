#include "transport.h"

void Transport::printTransport()
{
		std::cout << "��� ����������:" << typeTransport << std::endl;
		std::cout << "��� ����������:" << weight << std::endl;
		std::cout << "��� ������� ����������:" << yearManufacture << std::endl;
		std::cout << "����� ����������:" << brand << std::endl;
		std::cout << "������ ����������:" << model << std::endl;
}
void Transport::fillBlank() {
	std::cout << "������� ��� ����������:";
	std::cin >> weight;
	std::cout << "������� ��� �������:";
	std::cin >> yearManufacture;
	std::cout << "������� ����� ����������:";
	std::cin >> brand;
	std::cout << "������� ������ ����������:";
	std::cin >> model;
}

