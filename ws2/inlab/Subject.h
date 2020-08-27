/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID154469183
*/

#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H
namespace sdds {

	
	struct Subject //Declare struct subject and pointer variable for members
	{
	int* m_noOfSection;
	int* m_noOfStdsInSecs;
	char* m_subjectName;
	};


	//Read Function Prototypes 
	void read(char* stdName);
	void read(int& section);
	void read(int noStudent[] , int value);


	void read(Subject& sub);
	int report(const Subject& report);
	void freeMem(Subject& del);
}
#endif