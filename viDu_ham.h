// THIS FILE IS FOR REFERENCE ONLY
// DO NOT INCLUDE IN PROJECT

#ifndef VIDU_HAM_H
#define VIDU_HAM_H

// Struct bệnh nhân (đơn giản)
typedef struct {
    char id[10];
    char name[50];
} PatientDemo;

// Hàm thêm 1 bệnh nhân mẫu
void addOneSamplePatient(PatientDemo** list, int* count);

#endif
