#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctor.h"
void addDoctor(Doctor** doctors, int* count,
               Specialization* specs, int specCount) {

    if (specCount == 0) {
        printf("No specialization available. Cannot add doctor.\n");
        return;
    }

    Doctor newDoctor;
    int found = 0;

    printf("\n===== ADD DOCTOR =====\n");

    // ===== Doctor ID =====
    printf("Enter Doctor ID (Dxxx): ");
    fgets(newDoctor.doctorID, sizeof(newDoctor.doctorID), stdin);
    newDoctor.doctorID[strcspn(newDoctor.doctorID, "\n")] = '\0';

    if (strlen(newDoctor.doctorID) == 0) {
        printf("Doctor ID cannot be empty!\n");
        return;
    }

    // Check duplicate
    for (int i = 0; i < *count; i++) {
        if (strcmp((*doctors)[i].doctorID, newDoctor.doctorID) == 0) {
            printf("Doctor ID already exists!\n");
            return;
        }
    }

    // ===== Doctor Name =====
    printf("Enter Doctor Name: ");
    fgets(newDoctor.doctorName, sizeof(newDoctor.doctorName), stdin);
    newDoctor.doctorName[strcspn(newDoctor.doctorName, "\n")] = '\0';

    if (strlen(newDoctor.doctorName) == 0) {
        printf("Doctor Name cannot be empty!\n");
        return;
    }

    // ===== Show Specializations =====
    printf("\nAvailable Specializations:\n");
    for (int i = 0; i < specCount; i++) {
        printf("%s - %s\n", specs[i].specID, specs[i].specName);
    }

    printf("Enter Specialization ID: ");
    fgets(newDoctor.specID, sizeof(newDoctor.specID), stdin);
    newDoctor.specID[strcspn(newDoctor.specID, "\n")] = '\0';

    if (strlen(newDoctor.specID) == 0) {
        printf("Specialization ID cannot be empty!\n");
        return;
    }

    // Check specialization exists
    for (int i = 0; i < specCount; i++) {
        if (strcmp(specs[i].specID, newDoctor.specID) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid Specialization ID!\n");
        return;
    }

    // ===== Reallocate Memory =====
    Doctor* temp = realloc(*doctors, (*count + 1) * sizeof(Doctor));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *doctors = temp;
    (*doctors)[*count] = newDoctor;
    (*count)++;

    printf("Doctor added successfully!\n");
}
void listDoctors(Doctor* doctors, int count) {

    if (doctors == NULL || count == 0) {
        printf("\nDoctor list is empty.\n");
        return;
    }

    printf("\n================ DOCTOR LIST ================\n");
    printf("%-5s | %-10s | %-25s | %-10s\n",
           "No", "DoctorID", "Doctor Name", "SpecID");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-10s | %-25s | %-10s\n",
               i + 1,
               doctors[i].doctorID,
               doctors[i].doctorName,
               doctors[i].specID);
    }

    printf("=============================================================\n");
}