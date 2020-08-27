//Name:Nisham Bohora
//AddressID:nbohora@myseneca.ca  
//ID NO:1554469183

//Prototype for all the function that are related to contact are mention in this file.
#ifndef NAMESPACE_CONTACT_H 
#define NAMESPACE_CONTACT_H

#define MAX_REC_NO 100

namespace sdds
{ //Contact structure
	struct Contact
	{
		char name[31];
		long long phoneNumber;
	};
//All protoype for contact functions
	bool nameInContact(const Contact* C, const char* nameSubStr);
	void printContacts(const Contact* C, int num);
	void sort(Contact c[], int n);
	void printContact(const Contact* C);
	void getContact(Contact* C);
	int compare(const Contact* A, const Contact* B);
	int search(Contact* found, const Contact* C, const char* name, int noOfRecs);
	
}
#endif
