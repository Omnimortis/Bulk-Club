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
#include "date.h"
#include "member.h"
using namespace std;

class member;

class purchase
{
public:
	purchase();

	purchase(string& nameInit, int quantityInit, float totalInit,
			member& memberInit, int monthInit, int dayInit,
			int yearInit);

	void setDate(int month, int day, int year);

	date& getDate();

	void setItemName(string& nameSet);

	string getItemName();

	void setQuantity(int quantitySet);

	int getQuantity();

	void setTotalAmount(float totalSet);

	float getTotalAmount();

	void setMember(member& member);

	member* getMember();

	string toString();

private:
	string itemName;
	int quantity;
	float totalAmount;
	member *bulkMember;
	date purchaseDate;
};

#endif /* PURCHASE_H_ */
