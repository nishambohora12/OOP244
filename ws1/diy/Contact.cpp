//Name:Nisham Bohora
//AddressID:nbohora@myseneca.ca  
//ID NO:1554469183

//All the function related to the contact are define here to

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"
#include "Tools.h"
#include "File.h"




using namespace std;
//MAXREC Number Define
#define MAX_REC_NO 100

//Enclosing all with in namespace sdds
namespace sdds {

//Defination to get function.
void getContact(Contact* C) 
{
	cout << "Name: ";
	getName(C->name);
	cout << "Phone Number: ";
	C->phoneNumber = getPhoneNumber();
}
//Defination to printcontact
void printContact(const Contact* C)
{
	cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
}
//Defination to sort the contact in order.
void sort(Contact c[], int n) {
	Contact temp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (compare(&c[j], &c[j + 1]) > 0) {
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
}
//Defination of function that print contacts.
void printContacts(const Contact* C, int num)
{
	for (int i = 0; i < num; i++) 
	{
		printContact(&C[i]);
	}
}
//Defination of fuction that accepts name and all.
bool nameInContact(const Contact* C, const char* nameSubStr) 
{
	char name[31];
	char subName[31];
	toLowerCase(name, C->name);
	toLowerCase(subName, nameSubStr);
	return strstr(name, subName) != nullptr;
}
//Defination of function that search contact.
int search(Contact* found, const Contact* C, const char* name, int noOfRecs)
{
	int i;
	int noOfMatches = 0;
	for (i = 0; i < noOfRecs; i++) {
		if (nameInContact(&C[i], name)) {
			found[noOfMatches] = C[i];
			noOfMatches++;
		}
	}
	return noOfMatches;
}
//Function defination that compare contact.
 int compare(const Contact* A, const Contact* B)
{
	return strcmp(A->name, B->name);
}
}
