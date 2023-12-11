#include "phonebook.h"

uint32_t contactCount;

void saveToFile() {
    FILE *file = fopen("phonebook.txt", "w");
    if (file != NULL) {
        for (size_t i = 0; i < contactCount; i++) {
            fprintf(file, "%s %s %s %s - %s\n", phonebook[i].firstName, phonebook[i].lastName,
                    phonebook[i].middleName, phonebook[i].City, phonebook[i].phoneNumber);
        }
        fclose(file);
        printf("Save succesfully.\n");
    } else {
        printf("Save error.\n");
    }
}

void loadFromFile() {
    FILE *file = fopen("phonebook.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s %s - %s", phonebook[contactCount].firstName,
                      phonebook[contactCount].lastName, 
                      phonebook[contactCount].middleName,
                      phonebook[contactCount].City,
                      phonebook[contactCount].phoneNumber) == 5) {
            contactCount++;
            if (contactCount >= MAX_CONTACTS) {
                printf("Phonebook is full.\n");
                break;
            }
        }
        fclose(file);
    }
}