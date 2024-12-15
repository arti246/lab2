#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include "patient.h"

using namespace std;

int Patient::patientCount = 0;

Patient::Patient() : year_birth(0), gender(0) { patientCount++; }

Patient::Patient(const string& name, const string& surname, const string& patronymic, int year_birth,
	int gender, const string& address, const string& phone, const string& insurance)
	: name(name), surname(surname), patronymic(patronymic), year_birth(year_birth), gender(gender),
	address(address), phone(phone), insurance(insurance) {
	patientCount++;
}

Patient::Patient(const Patient& other) :
	name(other.name), surname(other.surname), patronymic(other.patronymic), year_birth(other.year_birth),
	gender(other.gender), address(other.address), phone(other.phone), insurance(other.insurance) {
	patientCount++;
}

Patient& Patient::operator=(const Patient& other) {
	if (this != &other) {
		name = other.name;
		surname = other.surname;
		patronymic = other.patronymic;
		year_birth = other.year_birth;
		gender = other.gender;
		address = other.address;
		phone = other.phone;
		insurance = other.insurance;
	}
	return *this;
}

int Patient::addPatientFile() {
	setlocale(LC_ALL, "ru");
	try {
		ofstream outfile("db.txt", ios::app);
		if (!outfile.is_open()) {
			throw runtime_error("Ошибка открытия файла!"); // Исключение
		}
		outfile << *this << endl;
		outfile.close();
		cout << "Пациент добавлен!" << endl;
		return 0;
	}
	catch (const runtime_error& error) {
		cerr << "Ошибка: " << error.what() << endl;
		return 1;
	}
}

int Patient::deletePatientFile(const string& insuranceFind) {
	setlocale(LC_ALL, "ru");
	ifstream infile("db.txt");
	ofstream outfile("db1.txt");
	string line;
	bool found = false;

	if (!infile.is_open() || !outfile.is_open()) {
		cerr << "Ошибка открытия файла!" << endl;
		return 1;
	}

	while (getline(infile, line)) {
		size_t pos = line.rfind(' ');
		if (pos != string::npos) {
			string insurance = line.substr(pos + 1);
			if (insurance == insuranceFind) {
				found = true;
			}
			else {
				outfile << line << endl;
			}
		}
	}
	infile.close();
	outfile.close();

	if (found) {
		if (remove("db.txt") != 0 || rename("db1.txt", "db.txt") != 0) {
			cerr << "Ошибка удаления пациента!" << endl;
			return 1;
		}
		else {
			cout << "Запись пациента успешно удалена!" << endl;
			return 0;
		}
	}
	return 0;
}

void Patient::printPatientAllFile() {
	setlocale(LC_ALL, "ru");
	ifstream infile("db.txt");
	if (!infile.is_open()) {
		cerr << "Ошибка открытия файла!" << endl;
		return;
	}
	string line;
	cout << "\nСписок пациентов:\n";
	while (getline(infile, line)) {
		cout << line << endl;
	}
	infile.close();
}

void Patient::printPatientInfo() const {
	setlocale(LC_ALL, "ru");
	cout << "Информация о пациенте:\nИмя: " << name << endl
		<< "Фамилия: " << surname << endl
		<< "Отчество: " << patronymic << endl
		<< "Год рождения: " << year_birth << endl
		<< "Пол: " << (gender == 0 ? "Мужской" : "Женский") << endl
		<< "Адрес: " << address << endl
		<< "Телефон: " << phone << endl
		<< "Страховой полис: " << insurance << endl << endl;
}

int Patient::setPatient() {
	setlocale(LC_ALL, "ru");
	cout << "Ввод информации о пациенте:\n";
	do
	{
		cout << "Введите имя (Не больше 20 символов): ";
		getline(cin >> ws, name);
		int c = name.length();
	} while (name.length() < 1 || name.length() > 20);

	do
	{
		cout << "Введите фамилию (Не больше 20 символов): ";
		getline(cin, surname);
	} while (surname.length() < 1 || surname.length() > 20);

	do
	{
		cout << "Введите отчество (Не больше 20 символов): ";
		getline(cin, patronymic);
	} while (patronymic.length() < 1 || patronymic.length() > 20);

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

	do
	{
		cout << "Введите адрес проживания (Не больше 100 символов): ";
		getline(cin >> ws, address);
	} while (address.length() < 1 || address.length() > 100);

	do
	{
		cout << "Введите номер телефона (Не больше 20 символов): ";
		getline(cin, phone);
	} while (phone.length() < 1 || phone.length() > 20);

	do
	{
		cout << "Введите номер страхового полиса (16 символов): ";
		getline(cin, insurance);
	} while (insurance.length() != 16);

	return 0;
}

int* Patient::getYearBirthPtr() {
	return &year_birth;
}

int& Patient::getYearBirthRef() {
	return year_birth;
}

int Patient::getPatientCount() {
	return patientCount;
}

void Patient::resetPatientCount() {
	patientCount = 0;
}

bool Patient::operator==(const Patient& other) const {
	return (name == other.name && surname == other.surname && insurance == other.insurance);
}

ostream& operator<<(ostream& os, const Patient& patient) {
	os << patient.name << " " << patient.surname << " " << patient.patronymic << " "
		<< patient.year_birth << " " << patient.gender << " " << patient.address << " "
		<< patient.phone << " " << patient.insurance;
	return os;
}