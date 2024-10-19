#pragma once

/*Пациент*/
class Patient 
{
public:
    int addPatientFile(class Patient);
    int deletePatientFile(std::string);
    int findPatientFile(std::string);
    int printPatientAllFile();
    Patient();
    Patient(const char*, const char*, const char*, int, int, const char*, const char*, const char*); 
    void printPatientInfo();
    int setPatient();
    
private:
    char name[50];
    char surname[50];
    char patronymic[50];
    int year_birth;
    int gender; // '0' - мужской, '1' - женский
    char address[100];
    char phone[20];
    char insurance[20]; // Номер страхового полиса
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
private:
    int id_patient;
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
    char name_disease[10]; // Название болезни
    char description[255];
};

/*Лечение*/
class Treatment 
{
private:
    char medicine[50]; // лекарство
    int dosage; // дозировка
    char frequency[20]; // частота приёма
    char duration[20]; // продолжительность приёма
};

/*Рецепт врача*/
class Prescription
{
private:
    int id_patient;
    int id_doctor;
    char date_issue[11]; // дата выдачи
    class Treatment medicine_prescription;
};

/*Свободное время врача*/
class FreeTime
{
private:
    int id_doctor;
    char date[11];
    char time_start[6];
    char time_end[6];
};
