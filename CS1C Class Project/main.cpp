/**************************************************************************
 * AUTHOR       : Matt Clark
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include <iostream>
#include <string>
#include "member.h"
using namespace std;

int main()
{
    member m;

    cout << m.toString() << "\n";

    string name = "Matt";

    date d(1, 21, 2001);

    member m1(name, 11111, true, d, 1000, 100);

    cout << m1.toString() << "\n";

    return 0;
}
