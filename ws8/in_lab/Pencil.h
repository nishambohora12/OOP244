


#ifndef SDDS_PENCIL_H
#define SDDS_PENCIL_H


#include"WriteInstrument.h"
#define HB_MAX 2
#define GRAPHITE_MAX 100


namespace sdds 
{


	class Pencil : public WriteInstrument
	{
	private:
		char pencil_HB_scale[HB_MAX+1];
		int pencil_graphite;
	public:
		Pencil();
		Pencil(const char* hbscale, int graphite);
		~Pencil();
		 void write(const char*);
		 void refill(int);
		 bool filled()const;
		 std::ostream& display(std::ostream& os)const;
	};

}


#endif