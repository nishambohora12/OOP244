
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Robot.h
Section:NAB
*/
#ifndef SDDS_Robot_H
#define SDDS_Robot_H
#include "Parts.h"

namespace sdds {


	int const NICK_MAX_LEN = 10;


	class Robot //Class robot declaration
	{//All methods prototye are declared here
	private:
		//private memeber
		char r_nickname[NICK_MAX_LEN];
		int r_durability;
		Arms arms;

	public://public member
		Robot();
		Robot(const char* nickname, int armForce, int durability);
		~Robot();
		std::ostream& display() const;
		operator bool() const;




	};





}


#endif
