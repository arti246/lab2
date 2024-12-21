#pragma once
using namespace std;

/*�������*/
class Patient 
{
public:
    Patient(); //�������� patientID

    Patient(const string& name, const string& surname, const string& patronymic, int year_birth,
        int gender, const string& address, const string& phone, const string& insurance);

    Patient(const Patient& other);

    Patient& operator=(const Patient& other);

    virtual ~Patient() = default;

    virtual void printPatientSummary() const { // ����������� �������
        cout << "���: " << name << ", �������: " << surname << ", ��������� �����: " << insurance << endl;
    }

    virtual int addPatientFile() const;
    int deletePatientFile(const string& insuranceFind) const;
    void printPatientAllFile() const;
    virtual void printPatientInfo() const;
    int setPatient();
    int* getYearBirthPtr();
    int& getYearBirthRef();
    bool operator==(const Patient& other) const;
    friend ostream& operator<<(ostream& os, const Patient& patient);

    static void resetPatientCount();

    //�������
    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getPatronymic() const { return patronymic; }
    int getYearBirth() const { return year_birth; }
    int getGender() const { return gender; }
    string getAddress() const { return address; }
    string getPhone() const { return phone; }
    string getInsurance() const { return insurance; }
    int getPatientCount() { return patientCount; }
    int getPatientID() { return patientID; }

    //�������
    void setName(string name) { this->name = name; }
    void setSurname(string surname) { this->surname = surname; }
    void setPatronymic(string patronymic) { this->patronymic = patronymic; }
    void setYearBirth(int year_birth) { this->year_birth = year_birth; }
    void setGender(int gender) { this->gender = gender; }
    void setAddress(string address) { this->address = address; }
    void setPhone(string phone) { this->phone = phone; }
    void getInsurance(int patientCouninsurancet) { this->insurance = insurance; }
    void getPatientCount(int patientCount) { this->patientCount = patientCount; }

    // ���������� ������ � ID ��������
protected:
    int patientID;
    static int generatePatientID();

private:
    string name;
    string surname;
    string patronymic;
    int year_birth;
    int gender;
    string address;
    string phone;
    string insurance;
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