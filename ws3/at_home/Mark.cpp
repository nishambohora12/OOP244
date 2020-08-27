
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Mark.ccp
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mark.h"


using namespace std;
namespace sdds {
	void Mark::flushkeyboard()const
	{
		char ch;
		do {
			ch = cin.get();

		} while (ch != '\n');
	}
	void Mark::prnLetter()const {
		if (!isEmpty()) {
			if (percent() >= 0 && percent() <= 49)

			{
				cout << "F";
			}
			else if (percent() >= 50 && percent() <= 54)
			{
				cout << "D";
			}
			else if (percent() >= 55 && percent() <= 59)
			{
				cout << "D+";
			}
			else if (percent() >= 60 && percent() <= 64)
			{
				cout << "C";
			}
			else if (percent() >= 65 && percent() <= 69)
			{
				cout << "C+";
			}
			else if (percent() >= 70 && percent() <= 74)
			{
				cout << "B";
			}
			else if (percent() >= 75 && percent() <= 79)
			{
				cout << "B+";
			}
			else if (percent() >= 80 && percent() <= 89)
			{
				cout << "A";
			}
			else if (percent() >= 90 && percent() <= 100)
			{
				cout << "A+";
			}
			else if (percent() > 100)
			{
				cout << "?";
			}
		}
	}
	void Mark::set(int displayMode)
	{
		m_displayMode = displayMode;
	}

	void Mark::set(double mark, int outof) {
		m_mark = mark;
	    m_outof = outof;
   

	}
	void Mark::setEmpty()
	{
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outof = 100;
		strcpy(m_name, "");
		
	}
	bool Mark::isEmpty()const
	{
		return m_mark == -1;//marks can never be empty so set empty space to neg one
	}
	int Mark::percent()const 
	{
		double x;
		x = (m_mark / m_outof * 100) + 0.5;
		return x;
		
	}

	double Mark::rawValue()const {
		double x;
		x=m_mark / m_outof;
		return x;
		
	}
	bool Mark::read(const char* prompt) {
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outof;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			success = false;

		}
		flushkeyboard();
		return success;
	}
	ostream& Mark::display(int width) const //function to print in format as output required output
	{
		cout.setf(ios::fixed);
		if (isEmpty())
		{
			cout << "Empty Mark object!";
		}
		else {

			if (strcmp(m_name,"\0")>0)
			{
				cout.fill('.');
                              cout.width(width);
                               cout.setf(ios::left);
				cout<< m_name;

			}
			if (m_displayMode == DSP_RAW)
			{
				cout.precision(2);
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT)
			{
				cout << "%" << percent();

			}
			else if (m_displayMode == DSP_ASIS)
			{
				cout.precision(1);
				cout << m_mark <<  "/" << m_outof;

			}
			

			else if (m_displayMode == DSP_LETTER)
			{
				prnLetter();
			}
			else if (m_displayMode == DSP_GPA) {
				cout.precision(1); 
                 cout << GPA();
			}
		
			else if (m_displayMode == DSP_UNDEFINED)
			{
				cout << "Display mode not set";

			}
			else {
				cout << "Invalid Mark Display setting!";
			}
		}
			return cout;
		
	}
	void Mark::set(const char* name) {//Function defination to setup name
		
		strncpy(m_name, name, 50);
	}

	void Mark::set(const char* name, double rawMark, int outof ) // Function defination to set up obtain marks and total marks.
	{
		set(name);
		set(rawMark, outof);
	}
	bool Mark::readName(const char* prompt, int maxLen ) {
		
		cout << prompt;
		cin.getline(m_name, maxLen + 1);
		if(cin.fail()){
			cin.clear();
			setEmpty();
			flushkeyboard();

			return false;

		}
		
		return true;
	}
	void Mark::changeOutOf(int value) {
		if (value < 1) 
		{ value = 100; }
		m_mark = m_mark * ((double)value / m_outof);
		m_outof = value;
	}


	double Mark::GPA()const//Function defination to return (GPA) rawvalue *4
	{
		return rawValue() * 4;
	}

	double Mark::letterBasedGPA()const //Function defination for point based GPA
	{
		double gradepoint;
		if (percent() >= 0 && percent() <= 49) {
			gradepoint =0.0;
		}
		else if (percent() >= 50 && percent() <= 54) {
			gradepoint = 1.0;
		}
		else if (percent() >= 55 && percent() <= 59) {
			gradepoint = 1.5;
		}
		else if (percent() >= 60 && percent() <= 64) {
			gradepoint = 2.0;
		}
		else if (percent() >= 65 && percent() <= 69) {
			gradepoint = 2.5;
		}
		else if (percent() >= 70 && percent() <= 74) {
			gradepoint = 3.0;
		}
		else if (percent() >= 75 && percent() <= 79) {
			gradepoint = 3.5;
		}
		else if (percent() >= 80 && percent() <= 89) {
			gradepoint = 4.0;
		}
		else if (percent() >= 90 && percent() <= 100) {
			gradepoint =4.0;
		}
		return gradepoint;
	}
}

