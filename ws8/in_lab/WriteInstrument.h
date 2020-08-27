//Name:Nisham Bohora
//ID:154469183
//File:WriteInstrument.h

#ifndef _SDDS_WRITEINSTRUMENT_H
#define _SDDS_WRITEINSTRUMENT_H
#include<iostream>
namespace sdds
{
	class WriteInstrument 
	{
	public:
		virtual ~WriteInstrument() {};
		virtual void write(const char*) = 0;
		virtual void refill(int) = 0;
		virtual bool filled() const = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;;
	};

}

#endif