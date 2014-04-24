/*
 * purchase.h
 *
 *  Created on: Apr 23, 2014
 *      Author: nbailey4
 */

#ifndef PURCHASE_H_
#define PURCHASE_H_


#include <iostream>
#include <sstream>
#include <string>
#include "date.h"
#include "member.h"
using namespace std;


class purchase
{
public:
	purchase();
	purchase(string nameInit, int quantityInit,int totalInit,
			member& memberInit, int monthInit, int dayInit,
			int yearInit);
	void setDate(int month, int day, int year);
	date* getDate() const;
	void setItemName(string nameSet);
	string getItemName() const;
	void setQuantity(int quantitySet);
	int getQuantity() const;
	void setTotalAmount(int totalSet);
	int getTotalAmount() const;
	void setMember(member& member);
	member* getMember() const;
	string toString() const;

private:
	string itemName;
	int quantity;
	int totalAmount;
	member* bulkMember;
	date purchaseDate;

};



#endif /* PURCHASE_H_ */
