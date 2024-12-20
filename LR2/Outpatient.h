#pragma once
#include "patient.h"

using namespace std;

class Outpatient : public Patient {
public:
    Outpatient(const string& name, const string& surname, const string& patronymic, int year_birth,
        int gender, const string& address, const string& phone, const string& insurance,
        const string& nextAppointment)
        : Patient(name, surname, patronymic, year_birth, gender, address, phone, insurance), nextAppointment(nextAppointment) {}

    void printPatientInfo() const override { // Переопределение метода без вызова базового метода
        cout << "Имя: " << this->getName() << ", Фамилия: " << this->getSurname()
            << ", Отчество: " << this->getPatronymic() << ", Год рождения: " << this->getYearBirth()
            << ", Пол: " << (this->getGender() == 1 ? "Мужской" : "Женский")
            << ", Адрес: " << this->getAddress() << ", Телефон: " << this->getPhone()
            << ", Страховой полис: " << this->getInsurance() << ", Следующий прием: " << 
            nextAppointment << endl;

        cout << "ID Пациента: " << this->patientID << endl; // Доступ к защищенному полю
    }

    int addPatientFile() const override { // Переопределение без вызова базового класса
        ofstream outfile("db.txt", ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("Ошибка открытия файла!");
        }
        outfile << *this << endl;
        outfile.close();
        cout << "Амбулаторный пациент добавлен!" << endl;
        return 0;
    }

    void printPatientSummary() const {
        Patient::printPatientSummary();
        std::cout << "Статус: Амбулаторный, Следующий прием: " << nextAppointment << std::endl;
    }

private:
    string nextAppointment;
};