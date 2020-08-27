/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file name:School.cpp
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Subject.h"
#include "utils.h"
#include "School.h"
using namespace std;
namespace sdds {

	//Function defination for input of school name , number of subject
	void read(School& Sch) 
	{
		char name[61];
		cout << "Please enter the name of the school:\n> ";
		read(name, 61, "Name is too long, only 60 characters allowed!\nRedo Entry: ");




		Sch.m_name = new char[strlen(name) + 1];// Memory Allocation for school name
		strcpy(Sch.m_name, name);

		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

		Sch.m_subjects = new Subject[Sch.m_noOfSubjects];//Memory Allocation for subject up to input number of subject
		for (int i = 0; i < Sch.m_noOfSubjects; i++)
		{
			
			cout << i + 1 << ") ------------------------------" << endl;
			read(Sch.m_subjects[i]);
		}

	}

	//Function defination for printing given data in order
	int report(const School& schoolreport)
	{
		int total = 0;
		int subtotal = 0;
		cout << schoolreport.m_name << endl;
		cout << "Subject Enrollments" << endl;
		for (int i = 0; i < schoolreport.m_noOfSubjects; i++)
		{
			for (int j = 0; j < *schoolreport.m_subjects[i].m_noOfSection; j++)
			{

				cout << schoolreport.m_subjects[i].m_noOfStdsInSecs[j];
				subtotal += schoolreport.m_subjects[i].m_noOfStdsInSecs[j];
				if (j < *schoolreport.m_subjects[i].m_noOfSection - 1)
				{
					cout << ",";
				}

				if (j == *schoolreport.m_subjects[i].m_noOfSection - 1)
				{
					cout << endl;
					cout << schoolreport.m_subjects[i].m_subjectName << ": " << subtotal << endl;
					total += subtotal;
				}


			}

			subtotal = 0;
		}
		cout << "Total enrollment: " << total << endl;
		return total;
	}

	////Function to deallocate the allocatated memory before 
	void freeMem(School& delschool)

	{
	
		delete[] delschool.m_name;//memory deallocation for name
		for (int i = 0; i < delschool.m_noOfSubjects; i++) 
		{
			freeMem(delschool.m_subjects[i]);
		}

		

	}
}
	
