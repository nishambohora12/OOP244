/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:MarksReport.h
*/
#ifndef SDDS_MARKSREPORT_H
#define SDDS_MARKSREPORT_H

#include "Mark.h"

namespace sdds
{
	class MarksReport //Class Marks report declaration
	{
	private:
		Mark* m_mark;
		char* m_reportname;
		int m_noOfMarks;
	public://Public Method of class ,prototype
		void initialize();
		void getMarks();
		void print();
		void terminate();


	};

}
#endif