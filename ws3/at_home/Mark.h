/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:mark.h
*/

 #ifndef SDDS_MARK_H
 #define SDDS_MARK_H

#include <iostream>


namespace sdds {

	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;
	const int DSP_GPA = 4;
	const int DSP_LETTER = 5;


	class Mark {
	private:
		char m_name[51];
		int m_displayMode;
		double m_mark;
		int m_outof;
		void flushkeyboard()const;
		void prnLetter()const;

	public://All Protype for public function of class
		void set(int displayMode);
		void set(double mark, int outof = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display(int width = 55)const;
		void set(const char* name);
		void set(const char* name, double rawMark, int outof = 1);
		bool readName(const char* prompt, int maxLen = 50);
		void changeOutOf(int value);
		double GPA()const;
		double letterBasedGPA()const;
		



	};
}
#endif