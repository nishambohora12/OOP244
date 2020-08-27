//Name:Nisham Bohora
//AddressID:nbohora@myseneca.ca  
//ID NO:1554469183
//This file contain the main function

// all required header filer are included
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

#include "File.h"
#include "Tools.h"
#include "PhoneDir.h"
#include "Contact.h"

using namespace std;
using namespace sdds;
//main function
int main() {
	phoneDir("SDDS Phone Directory", "phones.txt");
	return 0;
}

