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
    amtSpent = 0;
    rebate = 0;
}

member::member(string initName, int initID, bool initType,
		int monthInit, int dayInit, int yearInit):
				expDate(monthInit, dayInit, yearInit)
{
    name = initName;
    id = initID;
    type = initType;
    amtSpent = 0;
    rebate = 0;
}

void member::setName(string input)
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

void member::setAmtSpent(float input)
{
    amtSpent = input;
}

float member::getAmtSpent() const
{
    return amtSpent;
}

void member::setRebate(float input)
{
    rebate = input;
}

float member::getRebate() const
{
    return rebate;
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

    convert << rebate;
    temp = convert.str();
    rtn += ("Current Rebate amount: $" + temp + "\n");
    convert.str("");

    return rtn;
}
