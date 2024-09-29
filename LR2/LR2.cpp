#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polyclinic.h"

int main()
{
    patient p1{"Ivanov", "Ivan", "Ivanovich", 2002, 0, "Barnaul_sity_Lenina46", "88005553535", "1111"}; // Создание записи "пациент"
    //add_patient(p1); // Добавление новой записи "пациент" в БД
    //delete_patient("Ivanov"); // Удаление записи "пациент" по фамилии из БД
    print_patient_all(); // Вывод в консоль все записи из БД "пациент"
}