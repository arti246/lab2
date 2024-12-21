#pragma once
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include "patient.h"
#include <vector>

using namespace std;

/*Абстрактный класс*/
class MedicalRecord {
public:
    virtual void addDiagnosis(const string& diagnosis) = 0;
    virtual void printRecord() const = 0;
    virtual ~MedicalRecord() = default;
};

class PatientRecord : public MedicalRecord {
public:
    PatientRecord(const Patient& p) : patient(p) {}

    void addDiagnosis(const string& diagnosis) override {
        diagnoses.push_back(diagnosis);
    }

    void printRecord() const override {
        cout << "Запись для пациента: " << patient.getSurname() << " " << patient.getName() << endl;
        for (const auto& diag : diagnoses) {
            cout << "- " << diag << endl;
        }
    }

private:
    Patient patient;
    vector<string> diagnoses;
};
