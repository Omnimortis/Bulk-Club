/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include "purchase.h"

purchase::purchase():
                itemName(" "), quantity(0), totalAmount(0),
                bulkMember(NULL)
{
}

purchase::purchase(string nameInit, int quantityInit,float totalInit,
		member& memberInit, int monthInit, int dayInit,
		int yearInit):
		        itemName(nameInit), quantity(quantityInit),
		        totalAmount(totalInit), bulkMember(&memberInit),
		        purchaseDate(monthInit, dayInit, yearInit)
{
}

void purchase::setDate(int monthInit, int dayInit, int yearInit)
{
	purchaseDate.setDate(monthInit, dayInit, yearInit);
}

date& purchase::getDate()
{
	return purchaseDate;
}

void purchase::setItemName(string& nameSet)
{
	itemName = nameSet;
}

string purchase::getItemName()
{
	return itemName;
}

void purchase::setQuantity(int quantitySet)
{
	quantity = quantitySet;
}

int purchase::getQuantity()
{
	return quantity;
}

void purchase::setTotalAmount(float totalSet)
{
	totalAmount = totalSet;
}

float purchase::getTotalAmount()
{
	return totalAmount;
}

void purchase::setMember(member& member)
{
	bulkMember = &member;
}

member* purchase::getMember()
{
	return bulkMember;

}

string purchase::toString()
{

	stringstream ss; // PROCESSING - string stream variable used to store
					  //              data member string

	// PROCESSING - data members are added to string stream with various set
	//				widths for formatted output
	ss << "Purchase Date: " <<  purchaseDate.toString() << endl
	   << "Item Name: " << itemName << endl
	   << "Quantity Sold: " << quantity << endl
	   << "Total Amount: " << totalAmount << endl
	   << "Member: " << bulkMember->getName() << " - " << bulkMember->getID() << endl
	   << "Membership Type: " ;
	   if (bulkMember->getType())
	        ss << "Preferred";
	    else
	        ss << "Basic";

	ss << endl;

	// PROCESSING - string stream variable is converted to string and returned
	return ss.str();
}

