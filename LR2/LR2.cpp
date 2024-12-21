#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "patient.h"
#include "HospitalizedPatient.h"
#include "Outpatient.h"
#include "MedicalRecord.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Patient* p1 = new Patient("Dmitriy", "Dmitriev", "Dmitrievich", 1980, 1, "Kazan,ul.Pushkina..., 1", "+71234567890", "111111");
    HospitalizedPatient* p2 = new HospitalizedPatient("Evgeniy", "Evgeniev", "Evgenievich", 1990, 1, "Kazan,ul.Lermonova...", "+79876543210", "222222", "202", 10);
    Outpatient* p3 = new Outpatient("Sidor", "Sidorov", "Sivorovich", 1985, 0, "Kazan,ul.Tolstova...", "+70000000000", "333333", "2024-04-10");

    // Вызов через базовый класс (виртуальный вызов)
    p1->printPatientSummary();
    p2->printPatientSummary();
    p3->printPatientSummary();

    
    Patient* p4 = p2; // указатель базового класса на объект производного класса
    p4->printPatientSummary(); // Виртуальный вызов - работает полиморфизм

    //Пример с абстрактным классом
    PatientRecord record(*p1);
    record.addDiagnosis("Кашель");
    record.addDiagnosis("Болит голова");
    record.printRecord();

    // Если бы printPatientSummary() НЕ была виртуальной:
    // p4->printPatientSummary(); // Выведет только информацию из базового класса

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}