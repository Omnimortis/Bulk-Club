/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class date
{
public:
	//default constructor
	date();

	//non-default constructor
	date(int initMonth, int initDay, int initYear);

	//mutator functions
	 void setDate(int monthInput, int dayInput, int yearInput);

	 void getDate(int& monthOutput, int& dayOutput, int& yearOutput) const;

	 void setDay(int dayInput);

	 int getDay() const;

	 void setMonth(int monthInput);

	 int getMonth() const;

	 void setYear(int yearInput);

	 int getYear() const;

	 //to string function for printing date
	 string toString() const;

private:
	 //data table
	 int month;
	 int day;
	 int year;
};

#endif /* DATE_H_ */
