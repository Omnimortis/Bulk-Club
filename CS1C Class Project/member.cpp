/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include "member.h"

member::member()
{
    name = "";
    id = 0;
    type = false;
    expDate = date();
    amtSpent = 0;
    rebateAmt = 0;
}
//purchase::purchase(string nameInit, int quantityInit,float totalInit,
//		member& memberInit, int monthInit, int dayInit,
//		int yearInit):
//		        itemName(nameInit), quantity(quantityInit),
//		        totalAmount(totalInit), bulkMember(&memberInit),
//		        purchaseDate(monthInit, dayInit, yearInit)
member::member(string& initName, int initID, bool initType,
       int monthInit, int dayInit, int yearInit,  int initAmtSpent, int initRebateAmt): expDate(monthInit, dayInit, yearInit)
{
    name = initName;
    id = initID;
    type = initType;
      amtSpent = initAmtSpent;
    rebateAmt = initRebateAmt;
}

void member::setName(string& input)
{
    name = input;
}

string member::getName() const
{
    return name;
}

void member::setID(int input)
{
    id = input;
}

int member::getID() const
{
    return id;
}

void member::setType(bool input)
{
    type = input;
}

bool member::getType() const
{
    return type;
}

void member::setExpDate(int monthInit, int dayInit, int yearInit)
{
    expDate.setDate(monthInit, dayInit, yearInit);
}

date member::getExpDate() const
{
    return expDate;
}

void member::setAmtSpent(int input)
{
    amtSpent = input;
}

int member::getAmtSpent() const
{
    return amtSpent;
}

void member::setRebateAmount(int input)
{
    rebateAmt = input;
}

int member::getRebateAmt() const
{
    return rebateAmt;
}

void member::addPurchase(purchase& input)
{
    purchases.push_back(input);
}

vector<purchase>& member::getPurchases()
{
    return purchases;
}

string member::toString() const
{
    string rtn = "";
    string temp;
    ostringstream convert;

    rtn += "Member Name: " + name + "\n";

    convert << id;
    temp = convert.str();
    rtn += ("Member Number: " + temp + "\n");
    convert.str("");

    if (type == true)
        temp = "Preferred";
    else
        temp = "Basic";
    rtn += ("Membership Type: " + temp + "\n");

    rtn += "Membership Expiration: " + expDate.toString() + "\n";

    convert << amtSpent;
    temp = convert.str();
    rtn += ("Total Amount Spent: $" + temp + "\n");
    convert.str("");

    convert << rebateAmt;
    temp = convert.str();
    rtn += ("Rebate Anount: $" + temp + "\n");
    convert.str("");

    return rtn;
}
