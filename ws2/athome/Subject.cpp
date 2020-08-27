/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Subject.h"
#include "utils.h"
using namespace std;
namespace sdds
{


	void read(char* stdName) //Function Defination for reading suject name
	{

		cout << "Enter subject name: ";
		read(stdName, 69, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
		return;

	}
	void read(int& section) //Funciton Defination to Enter the number of section
	{

		cout << "Enter number of sections: ";

		read(section, 1, 10,"Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
		return;
	}
	void read(int noStudent[], int value) //Function Defination to Enter number of student in each section
	{
		cout << "Enter the number of students in each one of the " << value << " sections:" << endl;
		for (int i = 0; i < value; ++i)
		{
			cout << i + 1 << ": ";
			read(noStudent[i], 5, 35,"Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}

		return;
	}

	void read(Subject& sub)//Dynamic memory Allocation
	{
		char name[71];
		read(name);
		sub.m_subjectName = new char[strlen(name) + 1];//Dynamic Memory Allocation for suject name
		strcpy(sub.m_subjectName, name);


		sub.m_noOfSection = new int;//Dynamic Memory Allocation for no of section
		read(*sub.m_noOfSection);

		sub.m_noOfStdsInSecs = new int[*sub.m_noOfSection];//Dynamic Memory Allocation for no of student in each section
		read(sub.m_noOfStdsInSecs, *sub.m_noOfSection);



	}

	int report(const Subject& report)//Function that print recieved data in order
	{
		int total = 0;
		for (int i = 0; i < *report.m_noOfSection; i++)
		{
			cout << report.m_noOfStdsInSecs[i];
			if(i<*report.m_noOfSection -1)
			{
				cout << ",";
			}
				
			total += report.m_noOfStdsInSecs[i];
		}
		cout << endl;
		cout << report.m_subjectName << ": " << total;
		cout << endl;
		return total;
	}
	void freeMem(Subject& del) //Function to deallocate the allocatated memory before
	{
		delete[] del.m_subjectName;
		delete[] del.m_noOfStdsInSecs;
		delete del.m_noOfSection;


	}
}
