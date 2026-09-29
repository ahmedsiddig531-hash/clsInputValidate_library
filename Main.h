#pragma once
#include <iostream>
#include "clsdate.h"

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number,  double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate MiddleDate, clsDate Date1, clsDate Date2)
	{
		if (clsDate::IsDate1BeforeDate2(Date1, Date2))
		{
			// Date1 is the smaller date
			return
				(clsDate::IsDate1EqualDate2(MiddleDate, Date1) ||
					clsDate::IsDate1BeforeDate2(Date1, MiddleDate))
				&&
				(clsDate::IsDate1EqualDate2(MiddleDate, Date2) ||
					clsDate::IsDate1BeforeDate2(MiddleDate, Date2));
		}
		else
		{
			// Date2 is the smaller date
			return
				(clsDate::IsDate1EqualDate2(MiddleDate, Date2) ||
					clsDate::IsDate1BeforeDate2(Date2, MiddleDate))
				&&
				(clsDate::IsDate1EqualDate2(MiddleDate, Date1) ||
					clsDate::IsDate1BeforeDate2(MiddleDate, Date1));
		}
	}
	 
	
	static int ReadIntNumberBetween(int From, int To, string Message)
	{
		int Number;
		bool IsValid = false;
		do
		{

			if (IsValid)
			{
				cout << Message << endl;
			}

			cout << "\nEnter An Integer Number Between " << From << " To " << To << " ? ";
			cin >> Number;

			IsValid = true;

		} while (Number < From || Number > To);

		return Number;	 
  }

	static double ReadDoubleNumberBetween(double From, double To, string Message)
	{
		int Number;
		bool IsValid = false;

		do
		{
			if (IsValid)
			{
				cout << Message << endl;
			}

			cout << "\nEnter A Double Number Between " << From << " To " << To << " ? ";
			cin >> Number;

			IsValid = true;

		} while (Number < From || Number > To);

		return Number;
	}

	static int ReadIntNumber(string Message)
	{
		int Number;
		bool IsValid = false;

		do
		{
			if (IsValid)
			{
				cout << Message << endl;
			}

			cout << "Enter An Integer Number: ";
			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				IsValid = true;
			}
			else
			{
				IsValid = false;
			}

		} while (IsValid);

		return Number;
	}

	static double ReadDoubleNumber(string Message)
	{
	 double Number;
		bool IsValid = false;

		do
		{
			if (IsValid)
			{
				cout << Message << endl;
			}

			cout << "Enter An Integer Number: ";
			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				IsValid = true;
			}
			else
			{
				IsValid = false;
			}

		} while (IsValid);

		return Number;
	}
};

