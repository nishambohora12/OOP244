#ifndef NAMESPACE_TOOLS_H 
#define NAMESPACE_TOOLS_H
#include <iomanip>
namespace sdds
{
	int getInt(int min, int max);
	// moves the cursor backwards
	void goBack(int n);
	// displays the user interface menu
	int menu(int noOfSamples);
	// Draws a line and adds a label if provided
	void line(int n, const char* label = nullptr);
}
#endif 