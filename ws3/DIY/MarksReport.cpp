/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:MarkReport.ccp
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MarksReport.h"
#include "ReportUtils.h"
#include "Mark.h"
#include <cstring>
using namespace std;


namespace sdds {

	void MarksReport::initialize() {//Function Defination to Initialize report module
		
		m_reportname = new char[71];

	}
	void MarksReport::getMarks() {// Function Defination to get report name and number of marks.
		char name[70];
		cout << "Enter the report Name: ";//For report name input
		cin.getline(name, 71);
		if (cin.fail())
		{
			cin.clear();
		}
		else
		{
			strncpy(m_reportname, name, 70);
		}
		cout << "Enter the number of marks: ";//For number of marks input
		cin >> m_noOfMarks;
		m_mark = new Mark[m_noOfMarks];//Dynamic Memory Allocation
		cout << "Please enter " << m_noOfMarks << " marks:" << endl;
		flushkeyboard();
		for (int i = 0; i < m_noOfMarks; i++) {
			cout << i + 1;
			cout << ": ";
	
			m_mark[i].readName("Subject Name: ", 6);//Function call from mark.cpp
			m_mark[i].read("Mark (mark/outof): ");//Function call from mark.cpp
		}
		cout << "Entry Completed!";
		cout<<endl << endl;


	}
	void MarksReport::print() {//Function Defination to print detail in order
		double gradingpoint = 0;
		int highnum = -1;
		int lownum = 100;
		line(70, '-');
		cout <<endl;
		cout << m_reportname << endl;
		line(70, '-');//Function that print required number of any character
		cout << endl;
		cout << "Marks entered:";
		cout << endl;
		for (int i = 0; i < m_noOfMarks; i++) {
			m_mark[i].set(DSP_LETTER);
			m_mark[i].display(66);
			cout << endl;
			highnum > m_mark[i].percent() ? highnum : highnum = m_mark[i].percent();
			lownum < m_mark[i].percent() ? lownum : lownum = m_mark[i].percent();


		}
		line(70);
		cout << endl;

		line(30, ' ');
        cout << "Lowest Mark";
		line(25, '.');
		cout << "%" << lownum;
		cout << endl;

		line(30, ' ');
		cout << "Highest mark";
		line(24, '.');
		cout << "%" << highnum;
		cout<< endl;

		line(30, ' ');
		cout << "GPA";
		line(33, '.');

		for (int i = 0; i < m_noOfMarks; i++) {//Calculation for final GPA
			gradingpoint += m_mark[i].letterBasedGPA();
		}
		gradingpoint = gradingpoint / m_noOfMarks;
		cout.precision(1);
		cout<< gradingpoint << endl;






	}
	void MarksReport::terminate() {// Function Defination to Deallocate the memory
		delete[] m_reportname;
		delete[] m_mark;
		
	}



}
