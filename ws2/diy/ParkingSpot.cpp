/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
File name:ParkingSpot.cpp

*/
#include "ParkingSpot.h"
#include<cstring>
#include <iostream>
#include "utils.h"
using namespace std;
namespace sdds
{
	void setEmpty(ParkingSpot& empty)
	{
		
		for (int i = 0; i < 8; i++) {//looping through string
			empty.m_licensePlate[i] = '\0';//set licenseplate to null
		}
		empty.m_modelOfCar = nullptr;//set make and model to null pointer

	}

	bool isEmpty(const ParkingSpot& emp) {//Function to check make and model is null or not and retrun treu or false
		if (emp.m_modelOfCar != nullptr)
		{
			return false;
		}
		else return true;
		
	}
	void freeSpot(ParkingSpot& freearea)//Function for deallocation of memory and setempty
		{
			delete[] freearea.m_modelOfCar;
	setEmpty(freearea);
	}
	void print(const ParkingSpot& printDetail) {//Function to print car detail
		cout << printDetail.m_modelOfCar<<", plate number: " << printDetail.m_licensePlate ;



	}
	void parkCar(ParkingSpot& carDetail) {
		cout << "Make and Model: ";
		carDetail.m_modelOfCar = new char[60];//Dynamic memory allocation
		read(carDetail.m_modelOfCar, 60, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
		cout << "License Plate: ";
		read(carDetail.m_licensePlate, 8, "Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");


	}



}
