// Robot.cpp
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Robot.cpp
Section:NAB
*/
#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include "Robot.h"
#include "Parts.h"
#include <cstring>
using namespace std;


namespace sdds
{

	Robot::Robot()//Default constructor
	{
		r_nickname[0] = '\0';
		r_durability = -1;
		arms = -1;

	}
	Robot::~Robot() {
		////Destructor
	}
	Robot::Robot(const char* nickName, int armForce, int durability)//Constructor that accept 3 arguement
	{
		if (nickName == nullptr || nickName[0] == '\0')
		{
			Robot();//setting to safe empty space
		}
		else
		{
			if (strlen(nickName) > NICK_MAX_LEN)
			{
				strncpy(r_nickname, nickName, NICK_MAX_LEN + 1);
			}
			else 
			{
				strcpy(r_nickname, nickName);
			}
			if (durability < 1)
			{
				r_durability = 100;
			}
			else r_durability = durability;
			arms = armForce;
		}
	}
	ostream& Robot::display() const//Fucntion to display input value in order
	{
		if (r_nickname[0] == '\0' || r_durability == -1)
		{
			cout << "This Robot isn't operational" << endl;
		}
		else
		{
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << r_nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << r_durability << endl;
		}
		return cout;
	}
	Robot::operator bool() const//Operational Function to check condition
	{
		return r_nickname == nullptr || r_durability == -1;
	}

}
