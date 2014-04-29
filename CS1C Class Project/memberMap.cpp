/**************************************************************************
 * AUTHOR       : Matt Clark
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include <string>
#include "memberMap.h"
using namespace std;

memberMap::memberMap()
{
}//end constructor

void memberMap::add(member& input)
{
    idMap.insert(pair<int, member>(input.getID(), input));
    nameMap.insert(pair<string, member>(input.getName(), input));
}//end add function


