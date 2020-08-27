/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Figurine.cpp
Section:NAB
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Figurine.h"
#include<iomanip>
#include<cstring>
using namespace std;
namespace sdds
{
	Figurine::Figurine() :f_pose(nullptr)
	{
		strcpy(f_name, "");
		f_pose = nullptr;
		f_price = 0.0;

	}
	Figurine::Figurine(const char* name, const char* pose, double value) //Three argument consturctor
	{
		if (name == nullptr|| pose == nullptr || name[0]=='\0' || pose[0] == '\0' )//checking empty state
		{
			strcpy(f_name, "");
			f_pose = nullptr;
			f_price = 0.0;
		}
		else
		{//Reusng code
			setName(name);
			setPose(pose);
			setPrice(value);
		}
	}
	Figurine::~Figurine() //Destructor
	{
		delete[] f_pose;
	}
	Figurine::Figurine(const Figurine& RO )//Copy constructor
	{
		setName(RO.f_name);
		setPrice(RO.f_price);
		if(RO.f_pose==nullptr || RO.f_pose[0]=='\0')//Checking RO value empty state
		{
			f_pose = nullptr;
		}
		else
		{
			setPose(RO.f_pose);
		}

	}
	void Figurine::setName(const char* name)//function to setname
	{

		if (strlen(name) > MAX_NAME_LEN)
		{
			strncpy(f_name, name, MAX_NAME_LEN);
		}
		else {
			strncpy(f_name, name, strlen(name)+1);
			
		}
	}
	void Figurine::setPose(const char* pose)//Function to set pose
	{
		delete[] f_pose;
		f_pose = nullptr;
		f_pose = new char[strlen(pose) + 1];//Dynamic mermory allocation 
		strncpy(f_pose, pose, strlen(pose));
		f_pose[strlen(pose)] = '\0';

	}
	void Figurine::setPrice(double value)//Functio to set price
	{
		if (value < 1)
		{
			f_price = DEFAULT_PRICE;
		}
		else f_price= value;

	}
	std::ostream& Figurine::display()const//Function to display as order
	{
		
		
			if (*this)
			{
				cout << "This Figurine has not yet been sculpted" << endl;
			}

			else {
				cout << "Figurine Details" << endl;
				cout << "Name: " << f_name << endl;
				cout << "Pose: " << f_pose << endl;
				cout << "Price: " << setprecision(2) << fixed << f_price << endl;
			}

			return cout;
		

	}
	Figurine::operator bool() const//Bool operator function to check 
	{
		return f_name[0] == '\0';
	}
}
