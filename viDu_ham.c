// THIS FILE IS FOR REFERENCE ONLY
// DO NOT INCLUDE IN PROJECT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viDu_ham.h"

void addOneSamplePatient(PatientDemo** list, int* count) {
    // Cấp phát thêm 1 ô nhớ
    *list = realloc(*list, (*count + 1) * sizeof(PatientDemo));

    // Gán dữ liệu mẫu
    strcpy((*list)[*count].id, "P001");
    strcpy((*list)[*count].name, "Nguyen Van A");

    // Tăng số lượng
    (*count)++;

    printf("Added 1 sample patient successfully!\n");
}
