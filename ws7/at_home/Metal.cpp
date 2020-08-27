/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Metal.cpp
Section:NAB
*/



#define _CRT_SECURE_NO_WARNINGS
#include"Metal.h"
#include<iostream>
#include<cstring>
using namespace std;
namespace sdds
{
	Metal::Metal() :Ore()//Default Constructor Function
	{
		safeEmpty();
	}
	Metal::Metal(double m_weight, int purityOfMetal, const char* classification, const char* metalName, double metalMohs):Ore(m_weight,purityOfMetal,classification)//Five Arguement Consturctor, utilize another three arguemnent constructor of metal
	{
		if (metalName == nullptr || metalName[0] == '\0')//Checking parameter state
		{
			safeEmpty();
		}
		else
		{
			if (strlen(metalName) > NAME_LEN)
			{
				m_name = new char[NAME_LEN];//Dynamic Memory Allocating
				strncpy(m_name, metalName, NAME_LEN);

			}
			else
			{
				m_name = new char[strlen(metalName) + 1];//Dynamic Memory Allocating
				strncpy(m_name, metalName, strlen(metalName) + 1);
			}
			if (metalMohs > 0)
			{
				m_mohs = metalMohs;

			}
			else
			{
				m_mohs = DEFAULT_MOHS;
			}
		}
	}
	Metal::~Metal() //Default Destructor
	{
		delete[] m_name;//Memory Deallocation
	}
	void Metal::safeEmpty()//Function to set object in empty state
	{
		
		m_mohs = 0.0;
		m_name = nullptr;
	}
	void Metal::refine()//Function to refine Metal 
	{
		if (Ore::refine() == true)//Condition check using Ore Function
		{
			m_mohs += 1;
		}
	}
	std::ostream& Metal::display(std::ostream& os)const //Display function Defination (ostream)
	{
		
			if (m_name==nullptr)
			{
				os << "This metal is imaginary" << endl;
			}

			else 
			{

				os << "Name: " << m_name << endl;
				Ore::display(os);//Calling Display function of ore
				os << "Mohs: " << m_mohs << endl;

			}

			return os;
		

	}
	std::istream& Metal::input(std::istream& is)
	{
		char tempArray[NAME_LEN + 1];
		strcpy(tempArray, "");
		double tempMohs = 0.0;
		cout << "Enter a value for this metal's name: ";
		is.getline(tempArray, NAME_LEN);
		if (m_name != nullptr)
		{//Dealloacting before alloaction other one to prevent memory leak
			delete[] m_name;
			m_name = nullptr;
		}
		m_name = new char[strlen(tempArray) + 1];

		strcpy(m_name, tempArray);
		cout << "Enter a value for this metal's mohs: ";

		is >> tempMohs;
		is.clear();
		is.ignore(2000, '\n');

		if (tempMohs > 0)//Condition check
		{
			m_mohs=DEFAULT_MOHS;
		}

		m_mohs = tempMohs;
		Ore::input(is);//Calling Input Function From Ore to set the variables

		return is;
	}



	//Helper Function Overload
	std::istream& operator>>(std::istream& is, Metal& met) //Input function overload
	{
		met.input(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const Metal& met)// Display Function overload
	{
		os << "Metal" << endl;
		met.display(os);
		return os;
	}
}