﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "patient.h"
#include "HospitalizedPatient.h"
#include "Outpatient.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Patient* p1 = new Patient("Иван", "Иванов", "Иванович", 1980, 1, "ул. Пушкина, 1", "+71234567890", "111111");
    HospitalizedPatient* p2 = new HospitalizedPatient("Петр", "Петров", "Петрович", 1990, 1, "ул. Лермонтова, 2", "+79876543210", "222222", "202", 10);
    Outpatient* p3 = new Outpatient("Сидор", "Сидоров", "Сидорович", 1985, 0, "ул. Толстого, 3", "+70000000000", "333333", "2024-04-10");

    // Вызов через базовый класс (виртуальный вызов)
    p1->printPatientSummary();
    p2->printPatientSummary();
    p3->printPatientSummary();

    Patient* p4 = p2; // указатель базового класса на объект производного класса
    p4->printPatientSummary(); // Виртуальный вызов - работает полиморфизм

    delete p1;
    delete p2;
    delete p3;

    //Пример с абстрактным классом
    PatientRecord record(*p2);
    record.addDiagnosis("Пневмония");
    record.printRecord();

    // Если бы printPatientSummary() НЕ была виртуальной:
    // p4->printPatientSummary(); // Выведет только информацию из базового класса

    return 0;
}