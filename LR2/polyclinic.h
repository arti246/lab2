#pragma once
int add_patient(struct patient);
int delete_patient(std::string);
int find_patient(std::string);
int print_patient_all();

/*�������*/
class Patient 
{
public:
    int AddPatient(class Patient);
    
private:
    char name[50];
    char surname[50];
    char patronymic[50];
    int year_birth;
    int gender; // '0' - �������, '1' - �������
    char address[100];
    char phone[20];
    char insurance[20]; // ����� ���������� ������

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
private:
    int id_patient;
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
    char name_disease[10]; // �������� �������
    char description[255];
};

/*�������*/
class Treatment 
{
private:
    char medicine[50]; // ���������
    int dosage; // ���������
    char frequency[20]; // ������� �����
    char duration[20]; // ����������������� �����
};

/*������ �����*/
class Prescription
{
private:
    int id_patient;
    int id_doctor;
    char date_issue[11]; // ���� ������
    class Treatment medicine_prescription;
};

/*��������� ����� �����*/
class FreeTime
{
private:
    int id_doctor;
    char date[11];
    char time_start[6];
    char time_end[6];
};
