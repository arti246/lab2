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

    void printPatientInfo() const override {  // ��������������� � ������� �������� ������
        Patient::printPatientInfo();
        cout << "������: " << ward << ", ���� � ��������: " << daysInHospital << endl;
    }

    int addPatientFile() const override { // ��������������� ��� ������ �������� ������
        ofstream outfile("db.txt", ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("������ �������� �����!");
        }
        outfile << *this << endl;
        outfile.close();
        cout << "������������������� ������� ��������!" << endl;
        return 0;
    }

    void printPatientSummary() const {
        Patient::printPatientSummary();
        cout << "������: �������������������, ������: " << ward << endl;
    }

private:
    string ward; // ������
    int daysInHospital;
};