// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>
// #include <ctype.h>

// #define TRUE 1
// #define FALSE 0
// #define MAX_CONTACTS 10000

// typedef struct Contact{
//     char firstName[100];
//     char lastName[100];
//     char middleName[100];
//     char phoneNumber[15];
//     char City[100];
// } Contact;

// Contact phonebook[MAX_CONTACTS];
// uint32_t contactCount = 0;

// //Приведение строку в нижний регистр
// char* stringToLower(char * str) {
//     char *newStr = (char*)malloc(strlen(str) * sizeof(char));
//     for (size_t i = 0; i < strlen(str); i++) {
//         newStr[i] = tolower(str[i]);
//     }
//     return newStr;
// }

// // Функция для сравнения контактов по фамилии
// int compareContactsBySurname(const void *a, const void *b) {
//     return strcmp(((Contact*)a)->lastName, ((Contact*)b)->lastName);
// }

// // Функция для сравнения контактов по имени
// int compareContactsByName(const void *a, const void *b) {
//     return strcmp(((Contact*)a)->firstName, ((Contact*)b)->firstName);
// }

// // Функция для сравнения контактов по отчеству
// int compareContactsByPatronymic(const void *a, const void *b) {
//     return strcmp(((Contact*)a)->middleName, ((Contact*)b)->middleName);
// }

// // Функция для сравнения контактов по номеру
// int compareContactsByPhoneNumber(const void *a, const void *b) {
//     return strcmp(((Contact*)a)->phoneNumber, ((Contact*)b)->phoneNumber);
// }

// // Функция для сравнения контактов по городу
// int compareContactsByCity(const void *a, const void *b) {
//     return strcmp(((Contact*)a)->City, ((Contact*)b)->City);
// }

// // Функция для добавления нового контакта
// void addContact() {
//     if (contactCount < MAX_CONTACTS) {
//         printf("Enter name: ");
//         scanf("%s", phonebook[contactCount].firstName);

//         printf("Enter surname: ");
//         scanf("%s", phonebook[contactCount].lastName);

//         printf("Enter patronymic: ");
//         scanf("%s", phonebook[contactCount].middleName);

//         printf("Enter phone number: ");
//         scanf("%s", phonebook[contactCount].phoneNumber);

//         printf("Enter a city: ");
//         scanf("%s", phonebook[contactCount].City);

//         contactCount++;
//         printf("Contact successfully added.\n");
//     } else {
//         printf("Book is full.\n");
//     }
// }

// // Функция для вывода справочника
// void displayPhonebook(int(*pred)(const void *, const void *)) {
//     if (contactCount == 0) {
//         printf("Phonebook is clear.\n");
//         return;
//     }

//     qsort(phonebook, contactCount, sizeof(Contact), pred);

//     printf("Phonebook:\n");
//     for (size_t i = 0; i < contactCount; i++) {
//         printf("%s %s %s %s - %s\n", phonebook[i].lastName, phonebook[i].firstName,
//                phonebook[i].middleName, phonebook[i].City, phonebook[i].phoneNumber);
//     }
// }

// // Функция для сохранения в файл
// void saveToFile() {
//     FILE *file = fopen("phonebook.txt", "w");
//     if (file != NULL) {
//         fwrite(phonebook, sizeof(Contact), contactCount, file);
//         fclose(file);
//         printf("Save succesfully.\n");
//     } else {
//         printf("Save error.\n");
//     }
// }

// // Функция для загрузки из файла
// void loadFromFile() {
//     FILE *file = fopen("phonebook.txt", "r");
//     if (file != NULL) {
//         contactCount = fread(phonebook, sizeof(Contact), MAX_CONTACTS, file);
//         fclose(file);
//     }
// }

// //Функция выбора сортировки 
// void sortingPhonebook() {
//     uint16_t typeSort;
//     printf("I can sort phonebook by :\n");
//     printf("1. Name.\n");
//     printf("2. Surname.\n");
//     printf("3. Patronymic.\n");
//     printf("4. Phone number.\n");
//     printf("5. City. \n");
//     printf("Enter how to sort phonebook: ");
//     printf("\n");
//     scanf("%hu", &typeSort);
//     switch (typeSort) {
//     case 1:
//         displayPhonebook(compareContactsByName);
//         break;
//     case 2:
//         displayPhonebook(compareContactsBySurname);
//         break;
//     case 3:
//         displayPhonebook(compareContactsByPatronymic);
//         break;
//     case 4:
//         displayPhonebook(compareContactsByPhoneNumber);
//         break;
//     case 5:
//         displayPhonebook(compareContactsByCity);
//         break;
//     default:
//         printf("Error number. Try again.\n");
//     }

// }

// //Функция для изменения контакта 
// void editContact() {
//     char *searchName = (char*)malloc(100 * sizeof(char));
//     printf("Enter surname which you wanna change: ");
//     scanf("%s", searchName);

//     int found = FALSE;
//     for (size_t i = 0; i < contactCount; i++) {
//         if (strcmp(searchName, phonebook[i].lastName) == 0) {
//             printf("Enter new name: ");
//             scanf("%s", phonebook[i].firstName);

//             printf("Enter new surname: ");
//             scanf("%s", phonebook[i].lastName);

//             printf("Enter new patronymic: ");
//             scanf("%s", phonebook[i].middleName);

//             printf("Enter new phone number: ");
//             scanf("%s", phonebook[i].phoneNumber);

//             printf("Enter new city: ");
//             scanf("%s", phonebook[i].City);

//             found = TRUE;
//             printf("Contact succesfully changed!\n");
//             break;
//         }
//     }

//     if (!found) {
//         printf("Not found to edit!\n");
//     }

//     free(searchName);
// }

// //Функция для удаления контакта 
// void deleteContact() {
//     char *searchName = (char*)malloc(100 * sizeof(char));
//     printf("Enter surname which you wanna delete: ");
//     scanf("%s", searchName);

//     int found = FALSE;
//     for (size_t i = 0; i < contactCount; i++) {
//         if (strcmp(searchName, phonebook[i].lastName) == 0) {
//             for (size_t j = i; j < contactCount - 1; j++) {
//                 phonebook[j] = phonebook[j + 1];
//             }
//             contactCount--;
//             found = TRUE;
//             printf("Contact succesfully deleted.\n");
//             break;
//         }
//     }

//     if (!found) {
//         printf("Not found contact to delete!\n");
//     }

//     free(searchName);
// }

// //Функция для поиска контакта
// void searchContact() {
//     char *searchStr = (char*)malloc(100 * sizeof(char));
//     printf("Enter string to search: ");
//     scanf("%s", searchStr);
    
//     stringToLower(searchStr);

//     int found = FALSE;
    
//     for (size_t i = 0; i < contactCount; i++) {
//         if (strstr(stringToLower(phonebook[i].firstName), searchStr) != NULL ||
//             strstr(stringToLower(phonebook[i].lastName), searchStr) != NULL ||
//             strstr(stringToLower(phonebook[i].middleName), searchStr) != NULL ||
//             strstr(phonebook[i].phoneNumber, searchStr) != NULL ||
//             strstr(stringToLower(phonebook[i].City), searchStr) != NULL) {
//             found = TRUE;
//             printf("%s %s %s %s - %s\n", phonebook[i].lastName, phonebook[i].firstName,
//                 phonebook[i].middleName, phonebook[i].City, phonebook[i].phoneNumber);
//         }
//     }
//     if (!found) {
//         printf("Contact not found!\n");
//     }

//     free(searchStr);
// }

// int main() {
//     loadFromFile();
//     uint16_t runProgram = TRUE;
//     uint16_t choice;
//     while (runProgram) {
//         printf("\n1. Add contact\n");
//         printf("2. Display phonebook\n");
//         printf("3. Save in file\n");
//         printf("4. Rewrtie contact\n");
//         printf("5. Delete contact\n");
//         printf("6. Search contact\n");
//         printf("7. Exit\n");
//         printf("\nChoose operation: ");
//         scanf("%hu", &choice);
//         printf("\n");
//         switch (choice) {
//             case 1:
//                 addContact();
//                 break;
//             case 2:
//                 sortingPhonebook();
//                 break;
//             case 3:
//                 saveToFile();
//                 break;
//             case 4:
//                 editContact();
//                 break;
//             case 5:
//                 deleteContact();
//                 break;
//             case 6:
//                 searchContact();
//                 break;
//             case 7:
//                 printf("Exit...\n");
//                 runProgram = FALSE;
//                 break;
//             default:
//                 printf("Uncorrect number. Try again.\n");
//         }
//     };

//     return 0;
// }
