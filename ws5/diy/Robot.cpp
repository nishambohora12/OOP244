
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
		r_durability = 0;

	}
	Robot::~Robot() {
		////Destructor
	}
	Robot::Robot(const char* nickName, int armForce, int legSpeed, int durability)//Constructor that accept 3 arguement
	{
		if (nickName == nullptr || nickName[0] == '\0')
		{
			r_nickname[0] = '\0';
			r_durability = 0;//setting to safe empty space
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
			r_arms = armForce;
			r_legs = legSpeed;
		}
	}
	ostream& Robot::display() const//Fucntion to display input value in order
	{
		if (r_nickname[0] == '\0' || r_durability == 0)
		{
			cout << "This Robot isn't operational" << endl;
		}
		else
		{
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << r_nickname << endl;
			cout << "Arm Power: " << r_arms.getForce() << endl;
			cout << "Durability: " << r_durability << endl;
			cout << "Legs: " << r_legs.getSpeed() << endl;
		}
		return cout;
	}
	Robot::operator bool() const//Operational Function to check condition
	{
		return r_nickname == nullptr || r_durability == 0;
	}
	Arms Robot::getArms() {//function to return or access arms
		return r_arms;

	}
	Legs Robot::getLegs() {//function to return or access legs
		return r_legs;

	}
	Robot& Robot::operator-=(int value) {//Operational function to decreased durablity by giving parameter
		r_durability -= value;
		if (r_durability < 1)
		{
			r_durability = 0;
		}

		return *this;
	}

	//Helper function for robot fighting
	void box(Robot& firstRobot, Robot& secondRobot)
	{

		cout << "Attempting to begin a Robot boxing match" << endl;
		if (firstRobot || secondRobot)//checking empty state
		{
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
		}
		else
		{
			cout << "Both participants are operational... beginning the bout" << endl;
			while (!firstRobot && !secondRobot)
			{//Speed comparsion of two robot

				if (firstRobot.getLegs().getSpeed() > secondRobot.getLegs().getSpeed())
				{//when first robot is faster
					secondRobot -= firstRobot.getArms().getForce();

					if (!secondRobot)
					{
						firstRobot -= secondRobot.getArms().getForce();

					}
				}
				else {//when second robot is faster
					firstRobot -= secondRobot.getArms().getForce();
					if (!firstRobot)
					{
						secondRobot -= firstRobot.getArms().getForce();

					}
				}
			}

			if (!firstRobot)//first robot win display
			{
				cout << "The bout has concluded... the winner is: " << endl;
				firstRobot.display();
			}
			else if (!secondRobot)//second robot win display
			{
				cout << "The bout has concluded... the winner is: " << endl;
				secondRobot.display();
			}
			else
			{
				cout << "No bout will begin" << endl;
			}
		}

	}

}
