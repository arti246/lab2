#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polyclinic.h"

int main()
{
    patient p1{"Artur", "Grishin", "Artemovich", 2002, 0, "Barnaul sity...", "88005553535", "1111"}; // Создание записи "пациент"
    add_patient(p1); // Добавление новой записи "пациент" в БД
    delete_patient("Grishin"); // Удаление записи "пациент" по фамилии из БД
    print_patient_all(); // Вывод в консоль все записи из БД "пациент"
}