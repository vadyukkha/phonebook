#include "phonebook.h"

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
    printf("Enter surname which you wanna change: ");
    scanf("%s", searchName);

    int found = FALSE;
    for (size_t i = 0; i < contactCount; i++) {
        if (strcmp(searchName, phonebook[i].lastName) == 0) {
            printf("Enter new name: ");
            scanf("%s", phonebook[i].firstName);

            printf("Enter new surname: ");
            scanf("%s", phonebook[i].lastName);

            printf("Enter new patronymic: ");
            scanf("%s", phonebook[i].middleName);

            printf("Enter new phone number: ");
            scanf("%s", phonebook[i].phoneNumber);

            printf("Enter new city: ");
            scanf("%s", phonebook[i].City);

            found = TRUE;
            printf("Contact succesfully changed!\n");
            break;
        }
    }

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