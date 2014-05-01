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
        //Post: memberMap is changed and input is added to map and the
        //      name is added to nameMap

    void removeMember(int memberID);
        //remove the member with the id memberID
        //Post: memberMap is changed and the specified member is removed

    void removeMember(string& memberName);
        //remove the member with the name memberName
        //Post memberMap is changed and the specified member is removed

    member& findMember(int memberID);
        //returns the member with the id memberID

    member& findMember(string& memberName);
        //returns the member with the name memberName

private:
    map<int, member> idMap;
    map<string, member> nameMap;
    multimap<date, purchase> purchaseByDateMap;
    multimap<int, purchase> purchaseByIDMap;
};


#endif /* MEMBERMAP_H_ */
