/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:RobotSquad.cpp
Section:NAB
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "RobotSquad.h"

using namespace std;
namespace sdds
{


	
	RobotSquad::RobotSquad(const char* r_name) {//Function difination for constructor that accept single arguements
		name = new char[11];//Memory allocation
		strncpy(name, r_name, 10);
		name[10] = '\0';
		r_noOfRobotCount = 0;
		rosterRobots = nullptr;
	}
	RobotSquad::~RobotSquad()//Function defination for destructor
	{
		delete[] name;//Dellocation of memory 
		delete[] rosterRobots;//Dellocation of memory

	}
	const char* RobotSquad::getName()const
	{
		return name;
	}
	int RobotSquad::getCount()const {
		return r_noOfRobotCount;

	}
	
	Robot* RobotSquad::getRoster() const {
		return this->rosterRobots;
	}
	ostream& RobotSquad::display() const {//Function defination to Display in order
		{
			if (r_noOfRobotCount == 0)  // Checking empty state
			{
				cout << "Squad **" << name << "** has no members" << endl;
			}
			else
			{
				cout << "***Squad Summary***" << endl;
				cout << "Name: " << name << endl;
				cout << "Roster Count: " << r_noOfRobotCount<< endl;
				cout << "Roster:" << endl;
				for (int i = 0; i < r_noOfRobotCount; i++)
				{
					rosterRobots[i].display();
				}
			}
			return cout;
		}

	}
	RobotSquad& RobotSquad::operator+=(Robot& robots)//Fucntion defination For dynamic memory increament while adding more robots
	{
		Robot* temp = new Robot[r_noOfRobotCount + 1];//Memory allocation
		for (int i = 0; i < r_noOfRobotCount; i++) {
			temp[i] = rosterRobots[i];
		}
		r_noOfRobotCount++;
		delete[] rosterRobots;//delete current arrays
		rosterRobots = temp;//change to point to temp
		rosterRobots[r_noOfRobotCount - 1] = robots;
		return *this;

	}
	RobotSquad& RobotSquad::operator--()
	{
		if (rosterRobots == nullptr) {//checking empty state
			cout << "This squad **" << name << "** has no members or is uninitialized. Can't do --." << endl;
		}
		else 
		{
			if (r_noOfRobotCount == 0) 
			{
				rosterRobots = nullptr; //safe empty space

			}
			else 
			{
				Robot* temp = new Robot[r_noOfRobotCount - 1];
				for (int i = 0; i < r_noOfRobotCount - 1; i++)
				{
					temp[i] = rosterRobots[i];
				}
				delete[] rosterRobots;
				rosterRobots = temp;
				r_noOfRobotCount--;
			}
		}
		return *this;
	}


 }