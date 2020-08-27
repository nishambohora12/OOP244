/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
File name:ParkingLot.cpp
*/

#include <iostream>
#include "ParkingSpot.h"
#include"ParkingLot.h"

using namespace std;
namespace sdds {


	void setEmpty(ParkingLot& Empty)// Function to set spots to zero
	{
		Empty.m_noOfParkingSpot = 0;
		Empty.m_parkingSpot = nullptr;
	}
	
	bool isEmpty(const ParkingLot& emp )//Function to check empty spot
	{
		
		if (emp.m_parkingSpot != nullptr) {
			return false;
		}
		else 
		return true;
	}
	void openParking(ParkingLot& openArea, int noOfSpots) //Function defination for Dynamic memory allocatin and set parking spot empty
	{
		openArea.m_parkingSpot = new ParkingSpot[noOfSpots];//Dynamic memory allocation
		openArea.m_noOfParkingSpot = noOfSpots;
		for (int i=0;i<noOfSpots;i++)
		{
			setEmpty(openArea.m_parkingSpot[i]);
		}

    }
	int parkCar(ParkingLot& parkarea)//Function defination to  search empty spot and park in empty spot
	{
		int i,index = -1;//index for found car
		for ( i = 0; i < parkarea.m_noOfParkingSpot; i++)
		{
		if (isEmpty(parkarea.m_parkingSpot[i]) == true)
			{
				parkCar(parkarea.m_parkingSpot[i]);
				index = i;
				i = parkarea.m_noOfParkingSpot;// ending for loop after the car is found

			}
			

		}
		return index;

	}
	bool returnCar(ParkingLot& retCar, int spotNo) //Function Defination check spot number,empty spot and print
	{
		if ((spotNo >= 0 && spotNo <= retCar.m_noOfParkingSpot) && (isEmpty(retCar.m_parkingSpot[spotNo
		])==false))
		{
			cout<< "Returning ";
				print(retCar.m_parkingSpot[spotNo]);
				freeSpot(retCar.m_parkingSpot[spotNo]);
				cout << endl;
				return true;


		}
		return false;
	}
	//Function Defination to Deallocate the allocated meomory
	void closeParking(ParkingLot& close)
	{
		int i;
		for (i = 0; i < close.m_noOfParkingSpot; i++)
		{
			if (isEmpty(close.m_parkingSpot[i]) == false)
			{
				returnCar(close, i);

			}
		
		} delete[] close.m_parkingSpot;//Deallocation of memory
		setEmpty(close);
	}
 }