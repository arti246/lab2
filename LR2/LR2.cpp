#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "patient.h"
#include "HospitalizedPatient.h"
#include "Outpatient.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    // (Пример использования HospitalizedPatient и Outpatient)
    HospitalizedPatient hp("", "Иванов", "Иванович", 1985, 1, "ул. Ленина, 1", "+79001234567", "1234567890", "101", 5);
    hp.addPatientFile();
    hp.printPatientInfo();

    Outpatient op("Петр", "Петров", "Петрович", 1990, 1, "ул. Мира, 2", "+79009876543", "9876543210", "2024-03-15");
    op.addPatientFile();
    op.printPatientInfo();

    return 0;

    return 0;
}