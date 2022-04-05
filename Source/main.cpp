#include "Car.h"
#include "Plane.h"
#include "Boat.h"
#include "Spaceship.h"
#include "transport.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <fstream>
typedef std::vector<std::pair<int, std::shared_ptr<Transport>>> myVec;
typedef std::vector<std::pair<int, std::shared_ptr<Transport>>>::iterator myIter;
typedef std::pair<int, std::shared_ptr<Transport>> para;

void printDataBase(myVec table) {
	std::cout << "					������� �������" << std::endl;
	int i = 1;
	for (auto item : table) {
		std::cout << "����� ������:" << i << std::endl;
		std::cout << "���������� ������������� ����������:" << item.first << std::endl;
		item.second->printTransport();
		std::cout << std::endl;
		i++;
	}
}

void printDataBaseInfile(myVec table) {
	std::fstream inOut;
	inOut.open("file.txt", std::ios::out);
	inOut << "					������� �������" << std::endl;
	int i = 1;
	for (auto item : table){
		inOut << "����� ������:" << i << std::endl;
		inOut << "���������� ������������� ����������:" <<item.first << std::endl;
		inOut << "��� ����������:" << item.second->typeTransport << std::endl;
		inOut << "��� ����������:" << item.second->weight << std::endl;
		inOut << "��� ������� ����������:" << item.second->yearManufacture << std::endl;
		inOut << "����� ����������:" << item.second->brand << std::endl;
		inOut << "������ ����������:" << item.second->model << std::endl;
		if (item.second->typeTransport == "������") {
			std::shared_ptr<Car> temp = std::dynamic_pointer_cast<Car>(item.second);
			inOut << "����� ���������:" << temp->engineSize << std::endl;
			inOut << "���������� ��������� ���:" << temp->horsepower << std::endl;
		}
		else if (item.second->typeTransport == "������") {
			std::shared_ptr<Plane> temp = std::dynamic_pointer_cast<Plane>(item.second);
			inOut << "������ �����:" << temp->wingspan << std::endl;
			inOut << "����������������:" << temp->loadCapacity << std::endl;
		}
		else if (item.second->typeTransport == "�����") {
			std::shared_ptr<Boat> temp = std::dynamic_pointer_cast<Boat>(item.second);
			inOut << "������� ���������� �����:" << temp->screwInmmersionDepth << std::endl;
		}
		else if (item.second->typeTransport == "����������� �������") {
			std::shared_ptr<Spaceship> temp = std::dynamic_pointer_cast<Spaceship>(item.second);
			inOut << "��� �������:" << temp->fuelType << std::endl;
		}
		i++;
		inOut << std::endl;
	}
	inOut.close();
}
void fillDataBaseOutFile(myVec& dataBase) {
	std::ifstream inOut;
	inOut.open("file.txt", std::ios::in);
	std::vector<std::string> vec(10);
	std::string str;
	std::string str2;
	int found;
	int count = 8;
	int j = 0;
	while (getline(inOut, str)) {
		count--;
		while(count){
			getline(inOut, str);
			if (count <= 6 && str.length()) {
				found = str.find(':');
				vec[j] = str.substr(found + 1);
				j++;
			}
			count--;
		}
		if (str.length() &&  vec[1] == "������") {
			for (int i = 0; i < 2; i++,j++) {
				getline(inOut, str);
				found = str.find(':');
				vec[j] = str.substr(found + 1);
			}
			std::shared_ptr<Car> a(new Car());
			a->fileFillCar(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		else if (str.length() && vec[1] == "������") {
			for (int i = 0; i < 2; i++,j++) {
				getline(inOut, str);
				found = str.find(':');
				vec[j] = str.substr(found + 1);
			}
			std::shared_ptr<Plane> a(new Plane());
			a->fileFillPlane(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		else if (str.length() && vec[1] == "�����") {
			getline(inOut, str);
			found = str.find(':');
			vec[j] = str.substr(found + 1);
			j++;
			std::shared_ptr<Boat> a(new Boat());
			a->fileFillBoat(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		else if (str.length() && vec[1] == "����������� �������" ) {
			getline(inOut, str);
			found = str.find(':');
			vec[j] = str.substr(found + 1);
			j++;
			std::shared_ptr<Spaceship> a(new Spaceship());
			a->fileFillSpaceship(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		count = 8;
		j = 0;
	}
	inOut.close();
}
bool comp_id(para a, para b) {
	return a.first < b.first;
}
bool comp_type(para a, para b) {
	return a.second->typeTransport < b.second->typeTransport;
}
bool comp_weight(para a, para b) {
	return a.second->weight < a.second->weight;
}
bool comp_year(para a, para b) {
	return a.second->yearManufacture < b.second->yearManufacture;
}
bool comp_brand(para a, para b) {
	return a.second->brand < b.second->brand;
}
bool comp_model(para a, para b) {
	return a.second->model < b.second->model;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k = 1; // ���������� ��� ������ �����
	int choice;// ���������� ��� ������ � ���������� �������
	int typeChoice; // ���������� ��� ������ ���� ����������, ������� ����� �������
	myVec dataBase; // ������� �������
	
	while (k) {
		std::cout << "������� 1, ���� ������ ������� ������ ������������� ��������." << std::endl
			<< "������� 2, ���� ������ ������������� ������ ������������� ��������." << std::endl
			<< "������� 3, ���� ������ ������� ������ ������������� ��������." << std::endl
			<< "������� 4, ���� ������ ���������� ���� ������ ������� � ����������� �� ���������� ����." << std::endl
			<< "������� 5, ���� ��������� ����� �� ���������� ����." << std::endl 
			<< "������� 6, ���� ������ ��������� ��� ������ � ����." << std::endl
			<< "������� 7, ���� ������ ��������� ��� ������ �� �����." << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
		{	
			std::cout << "������� 1, ���� ������ ������� ������." << std::endl
				<< "������� 2, ���� ������ ������� �������." << std::endl
				<< "������� 3, ���� ������ ������� �����." << std::endl
				<< "������� 4, ���� ������ ������� ����������� �������." << std::endl;
			std::cin >> typeChoice;
			int uniqueIdentificator;
			std::cout << "������� ���������� ������������� ����������:";
			std::cin >> uniqueIdentificator;
			switch (typeChoice) {
			case 1:
			{
				std::shared_ptr<Car> a(new Car());
				a->typeTransport = "������";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
			case 2:
			{
				std::shared_ptr<Plane> a(new Plane());
				a->typeTransport = "������";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
			case 3:
			{
				std::shared_ptr<Boat> a(new Boat());
				a->typeTransport = "�����";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
			case 4: 
			{
				std::shared_ptr<Spaceship> a(new Spaceship());
				a->typeTransport = "����������� �������";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
		}
			break;
			
		}	
		
		case 2:
		{
			printDataBase(dataBase);
			int uniqueIdentificator;
			myIter it;
			std::cout << "������� ���������� ������������� ����������, ���������� � ������� �� ������ ���������������:";
			std::cin >> uniqueIdentificator;

			for (auto iter = dataBase.begin(); iter != dataBase.end();iter++) {
				if (uniqueIdentificator == iter->first) it = iter;
			}
			std::cout << "������� 1, ���� ������ ��������� ���������� �������������."<<std::endl
				<< "������� 2, ���� ������ �������� ��� ����������." << std::endl
				<< "������� 3, ���� ������ �������� ��� �������." << std::endl
				<< "������� 4, ���� ������ �������� ����� ����������." << std::endl
				<< "������� 5, ���� ������ �������� ������ ����������." << std::endl
				<< "������� 6, ���� ������ �������� �������������� �������� ����������." << std::endl;
			int choiceChange;
			std::cin >> choiceChange;
			switch (choiceChange) {
			case 1:
				std::cout << "������� ���������� ������������� ����������:";
				std::cin >> it->first;
				break;
			case 2:
				std::cout << "������� ����� ��� ����������:";
				std::cin >> it->second->weight;
				break;
			case 3:
				std::cout << "������� ����� ��� �������:";
				std::cin >> it->second->yearManufacture;
				break;
			case 4:
				std::cout << "������� ����� ����� ����������:";
				std::cin >> it->second->brand;
				break;
			case 5:
				std::cout << "������� ����� ������ ����������:";
				std::cin >> it->second->model;
				break;
			case 6:
			{
				if (it->second->typeTransport == "������") {
					std::shared_ptr<Car> temp = std::dynamic_pointer_cast<Car>(it->second);
					int res;
					std::cout << "������� 1 - ���� ������ �������� ����� ���������, 0 - ���� ������ �������� ���������� ��������� ���." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "������� ����� ����� ��������� ����������:";
						std::cin>>temp->engineSize;
					}
					else {
						std::cout << "������� ����� ���������� ��������� ��� ����������:";
						std::cin>>temp->horsepower;
					}
				}
				else if (it->second->typeTransport == "������") {
					std::shared_ptr<Plane> temp(std::dynamic_pointer_cast<Plane>(it->second));
					int res;
					std::cout << "������� 1 - ���� ������ �������� ������ �����, 0 - ���� ������ �������� ����������������." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "������� ����� ������ ����� ����������:";
						std::cin>>temp->wingspan;
					}
					else {
						std::cout << "������� ����� ���������������� ����������:";
						std::cin>>temp->loadCapacity;
					}
				}
				else if (it->second->typeTransport == "�����") {
					std::shared_ptr<Boat> temp(std::dynamic_pointer_cast<Boat>(it->second));
					std::cout << "������� ����� ������� ���������� �����:";
					std::cin>>temp->screwInmmersionDepth;
				}
				else if (it->second->typeTransport == "����������� �������") {
					std::shared_ptr<Spaceship> temp(std::dynamic_pointer_cast<Spaceship>(it->second));
					std::cout << "������� ����� ��� �������:";
					std::cin>>temp->fuelType;
				}
			}
			}
			break;
		}
			
		case 3:
		{
			printDataBase(dataBase);
			myIter it;
			int uniqueIdentificator;
			std::cout << "������� ���������� ������������� ����������, ������ � ������� �� ������ �������:";
			std::cin >> uniqueIdentificator;
			for (auto iter = dataBase.begin(); iter != dataBase.end();iter++) {
				if (uniqueIdentificator == iter->first) it = iter;
			}
			dataBase.erase(it);
			break;
		}
		
		case 4:
		{
			std::cout << "������� 1, ���� ������ ������� ���������� �� ����������� ��������������." << std::endl
				<< "������� 2, ���� ������ ������� ���������� �� ���� ����������." << std::endl
				<< "������� 3, ���� ������ ������� ���������� �� ���� �������." << std::endl
				<< "������� 4, ���� ������ ������� ���������� �� ����� ����������." << std::endl
				<< "������� 5, ���� ������ ������� ���������� �� ������ ����������." << std::endl
				<< "������� 6, ���� ������ ������� ���������� �� ���� ����������." << std::endl;
			int choice_change;
			std::cin >> choice_change;
			switch (choice_change) {
			case 1:
				sort(dataBase.begin(), dataBase.end(), comp_id);
				break;
			case 2:
				sort(dataBase.begin(), dataBase.end(), comp_weight);
				break;
			case 3:
				sort(dataBase.begin(), dataBase.end(), comp_year);
				break;
			case 4:
				sort(dataBase.begin(), dataBase.end(), comp_brand);
				break;
			case 5:
				sort(dataBase.begin(), dataBase.end(), comp_model);
				break;
			case 6:
				sort(dataBase.begin(), dataBase.end(), comp_type);
				break;
			}
			printDataBase(dataBase);
			break;
		}
		
		case 5:
		{
			std::cout << "������� 1, ���� ������ ������� ����� �� ����������� ��������������." << std::endl
				<< "������� 2, ���� ������ ������� ����� �� ���� ����������." << std::endl
				<< "������� 3, ���� ������ ������� ����� �� ���� �������." << std::endl
				<< "������� 4, ���� ������ ������� ����� �� ����� ����������." << std::endl
				<< "������� 5, ���� ������ ������� ����� �� ������ ����������." << std::endl
				<< "������� 6, ���� ������ ������� ����� �� ���� ����������." << std::endl;
			int searchChoice;
			int temp = 1;
			std::cin >> searchChoice;
			switch (searchChoice) {
			case 1:
			{
				int searchUniqueId;
				std::cout << "������� ���������� ������������� (��������) ����������:";
				std::cin >> searchUniqueId;
				for (auto item : dataBase) {
					if (item.first == searchUniqueId) {
						std::cout << "����� ������:" << temp << std::endl;
						std::cout << "���������� ������������� ����������:" << item.first << std::endl;
						item.second->printTransport();
						std::cout << std::endl;
					}
					temp++;
				}
				break;
			}
			case 2:
			{
				int searchWeight;
				std::cout << "������� ��� ����������:";
				std::cin >> searchWeight;
				for (auto item : dataBase) {
					if (item.second->weight == searchWeight) {
						std::cout << "����� ������:" << temp << std::endl;
						std::cout << "���������� ������������� ����������:" << item.first << std::endl;
						item.second->printTransport();
						std::cout << std::endl;
					}
					temp++;
				}
				break;
			}
			case 3:
			{
				int searchYear;
				int temp = 1;
				std::cout << "������� ��� ������� ����������:";
				std::cin >> searchYear;
				for (auto item : dataBase) {
					if (item.second->yearManufacture == searchYear) {
						std::cout << "����� ������:" << temp << std::endl;
						std::cout << "���������� ������������� ����������:" << item.first << std::endl;
						item.second->printTransport();
						std::cout << std::endl;
					}
					temp++;
				}
				break;
			}
			case 4:
			{
				int temp = 1;
				std::string searchBrand;
				std::cout << "������� ����� ����������:";
				std::cin >> searchBrand;
				for (auto item : dataBase) {
					if (item.second->brand == searchBrand) {
						std::cout << "����� ������:" << temp << std::endl;
						std::cout << "���������� ������������� ����������:" << item.first << std::endl;
						item.second->printTransport();
						std::cout << std::endl;
					}
					temp++;
				}
				break;
			}
			case 5:
			{
				int temp = 1;
				std::string searchModel;
				std::cout << "������� ������ ����������:";
				std::cin >> searchModel;
				for (auto item : dataBase) {
					if (item.second->model == searchModel) {
						std::cout << "����� ������:" << temp << std::endl;
						std::cout << "���������� ������������� ����������:" << item.first << std::endl;
						item.second->printTransport();
						std::cout << std::endl;
					}
					temp++;
				}
				break;
			}
			case 6:
			{
				std::string searchTypeTtransport;
				std::cout << "������� ��� ����������:";
				std::cin >> searchTypeTtransport;
				for (auto item : dataBase) {
					if (item.second->typeTransport == searchTypeTtransport) {
						std::cout << "����� ������:" << temp << std::endl;
						std::cout << "���������� ������������� ����������:" << item.first << std::endl;
						item.second->printTransport();
						std::cout << std::endl;
					}
					temp++;
				}
				break;
			}
			}
			break;
		}
		case 6:
		{
			printDataBaseInfile(dataBase);
			break;
		}
		case 7:
			fillDataBaseOutFile(dataBase);
			break;
		}
		std::cout << "������� 1 - ���� ������ ��������� �����-�� ���������� �������� � ��������, 0 - ���� ������ ��������� ���������."<<std::endl;
		std::cin >> k;
	}
}

