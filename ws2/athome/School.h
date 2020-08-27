/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file name:School.h
*/
#ifndef SDDS_SCHOOL_H__
#define SDDS_SCHOOL_H__
#include "School.h"
#include "Subject.h"


namespace sdds {

	struct School //structure declartion for school
	{
		int m_noOfSubjects;//int variable
		Subject* m_subjects;//pointer type structure
		char* m_name;//pointer type character
	};
	//Prototype for function used in school.cpp file
	void read(School& Sch);
	int report(const School& schoolreport);
	void freeMem(School& delschool);

}

#endif