#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include "polyclinic.h"
using namespace std;

int Patient::addPatientFile(class Patient patientAdd)
{
	setlocale(LC_ALL, "RUS");
	ofstream outfile("db.txt", ios::app);
	if (!outfile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}
	outfile << patientAdd.name << " " << patientAdd.surname << " " << patientAdd.patronymic << " "
		<< patientAdd.year_birth << " " << patientAdd.gender << " " << patientAdd.address << " "
		<< patientAdd.phone << " " << patientAdd.insurance << endl;
	outfile.close();
	cout << "Пациент добавлен!" << endl;
}

int Patient::findPatientFile(string surnameFind)
{
	setlocale(LC_ALL, "RUS");
	ifstream infile("db.txt", ios::in);
	string name, surname;
	if (!infile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 2;
	}
	while (getline(infile, name, ',') && getline(infile, surname))
	{
		if (surname == surnameFind)
		{
			return 1;
			break;
		}
	}
	return 0;
	infile.close();
}

int Patient::deletePatientFile(string surnameFind)
{
	setlocale(LC_ALL, "RUS");
	ifstream infile("db.txt", ios::in);
	ofstream outfile("db1.txt", ios::app);
	string name, surname, patronymic, year_birth, gender, address, phone, insurance;
	bool found = false;

	if (!infile.is_open() && !outfile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	while (getline(infile, name, ' ') && getline(infile, surname, ' ') && getline(infile, patronymic, ' ') && getline(infile, year_birth, ' ')
		&& getline(infile, gender, ' ') && getline(infile, address, ' ') && getline(infile, phone, ' ') && getline(infile, insurance))
	{
		if (surnameFind == surname) found = true;
		else outfile << name << " " << surname << " " << patronymic << " " << year_birth << " " << gender << " " << address
			<< " " << phone << " " << insurance << endl;
	}
	infile.close(); outfile.close();

	if (found)
	{
		if (remove("db.txt") != 0) cout << "Ошибка удаления пациента!" << endl;
		else if (rename("db1.txt", "db.txt") != 0) cout << "Ошибка удаления пациента!" << endl;
		else cout << "Запись пациента успешно удалена!" << endl;
	}
	return 0;
}

int Patient::printPatientAllFile()
{
	setlocale(LC_ALL, "RUS");
	ifstream infile("db.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	string line;

	while (getline(infile, line))
	{
		cout << line << endl;
	}

	infile.close();
}

Patient::Patient() : year_birth(0), gender(0) {
	strcpy(name, "");
	strcpy(surname, "");
	strcpy(patronymic, "");
	strcpy(address, "");
	strcpy(phone, "");
	strcpy(insurance, "");
}

Patient::Patient(const char* name, const char* surname, const char* patronymic, int year_birth,
	int gender, const char* address, const char* phone, const char* insurance):
	year_birth(year_birth), gender(gender) {
	strcpy(this->name, name);
	strcpy(this->surname, surname);
	strcpy(this->patronymic, patronymic);
	strcpy(this->address, address);
	strcpy(this->phone, phone);
	strcpy(this->insurance, insurance);
}

void Patient::printPatientInfo()
{
	setlocale(LC_ALL, "ru");
	cout << "\nИнформации о пациенте:\nИмя: " << name << endl << "Фамилия: " << surname << endl;
	cout << "Отчество: " << patronymic << endl << "Год рождения: " << year_birth << endl;
	cout << "Пол: " << (gender == 0 ? "Мужской" : "Женский") << endl << "Адрес: " << address << endl;
	cout << "Телефон: " << phone << endl << "Страховой полис: " << insurance << endl << endl;
}

int Patient::setPatient()
{
	setlocale(LC_ALL, "ru");
	int check = 0;
	cout << "Ввод информации о пациенте:\n" << "Введите имя: ";
	cin.getline(name, 50);
	cout << "Введите фамилию: ";
	cin.getline(surname, 50);
	cout << "Введите отчество: ";
	cin.getline(patronymic, 50);

	do
	{
		cout << "Введите год рождения (От 1900 до 2024): ";
		cin >> year_birth;
	} while (year_birth < 1900 || year_birth > 2024);

	do
	{
		cout << "Введите пол (0 - мужской, 1 - женский): ";
		cin >> gender;
	} while (gender != 0 && gender != 1);

	cin.ignore();
	cout << "Введите адрес: ";
	cin.getline(address, 100);
	cout << "Введите телефон: ";
	cin.getline(phone, 20);
	cout << "Введите номер страхового полиса: ";
	cin.getline(insurance, 20);
	return 0;
}