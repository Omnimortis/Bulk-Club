/**************************************************************************
 * AUTHOR		: Matt Clark
 * Assignment #1: Employee
 * CLASS		: CS1C
 * SECTION		: TTh: 8:30AM - 9:50AM
 * Due Date		: 2/11/2014
 *************************************************************************/
#include "date.h"

//default constructor
date::date()
{
	month = 0;
	day = 0;
	year = 0;
}

//non-default constructor
date::date(int initMonth, int initDay, int initYear)
{
	month = initMonth;
	day = initDay;
	year = initYear;
}

//mutator functions
void date::setDate(int monthInput, int dayInput, int yearInput)
{
	month = monthInput;
	day = dayInput;
	year = yearInput;
}

void date::getDate(int& monthOutput, int& dayOutput, int& yearOutput) const
{
	monthOutput = month;
	dayOutput = day;
	yearOutput = year;
}

void date::setDay(int dayInput)
{
	day = dayInput;
}

void date::getDay(int& dayOutput) const
{
	dayOutput = day;
}

void date::setMonth(int monthInput)
{
	month = monthInput;
}

void date::getMonth(int& monthOutput) const
{
	monthOutput = month;
}

void date::setYear(int yearInput)
{
	year = yearInput;
}

void date::getYear(int& yearOutput) const
{
	yearOutput = year;
}

//to string function
string date::toString() const
{
	string rtn = "";		//string to return
	string temp;			//string for converting int to string
	ostringstream convert;	//stream for converting int to string

	switch (month)
	{
	case 1:
		rtn += "January ";
		break;
	case 2:
		rtn += "February ";
		break;
	case 3:
		rtn += "March ";
		break;
	case 4:
		rtn += "April ";
		break;
	case 5:
		rtn += "May ";
		break;
	case 6:
		rtn += "June ";
		break;
	case 7:
		rtn += "July ";
		break;
	case 8:
		rtn += "August ";
		break;
	case 9:
		rtn += "September ";
		break;
	case 10:
		rtn += "October ";
		break;
	case 11:
		rtn += "November ";
		break;
	case 12:
		rtn += "December ";
		break;
	}

	convert << day;				//convert day int to string
	temp = convert.str();
	rtn += (temp + ", ");
	convert.str("");

	convert << year;			//convert year int to string
	temp = convert.str();
	rtn += (temp);
	convert.str("");

	return rtn;
}
