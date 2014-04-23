/**************************************************************************
 * AUTHOR       : Matt Clark
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
using namespace std;

class member
{
public:
    member();
        //default constructor

    member(string& initName, int initID, bool initType, date& initExpDate,
            int initSpent, int initRebate);
        //non-default constructor

    void setName(string& input);
        //set the name
        //Post: member is changed and name is set to input

    string& getName();
        //returns the name of the member

    void setID(int input);
        //set the ID
        //Post: member is changed and id is set to input

    int getID();
        //returns the id of the member

    void setType(bool input);
        //set the member type
        //Post: member is changed and type is set to input

    bool getType();
        //return the member type

    void setExpDate(date& input);
        //set the member expiration date
        //Post: member is changed and expDate is set to input

    date& getexpDate();
        //return the member expiration date

    void setAmtSpent(int input);
        //set the member's amount spent
        //Post: member is changed and amtSpent is set to input

    int getAmtSpent();
        //return the member's amount spent


};

#endif /* MEMBER_H_ */
