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

class member;

class purchase
{
public:
	purchase();

	purchase(string nameInit, int quantityInit, float priceInit,
			member& memberInit, int monthInit, int dayInit,
			int yearInit);

	void setDate(int month, int day, int year);

	date& getDate();

	void setItemName(string nameSet);

	string getItemName();

	void setQuantity(int quantitySet);

	int getQuantity();

	void setUnitPrice(float totalSet);

	float getUnitPrice();

	void setMember(member& member);

	member* getMember();

	string toString();

private:
	string itemName;
	int quantity;
	float unitPrice;
	member *bulkMember;
	date purchaseDate;
};

#endif /* PURCHASE_H_ */
