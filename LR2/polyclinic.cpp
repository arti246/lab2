#include <cstdio>
#include <string>
#include <fstream>
#include <windows.h>
#include "polyclinic.h"
using namespace std;

int add_patient(struct patient patient_add)
{
	setlocale(LC_ALL, "RUS");
	ofstream out("db.txt", ios::app);
	if (!out.is_open())
	{
		printf("Ошибка открытия файла!");
		return 1;
	}
	out << patient_add.name << " " << patient_add.surname << " " << patient_add.patronymic << " " 
		<<  patient_add.year_birth << " " << patient_add.gender << " " << patient_add.address << " " 
		<< patient_add.phone << " " << patient_add.insurance << endl;
	out.close();
	printf("Пациент добавлен!");
}