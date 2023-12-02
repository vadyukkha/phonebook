#include "phonebook.h"

uint32_t contactCount;

int compareContactsBySurname(const void *a, const void *b) {
    return strcmp(stringToLower(((Contact*)a)->lastName), stringToLower(((Contact*)b)->lastName));
}

int compareContactsByName(const void *a, const void *b) {
    return strcmp(stringToLower(((Contact*)a)->firstName), stringToLower(((Contact*)b)->firstName));
}

int compareContactsByPatronymic(const void *a, const void *b) {
    return strcmp(stringToLower(((Contact*)a)->middleName), stringToLower(((Contact*)b)->middleName));
}

int compareContactsByPhoneNumber(const void *a, const void *b) {
    return strcmp(stringToLower(((Contact*)a)->phoneNumber), stringToLower(((Contact*)b)->phoneNumber));
}

int compareContactsByCity(const void *a, const void *b) {
    return strcmp(stringToLower(((Contact*)a)->City), stringToLower(((Contact*)b)->City));
}

void displayPhonebook(int(*pred)(const void *, const void *)) {
    if (contactCount == 0) {
        printf("Phonebook is clear.\n");
        return;
    }

    qsort(phonebook, contactCount, sizeof(Contact), pred);

    printf("Phonebook:\n");
    for (size_t i = 0; i < contactCount; i++) {
        printf("%s %s %s %s - %s\n", phonebook[i].lastName, phonebook[i].firstName,
               phonebook[i].middleName, phonebook[i].City, phonebook[i].phoneNumber);
    }
}

void sortingPhonebook() {
    uint16_t typeSort;
    printf("I can sort phonebook by :\n");
    printf("1. Name.\n");
    printf("2. Surname.\n");
    printf("3. Patronymic.\n");
    printf("4. Phone number.\n");
    printf("5. City. \n");
    printf("Enter how to sort phonebook: ");
    printf("\n");
    scanf("%hu", &typeSort);
    switch (typeSort) {
    case 1:
        displayPhonebook(compareContactsByName);
        break;
    case 2:
        displayPhonebook(compareContactsBySurname);
        break;
    case 3:
        displayPhonebook(compareContactsByPatronymic);
        break;
    case 4:
        displayPhonebook(compareContactsByPhoneNumber);
        break;
    case 5:
        displayPhonebook(compareContactsByCity);
        break;
    default:
        printf("Error number. Try again.\n");
    }

}