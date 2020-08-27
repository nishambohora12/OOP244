
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


	Arms ::Arms(){//Function for default constructor
		a_force = 0;
	}
	Arms::Arms(int arms_force) {
		if (arms_force < 1) {
			a_force = MIN_FORCE;
		}
		else a_force = arms_force;
	}
	Arms::~Arms(){//Function  for destructor

	}
   int Arms:: getForce() const {//Function that return number of force
	   return a_force;
	}


   Arms& Arms::operator++() {//Operational function
	   return(*this) += 10;
   }
	Arms Arms::operator++(int ) {//postfix function
		Arms before = *this;
		(*this) += 10;
		return before;
	}
	Arms& Arms::operator+=(int value) {//overloading operational funciton to add arm forces.
		a_force = a_force + value;
		if (a_force < 1) a_force = 0;
			return *this;
	}

}