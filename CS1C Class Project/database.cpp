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

void database::addMember(basicMember& input)
{
    memberByIDMap.insert(pair<int, basicMember>(input.getID(), input));
    memberByNameMap.insert(pair<string, basicMember>(input.getName(), input));
}//end addMember function

void database::removeMember(int memberID)
{
    string memberName = memberByIDMap[memberID].getName();

    memberByIDMap.erase(memberID);
    memberByNameMap.erase(memberName);
}//end removeMember function

void database::removeMember(string memberName)
{
    int memberID = memberByNameMap[memberName].getID();

    memberByIDMap.erase(memberID);
    memberByNameMap.erase(memberName);
}//end removeMember function

basicMember& database::findMember(int memberID)
{
    return memberByIDMap[memberID];
}//end findMember function

basicMember& database::findMember(string memberName)
{
    return memberByNameMap[memberName];
}//end findMember function

void database::addPurchase(purchase& input)
{
    purchaseByDateMap.insert(pair<date, purchase>(input.getDate(), input));
    purchaseByIDMap.insert(pair<int, purchase>(input.getMember()->getID(),
            input));
}//end addPurchase function

multimap<int, purchase>::iterator database::purchaseByIDBegin()
{
    return purchaseByIDMap.begin();
}

multimap<int, purchase>::iterator database::purchaseByIDEnd()
{
    return purchaseByIDMap.end();
}

purchase& database::getPurchase(multimap<date, purchase>::iterator& input)
{
    return input->second;
}//end getPurchase function

purchase& database::getPurchase(multimap<int, purchase>::iterator& input)
{
    return input->second;
}//end getPurchase function

pair <multimap<date, purchase>::iterator,
    multimap<date, purchase>::iterator> database::getPurchases
    (date& input)
{
    return purchaseByDateMap.equal_range(input);
}

pair <multimap<int, purchase>::iterator,
    multimap<int, purchase>::iterator> database::getPurchases
    (int input)
{
    return purchaseByIDMap.equal_range(input);
}
