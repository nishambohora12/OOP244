//Name:Nisham Bohora
//AddressID:nbohora@myseneca.ca  
//ID NO:1554469183
//This file contain all the defination of the function which are related to the file phone directory


#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include <iostream>


namespace sdds
{ 
	//Defination to read contact from file
	bool readContact(Contact* C, FILE* fptr) 
	{
		return fscanf(fptr, "%[^,],%lld", C->name, &C->phoneNumber) == 2;
	}
	//Function Defination for write contact
	void writeContact(FILE* fptr, const Contact* C) {
		fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
	}
	//Function Defination read contact
	int readContacts(Contact* contacts, const char* filename) {
		FILE* fptr = fopen(filename, "r");
		Contact C;
		int num;
		for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
			contacts[num] = C;
		}
		return num;
	}
	//Function Defination to write contact
	void writeContacts(Contact* contacts, int cntno, const char* filename) {
		FILE* fptr = fopen(filename, "w");
		int num;
		for (num = 0; num < cntno; num++) {
			writeContact(fptr, &contacts[num]);
		}
		fclose(fptr);
	}
}
