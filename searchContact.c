#include "phonebook.h"

char* stringToLower(char * str) {
    char *newStr = (char*)malloc(strlen(str) * sizeof(char));
    for (size_t i = 0; i < strlen(str); i++) {
        newStr[i] = tolower(str[i]);
    }
    return newStr;
}


void searchContact() {
    char *searchStr = (char*)malloc(100 * sizeof(char));
    printf("Enter string to search: ");
    scanf("%s", searchStr);
    
    stringToLower(searchStr);

    int found = FALSE;
    
    for (size_t i = 0; i < contactCount; i++) {
        if (strstr(stringToLower(phonebook[i].firstName), searchStr) != NULL ||
            strstr(stringToLower(phonebook[i].lastName), searchStr) != NULL ||
            strstr(stringToLower(phonebook[i].middleName), searchStr) != NULL ||
            strstr(phonebook[i].phoneNumber, searchStr) != NULL ||
            strstr(stringToLower(phonebook[i].City), searchStr) != NULL) {
            found = TRUE;
            printf("%s %s %s %s - %s\n", phonebook[i].lastName, phonebook[i].firstName,
                phonebook[i].middleName, phonebook[i].City, phonebook[i].phoneNumber);
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }

    free(searchStr);
}