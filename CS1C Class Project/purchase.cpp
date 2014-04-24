/*
 * purchase.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: nbailey4
 */

#include "purchase.h"

purchase::purchase(): itemName(" "), quantity(0), totalAmount(0), bulkMember(NULL)
{

}

purchase::purchase(string nameInit, int quantityInit,int totalInit,
		member& memberInit, int monthInit, int dayInit,
		int yearInit): itemName(nameInit), quantity(quantityInit), totalAmount(totalInit),
			bulkMember(&memberInit),purchaseDate(monthInit, dayInit, yearInit)
{

}

void purchase::setDate(int monthInit, int dayInit, int yearInit)
{
	purchaseDate.setDate(monthInit, dayInit, yearInit);
}

//date* purchase::getDate() const
//{
//	return &purchaseDate;
//
//}

void purchase::setItemName(string nameSet)
{
	itemName = nameSet;
}

string purchase::getItemName() const
{
	return itemName;
}

void purchase::setQuantity(int quantitySet)
{
	quantity = quantitySet;
}

int purchase::getQuantity() const
{
	return quantity;
}

void purchase::setTotalAmount(int totalSet)
{
	totalAmount = totalSet;
}

int purchase::getTotalAmount() const
{
	return totalAmount;
}

void purchase::setMember(member& member)
{
	bulkMember = &member;
}

member* purchase::getMember() const
{
	return bulkMember;

}

string purchase::toString() const
{

		string rtn = "";
	    string temp;
	    ostringstream convert;

//	    rtn += "Member Name: " + bulkMember->getName() + "\n";
//
//	    convert << bulkMember->getID();
//	    temp = convert.str();
//	    rtn += ("Member Number: " + temp + "\n");
//	    convert.str("");
//
//	    if (type == true)
//	        temp = "Preferred";
//	    else
//	        temp = "Basic";
//	    rtn += ("Membership Type: " + temp + "\n");
//
//	    rtn += "Membership Expiration: " + expDate.toString() + "\n";
//
//	    convert << amtSpent;
//	    temp = convert.str();
//	    rtn += ("Total Amount Spent: $" + temp + "\n");
//	    convert.str("");
//
//	    convert << rebateAmt;
//	    temp = convert.str();
//	    rtn += ("Rebate Anount: $" + temp + "\n");
//	    convert.str("");

	    return rtn;



	//ostringstream ss; // PROCESSING - string stream variable used to store
					  //              data member string

	// PROCESSING - data members are added to string stream with various set
	//				widths for formatted output
//	ss << left << setw(20) << itemName;
//	ss << setw(10) << id;
//	ss << setw(15) << phone;
//	ss << setw(4) << age;
//	ss << setw(8) << gender;
//	ss << setw(15) << jobTitle;
//	ss << setw(10) << dollarString(salary); // Formated to dollar amount
//	ss << setw(12) << hireDate.toString(); // Date date members converted
//										   // to string
//	ss << right;

	// PROCESSING - string stream variable is converted to string and returned
	return ss.str();
}

