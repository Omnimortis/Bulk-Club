/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef MEMBERMAP_H_
#define DATABASE_H_

#include <string>
#include <map>
#include "member.h"
#include "purchase.h"
#include "RuntimeException.h"
using namespace std;

class purchase;

class database
{
public:
    database();
        //default constructor

    void addMember(member& input);
        //add a new member
        //Post: database is changed and input is added to maps

    void removeMember(int memberID);
        //remove the member with the id memberID
        //Post: database is changed and the specified member is removed

    void removeMember(string memberName);
        //remove the member with the name memberName
        //Post database is changed and the specified member is removed

    member& findMember(int memberID);
        //returns the member with the id memberID

    member& findMember(string memberName);
        //returns the member with the name memberName

    int checkMember(int memberID);

    int checkMember(string memberName);

    int checkItem(string itemName);

    void addPurchase(purchase& input);
        //add a new purchase
        //Post: database is changed and input is added to maps

    int getItemQuantity(string itemName);
    	//returns the quantity of the item with itemName sold

    float getItemSales(string itemName);
    	//returns the total sales of the item with itemName

    map<int, member>::iterator memberIDMapBegin();
    //returns an iterator that represents the beginning of the
    //members sorted by ID

    map<int, member>::iterator memberIDMapEnd();
    //returns an iterator that represents the end of the
    //members sorted by ID

    map<string, member>::iterator memberNameMapBegin();
    //returns an iterator that represents the beginning of the
    //members sorted by name

    map<string, member>::iterator memberNameMapEnd();
    //returns an iterator that represents the end of the
    //members sorted by name

    map<string, int>::iterator quantityItemMapBegin();
    //returns an iterator that represents the beginning of the
    //items sorted by item name

    map<string, int>::iterator quantityItemMapEnd();
    //returns an iterator that represents the end of the
    //items sorted by item name

    multimap<int, purchase>::iterator purchaseByIDBegin();
        //returns an iterator that represents the beginning of the
        //purchases sorted by member ID

    multimap<int, purchase>::iterator purchaseByIDEnd();
        //returns an iterator that represents the end of the purchases
        //sorted by member ID

    pair <multimap<date, purchase>::iterator,
    multimap<date, purchase>::iterator> getPurchases (date& input);
        //returns a pair of iterators that represent the range of purchases
        //that have the date input

    pair <multimap<int, purchase>::iterator,
    multimap<int, purchase>::iterator> getPurchases (int input);
        //returns a pair of iterators that represent the range of purchases
        //that have the member ID input

private:
    struct datecomp {
        bool operator () (const date& lhs, const date& rhs) const
        {
            bool rtn;

            if (lhs.getYear() == rhs.getYear())
            {
                if (lhs.getMonth() == rhs.getMonth())
                {
                    rtn = lhs.getDay() < rhs.getDay();
                }
                else
                {
                    rtn = lhs.getMonth() < rhs.getMonth();
                }
            }
            else
            {
                rtn = lhs.getYear() < rhs.getYear();
            }

            return rtn;
        }
    };

    map<int, member> memberByIDMap;
    map<string, member> memberByNameMap;
    map<string, int> itemQuantityMap;
    map<string, float> itemSalesMap;
    multimap<date, purchase, datecomp> purchaseByDateMap;
    multimap<int, purchase> purchaseByIDMap;
};


#endif /* MEMBERMAP_H_ */
