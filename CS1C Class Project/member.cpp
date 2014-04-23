/**************************************************************************
 * AUTHOR       : Matt Clark
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

member::member(string& initName, int initID, bool initType,
        date& initExpDate, int initAmtSpent, int initRebateAmt)
{
    name = initName;
    id = initID;
    type = initType;
    expDate = initExpDate;
    amtSpent = initAmtSpent;
    rebateAmt = initRebateAmt;
}

void member::setName(string& input)
{
    name = input;
}

string member::getName()
{
    return name;
}

void member::setID(int input)
{
    id = input;
}

int member::getID()
{
    return id;
}

void member::setType(bool input)
{
    type = input;
}

bool member::getType()
{
    return type;
}

void member::setExpDate(date& input)
{
    expDate = input;
}

date member::getExpDate()
{
    return expDate;
}

void member::setAmtSpent(int input)
{
    amtSpent = input;
}

int member::getAmtSpent()
{
    return amtSpent;
}

void member::setRebateAmount(int input)
{
    rebateAmt = input;
}

int member::getRebateAmt()
{
    return rebateAmt;
}

string member::toString()
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
