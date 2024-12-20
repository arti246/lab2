#pragma once
#include "patient.h"

using namespace std;

class Outpatient : public Patient {
public:
    Outpatient(const std::string& name, const std::string& surname, const std::string& patronymic, int year_birth,
        int gender, const std::string& address, const std::string& phone, const std::string& insurance,
        const std::string& nextAppointment)
        : Patient(name, surname, patronymic, year_birth, gender, address, phone, insurance), nextAppointment(nextAppointment) {}

    void printPatientInfo() const override { // ���������� ��� ������ �������� ������
        std::cout << "���: " << this->getName() << ", �������: " << this->getSurname()
            << ", ��������: " << this->getPatronymic() << ", ��� ��������: " << this->getYearBirth()
            << ", ���: " << (this->getGender() == 1 ? "�������" : "�������")
            << ", �����: " << this->getAddress() << ", �������: " << this->getPhone()
            << ", ��������� �����: " << this->getInsurance() << ", ��������� �����: " << 
            nextAppointment << std::endl;

        std::cout << "ID ��������: " << this->patientID << std::endl; // ������ � ����������� ����
    }

private:
    std::string nextAppointment;
};