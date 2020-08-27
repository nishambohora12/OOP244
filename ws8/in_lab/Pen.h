
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Pen.cpp
Section:NAB
*/
#ifndef SDDS_PEN_H
#define SDDS_PEN_H
#include "WriteInstrument.h"
#define INK_MAX 50
namespace sdds 
{
	class Pen: public WriteInstrument
	{ 
	private:
		char* pen_style;
		int pen_ink;
	public:
		Pen();
		Pen(const char* style, int inkAmount);
		~Pen();
		void write(const char* wordText);
		void refill(int newInk);
		bool filled()const;
		std::ostream& display(std::ostream& os)const;
	};
}

#endif