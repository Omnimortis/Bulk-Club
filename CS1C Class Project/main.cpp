/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <limits>
#include <map>
#include <fstream>
#include "member.h"
#include "RuntimeException.h"
#include "database.h"
using namespace std;

#define INTERFACE 1

void MemberRead(database& d);
void PurchaseRead(database& d);
int validInt(int, int);
int getReportType(const vector<const char*> &);
void printPurchases(database& db, date& day);
void printPurchases(database& db, int id);
void printPurchases(database& db, string name);

const int maxWidth = 80;
enum  {PURCHASE_BY_DAY = 1, PURCHASE_BY_ITEM, PURCHASE_BY_MEMBER,
		TOTAL_SALES, QUANTATIES, REBATES, DUES_PAID,
		MEMBERSHIP_EXPIRTATIONS, UPGRADES, DOWNGRADES, MODIFY_MEMBERS,
		EXIT};

int main()
{
	database db;

	MemberRead(db);
	PurchaseRead(db);

#if INTERFACE
	int menuChoice;
	int filterType;
	int month;
	int day;
	int year;
	date tempDate;
	string name;
	int id;
	
    vector<const char*> menuOptions;
    menuOptions.push_back("View Purchases for given day");
    menuOptions.push_back("View Purchases for given item");
    menuOptions.push_back("View Purchases for given member");
    menuOptions.push_back("View Total Sales");
    menuOptions.push_back("View Quantity of Items Sold");
    menuOptions.push_back("View Member Rebate Report");
    menuOptions.push_back("View Membership Dues Paid");
    menuOptions.push_back("View Membership Expirations");
    menuOptions.push_back("Check for Membership Upgrades");
    menuOptions.push_back("Check for Membership Downgrades");
    menuOptions.push_back("Add/Delete/Edit Members");
    menuOptions.push_back("Exit");

	vector<const char*> reportType;
    reportType.push_back("Basic Members Only");
    reportType.push_back("Preferred Members Only");
    reportType.push_back("All members");

    vector<const char*> modifyType;
    modifyType.push_back("Add");
    modifyType.push_back("Delete");
    modifyType.push_back("Modify");
    modifyType.push_back("Exit");

	bool exit = false;

	//output welcome statement
	cout << setfill('*')  << setw(maxWidth) <<"*" << endl
	     << setw(maxWidth/3) << "| " << setw(2) << setfill(' ') <<""
		 << "BULK CLUB MANAGER SUITE "
		 << setw(2) << setfill(' ') <<""
		 << left <<setfill('*')
		 << setw(maxWidth/3)<< " |" << endl
		 <<setfill('*')  << setw(maxWidth) <<"*" << endl << endl;

	cout << "Welcome to the Bulk Club Manager Suite. " << endl;
	cout << "What would you like to do?" << endl;

	do
	{
		// OUTPUT - Display menu options stored in menuOptions and prompt
	    //          for input
		for (unsigned int i = 0; i < menuOptions.size(); i++)
		{
            cout << i + 1 << ". " << menuOptions[i] << endl;
		}

		cout << "\nPlease enter your choice: ";

		// INPUT/OUTPUT - Call validInt function to accept valid input
		//		          Returns into menuChoice integer variable

		menuChoice = validInt(1, menuOptions.size());

		cout << endl << menuOptions[menuChoice - 1] << endl << endl;

		if (menuChoice != PURCHASE_BY_MEMBER && menuChoice != REBATES &&
				menuChoice != UPGRADES && menuChoice != DOWNGRADES
				&& menuChoice !=EXIT )
		{
			filterType = getReportType(reportType);
            cout << endl << reportType[(filterType - 1)]
                 << endl << endl;
		}

		switch(menuChoice)
		{
			case PURCHASE_BY_DAY:
				cout << "Enter the date for the sales report:\n";
				cout << "Enter month: ";
				month = validInt(1, 12);
				cout << "Enter day: ";
				day = validInt(1, 31);
				cout << "Enter year: ";
				year = validInt(1950, 2014);
				tempDate.setDay(day);
				tempDate.setMonth(month);
				tempDate.setYear(year);
				printPurchases(db, tempDate);
				break;
			case PURCHASE_BY_ITEM:
				cout << "Enter Item Name: ";
				break;
			case PURCHASE_BY_MEMBER:
				cout << "Search by Member Name or Number?\n";
				cout << "1. Member Name" << endl;
				cout << "2. Member Number" << endl;
				cout << "3. Exit" << endl;
				cout << "\nPlease enter your choice: ";
				menuChoice = validInt(1, 3);
				if (menuChoice == 1)
				{
				    cout << "Enter the member name: ";
				    getline(cin, name);
				    printPurchases(db, name);
				}
				else if (menuChoice == 2)
				{
				    cout << "Enter the member number: ";
				    printPurchases(db, validInt(0, 99999));
				}
				break;
			case TOTAL_SALES:
				cout << "Printing all sales sorted by member ID:" << endl;
			    cout << "------------------------------------\n";

			    for (multimap<int,purchase>::iterator it =
			            db.purchaseByIDBegin();
			            it!= db.purchaseByIDEnd(); ++it)
			    {
			        cout << it->second.toString();
			        cout << "------------------------------------" << endl;
			    }
				break;
			case QUANTATIES:
				cout << "Printing quantities of items sold ";
				break;
			case REBATES:
				cout << "Printing rebate information for Preferred"
				        "Members ";
				break;
			case DUES_PAID:
				cout << "Printing membership dues  ";
				break;
			case MEMBERSHIP_EXPIRTATIONS:
				cout << "Enter month to check for membership expirations";
				break;
			case UPGRADES:
				cout << "Checking for members that would benefit from an"
				        "upgrade";
				break;
			case DOWNGRADES:
				cout << "Checking for members that would benefit from an"
				        "upgrade";
				break;
			case MODIFY_MEMBERS:  // Handle logic
				cout << "What would you like to do?" << endl;
				for (unsigned int i = 0; i < modifyType.size(); i++)
				{
                    cout << i+1 << ". "<< modifyType.at(i) << endl;
				}

				cout << "Please enter your choice: ";
				menuChoice = validInt(1, 4);
				cout << "You have chosen " << modifyType[menuChoice -1]
				     << endl;
				switch (menuChoice)
				{
				case 1:
				    cout << "Enter the name of the member you would like "
				            "to add: ";
				    getline(cin, name);
				    cout << "Enter the ID of the member you would like to"
				            " add: ";
				    id = validInt(0, 99999);
				    cout << "Is this a preferred member? (Yes or No): ";

				}
				break;
			case EXIT:
				cout << "Goodbye";
				exit = true;
				break;
		}
		cout << endl;
	} while (!exit);
#endif
	return 0;
}

int validInt(int lowerB, int upperB)
{
	string input;
	int choice;

	while (getline(cin, input))
	{
		stringstream ss(input);
		if (ss >> choice && (choice >= lowerB) && (choice <= upperB))
		{
			if(ss.eof())
			{
				break;
			}

		}
		cout << "Invalid Input, please try again: ";
	}
	return choice;
}

void printPurchases(database& db, date& day)
{
    cout << "\nPurchases for " << day.toString() << ":"
            << endl;
    cout << "------------------------------------\n";

    for (multimap<date,purchase>::iterator it =
            db.getPurchases(day).first;
            it!= db.getPurchases(day).second; ++it)
    {
        cout << it->second.toString();
        cout << "------------------------------------" << endl;
    }
}

void printPurchases(database& db, int id)
{
    cout << "\nPurchases for member #" << id << " - "
            << db.findMember(id).getName() << ":" << endl;
    cout << "------------------------------------\n";

    for (multimap<int,purchase>::iterator it =
            db.getPurchases(id).first;
            it!= db.getPurchases(id).second; ++it)
    {
        cout << it->second.toString();
        cout << "------------------------------------" << endl;
    }
}

void printPurchases(database& db, string name)
{
    int id = db.findMember(name).getID();

    cout << "\nPurchases for " << name << " - "
            << id << ":" << endl;
    cout << "------------------------------------\n";

    for (multimap<int,purchase>::iterator it =
            db.getPurchases(id).first;
            it!= db.getPurchases(id).second; ++it)
    {
        cout << it->second.toString();
        cout << "------------------------------------" << endl;
    }
}

int getReportType(const vector<const char*> &)
{
	cout << "Please Specify Report Type  " << endl;
	cout << "1. Basic Only" << endl;
	cout << "2. Preferred Only" << endl;
	cout << "3. Both" << endl;
	cout << "Report Type: ";
	return validInt(1, 3);
}

void MemberRead(database& d)
{
	ifstream iFile; // INPUT - input stream variable
	string memberName, memTypeStr, dateStr;
	bool memTypeBool;
	int month, day, year, memberNum;

	// PROCESSING - Associates file name with input stream variable
	iFile.open("warehouse shopper.txt");

	while (iFile)
	{
		// INPUT - Copies contents of file to CPU and Input/Output index
		getline(iFile, memberName);

			iFile >> memberNum ;
		iFile.ignore(1000, '\n');

		getline(iFile, memTypeStr);

		if (memTypeStr == "Basic")
			memTypeBool = false;
		else if (memTypeStr == "Preferred")
			memTypeBool = true;
		else
			cout << "Error: Incorrect Membership Type" << endl;

		getline(iFile, dateStr);

		stringstream(dateStr.substr(0,2)) >> month;
		stringstream(dateStr.substr(3,4)) >> day;
		stringstream(dateStr.substr(6,dateStr.length()-1)) >> year;

		member temp(memberName, memberNum, memTypeBool, month, day, year, 0, 0);

		d.addMember(temp);
	}

	iFile.close();
}

void PurchaseRead(database& d)
{
	ifstream iFile; // INPUT - input stream variable
	string dateStr, itemName;
	float unitPrice;
	int month, day, year, memNum, quantity;

	// PROCESSING - Associates file name with input stream variable
	iFile.open("purchaseFile.txt");

	while(iFile)
	{
		getline(iFile, dateStr);
		stringstream(dateStr.substr(0,2)) >> month;
		stringstream(dateStr.substr(3,4)) >> day;
		stringstream(dateStr.substr(6,dateStr.length()-1)) >> year;

		iFile >> memNum ;
		iFile.ignore(1000, '\n');

		getline(iFile, itemName);

		iFile >> unitPrice;

		iFile >> quantity;
		iFile.ignore(1000, '\n');

		purchase temp(itemName, quantity, (quantity*unitPrice), d.findMember(memNum), month, day, year);
		d.addPurchase(temp);
	}

	iFile.close();
}
