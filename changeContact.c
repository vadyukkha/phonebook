#include "phonebook.h"

uint32_t contactCount;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", phonebook[contactCount].firstName);

        printf("Enter surname: ");
        scanf("%s", phonebook[contactCount].lastName);

        printf("Enter patronymic: ");
        scanf("%s", phonebook[contactCount].middleName);

        printf("Enter phone number: ");
        scanf("%s", phonebook[contactCount].phoneNumber);

        printf("Enter a city: ");
        scanf("%s", phonebook[contactCount].City);

        contactCount++;
        printf("Contact successfully added.\n");
    } else {
        printf("Book is full.\n");
    }
}

void editContact() {
    char *searchName = (char*)malloc(100 * sizeof(char));

    size_t *IndexFounded = (size_t*)malloc(sizeof(size_t)*contactCount);
    size_t Index = 0;
    printf("Enter surname which you wanna change: ");
    scanf("%s", searchName);

    searchName = stringToLower(searchName);
    int found = FALSE;

    for (size_t i = 0; i < contactCount; i++) {
        if (!strcmp(searchName, stringToLower(phonebook[i].lastName))) {
            IndexFounded[Index++] = i;
            found = TRUE;
        }
    }

    if (!found) {
        printf("Contact not found!!");
        return;
    }

    for (size_t i = 0; i < Index; i++) {
        printf("Position %lu\nName: %s\nSurname: %s\nPatronymic: %s\nCity: %s\nPhone number: %s\n\n",
            IndexFounded[i], 
            phonebook[IndexFounded[i]].lastName, 
            phonebook[IndexFounded[i]].firstName,
            phonebook[IndexFounded[i]].middleName, 
            phonebook[IndexFounded[i]].City, 
            phonebook[IndexFounded[i]].phoneNumber);
    }
    size_t pos;
    printf("Choose position which you wanna edit: ");
    scanf("%lu", &pos);

    printf("Enter new name: ");
    scanf("%s", phonebook[pos].firstName);

    printf("Enter new surname: ");
    scanf("%s", phonebook[pos].lastName);

    printf("Enter new patronymic: ");
    scanf("%s", phonebook[pos].middleName);

    printf("Enter new phone number: ");
    scanf("%s", phonebook[pos].phoneNumber);

    printf("Enter new city: ");
    scanf("%s", phonebook[pos].City);

    if (!found) {
        printf("Not found to edit!\n");
    }

    free(searchName);
}

void deleteContact() {
    char *searchName = (char*)malloc(100 * sizeof(char));
    printf("Enter surname which you wanna delete: ");
    scanf("%s", searchName);

    int found = FALSE;
    for (size_t i = 0; i < contactCount; i++) {
        if (strcmp(searchName, phonebook[i].lastName) == 0) {
            for (size_t j = i; j < contactCount - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            contactCount--;
            found = TRUE;
            printf("Contact succesfully deleted.\n");
            break;
        }
    }

    if (!found) {
        printf("Not found contact to delete!\n");
    }

    free(searchName);
}