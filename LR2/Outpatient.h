#pragma once
#include "patient.h"

using namespace std;

class Outpatient : public Patient {
public:
    Outpatient(const std::string& name, const std::string& surname, const std::string& patronymic, int year_birth,
        int gender, const std::string& address, const std::string& phone, const std::string& insurance,
        const std::string& nextAppointment)
        : Patient(name, surname, patronymic, year_birth, gender, address, phone, insurance), nextAppointment(nextAppointment) {}

    void printPatientInfo() const override { // Перегрузка без вызова базового метода
        std::cout << "Имя: " << this->getName() << ", Фамилия: " << this->getSurname()
            << ", Отчество: " << this->getPatronymic() << ", Год рождения: " << this->getYearBirth()
            << ", Пол: " << (this->getGender() == 1 ? "Мужской" : "Женский")
            << ", Адрес: " << this->getAddress() << ", Телефон: " << this->getPhone()
            << ", Страховой полис: " << this->getInsurance() << ", Следующий прием: " << 
            nextAppointment << std::endl;

        std::cout << "ID Пациента: " << this->patientID << std::endl; // Доступ к защищенному полю
    }

private:
    std::string nextAppointment;
};