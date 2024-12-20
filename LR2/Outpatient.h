#pragma once
#include "patient.h"

using namespace std;

class Outpatient : public Patient {
public:
    Outpatient(const string& name, const string& surname, const string& patronymic, int year_birth,
        int gender, const string& address, const string& phone, const string& insurance,
        const string& nextAppointment)
        : Patient(name, surname, patronymic, year_birth, gender, address, phone, insurance), nextAppointment(nextAppointment) {}

    void printPatientInfo() const override { // ��������������� ������ ��� ������ �������� ������
        cout << "���: " << this->getName() << ", �������: " << this->getSurname()
            << ", ��������: " << this->getPatronymic() << ", ��� ��������: " << this->getYearBirth()
            << ", ���: " << (this->getGender() == 1 ? "�������" : "�������")
            << ", �����: " << this->getAddress() << ", �������: " << this->getPhone()
            << ", ��������� �����: " << this->getInsurance() << ", ��������� �����: " << 
            nextAppointment << endl;

        cout << "ID ��������: " << this->patientID << endl; // ������ � ����������� ����
    }

    int addPatientFile() const override { // ��������������� ��� ������ �������� ������
        ofstream outfile("db.txt", ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("������ �������� �����!");
        }
        outfile << *this << endl;
        outfile.close();
        cout << "������������ ������� ��������!" << endl;
        return 0;
    }

    void printPatientSummary() const {
        Patient::printPatientSummary();
        std::cout << "������: ������������, ��������� �����: " << nextAppointment << std::endl;
    }

private:
    string nextAppointment;
};