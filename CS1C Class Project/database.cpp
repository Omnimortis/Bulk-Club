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
    idMap.insert(pair<int, member>(input.getID(), input));
    nameMap.insert(pair<string, member>(input.getName(), input));
}//end add function

void database::removeMember(int memberID)
{
    string memberName = idMap[memberID].getName();
    idMap.erase(memberID);
    nameMap.erase(memberName);
}//end remove function

void database::removeMember(string& memberName)
{
    int memberID = nameMap[memberName].getID();
    idMap.erase(memberID);
    nameMap.erase(memberName);
}//end remove function

member& database::findMember(int memberID)
{
    return idMap[memberID];
}//end find functions

member& database::findMember(string& memberName)
{
    return nameMap[memberName];
}
