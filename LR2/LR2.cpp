#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "patient.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Patient p1("Ivan", "Ivanov", "Ivanovich", 1985, 0, "Moskva", "+79161234567", "1234567890");
    Patient p2;
    p2.setPatient();

    if (p1 == p2) {
        cout << "Пациенты одинаковы" << endl;
    }
    else {
        cout << "Пациенты разные" << endl;
    }

    int* year = p1.getYearBirthPtr();
    cout << "Год рождения через указатель: " << *year << endl;
    int& yearRef = p1.getYearBirthRef();
    yearRef = 1986;
    cout << "Год рождения через ссылку: " << p1.getYearBirthRef() << endl;

    cout << p1 << endl; //Используем перегрузку оператора <<
    
    cout << "Количество пациентов: " << Patient::getPatientCount() << endl;

    p1.addPatientFile();
    p2.addPatientFile();

    p1.printPatientAllFile();

    Patient::resetPatientCount(); // Сброс счетчика
    cout << "Количество пациентов после сброса: " << Patient::getPatientCount() << endl;

    return 0;
}