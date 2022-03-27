#include "Car.h"
#include "Plane.h"
#include "Boat.h"
#include "Spaceship.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <fstream>

void fill_blank(Transport* transport) {
	std::cout << "Введите уникальный идентификатор (числовой) транспорта:";
	std::cin >> (*transport).unique_identificator;
	std::cout << "Введите вес транспорта:";
	std::cin >> (*transport).weight;
	std::cout << "Введите год выпуска:";
	std::cin >> (*transport).year_manufacture;
	std::cout << "Введите марку транспорта:";
	std::cin >> (*transport).brand;
	std::cout << "Введите модель транспорта:";
	std::cin >> (*transport).model;
}
void print_data_base(std::vector<Transport*> table) {
	std::cout << "					Таблица записей" << std::endl;
	int i = 1;
	for (auto iter = table.begin(); iter != table.end(); iter++, i++) {
		std::cout << "Номер записи:" << i << std::endl;
		std::cout << "Уникальный идентификатор транспорта:" << (*iter)->unique_identificator << std::endl;
		std::cout << "Тип транспорта:" << (*iter)->type_transport << std::endl;
		std::cout << "Вес транспорта:" << (*iter)->weight << std::endl;
		std::cout << "Год выпуска транспорта:" << (*iter)->year_manufacture << std::endl;
		std::cout << "Марка транспорта:" << (*iter)->brand << std::endl;
		std::cout << "Модель транспорта:" << (*iter)->model << std::endl;
		if ((*iter)->type_transport == "Машина") {
			Car* temp = (Car*)(*iter);
			std::cout << "Объём двигателя:" << temp->engine_size << std::endl;
			std::cout << "Количество лошадиных сил:" << temp->horsepower << std::endl;
		}
		else if ((*iter)->type_transport == "Самолёт") {
			Plane* temp = (Plane*)(*iter);
			std::cout << "Размах крыла:" << temp->wingspan << std::endl;
			std::cout << "Грузоподъемность:" << temp->load_capacity << std::endl;
		}
		else if ((*iter)->type_transport == "Катер") {
			Boat* temp = (Boat*)(*iter);
			std::cout << "Глубина погружения винта:" << temp->screw_inmmersion_depth << std::endl;
		}
		else if ((*iter)->type_transport == "Космический корабль") {
			Spaceship* temp = (Spaceship*)(*iter);
			std::cout << "Тип топлива:" << temp->fuel_type<< std::endl;
		}
		std::cout << std::endl;
	}
}
void print_data_base_infile(std::vector<Transport*> table) {
	std::fstream inOut;
	inOut.open("file.txt", std::ios::out);
	inOut << "					Таблица записей" << std::endl;
	int i = 1;
	for (auto iter = table.begin(); iter != table.end(); iter++, i++) {
		inOut << "Номер записи:" << i << std::endl;
		inOut << "Уникальный идентификатор транспорта:" << (*iter)->unique_identificator << std::endl;
		inOut << "Тип транспорта:" << (*iter)->type_transport << std::endl;
		inOut << "Вес транспорта:" << (*iter)->weight << std::endl;
		inOut << "Год выпуска транспорта:" << (*iter)->year_manufacture << std::endl;
		inOut << "Марка транспорта:" << (*iter)->brand << std::endl;
		inOut << "Модель транспорта:" << (*iter)->model << std::endl;
		if ((*iter)->type_transport == "Машина") {
			Car* temp = (Car*)(*iter);
			inOut << "Объём двигателя:" << temp->engine_size << std::endl;
			inOut << "Количество лошадиных сил:" << temp->horsepower << std::endl;
		}
		else if ((*iter)->type_transport == "Самолёт") {
			Plane* temp = (Plane*)(*iter);
			inOut << "Размах крыла:" << temp->wingspan << std::endl;
			inOut << "Грузоподъемность:" << temp->load_capacity << std::endl;
		}
		else if ((*iter)->type_transport == "Катер") {
			Boat* temp = (Boat*)(*iter);
			inOut << "Глубина погружения винта:" << temp->screw_inmmersion_depth << std::endl;
		}
		else if ((*iter)->type_transport == "Космический корабль") {
			Spaceship* temp = (Spaceship*)(*iter);
			inOut << "Тип топлива:" << temp->fuel_type << std::endl;
		}
		inOut << std::endl;
	}
}
bool comp_id(Transport *a, Transport* b) {
	return (*a).unique_identificator < (*b).unique_identificator;
}
bool comp_type(Transport* a, Transport* b) {
	return (*a).type_transport < (*b).type_transport;
}
bool comp_weight(Transport* a, Transport* b) {
	return (*a).type_transport < (*b).type_transport;
}
bool comp_year(Transport* a, Transport* b) {
	return (*a).year_manufacture < (*b).year_manufacture;
}
bool comp_brand(Transport* a, Transport* b) {
	return (*a).brand < (*b).brand;
}
bool comp_model(Transport* a, Transport* b) {
	return (*a).model < (*b).model;
}
void print_transport(Transport* a) {
	std::cout << "Уникальный идентификатор транспорта:" << (*a).unique_identificator << std::endl;
	std::cout << "Тип транспорта:" << (*a).type_transport << std::endl;
	std::cout << "Вес транспорта:" << (*a).weight << std::endl;
	std::cout << "Год выпуска транспорта:" << (*a).year_manufacture << std::endl;
	std::cout << "Марка транспорта:" << (*a).brand << std::endl;
	std::cout << "Модель транспорта:" << (*a).model << std::endl << std::endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k = 1; // Переменная для работы цикла
	int choice;// Переменная для выбора с действиями таблицы
	int type_choice; // Переменная для выбора типа траснпорта, который хотим создать
	std::vector<Transport *> data_base; // Таблица записей
	
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
			std::cin >> type_choice;
			switch (type_choice) {
			case 1:
			{
				Car *a = new Car();
				(*a).type_transport = "Машина";
				fill_blank(a);
				std::cout << "Введите объём двигателя транспорта:";
				std::cin >> (*a).engine_size;
				std::cout << "Введите количество лошадиных сил транспорта:";
				std::cin >> (*a).horsepower;
				data_base.push_back(a);
				break;
			}
			case 2:
			{
				Plane* a = new Plane();
				(*a).type_transport = "Самолёт";
				fill_blank(a);
				std::cout << "Введите грузоподъмность транспорта:";
				std::cin >> (*a).load_capacity;
				std::cout << "Введите размах крыла транспорта:";
				std::cin >> (*a).wingspan;
				data_base.push_back(a);
				break;
			}
			case 3:
			{
				Boat* a = new Boat();
				(*a).type_transport = "Катер";
				fill_blank(a);
				std::cout << "Введите глубину погружения винта транспорта:";
				std::cin >> (*a).screw_inmmersion_depth;
				data_base.push_back(a);
				break;
			}
			case 4: 
			{
				Spaceship* a = new Spaceship();
				(*a).type_transport = "Космический корабль";
				fill_blank(a);
				std::cout << "Введите тип топлива транспорта:";
				std::cin >> (*a).fuel_type;
				data_base.push_back(a);
				break;
			}
		}
			break;
			
		}	
		case 2:
		{
			print_data_base(data_base);
			int unique_id;
			std::cout << "Введите уникальный индетификатор транспорта, информацию о котором вы хотите отредактировать:";
			std::cin >> unique_id;
			std::vector<Transport*>::iterator it;
			for (auto iter = data_base.begin(); iter != data_base.end(); iter++) {
				if ((*iter)->unique_identificator == unique_id) it = iter;
			}
			std::cout << "Введите 1, если хотите изменить уникальный идентификатор (числовой) транспорта." << std::endl
				<< "Введите 2, если хотите изменить вес транспорта." << std::endl
				<< "Введите 3, если хотите изменить год выпуска." << std::endl
				<< "Введите 4, если хотите изменить марку транспорта." << std::endl
				<< "Введите 5, если хотите изменить модель транспорта." << std::endl
				<< "Введите 6, если хотите изменить дополнительные свойства транспорта." << std::endl;
			int choice_change;
			std::cin >> choice_change;
			switch (choice_change) {
			case 1:
				std::cout << "Введите новый уникальный идентификатор (числовой) транспорта:";
				std::cin >> (*it)->unique_identificator;
				break;
			case 2:
				std::cout << "Введите новый вес транспорта:";
				std::cin >> (*it)->weight;
				break;
			case 3:
				std::cout << "Введите новый год выпуска:";
				std::cin >> (*it)->year_manufacture;
				break;
			case 4:
				std::cout << "Введите новую марку транспорта:";
				std::cin >> (*it)->brand;
				break;
			case 5:
				std::cout << "Введите новую модель транспорта:";
				std::cin >> (*it)->model;
				break;
			case 6:
			{
				if ((*it)->type_transport == "Машина") {
					Car* temp = (Car*)(*it);
					int res;
					std::cout << "Введите 1 - если хотите изменить объём двигателя, 0 - если хотите изменить количество лошадиных сил." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "Введите новый объём двигателя транспорта:";
						std::cin>>temp->engine_size;
					}
					else {
						std::cout << "Введите новое количество лошадиных сил транспорта:";
						std::cin>>temp->horsepower;
					}
				}
				else if ((*it)->type_transport == "Самолёт") {
					Plane* temp = (Plane*)(*it);
					int res;
					std::cout << "Введите 1 - если хотите изменить размах крыла, 0 - если хотите изменить грузоподъемность." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "Введите новый размах крыла транспорта:";
						std::cin>>temp->wingspan;
					}
					else {
						std::cout << "Введите новую грузоподъемность транспорта:";
						std::cin>>temp->load_capacity;
					}
				}
				else if ((*it)->type_transport == "Катер") {
					Boat* temp = (Boat*)(*it);
					std::cout << "Введите новую глубину погружения винта:";
					std::cin>>temp->screw_inmmersion_depth;
				}
				else if ((*it)->type_transport == "Космический корабль") {
					Spaceship* temp = (Spaceship*)(*it);
					std::cout << "Введите новый тип топлива:";
					std::cin>>temp->fuel_type;
				}
			}
			}
			break;
		}
			
		case 3:
		{
			print_data_base(data_base);
			int unique_id;
			std::cout << "Введите уникальный индетификатор транспорта, ззапись которого хотите удалить из таблицы:";
			std::cin >> unique_id;
			for (auto iter = data_base.begin(); iter != data_base.end(); iter++) {
				if ((*iter)->unique_identificator == unique_id) {
					data_base.erase(iter);
					break;
				}
			}
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
				sort(data_base.begin(), data_base.end(), comp_id);
				break;
			case 2:
				sort(data_base.begin(), data_base.end(), comp_weight);
				break;
			case 3:
				sort(data_base.begin(), data_base.end(), comp_year);
				break;
			case 4:
				sort(data_base.begin(), data_base.end(), comp_brand);
				break;
			case 5:
				sort(data_base.begin(), data_base.end(), comp_model);
				break;
			case 6:
				sort(data_base.begin(), data_base.end(), comp_type);
				break;
			}
			print_data_base(data_base);
			break;
		}
		case 5:
			std::cout << "Введите 1, если хотите сделать поиск по уникальному идентификатору." << std::endl
				<< "Введите 2, если хотите сделать поиск по весу транспорта." << std::endl
				<< "Введите 3, если хотите сделать поиск по году выпуска." << std::endl
				<< "Введите 4, если хотите сделать поиск по марке транспорта." << std::endl
				<< "Введите 5, если хотите сделать поиск по модели транспорта." << std::endl
				<< "Введите 6, если хотите сделать поиск по типу транспорта." << std::endl;
			int choice_change;
			std::cin >> choice_change;
			switch (choice_change) {
			case 1:
			{
				int search_unique_id;
				int temp = 1;
				std::cout << "Введите уникальный идентификатор (числовой) транспорта:";
				std::cin >> search_unique_id;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->unique_identificator == search_unique_id) {
						std::cout << "Номер записи:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 2:
			{
				int temp = 1;
				int search_weight;
				std::cout << "Введите вес транспорта:";
				std::cin >> search_weight;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->weight == search_weight) {
						std::cout << "Номер записи:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 3:
			{
				int search_year;
				int temp = 1;
				std::cout << "Введите год выпуска транспорта:";
				std::cin >> search_year;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->year_manufacture == search_year) {
						std::cout << "Номер записи:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 4: 
			{
				int temp = 1;
				std::string search_brand;
				std::cout << "Введите марку транспорта:";
				std::cin >> search_brand;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->brand == search_brand) {
						std::cout << "Номер записи:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}	
			case 5: 
			{
				int temp = 1;
				std::string search_model;
				std::cout << "Введите модель транспорта:";
				std::cin >> search_model;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->model == search_model) {
						std::cout << "Номер записи:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 6: 
			{
				int temp = 1;
				std::string search_type_transport;
				std::cout << "Введите тип транспорта:";
				std::cin >> search_type_transport;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->type_transport == search_type_transport) {
						std::cout << "Номер записи:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			}
			break;
		case 6:
		{
			print_data_base_infile(data_base);
			break;
		}
		case 7:
			break;
		}
		std::cout << "Нажмите 1 - если хотите совершить какие-то дальнейшие действия с таблицей, 0 - если хотите завершить программу."<<std::endl;
		std::cin >> k;
	}
}

