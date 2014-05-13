/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_

#include <string>
#include "date.h"
using namespace std;

class member
{
public:
    member();
        //default constructor

    member(string initName, int initID, bool initType, int monthInit,
    	   int dayInit, int yearInit);
        //non-default constructor

    void setName(string input);
        //set the name
        //Post: member is changed and name is set to input

    string getName() const;
        //returns the name of the member

    void setID(int input);
        //set the ID
        //Post: member is changed and id is set to input

    int getID() const;
        //returns the id of the member

    void setType(bool input);
        //set the member type
        //Post: member is changed and type is set to input

    bool getType() const;
        //return the member type

    void setExpDate(int monthInit, int dayInit, int yearInit);
        //set the member expiration date
        //Post: member is changed and expDate is set to input

    date getExpDate() const;
        //return the member expiration date

    void setAmtSpent(float input);
        //set the member's amount spent
        //Post: member is changed and amtSpent is set to input

    float getAmtSpent() const;
        //return the member's amount spent

    void setRebate(float input);
        //set the member's rebate amount
        //Post: member is changed and rebate is set to input

    float getRebate() const;
        //return the preferred member's current rebate amount

    string toString() const;
        //return a string representation of the member

private:
    string name;
    int id;
    bool type;
    date expDate;
    float amtSpent;
    float rebate;
};

#endif /* BASICMEMBER_H_ */
