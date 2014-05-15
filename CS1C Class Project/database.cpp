/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include <string>
#include "database.h"
using namespace std;

database::database()
{
}//end constructor

void database::addMember(member& input)
{
    memberByIDMap.insert(pair<int, member>(input.getID(), input));
    memberByNameMap.insert(pair<string, member>(input.getName(), input));
}//end addMember function

void database::removeMember(int memberID)
{
	//check if member exists
	if (memberByIDMap.count(memberID) == 0)
	{
		string error = "There is no member #";
	    string temp;
	    ostringstream convert;

	    convert << memberID;
	    temp = convert.str();
	    error += temp + "\n";
	    convert.str("");

		throw RuntimeException(error);
	}

    string memberName = memberByIDMap[memberID].getName();
    pair <multimap<int,purchase>::iterator,
    multimap<int,purchase>::iterator> ret;

    //erase all purchases related to member
    ret = purchaseByIDMap.equal_range(memberID);
    purchaseByIDMap.erase(ret.first, ret.second);

    for (multimap<date,purchase>::iterator it = purchaseByDateMap.begin();
    		it != purchaseByDateMap.end(); it++)
    {
    	if (it->second.getMember()->getID() == memberID)
    	{
    		purchaseByDateMap.erase(it);
    	}
    }

    //erase member
    memberByIDMap.erase(memberID);
    memberByNameMap.erase(memberName);
}//end removeMember function

void database::removeMember(string memberName)
{
	//check if member exists
	if (memberByNameMap.count(memberName) == 0)
	{
		string error = "There is no member named " + memberName + "\n";
		throw RuntimeException(error);
	}

    int memberID = memberByNameMap[memberName].getID();


    pair <multimap<int,purchase>::iterator,
    multimap<int,purchase>::iterator> ret;

    //erase all purchases related to member
    ret = purchaseByIDMap.equal_range(memberID);
    purchaseByIDMap.erase(ret.first, ret.second);

    for (multimap<date,purchase>::iterator it = purchaseByDateMap.begin();
    		it != purchaseByDateMap.end(); it++)
    {
    	if (it->second.getMember()->getID() == memberID)
    	{
    		purchaseByDateMap.erase(it);
    	}
    }

    //erase member
    memberByIDMap.erase(memberID);
    memberByNameMap.erase(memberName);
}//end removeMember function

member& database::findMember(int memberID)
{
    return memberByIDMap[memberID];
}//end findMember function

member& database::findMember(string memberName)
{
    return memberByNameMap[memberName];
}//end findMember function

int database::checkMember(int memberID)
{
	return memberByIDMap.count(memberID);
}//end checkMember function

int database::checkMember(string memberName)
{
	return memberByNameMap.count(memberName);
}//end checkMember function

int database::checkItem(string itemName)
{
	return itemQuantityMap.count(itemName);
}//end checkItem function

void database::addPurchase(purchase& input)
{
	float amtSpent;
	float rebate;

	//insert new purchase
    purchaseByDateMap.insert(pair<date, purchase>(input.getDate(), input));
    purchaseByIDMap.insert(pair<int, purchase>(input.getMember()->getID(),
            input));

    //update member amount spent
    amtSpent = memberByNameMap[input.getMember()->getName()].getAmtSpent();

    memberByNameMap[input.getMember()->getName()].setAmtSpent(amtSpent +
    		input.getUnitPrice());
    memberByIDMap[input.getMember()->getID()].setAmtSpent(amtSpent +
    		input.getUnitPrice());

    //update member rebate
	rebate = memberByNameMap[input.getMember()->getName()].getRebate();

	memberByNameMap[input.getMember()->getName()].setRebate(rebate +
			(input.getUnitPrice() * 0.05));
	memberByIDMap[input.getMember()->getID()].setRebate(rebate +
			(input.getUnitPrice() * 0.05));

	//update item quantity information
    if (itemQuantityMap.count(input.getItemName()) == 0)
    {
        itemQuantityMap.insert(pair<string, int>(input.getItemName(),
        		input.getQuantity()));
    }
    else
    {
    	itemQuantityMap[input.getItemName()] += input.getQuantity();
    }

    //update item sales information
    if(itemSalesMap.count(input.getItemName()) == 0)
    {
    	itemSalesMap.insert(pair<string, float>(input.getItemName(),
    			input.getUnitPrice()));
    }
    else
    {
    	itemSalesMap[input.getItemName()] += input.getUnitPrice();
    }
}//end addPurchase function

int database::getItemQuantity(string itemName)
{
	return itemQuantityMap.find(itemName)->second;
}//end getItemQuantity function

float database::getItemSales(string itemName)
{
	return itemSalesMap.find(itemName)->second;
}//end getItemSales function

map<int, member>::iterator database::memberIDMapBegin()
{
	return memberByIDMap.begin();
}//end memberIDMapBegin function

map<int, member>::iterator database::memberIDMapEnd()
{
	return memberByIDMap.end();
}//end memberIDMapEnd function

map<string, member>::iterator database::memberNameMapBegin()
{
	return memberByNameMap.begin();
}//end memberNameMapBegin function

map<string, member>::iterator database::memberNameMapEnd()
{
	return memberByNameMap.end();
}//end memberNameMapEnd function

map<string, int>::iterator database::quantityItemMapBegin()
{
	return itemQuantityMap.begin();
}//end quantityItemMapBegin function

map<string, int>::iterator database::quantityItemMapEnd()
{
	return itemQuantityMap.end();
}//end quantityItemMapEnd function

multimap<int, purchase>::iterator database::purchaseByIDBegin()
{
    return purchaseByIDMap.begin();
}//end purchaseByIDBegin function

multimap<int, purchase>::iterator database::purchaseByIDEnd()
{
    return purchaseByIDMap.end();
}//end purchaseByIDEnd function

pair <multimap<date, purchase>::iterator,
    multimap<date, purchase>::iterator> database::getPurchases
    (date& input)
{
    return purchaseByDateMap.equal_range(input);
}//end getPurchases function

pair <multimap<int, purchase>::iterator,
    multimap<int, purchase>::iterator> database::getPurchases
    (int input)
{
    return purchaseByIDMap.equal_range(input);
}//end getPurchases function
