#pragma once
/*Пациент*/
typedef struct patient {
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
typedef struct doctor {
    char name[50];
    char surname[50];
    char patronymic[50];
    char specialization[50]; // Например, "Терапевт", "Хирург"
    char office_number[10]; // Номер кабинета
};

/*Запись на приём*/
typedef struct appointment {
    int id_patient;
    int id_doctor;
    char date[11];
    char time[6];
    char status[20]; // "Записан", "Отменен", "Проведен"
};

/*Симптомы*/
typedef struct symptoms {
    char description[255];
    char date_start[11];
};

/*Диагноз*/
typedef struct diagnosis {
    char name_disease[10]; // Название болезни
    char description[255];
};

/*Лечение*/
typedef struct treatment {
    char medicine[50]; // лекарство
    int dosage; // дозировка
    char frequency[20]; // частота приёма
    char duration[20]; // продолжительность приёма
};

/*Рецепт врача*/
typedef struct prescription {
    int id_patient;
    int id_doctor;
    char date_issue[11]; // дата выдачи
    struct treatment medicine_prescription;
};

/*Свободное время врача*/
typedef struct free_time {
    int id_doctor;
    char date[11];
    char time_start[6];
    char time_end[6];
};
