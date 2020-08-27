//Name:Nisham Bohora
//AddressID:nbohora@myseneca.ca  
//ID NO:1554469183


#ifndef NAMESPACE_FILE_H 
#define NAMESPACE_FILE_H
#include "Contact.h"
#include <fstream>
namespace sdds 
{ 
	//All the prototype for  all function of file
	bool readContact(Contact* C, FILE* fptr);
	void writeContact(FILE* fptr, const Contact* C);
	int readContacts(Contact* contacts, const char* filename);
	void writeContacts(Contact* contacts, int cntno, const char* filename);
}
#endif
