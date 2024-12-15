#pragma once
using namespace std;

/*�������*/
class Patient 
{
public:
    Patient();
    Patient(const std::string& name, const std::string& surname, const std::string& patronymic, int year_birth,
        int gender, const std::string& address, const std::string& phone, const std::string& insurance);
    Patient(const Patient& other);
    Patient& operator=(const Patient& other);
    ~Patient() = default;

    int addPatientFile();
    int deletePatientFile(const std::string& insuranceFind);
    void printPatientAllFile();
    void printPatientInfo() const;
    int setPatient();
    int* getYearBirthPtr();
    int& getYearBirthRef();
    bool operator==(const Patient& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);

    static int getPatientCount(); // ����������� �����
    static void resetPatientCount();

private:
    std::string name;
    std::string surname;
    std::string patronymic;
    int year_birth;
    int gender;
    std::string address;
    std::string phone;
    std::string insurance;
    static int patientCount; // ����������� ����
};

/*������*/
class Doctor
{
private:
    char name[50];
    char surname[50];
    char patronymic[50];
    char specialization[50]; // ��������, "��������", "������"
    char office_number[10]; // ����� ��������
};

/*������ �� ����*/
class Appointment
{
public:
    Appointment(Patient* patient, int, const char* date, const char* time, const char* status): id_doctor(id_doctor), patient(patient) {
        strcpy(this->date, date);
        strcpy(this->time, time);
        strcpy(this->status, status);
    }

private:
    Patient* patient;
    Doctor* doctor;
    int id_doctor;
    char date[11];
    char time[6];
    char status[20]; // "�������", "�������", "��������"
};

/*��������*/
class Symptoms
{
private:
    char description[255];
    char date_start[11];
};

/*�������*/
class Diagnosis
{
private:
    Patient* patient;
    Doctor* doctor;
    char name_disease[10]; // �������� �������
    char description[255];
    Symptoms* symptoms;
};

/*�������*/
class Treatment 
{
private:
    Patient* patient;
    Doctor* doctor;
    char medicine[50]; // ���������
    int dosage; // ���������
    char frequency[20]; // ������� �����
    char duration[20]; // ����������������� �����
};

/*������ �����*/
class Prescription
{
private:
    Patient* patient;
    Doctor* doctor;
    char date_issue[11]; // ���� ������
    Treatment* medicine_prescription;
};

/*��������� ����� �����*/
class FreeTime
{
private:
    Doctor* doctor;
    char date[11];
    char time_start[6];
    char time_end[6];
};
