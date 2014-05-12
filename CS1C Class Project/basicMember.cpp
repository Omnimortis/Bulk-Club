/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include "basicMember.h"

basicMember::basicMember()
{
    name = "";
    id = 0;
    type = false;
    amtSpent = 0;
}

basicMember::basicMember(string initName, int initID, bool initType,
		int monthInit, int dayInit, int yearInit):
				expDate(monthInit, dayInit, yearInit)
{
    name = initName;
    id = initID;
    type = initType;
    amtSpent = 0;
}

void basicMember::setName(string input)
{
    name = input;
}

string basicMember::getName() const
{
    return name;
}

void basicMember::setID(int input)
{
    id = input;
}

int basicMember::getID() const
{
    return id;
}

void basicMember::setType(bool input)
{
    type = input;
}

bool basicMember::getType() const
{
    return type;
}

void basicMember::setExpDate(int monthInit, int dayInit, int yearInit)
{
    expDate.setDate(monthInit, dayInit, yearInit);
}

date basicMember::getExpDate() const
{
    return expDate;
}

void basicMember::setAmtSpent(float input)
{
    amtSpent = input;
}

float basicMember::getAmtSpent() const
{
    return amtSpent;
}

string basicMember::toString() const
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

    return rtn;
}
