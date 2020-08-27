/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Figurine.h
Section:NAB
*/

#ifndef SDDS_Figurine_H
#define SDDS_Figurine_H
#define MAX_NAME_LEN 20
#define	 DEFAULT_PRICE 25.25
namespace sdds 
{
	class Figurine{//Class Declaration
	private:

		char f_name[MAX_NAME_LEN + 1];
		char* f_pose=nullptr;
		double f_price;

	

	public://Public method declaration
		Figurine();
		Figurine(const char* name, const char* pose, double value);
		~Figurine();
		Figurine(const Figurine& RO);
		void setName(const char* name);
		void setPose(const char* pose);
		void setPrice(double value);
		std:: ostream& display()const;
		operator bool() const;


	};




}
#endif