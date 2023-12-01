#include "phonebook.h"

int main() {
    loadFromFile();
    uint16_t runProgram = TRUE;
    uint16_t choice;
    while (runProgram) {
        printf("\n1. Add contact\n");
        printf("2. Display phonebook\n");
        printf("3. Save in file\n");
        printf("4. Rewrtie contact\n");
        printf("5. Delete contact\n");
        printf("6. Search contact\n");
        printf("7. Exit\n");
        printf("\nChoose operation: ");
        scanf("%hu", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                sortingPhonebook();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                editContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                searchContact();
                break;
            case 7:
                printf("Exit...\n");
                runProgram = FALSE;
                break;
            default:
                printf("Uncorrect number. Try again.\n");
        }
    };

    return 0;
}
