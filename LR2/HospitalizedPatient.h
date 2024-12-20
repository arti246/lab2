#pragma once
#include "patient.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class HospitalizedPatient : public Patient {

public:
    HospitalizedPatient(const string& name, const string& surname, const string& patronymic, int year_birth,
        int gender, const string& address, const string& phone, const string& insurance,
        const string& ward, int daysInHospital)
        : Patient(name, surname, patronymic, year_birth, gender, address, phone, insurance), ward(ward), daysInHospital(daysInHospital) {}

    void printPatientInfo() const override {  // Переопределение с вызовом базового класса
        Patient::printPatientInfo();
        cout << "Палата: " << ward << ", Дней в больнице: " << daysInHospital << endl;
    }

    int addPatientFile() const override { // Переопределение без вызова базового класса
        ofstream outfile("db.txt", ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("Ошибка открытия файла!");
        }
        outfile << *this << endl;
        outfile.close();
        cout << "Госпитализированный пациент добавлен!" << endl;
        return 0;
    }

    void printPatientSummary() const {
        Patient::printPatientSummary();
        cout << "Статус: Госпитализированный, Палата: " << ward << endl;
    }

private:
    string ward; // палата
    int daysInHospital;
};