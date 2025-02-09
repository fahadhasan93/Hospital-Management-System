#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Patient {
    char name[100], mode_of_admission[100], gender[10];
    char mobile[15], email[100], med[200], drugs[100], other[100];
    char operations[100], dia[100], current[100], doctor_visit[100];
    char mode_of_consultation[100], year[5];
    int height, weight, token;
    struct Patient *next;
    struct Doctor *doctor;
};

struct Doctor {
    char name[100], dept[100];
    struct Doctor *next;
    struct Patient *patients;
};

struct Doctor *doctorList[26] = {NULL};
struct Patient *emergencyList = NULL;
int total_cases = 0, Normal = 0, Emergency = 0;

void addDoctor(char name[]) {
    struct Doctor *newDoctor = (struct Doctor *)malloc(sizeof(struct Doctor));
    printf("Enter department: ");
    scanf("%s", newDoctor->dept);
    strcpy(newDoctor->name, name);
    newDoctor->patients = NULL;
    newDoctor->next = NULL;
    
    int index = tolower(name[0]) - 'a';
    if (doctorList[index] == NULL) {
        doctorList[index] = newDoctor;
    } else {
        struct Doctor *temp = doctorList[index];
        while (temp->next) temp = temp->next;
        temp->next = newDoctor;
    }
    printf("Doctor added successfully. ID: %p\n", newDoctor);
}

struct Doctor* findDoctor() {
    char name[100];
    printf("Enter doctor's name: ");
    scanf("%s", name);
    int index = tolower(name[0]) - 'a';
    
    struct Doctor *temp = doctorList[index];
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Doctor found: %s, Department: %s, ID: %p\n", temp->name, temp->dept, temp);
            return temp;
        }
        temp = temp->next;
    }
    printf("Doctor not found!\n");
    return NULL;
}

void addPatient() {
    struct Patient *newPatient = (struct Patient *)malloc(sizeof(struct Patient));
    printf("Enter name: ");
    scanf("%s", newPatient->name);
    printf("Enter gender: ");
    scanf("%s", newPatient->gender);
    printf("Enter mobile: ");
    scanf("%s", newPatient->mobile);
    printf("Enter email: ");
    scanf("%s", newPatient->email);
    printf("Enter birth year: ");
    scanf("%s", newPatient->year);
    printf("Type of consultation? 1. Normal 2. Emergency: ");
    int type;
    scanf("%d", &type);
    newPatient->next = NULL;
    
    if (type == 1) {
        newPatient->doctor = findDoctor();
        if (newPatient->doctor) {
            struct Patient *temp = newPatient->doctor->patients;
            if (!temp) {
                newPatient->doctor->patients = newPatient;
            } else {
                while (temp->next) temp = temp->next;
                temp->next = newPatient;
            }
            Normal++;
            printf("Patient added to doctor %s's list. ID: %p\n", newPatient->doctor->name, newPatient);
        }
    } else {
        Emergency++;
        if (!emergencyList) {
            emergencyList = newPatient;
        } else {
            struct Patient *temp = emergencyList;
            while (temp->next) temp = temp->next;
            temp->next = newPatient;
        }
        printf("Patient added to emergency list. ID: %p\n", newPatient);
    }
    total_cases = Normal + Emergency;
}

void viewDoctorStatus(struct Doctor *doctor) {
    printf("Doctor Name: %s\n", doctor->name);
    printf("Department: %s\n", doctor->dept);
    struct Patient *temp = doctor->patients;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    printf("Remaining Patients: %d\n", count);
}

void completeConsultation(struct Doctor *doctor) {
    if (!doctor->patients) {
        printf("No patients in queue.\n");
        return;
    }
    struct Patient *temp = doctor->patients;
    doctor->patients = temp->next;
    free(temp);
    Normal--;
    printf("Consultation completed.\n");
}

void patientLog(struct Doctor *doctor) {
    struct Patient *temp = doctor->patients;
    printf("Patients under %s:\n", doctor->name);
    while (temp) {
        printf("- %s (ID: %p)\n", temp->name, temp);
        temp = temp->next;
    }
}

int main() {
    int choice;
    printf("Welcome to ABC Hospital\n");
    do {
        printf("\nTotal Cases: %d | Normal: %d | Emergency: %d\n", total_cases, Normal, Emergency);
        printf("1: Patient Admission\n2: New Doctor Entry\n3: Doctor Status\n4: Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addPatient(); break;
            case 2: {
                char docName[100];
                printf("Enter Doctor's Name: ");
                scanf("%s", docName);
                addDoctor(docName);
                break;
            }
            case 3: {
                struct Doctor *doc = findDoctor();
                if (doc) viewDoctorStatus(doc);
                break;
            }
            case 4: printf("Exiting. Have a nice day!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
