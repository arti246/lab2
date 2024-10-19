#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include "patient.h"

using namespace std;

int Patient::addPatientFile()
{
	setlocale(LC_ALL, "RUS");
	ofstream outfile("db.txt", ios::app);
	if (!outfile.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return 1;
	}
	outfile << this->name << " " << this->surname << " " << this->patronymic << " "
		<< this->year_birth << " " << this->gender << " " << this->address << " "
		<< this->phone << " " << this->insurance << endl;
	outfile.close();
	cout << "������� ��������!" << endl;
}

int Patient::deletePatientFile(string insuranceFind)
{
	setlocale(LC_ALL, "RUS");
	ifstream infile("db.txt", ios::in);
	ofstream outfile("db1.txt", ios::app);
	string name, surname, patronymic, year_birth, gender, address, phone, insurance;
	bool found = false;

	if (!infile.is_open() && !outfile.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return 1;
	}

	while (getline(infile, name, ' ') && getline(infile, surname, ' ') && getline(infile, patronymic, ' ') && getline(infile, year_birth, ' ')
		&& getline(infile, gender, ' ') && getline(infile, address, ' ') && getline(infile, phone, ' ') && getline(infile, insurance))
	{
		if (insuranceFind == insurance) found = true;
		else outfile << name << " " << surname << " " << patronymic << " " << year_birth << " " << gender << " " << address
			<< " " << phone << " " << insurance << endl;
	}
	infile.close(); outfile.close();

	if (found)
	{
		if (remove("db.txt") != 0) cout << "������ �������� ��������!" << endl;
		else if (rename("db1.txt", "db.txt") != 0) cout << "������ �������� ��������!" << endl;
		else cout << "������ �������� ������� �������!" << endl;
	}
	return 0;
}

int Patient::printPatientAllFile()
{
	setlocale(LC_ALL, "RUS");
	ifstream infile("db.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "������ �������� �����!" << endl;
		return 1;
	}

	string line;
	cout << "\n������ ���������:\n";
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
	cout << "���������� � ��������:\n���: " << name << endl << "�������: " << surname << endl;
	cout << "��������: " << patronymic << endl << "��� ��������: " << year_birth << endl;
	cout << "���: " << (gender == 0 ? "�������" : "�������") << endl << "�����: " << address << endl;
	cout << "�������: " << phone << endl << "��������� �����: " << insurance << endl << endl;
}

int Patient::setPatient()
{
	setlocale(LC_ALL, "ru");
	int check = 0;
	cout << "���� ���������� � ��������:\n" << "������� ���: ";
	cin.getline(name, 50);
	cout << "������� �������: ";
	cin.getline(surname, 50);
	cout << "������� ��������: ";
	cin.getline(patronymic, 50);

	do
	{
		cout << "������� ��� �������� (�� 1900 �� 2024): ";
		cin >> year_birth;
	} while (year_birth < 1900 || year_birth > 2024);

	do
	{
		cout << "������� ��� (0 - �������, 1 - �������): ";
		cin >> gender;
	} while (gender != 0 && gender != 1);

	cin.ignore();
	cout << "������� �����: ";
	cin.getline(address, 100);
	cout << "������� �������: ";
	cin.getline(phone, 20);
	cout << "������� ����� ���������� ������: ";
	cin.getline(insurance, 20);
	return 0;
}

Doctor::Doctor() {
	strcpy(name, "");
	strcpy(surname, "");
	strcpy(patronymic, "");
	strcpy(specialization, "");
	strcpy(office_number, "");
}

void Doctor::printDoctorInfo()
{
	setlocale(LC_ALL, "ru");
	cout << "���������� � �������:\n���: " << name << endl << "�������: " << surname << endl;
	cout << "��������: " << patronymic << endl << "�������������: " << specialization << endl;
	cout << "����� ��������: " << office_number << endl;
}

int Doctor::setDoctor()
{
	setlocale(LC_ALL, "ru");
	cout << "���� ���������� � �������:\n" << "������� ���: ";
	cin.getline(name, 50);
	cout << "������� �������: ";
	cin.getline(surname, 50);
	cout << "������� ��������: ";
	cin.getline(patronymic, 50);
	cout << "�������������: ";
	cin.getline(specialization, 50);
	cout << "����� ��������: ";
	cin.getline(office_number, 50);
	return 0;
}

Doctor::Doctor(const char* name, const char* surname, const char* patronymic, const char* specialization, const char* office_number)
{
	strcpy(this->name, name);
	strcpy(this->surname, surname);
	strcpy(this->patronymic, patronymic);
	strcpy(this->specialization, specialization);
	strcpy(this->office_number, office_number);
}

