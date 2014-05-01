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
using namespace std;

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

    void removeMember(string& memberName);
        //remove the member with the name memberName
        //Post database is changed and the specified member is removed

    member& findMember(int memberID);
        //returns the member with the id memberID

    member& findMember(string& memberName);
        //returns the member with the name memberName

    void addPurchase(purchase& input);
        //add a new purchase
        //Post: database is changed and input is added to maps

    purchase& getPurchase(multimap<date, purchase>::iterator& input);
        //returns the purchase represented by the iterator input

    purchase& getPurchase(multimap<int, purchase>::iterator& input);
        //returns the purchase represented by the iterator input

    pair <const multimap<date, purchase>::iterator,
    const multimap<date, purchase>::iterator>& getPurchases
    (const date& input);
        //returns a pair of iterators that represent the range of purchases
        //that have the date input

    pair <const multimap<int, purchase>::iterator,
    const multimap<int, purchase>::iterator>& getPurchases(const int input);
        //returns a pair of iterators that represent the range of purchases
        //that have the member ID input

private:
    map<int, member> memberByIDMap;
    map<string, member> memberByNameMap;
    multimap<date, purchase> purchaseByDateMap;
    multimap<int, purchase> purchaseByIDMap;
};


#endif /* MEMBERMAP_H_ */
