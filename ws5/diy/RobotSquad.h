
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:RobotSquad.h
Section:NAB
*/



#ifndef SDDS_ROBOTSQUAD_H
#define SDDS_ROBOTSQUAD_H
#include "Robot.h"
#include "Parts.h"


namespace sdds
{
	class RobotSquad {//Robot squad class declartion
		char* name;// for dynamic allocation of memory for name
		Robot* rosterRobots;//for dynamic allocation of memory of Robots class
		int r_noOfRobotCount;//For number of robot in rosterRobots
		
	public:
		//All prototypes
		RobotSquad(const char* r_name = "No Name");//Constructor for sigle arguement
		~RobotSquad();//destructor
		const char* getName()const;//access to get name
		int getCount()const;//access to get no of robot in  roaster
		std::ostream& display() const;
		Robot* getRoster() const;
		RobotSquad& operator+=(Robot& robots);//operator to add  robot 
		RobotSquad& operator--();// unary operator to remove robots



	};
}
#endif