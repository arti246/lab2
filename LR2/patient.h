#pragma once
using namespace std;

/*Пациент*/
class Patient 
{
public:
    Patient() : year_birth(1900), gender(0), patientID(generatePatientID()) {} //Добавлен patientID

    Patient(const std::string& name, const std::string& surname, const std::string& patronymic, int year_birth,
        int gender, const std::string& address, const std::string& phone, const std::string& insurance)
        : name(name), surname(surname), patronymic(patronymic), year_birth(year_birth), gender(gender),
        address(address), phone(phone), insurance(insurance), patientID(generatePatientID()) {}

    Patient(const Patient& other) : name(other.name), surname(other.surname), patronymic(other.patronymic),
        year_birth(other.year_birth), gender(other.gender), address(other.address),
        phone(other.phone), insurance(other.insurance), patientID(generatePatientID()) {}


    Patient& operator=(const Patient& other) = default;

    ~Patient() = default;

    virtual void printPatientSummary() const { // Виртуальная функция
        cout << "Имя: " << name << ", Фамилия: " << surname << ", Страховой полис: " << insurance << endl;
    }

    virtual ~Patient() = default; // Виртуальный деструктор - очень важно!

    virtual int addPatientFile() const;
    int deletePatientFile(const string& insuranceFind) const;
    void printPatientAllFile() const;
    virtual void printPatientInfo() const;
    int setPatient();
    int* getYearBirthPtr() { return &year_birth; }
    int& getYearBirthRef() { return year_birth; }
    bool operator==(const Patient& other) const;
    friend ostream& operator<<(ostream& os, const Patient& patient);

    static void resetPatientCount();

    //Геттеры
    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getPatronymic() const { return patronymic; }
    int getYearBirth() const { return year_birth; }
    int getGender() const { return gender; }
    string getAddress() const { return address; }
    string getPhone() const { return phone; }
    string getInsurance() const { return insurance; }
    int getPatientCount() { return patientCount; }

    //Сеттеры
    void setName(string name) { this->name = name; }
    void setSurname(string surname) { this->surname = surname; }
    void setPatronymic(string patronymic) { this->patronymic = patronymic; }
    void setYearBirth(int year_birth) { this->year_birth = year_birth; }
    void setGender(int gender) { this->gender = gender; }
    void setAddress(string address) { this->address = address; }
    void setPhone(string phone) { this->phone = phone; }
    void getInsurance(int patientCouninsurancet) { this->insurance = insurance; }
    void getPatientCount(int patientCount) { this->patientCount = patientCount; }

    // Защищенный доступ к ID пациента
protected:
    long long patientID;
    static long long generatePatientID();

private:
    string name;
    string surname;
    string patronymic;
    int year_birth;
    int gender;
    string address;
    string phone;
    string insurance;
    static int patientCount; // Статическое поле
};

/*Доктор*/
class Doctor
{
private:
    char name[50];
    char surname[50];
    char patronymic[50];
    char specialization[50]; // Например, "Терапевт", "Хирург"
    char office_number[10]; // Номер кабинета
};

/*Запись на приём*/
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
    char status[20]; // "Записан", "Отменен", "Проведен"
};

/*Симптомы*/
class Symptoms
{
private:
    char description[255];
    char date_start[11];
};

/*Диагноз*/
class Diagnosis
{
private:
    Patient* patient;
    Doctor* doctor;
    char name_disease[10]; // Название болезни
    char description[255];
    Symptoms* symptoms;
};

/*Лечение*/
class Treatment 
{
private:
    Patient* patient;
    Doctor* doctor;
    char medicine[50]; // лекарство
    int dosage; // дозировка
    char frequency[20]; // частота приёма
    char duration[20]; // продолжительность приёма
};

/*Рецепт врача*/
class Prescription
{
private:
    Patient* patient;
    Doctor* doctor;
    char date_issue[11]; // дата выдачи
    Treatment* medicine_prescription;
};

/*Свободное время врача*/
class FreeTime
{
private:
    Doctor* doctor;
    char date[11];
    char time_start[6];
    char time_end[6];
};