/**************************************************************************
 * AUTHOR       : Matt Clark
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef MEMBERMAP_H_
#define MEMBERMAP_H_

#include <string>
#include <map>
#include "member.h"
using namespace std;

class memberMap
{
public:
    memberMap();
        //default constructor

    void add(member& input);
        //add a new member
        //Post: memberMap is changed and input is added to map and the
        //      name is added to nameMap

    void remove(int memberID);
        //remove the member with the id memberID
        //Post: memberMap is changed and the specified member is removed

    void remove(string& memberName);
        //remove the member with the name memberName
        //Post memberMap is changed and the specified member is removed

    member& find(int memberID);
        //returns the member with the id memberID

    member& find(string& memberName);
        //returns the member with the name memberName

private:
    map<int, member> map;
    map<string, int> nameMap;
};


#endif /* MEMBERMAP_H_ */
