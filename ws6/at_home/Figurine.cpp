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
	Figurine::Figurine()
	{
		setEmpty();
	}
	Figurine::Figurine(const char* name, const char* pose, double value):f_pose(nullptr),f_copy(false) //Three argument consturctor
	{
		if (name == nullptr || pose == nullptr || name[0] == '\0' || pose[0] == '\0')//checking empty state
		{
			setEmpty();
		}

			
		else
		{//Reusng code
			setName(name);
			setPose(pose);
			setPrice(value);
			
		}
	}
	void Figurine::setEmpty()
	{
		f_pose = nullptr;
		f_price = 0.0;
		strcpy(f_name, "");
	     f_copy = false;
	}

	Figurine::~Figurine() //Destructor
	{
		delete[] f_pose;
	}
	Figurine::Figurine(const Figurine& RO)//Copy constructor
	{
		f_pose = nullptr;
		setName(RO.f_name);
		setPrice(RO.f_price);
		if (RO.f_pose == nullptr || RO.f_pose[0] == '\0')//Checking RO value empty state
		{
			f_pose = nullptr;
		}
		else
		{
			setPose(RO.f_pose);
		}
		f_copy = true;
	}
	void Figurine::setName(const char* name)//function to setname
	{

		if (strlen(name) > MAX_NAME_LEN)
		{
			strncpy(f_name, name, MAX_NAME_LEN);
		}
		else {
			strncpy(f_name, name, strlen(name) + 1);

		}
	}
	void Figurine::setPose(const char* pose)//Function to set pose
	{
		delete[] f_pose;
		f_pose = new char[strlen(pose) + 1];//Dynamic mermory allocation 
		strncpy(f_pose, pose, strlen(pose));
		f_pose[strlen(pose)] = '\0';//for null byte


	}
	void Figurine::setPrice(double value)//Functio to set price
	{
		if (value < 1)
		{
			f_price = DEFAULT_PRICE;
		}
		else f_price = value;

	}
	Figurine& Figurine::operator=(const Figurine& RO)//copy operator
	{
		if (this != &RO)//To prevent self assignment
		{
			setPrice(RO.f_price);
			setName(RO.f_name);

			if (RO.f_pose == nullptr || RO.f_pose[0] == '\0')
			{
				f_pose = nullptr;
			}

			else
			{
				setPose(RO.f_pose);
			}
			f_copy = true;

		}
		return *this;
	}
	//Display function Defination
	ostream& Figurine::display()const
	{


		if (*this)
		{
			cout << "This Figurine has not yet been sculpted" << endl;
			if (isCopy())
			{
				cout << "This is a replica of emptiness" << endl;
			}
		}

		else {
			cout << "Figurine Details" << endl;
			cout << "Name: " << f_name << endl;
			cout << "Pose: " << f_pose << endl;
			cout << "Price: " << setprecision(2) << fixed << f_price << endl;
			if (isCopy())
			{
				cout << "This is a replica" << endl;
			}
		}

		return cout;


	}
	Figurine::operator bool() const//Bool operator function to check 
	{
		return f_name[0] == '\0';
	}

	const char* Figurine::getName()const//Function to access name
	{
		return f_name;
	}
	const char* Figurine::getPose()const//function to access pose
	{
		return f_pose;
	}
	double Figurine::getPrice()const//function to accses price
	{
		return f_price;
	}
	
	bool Figurine::isCopy() const 
	{
		return f_copy;
	}


	//Bool operator to check wheather object is same or not
	bool operator==(const Figurine& A, const Figurine& B)
	{

		return A.getName() == B.getName() && A.getPose() == B.getPose() && A.getPrice() == B.getPrice();
	}
}
