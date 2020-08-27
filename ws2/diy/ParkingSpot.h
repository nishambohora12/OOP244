
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
File name:ParkingSpot.h
*/
#ifndef SDDS_PARKINGSPOT_H__
#define SDDS_PARKINGSPOT_H__
namespace sdds
{  //Structure Declaration for parking spot
	struct ParkingSpot {

		char m_licensePlate[9];
		char* m_modelOfCar;
	};
	//Function prototype of all function of Parkingspot.cpp
	void setEmpty(ParkingSpot& seneca);

	bool isEmpty(const ParkingSpot& emp);
	void freeSpot(ParkingSpot& freearea);
	void print(const ParkingSpot& printDetail);
	void parkCar(ParkingSpot& carDetail);

}


#endif