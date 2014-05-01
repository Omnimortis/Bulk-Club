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
    string memberName = memberByIDMap[memberID].getName();

    memberByIDMap.erase(memberID);
    memberByNameMap.erase(memberName);
}//end removeMember function

void database::removeMember(string& memberName)
{
    int memberID = memberByNameMap[memberName].getID();

    memberByIDMap.erase(memberID);
    memberByNameMap.erase(memberName);
}//end removeMember function

member& database::findMember(int memberID)
{
    return memberByIDMap[memberID];
}//end findMember function

member& database::findMember(string& memberName)
{
    return memberByNameMap[memberName];
}//end findMember function

void database::addPurchase(purchase& input)
{
    date purchaseDate = input.getDate();
    int memberID = input.getMember()->getID();

    //purchaseByDateMap.insert(pair<date, purchase>(purchaseDate, input));
    purchaseByIDMap.insert(pair<int, purchase>(memberID, input));
}//end addPurchase function

purchase& database::getPurchase(multimap<date, purchase>::iterator& input)
{
    return input->second;
}//end getPurchase function

purchase& database::getPurchase(multimap<int, purchase>::iterator& input)
{
    return input->second;
}//end getPurchase function

pair <const multimap<date, purchase>::iterator,
   const multimap<date, purchase>::iterator>& database::getPurchases
   (const date& input)
{
    //return purchaseByDateMap.equal_range(input);
}

pair <const multimap<int, purchase>::iterator,
   const multimap<int, purchase>::iterator>& database::getPurchases
   (const int input)
{
    //return purchaseByIDMap.equal_range(input);
}