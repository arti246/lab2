#pragma once
/*�������*/
typedef struct patient {
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
typedef struct doctor {
    char name[50];
    char surname[50];
    char patronymic[50];
    char specialization[50]; // ��������, "��������", "������"
    char office_number[10]; // ����� ��������
};

/*������ �� ����*/
typedef struct appointment {
    int id_patient;
    int id_doctor;
    char date[11];
    char time[6];
    char status[20]; // "�������", "�������", "��������"
};

/*��������*/
typedef struct symptoms {
    char description[255];
    char date_start[11];
};

/*�������*/
typedef struct diagnosis {
    char name_disease[10]; // �������� �������
    char description[255];
};

/*�������*/
typedef struct treatment {
    char medicine[50]; // ���������
    int dosage; // ���������
    char frequency[20]; // ������� �����
    char duration[20]; // ����������������� �����
};

/*������ �����*/
typedef struct prescription {
    int id_patient;
    int id_doctor;
    char date_issue[11]; // ���� ������
    struct treatment medicine_prescription;
};

/*��������� ����� �����*/
typedef struct free_time {
    int id_doctor;
    char date[11];
    char time_start[6];
    char time_end[6];
};
