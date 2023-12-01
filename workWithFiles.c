#include "phonebook.h"

void saveToFile() {
    FILE *file = fopen("phonebook.txt", "w");
    if (file != NULL) {
        fwrite(phonebook, sizeof(Contact), contactCount, file);
        fclose(file);
        printf("Save succesfully.\n");
    } else {
        printf("Save error.\n");
    }
}

void loadFromFile() {
    FILE *file = fopen("phonebook.txt", "r");
    if (file != NULL) {
        contactCount = fread(phonebook, sizeof(Contact), MAX_CONTACTS, file);
        fclose(file);
    }
}