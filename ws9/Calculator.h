// Calculator.h
// WS09 in-lab
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
*/

#ifndef SDDS_CALCULATOR_H
#define SDDS_CALCULATOR_H
#include<iostream>
using std::endl;
namespace sdds
{
	template<typename T, int N>//For Template
	class Calculator//Declaration of Class Calculator
	{
	private: T c_results[N];//Private Member
	public:
		Calculator() //Default Constructor
		{
			for (int i = 0; i < N; i++)
			{
				c_results[i] = 0;
			}
		}
		void add(const T* first, const T* second)//Add function  Template
		{

			for (int i = 0; i < N; ++i)
			{
				c_results[i] = first[i] + second[i];
			}
		}

		void subtract(const T* first, const T* second)//Subtract function template
		{
			for (int i = 0; i < N; ++i)
			{
				c_results[i] = first[i] - second[i];
			}
		}

		void multiply(const T* first, const T* second)//Multiply function templat
		{
			for (int i = 0; i < N; ++i)
			{
				c_results[i] = first[i] * second[i];
			}
		}
		void divide(const T* first, const T* second)//Divide Function template
		{
			for (int i = 0; i < N; ++i)
			{
				c_results[i] = first[i] / second[i];
			}
		}
		std::ostream& display(std::ostream& os) const//Display Function to show in console
		{

			for (int i = 0; i < N; ++i)
			{
				os << c_results[i];
				if (i < N - 1)
				{
					os << ",";
				}
			}


			os << endl;

			return os;
		}
		Calculator& operator+=(const T* arr)//operator += overload
		{
			add(c_results, arr);
			return *this;
		}
		Calculator& operator-=(const T* arr)//operator -= overload
		{
			subtract(c_results, arr);
			return *this;
		}
		Calculator& operator*=(const T* arr)//operator *= overload
		{
			multiply(c_results, arr);
			return *this;
		}
		Calculator& operator/=(const T* arr)//operator /= overlaod
		{
			divide(c_results, arr);
			return *this;
		}

	};

}

#endif