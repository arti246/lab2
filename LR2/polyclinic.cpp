#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include "polyclinic.h"
using namespace std;

int add_patient(struct patient patient_add)
{
	setlocale(LC_ALL, "RUS");
	ofstream outfile("db.txt", ios::app);
	if (!outfile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}
	outfile << patient_add.name << " " << patient_add.surname << " " << patient_add.patronymic << " "
		<<  patient_add.year_birth << " " << patient_add.gender << " " << patient_add.address << " " 
		<< patient_add.phone << " " << patient_add.insurance << endl;
	outfile.close();
	cout << "Пациент добавлен!" << endl;
}

int find_patient(string surname_find)
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
		if (surname == surname_find)
		{
			return 1;
			break;
		}
	}
	return 0;
	infile.close();
}

int delete_patient(string surname_find)
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
		if (surname_find == surname) found = true;
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

int print_patient_all()
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