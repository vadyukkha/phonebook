#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_CONTACTS 10000

typedef struct Contact{
    char firstName[100];
    char lastName[100];
    char middleName[100];
    char phoneNumber[15];
    char City[100];
} Contact;

Contact phonebook[MAX_CONTACTS];
uint32_t contactCount = 0;

//Приведение строку в нижний регистр
char* stringToLower(char * str);

// Функция для сравнения контактов по фамилии
int compareContactsBySurname(const void *a, const void *b);

// Функция для сравнения контактов по имени
int compareContactsByName(const void *a, const void *b);

// Функция для сравнения контактов по отчеству
int compareContactsByPatronymic(const void *a, const void *b);

// Функция для сравнения контактов по номеру
int compareContactsByPhoneNumber(const void *a, const void *b);

// Функция для сравнения контактов по городу
int compareContactsByCity(const void *a, const void *b);

// Функция для добавления нового контакта
void addContact();

// Функция для вывода справочника
void displayPhonebook(int(*pred)(const void *, const void *));

// Функция для сохранения в файл
void saveToFile();

// Функция для загрузки из файла
void loadFromFile();

//Функция выбора сортировки 
void sortingPhonebook();

//Функция для изменения контакта 
void editContact();

//Функция для удаления контакта 
void deleteContact();

//Функция для поиска контакта
void searchContact();

#endif