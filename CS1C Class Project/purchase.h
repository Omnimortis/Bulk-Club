/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef PURCHASE_H_
#define PURCHASE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "date.h"
#include "member.h"
using namespace std;

class member; // Forward declaration of member


/************************************************************************
 * 				purchase Class
 * 	This class creates a purchase object with data members for
 * 	datamembers for itemName, quantity, unitPrice, pointer to associated
 * 	member, and purchase date. There are set and get functions for all of
 * 	these data members.
 ************************************************************************/
class purchase
{
public:
	purchase(); // constructor

	// non-default constructor
	purchase(string nameInit, int quantityInit, float priceInit,
			member& memberInit, int monthInit, int dayInit,
			int yearInit);

	// sets date to passed month, day and year
	void setDate(int month, int day, int year);

	// returns reference to date
	date& getDate();

	//sets item name member
	void setItemName(string nameSet);

	// returns item name
	string getItemName();

	// sets purchase quantity
	void setQuantity(int quantitySet);

	// returns item quantity
	int getQuantity();

	// sets unit price of purchase
	void setUnitPrice(float totalSet);

	// returns unit price of purchase
	float getUnitPrice();

	// set member associated with purchase
	void setMember(member& member);

	// return pointer to member
	member* getMember();

	// convert to string for printing
	string toString();

private:
	string itemName;
	int quantity;
	float unitPrice;
	member *bulkMember;
	date purchaseDate;
};

#endif /* PURCHASE_H_ */
