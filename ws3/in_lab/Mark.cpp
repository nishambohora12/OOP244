
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
*/

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

	}
	bool Mark::isEmpty()const
	{
		return m_displayMode == DSP_UNDEFINED && m_mark ==-1 && m_outof == 100;
	}
	int Mark::percent()const 
	{
		int result = m_mark / m_outof * 100 + 0.5;
		return result;
	}

	double Mark::rawValue()const {
		 return  m_mark / m_outof;
		
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
	ostream& Mark:: display() const
	{
		if (isEmpty())
		{
			cout << "Empty Mark object!";

		}
		else if (m_displayMode == DSP_RAW)
		{
			cout << rawValue();
		}
		else if (m_displayMode == DSP_PERCENT)
		{
			cout << "%" << percent();

		}
		else if (m_displayMode == DSP_ASIS)
		{
			cout << m_mark << "/" << m_outof;

		}
		else if (m_displayMode == DSP_UNDEFINED)
		{
			cout << "Display mode not set!";

		}
		else {
			cout << "Invalid Mark Display setting!";
		}
		return cout;
	}
}

