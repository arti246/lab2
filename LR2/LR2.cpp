#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polyclinic.h"

int main()
{
    Patient patient1("Ivan", "Ivaniv", "Ivanovich", 1990, 0, "Lenina_st.,h.1", "8-800-555-35-35", "1234567890");
    patient1.printPatientInfo();
    patient1.setPatient();
    patient1.printPatientInfo();
    // Создание записи "пациент"
    
    //add_patient(p1); // Добавление новой записи "пациент" в БД
    //delete_patient("Ivanov"); // Удаление записи "пациент" по фамилии из БД
    //print_patient_all(); // Вывод в консоль все записи из БД "пациент"
}