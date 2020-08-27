

/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Part.cpp
Section:NAB
*/
#include<iostream>
#include"Parts.h"

using namespace std;
namespace sdds {


	Arms::Arms() {//Function for default constructor
		a_force = 0;
	}
	Arms::Arms(int arms_force) {
		if (arms_force < 1) {
			a_force = MIN_FORCE;
		}
		else a_force = arms_force;
	}
	Arms::~Arms() {//Function  for destructor

	}
	int Arms::getForce() const {//Function that return number of force
		return a_force;
	}


	Arms& Arms::operator++() {//Operational function
		return(*this) += 10;
	}
	Arms Arms::operator++(int) {//Function to add force
		Arms before = *this;
		(*this) += 10;
		return before;
	}
	Arms& Arms::operator+=(int value) {//overloading operational funciton to add arm forces.
		a_force = a_force + value;
		if (a_force < 1) a_force = 0;
		return *this;
	}
	Legs::Legs() {//Constructor
		l_speed = 0;
	}
	Legs::Legs(int legSpeed) {//Constructor to recieved single parameter
		if (legSpeed < 1) {
			l_speed = MIN_SPEED;

		}
		else l_speed = legSpeed;
	}
	Legs::~Legs() {//Destructor
		//no needed
	}
	int Legs::getSpeed()const {// function to access speed 
		return l_speed;
	}
	Legs& Legs::operator-=(int value) {
		l_speed = l_speed - value;
		if (l_speed < 1)
			l_speed = 0;
		return *this;
	}

	//Helper function that compare legs of robots
	bool operator>(const Legs& firstRobotLeg, const Legs& secondRobotLeg) {
		return firstRobotLeg.getSpeed() > secondRobotLeg.getSpeed();
			


	}
	bool operator<(const Legs& firstRobotLeg, const Legs& secondRobotLeg) {
		return firstRobotLeg.getSpeed() < secondRobotLeg.getSpeed();
			

	}
	//Helper Function that compare
	bool operator>(const Arms& firstArms, const Arms& secondArms) {
		return firstArms.getForce() > secondArms.getForce();
			

	}
	bool operator<(const Arms& firstArms, const Arms& secondArms) {
		return firstArms.getForce() < secondArms.getForce();
			
	}

}