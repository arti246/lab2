#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "patient.h"

using namespace std;

int main()
{
    Patient patient1("Ivan", "Ivaniv", "Ivanovich", 1990, 0, "Lenina_st.,h.1", "8-800-555-35-35", "1234567890");
    patient1.printPatientInfo();
    //patient1.setPatient();
    //patient1.printPatientInfo();
    //patient1.addPatientFile();
    //patient1.deletePatientFile("1234567890");
    //patient1.printPatientAllFile();

    int n;
    cout << "\nВведите количество пациентов: ";
    cin >> n;
    cin.ignore();

    // Работа с динамическим массивом объектов класса
    Patient* patients = new Patient[n];

    // Ввод информации о пациентах
    for (int i = 0; i < n; ++i) {
        cout << "Введите информацию о пациенте #" << i + 1 << endl;
        patients[i].setPatient();
    }

    // Вывод информации о пациентах
    cout << "\nИнформация о пациентах:" << endl;
    for (int i = 0; i < n; ++i) {
        patients[i].printPatientInfo();
    }
    delete[] patients;

    // Работа с массивом динамических объектов класса
    Patient** patients2 = new Patient * [n];

    // Создание объектов класса и инициализация массива указателей
    for (int i = 0; i < n; ++i) {
        patients2[i] = new Patient();
        cout << "Введите информацию о пациенте #" << i + 1 << endl;
        patients2[i]->setPatient();
    }

    // Вывод информации о пациентах
    cout << "\nИнформация о пациентах:" << endl;
    for (int i = 0; i < n; ++i) {
        patients2[i]->printPatientInfo();
    }

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete patients2[i];
    }
    delete[] patients2;
    
    //Принцип ассоциации
    Appointment appointment1(&patient1, 1, "25.12.2024", "10:00", "Записан");
    cout << "Запись пациента " << patient1.name << " " << patient1.surname << ":" << endl;
    appointment1.printAppointmentInfo();
}