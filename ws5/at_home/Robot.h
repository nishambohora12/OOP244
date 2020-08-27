
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
		Arms r_arms;
		Legs r_legs;

	public://public member
		Robot();
		Robot(const char* nickName, int armForce,int legSpeed,int durability);
		~Robot();
		std::ostream& display() const;
		operator bool() const;
		Arms getArms();
		Legs getLegs();
		Robot& operator-=(int);
	};

	void box(Robot& firstRobot, Robot& secondRobot);



}


#endif