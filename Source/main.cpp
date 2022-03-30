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
	std::cout << "					Таблица записей" << std::endl;
	int i = 1;
	for (auto item : table) {
		std::cout << "Номер записи:" << i << std::endl;
		std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
		item.second->printTransport();
		std::cout << std::endl;
		i++;
	}
}

void printDataBaseInfile(myVec table) {
	std::fstream inOut;
	inOut.open("file.txt", std::ios::out);
	inOut << "					Таблица записей" << std::endl;
	int i = 1;
	for (auto item : table){
		inOut << "Номер записи:" << i << std::endl;
		inOut << "Уникальный идентификатор транспорта:" <<item.first << std::endl;
		inOut << "Тип транспорта:" << item.second->typeTransport << std::endl;
		inOut << "Вес транспорта:" << item.second->weight << std::endl;
		inOut << "Год выпуска транспорта:" << item.second->yearManufacture << std::endl;
		inOut << "Марка транспорта:" << item.second->brand << std::endl;
		inOut << "Модель транспорта:" << item.second->model << std::endl;
		if (item.second->typeTransport == "Машина") {
			std::shared_ptr<Car> temp = std::dynamic_pointer_cast<Car>(item.second);
			inOut << "Объём двигателя:" << temp->engineSize << std::endl;
			inOut << "Количество лошадиных сил:" << temp->horsepower << std::endl;
		}
		else if (item.second->typeTransport == "Самолёт") {
			std::shared_ptr<Plane> temp = std::dynamic_pointer_cast<Plane>(item.second);
			inOut << "Размах крыла:" << temp->wingspan << std::endl;
			inOut << "Грузоподъемность:" << temp->loadCapacity << std::endl;
		}
		else if (item.second->typeTransport == "Катер") {
			std::shared_ptr<Boat> temp = std::dynamic_pointer_cast<Boat>(item.second);
			inOut << "Глубина погружения винта:" << temp->screwInmmersionDepth << std::endl;
		}
		else if (item.second->typeTransport == "Космический корабль") {
			std::shared_ptr<Spaceship> temp = std::dynamic_pointer_cast<Spaceship>(item.second);
			inOut << "Тип топлива:" << temp->fuelType << std::endl;
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
		if (str.length() &&  vec[1] == "Машина") {
			for (int i = 0; i < 2; i++,j++) {
				getline(inOut, str);
				found = str.find(':');
				vec[j] = str.substr(found + 1);
			}
			std::shared_ptr<Car> a(new Car());
			a->fileFillCar(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		else if (str.length() && vec[1] == "Самолёт") {
			for (int i = 0; i < 2; i++,j++) {
				getline(inOut, str);
				found = str.find(':');
				vec[j] = str.substr(found + 1);
			}
			std::shared_ptr<Plane> a(new Plane());
			a->fileFillPlane(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		else if (str.length() && vec[1] == "Катер") {
			getline(inOut, str);
			found = str.find(':');
			vec[j] = str.substr(found + 1);
			j++;
			std::shared_ptr<Boat> a(new Boat());
			a->fileFillBoat(vec);
			dataBase.push_back({ std::stoi(vec[0]),a });
		}
		else if (str.length() && vec[1] == "Космический корабль" ) {
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
	int k = 1; // Переменная для работы цикла
	int choice;// Переменная для выбора с действиями таблицы
	int typeChoice; // Переменная для выбора типа траснпорта, который хотим создать
	myVec dataBase; // Таблица записей
	
	while (k) {
		std::cout << "Нажмите 1, если хотите создать запись транспортного средства." << std::endl
			<< "Нажмите 2, если хотите редактировать запись транспортного средства." << std::endl
			<< "Нажмите 3, если хотите удалить запись транспортного средства." << std::endl
			<< "Нажмите 4, если хотите отобразить весь список записей с сортировкой по выбранному полю." << std::endl
			<< "Нажмите 5, если выполнить поиск по выбранному полю." << std::endl 
			<< "Нажмите 6, если хотите сохранить все записи в файл." << std::endl
			<< "Нажмите 7, если хотите загрузить все записи из файла." << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
		{	
			std::cout << "Нажмите 1, если хотите создать машину." << std::endl
				<< "Нажмите 2, если хотите создать самолет." << std::endl
				<< "Нажмите 3, если хотите создать катер." << std::endl
				<< "Нажмите 4, если хотите создать космический корабль." << std::endl;
			std::cin >> typeChoice;
			int uniqueIdentificator;
			std::cout << "Введите уникальный идентификатор транспорта:";
			std::cin >> uniqueIdentificator;
			switch (typeChoice) {
			case 1:
			{
				std::shared_ptr<Car> a(new Car());
				a->typeTransport = "Машина";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
			case 2:
			{
				std::shared_ptr<Plane> a(new Plane());
				a->typeTransport = "Самолёт";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
			case 3:
			{
				std::shared_ptr<Boat> a(new Boat());
				a->typeTransport = "Катер";
				a->fillBlank();
				dataBase.push_back({ uniqueIdentificator,a });
				break;
			}
			case 4: 
			{
				std::shared_ptr<Spaceship> a(new Spaceship());
				a->typeTransport = "Космический корабль";
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
			std::cout << "Введите уникальный индетификатор транспорта, информацию о котором вы хотите отредактировать:";
			std::cin >> uniqueIdentificator;

			for (auto iter = dataBase.begin(); iter != dataBase.end();iter++) {
				if (uniqueIdentificator == iter->first) it = iter;
			}
			std::cout << "Введите 1, если хотите измениить уникальный идентификатор."<<std::endl
				<< "Введите 2, если хотите изменить вес транспорта." << std::endl
				<< "Введите 3, если хотите изменить год выпуска." << std::endl
				<< "Введите 4, если хотите изменить марку транспорта." << std::endl
				<< "Введите 5, если хотите изменить модель транспорта." << std::endl
				<< "Введите 6, если хотите изменить дополнительные свойства транспорта." << std::endl;
			int choiceChange;
			std::cin >> choiceChange;
			switch (choiceChange) {
			case 1:
				std::cout << "Введите уникальный идентификатор транспорта:";
				std::cin >> it->first;
				break;
			case 2:
				std::cout << "Введите новый вес транспорта:";
				std::cin >> it->second->weight;
				break;
			case 3:
				std::cout << "Введите новый год выпуска:";
				std::cin >> it->second->yearManufacture;
				break;
			case 4:
				std::cout << "Введите новую марку транспорта:";
				std::cin >> it->second->brand;
				break;
			case 5:
				std::cout << "Введите новую модель транспорта:";
				std::cin >> it->second->model;
				break;
			case 6:
			{
				if (it->second->typeTransport == "Машина") {
					std::shared_ptr<Car> temp = std::dynamic_pointer_cast<Car>(it->second);
					int res;
					std::cout << "Введите 1 - если хотите изменить объём двигателя, 0 - если хотите изменить количество лошадиных сил." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "Введите новый объём двигателя транспорта:";
						std::cin>>temp->engineSize;
					}
					else {
						std::cout << "Введите новое количество лошадиных сил транспорта:";
						std::cin>>temp->horsepower;
					}
				}
				else if (it->second->typeTransport == "Самолёт") {
					std::shared_ptr<Plane> temp(std::dynamic_pointer_cast<Plane>(it->second));
					int res;
					std::cout << "Введите 1 - если хотите изменить размах крыла, 0 - если хотите изменить грузоподъемность." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "Введите новый размах крыла транспорта:";
						std::cin>>temp->wingspan;
					}
					else {
						std::cout << "Введите новую грузоподъемность транспорта:";
						std::cin>>temp->loadCapacity;
					}
				}
				else if (it->second->typeTransport == "Катер") {
					std::shared_ptr<Boat> temp(std::dynamic_pointer_cast<Boat>(it->second));
					std::cout << "Введите новую глубину погружения винта:";
					std::cin>>temp->screwInmmersionDepth;
				}
				else if (it->second->typeTransport == "Космический корабль") {
					std::shared_ptr<Spaceship> temp(std::dynamic_pointer_cast<Spaceship>(it->second));
					std::cout << "Введите новый тип топлива:";
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
			std::cout << "Введите уникальный индетификатор транспорта, запись о котором вы хотите удалить:";
			std::cin >> uniqueIdentificator;
			for (auto iter = dataBase.begin(); iter != dataBase.end();iter++) {
				if (uniqueIdentificator == iter->first) it = iter;
			}
			dataBase.erase(it);
			break;
		}
		
		case 4:
		{
			std::cout << "Введите 1, если хотите сделать сортировку по уникальному идентификатору." << std::endl
				<< "Введите 2, если хотите сделать сортировку по весу транспорта." << std::endl
				<< "Введите 3, если хотите сделать сортировку по году выпуска." << std::endl
				<< "Введите 4, если хотите сделать сортировку по марке транспорта." << std::endl
				<< "Введите 5, если хотите сделать сортировку по модели транспорта." << std::endl
				<< "Введите 6, если хотите сделать сортировку по типу транспорта." << std::endl;
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
			std::cout << "Введите 1, если хотите сделать поиск по уникальному идентификатору." << std::endl
				<< "Введите 2, если хотите сделать поиск по весу транспорта." << std::endl
				<< "Введите 3, если хотите сделать поиск по году выпуска." << std::endl
				<< "Введите 4, если хотите сделать поиск по марке транспорта." << std::endl
				<< "Введите 5, если хотите сделать поиск по модели транспорта." << std::endl
				<< "Введите 6, если хотите сделать поиск по типу транспорта." << std::endl;
			int searchChoice;
			int temp = 1;
			std::cin >> searchChoice;
			switch (searchChoice) {
			case 1:
			{
				int searchUniqueId;
				std::cout << "Введите уникальный идентификатор (числовой) транспорта:";
				std::cin >> searchUniqueId;
				for (auto item : dataBase) {
					if (item.first == searchUniqueId) {
						std::cout << "Номер записи:" << temp << std::endl;
						std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
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
				std::cout << "Введите вес транспорта:";
				std::cin >> searchWeight;
				for (auto item : dataBase) {
					if (item.second->weight == searchWeight) {
						std::cout << "Номер записи:" << temp << std::endl;
						std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
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
				std::cout << "Введите год выпуска транспорта:";
				std::cin >> searchYear;
				for (auto item : dataBase) {
					if (item.second->yearManufacture == searchYear) {
						std::cout << "Номер записи:" << temp << std::endl;
						std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
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
				std::cout << "Введите марку транспорта:";
				std::cin >> searchBrand;
				for (auto item : dataBase) {
					if (item.second->brand == searchBrand) {
						std::cout << "Номер записи:" << temp << std::endl;
						std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
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
				std::cout << "Введите модель транспорта:";
				std::cin >> searchModel;
				for (auto item : dataBase) {
					if (item.second->model == searchModel) {
						std::cout << "Номер записи:" << temp << std::endl;
						std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
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
				std::cout << "Введите тип транспорта:";
				std::cin >> searchTypeTtransport;
				for (auto item : dataBase) {
					if (item.second->typeTransport == searchTypeTtransport) {
						std::cout << "Номер записи:" << temp << std::endl;
						std::cout << "Уникальный идентификатор транспорта:" << item.first << std::endl;
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
		std::cout << "Нажмите 1 - если хотите совершить какие-то дальнейшие действия с таблицей, 0 - если хотите завершить программу."<<std::endl;
		std::cin >> k;
	}
}

