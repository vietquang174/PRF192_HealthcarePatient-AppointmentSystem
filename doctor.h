#ifndef DOCTOR_H
#define DOCTOR_H

// ===== Specialization Struct =====
typedef struct {
    char specID[10];
    char specName[50];
} Specialization;

// ===== Doctor Struct =====
typedef struct {
    char doctorID[10];
    char doctorName[50];
    char specID[10];
} Doctor;

// ===== Function Prototypes =====
void addDoctor(Doctor** doctors, int* count,
               Specialization* specs, int specCount);

void listDoctors(Doctor* doctors, int count);

#endif