
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
File name:ParkingLot.h
*/
#ifndef SDDS_PARKINGLOT_H__
#define SDDS_PARKINGlOT_H__
#include "ParkingSpot.h"
namespace sdds {
	//Declaration of Structure for parkinglot
	struct ParkingLot {

		int m_noOfParkingSpot;
		ParkingSpot* m_parkingSpot;


	};
	//Function prototype of all function of ParkingLot.cpp
	void setEmpty(ParkingLot& Empty);
	bool isEmpty(const ParkingLot&);
	void openParking(ParkingLot& openArea, int noOfParkingSpots);
	int parkCar(ParkingLot& parkarea);
	bool returnCar(ParkingLot& retCar, int spotNo);
	void closeParking(ParkingLot& close);


}

#endif

