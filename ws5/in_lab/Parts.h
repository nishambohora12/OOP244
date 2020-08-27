
// Parts.h
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:PArt.h
Section:NAB
*/
#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H

namespace sdds 
{
	const int MIN_FORCE = 50;//Constatn min force value declaration
	class Arms {//class arm declaration and prototype 

	private:
		int a_force;



	public://method prototype declaration
		Arms();//default constrcutor
		Arms(int arms_force);
		~Arms();//default destructor
		int getForce() const;
		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);

	};




}




#endif
