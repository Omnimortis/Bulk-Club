/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <fstream>
#include "member.h"
#include "RuntimeException.h"
#include "database.h"
#include "purchase.h"
using namespace std;

#define INTERFACE 1
// Reads members from input file
void MemberRead(database& d);

// Reads purchases from input file
void PurchaseRead(database& d);

// Validates input between range
int validInt(int, int);

// Validates a yes or no input
bool validBool();

// Outputs report type options and accepts input
int getReportType(const vector<const char*> &);

// Prints all Purchases based on filter type input
void printAllPurchases(database& db, int filterType);

// Prints purchases for certain day and filter type
void printPurchases(database& db, date& day, int filterType);

// Prints purchases for certain member ID
void printPurchases(database& db, int id);

// Prints purchases for certain member name
void printPurchases(database& db, string name);

// Writes all purchases to output file
void PurchaseWrite(database& db);

// Writes all members to output file
void MemberWrite(database& db);

// System pause and cin.ignore
void pause();

const int maxWidth = 80;  // used to format output

// menu options
enum  {PURCHASE_BY_DAY = 1, PURCHASE_BY_MEMBER, TOTAL_SALES,
		PURCHASE_BY_ITEM, QUANTATIES, REBATES, DUES_PAID,
		MEMBERSHIP_EXPIRTATIONS, UPGRADES, DOWNGRADES, MODIFY_MEMBERS,
		EXIT};

int main()
{
	// Initialize database object to store and search data
	// Database is comprised of two sets of STL maps and STL Multimaps
	database db;
	MemberRead(db); // Read member data from file
	PurchaseRead(db);// Read purchase data from file

#if INTERFACE
	int menuChoice;  	// stores user menu choice input
	int filterType;		// stores user input filter type
	int month;			// used to store month values
	int day;			// used to store day values
	int year;			// used to store year values
	date newDate;		// creates data object
	member newMember;	// creates new member object
	purchase newPurchase;// creates new purchase object
	string name;		// string used to store member name
	int id;				// int used to store member ID
	float price;		// float used to store item price
	bool exit = false;	// bool used to determine when to exit main loop
	vector<const char*> menuOptions; // Vector used to hold menu choices
	vector<const char*> reportType;  // Vector used to hold report type menu options
    vector<const char*> modifyType;  // Vector used to store modify menu options
	
	// PROCESSING - push all available menu options into menuOptions Vector
    menuOptions.push_back("View Sales Report for a given day");
    menuOptions.push_back("View Purchases for given member");
    menuOptions.push_back("View all Purchases for all members");
    menuOptions.push_back("View Sales Report for a given item");
    menuOptions.push_back("View Quantity of all Items sold");
    menuOptions.push_back("View Member Rebate Report");
    menuOptions.push_back("View Membership Dues Report");
    menuOptions.push_back("View Membership Expirations for a given month");
    menuOptions.push_back("Check for Membership Upgrades");
    menuOptions.push_back("Check for Membership Downgrades");
    menuOptions.push_back("Add/Delete Members");
    menuOptions.push_back("Exit");

	// PROCESSING - push all available filter type options into reportType Vector
    reportType.push_back("Basic Members Only");
    reportType.push_back("Preferred Members Only");
    reportType.push_back("All members");

	// PROCESSING - push all available modify options into modifyType Vector
    modifyType.push_back("Add");
    modifyType.push_back("Delete");
    modifyType.push_back("Go Back");

	//OUTPUT -  welcome statement
	cout << setfill('*')  << setw(maxWidth) <<"*" << endl
	     << setw(maxWidth/3) << "| " << setw(2) << setfill(' ') <<""
		 << "BULK CLUB MANAGER SUITE " << setw(2) << setfill(' ') <<""
		 << left <<setfill('*') << setw(maxWidth/3)<< " |" << endl
		 << setfill('*')  << setw(maxWidth) <<"*" << endl
		 << setfill(' ')<< endl;

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

		// IF filter options available for user menu choice, prompt for filter
		//	type input
		if (menuChoice != PURCHASE_BY_MEMBER &&
				menuChoice != PURCHASE_BY_ITEM && menuChoice != QUANTATIES
				&& menuChoice != REBATES && menuChoice != DUES_PAID &&
				menuChoice != MEMBERSHIP_EXPIRTATIONS &&
				menuChoice != UPGRADES && menuChoice != DOWNGRADES &&
				menuChoice != MODIFY_MEMBERS && menuChoice !=EXIT )
		{
			filterType = getReportType(reportType);
            cout << endl << reportType[(filterType - 1)]
                 << endl << endl;
		}

		cout << setprecision(2) << fixed;

		// SWITCH - select methods to call based on user input of menuChoice
		switch(menuChoice)
		{
			case PURCHASE_BY_DAY:		// Accepts user input for purchase date
				cout << "Enter the date for the sales report.\n";
				cout << "Enter month: ";
				month = validInt(1, 12);
				cout << "Enter day: ";
				day = validInt(1, 31);
				cout << "Enter year: ";
				year = validInt(1950, 2014);
				newDate.setDay(day);
				newDate.setMonth(month);
				newDate.setYear(year);

				// OUTPUT - display purchases for give day and filter
				printPurchases(db, newDate, filterType);
				pause();
				break;

			case PURCHASE_BY_MEMBER:    // Accepts user input for search type
				cout << "Search by Member Name or Number?\n";
				cout << "1. Member Name" << endl;
				cout << "2. Member Number" << endl;
				cout << "3. Exit" << endl;
				cout << "\nPlease enter your choice: ";

				// PROCESSING - depending on search type, accepts corresponding
				//				input
				menuChoice = validInt(1, 3);
				if (menuChoice == 1)
				{
				    cout << "Enter the member name: ";
				    getline(cin, name);

				    // OUTPUT - Displays all purchases based on input user name
				    printPurchases(db, name);
				}
				else if (menuChoice == 2)
				{
					 // OUTPUT - Displays all purchases based on input user ID
				    cout << "Enter the member number: ";
				    printPurchases(db, validInt(0, 99999));
				}
				pause();
				break;

			case TOTAL_SALES: // Prints all sales
				printAllPurchases(db, filterType);
				pause();
				break;
			case PURCHASE_BY_ITEM: // Prompts for Item name input
				cout << "Enter Item Name: ";
				getline(cin, name);

				// PROCESSING - checks if item is in database
				if (db.checkItem(name) != 0)
				{
					// If found, displays sales information for product
					cout << "\nQuantity of " << name << "s sold to date: "
							<< db.getItemQuantity(name) << endl;
					cout <<"Total revenue from all sales of " << name
							<< ": $" << db.getItemSales(name) << endl;
				}
				else
				{
					// If not found, outputs error
					cout << "\nNo " << name << "s have ever been sold."
							<< endl;
				}
				pause();
				break;

			case QUANTATIES: // OUTPUT - displays quantities of items sold
				cout << "Printing quantities of all items sold sorted by "
						"item name:" << endl;

				cout << setw(40) << setfill('-') << "-" << setfill(' ')
						<< endl;
			    cout << "| " << setw(30) << "Item Name";
			    cout << "| " << setw(5) << "Qty";
			    cout << "| " << endl;
			    cout << setw(40) << setfill('-') << "-" << setfill(' ')
			    		<< endl;

			    // PROCESSING - iterates through database, outputting
			    //				quantity and total sales of each item (pre-sorted)
				for (map<string ,int>::iterator it =
						db.quantityItemMapBegin();
						it!= db.quantityItemMapEnd(); it++)
				{
					cout << "| " << setw(30) <<  it->first;
					cout << "| " << setw(5) << it->second;
					cout << "|" << endl;
				}
				 cout << setw(40) << setfill('-') << "-" << setfill(' ')
						 << endl;

				 pause();
				break;

			case REBATES:  // Displays rebate information for members
				cout << "Printing rebate information for Preferred"
				        " Members sorted by ID:" << endl;

				cout << setw(45) << setfill('-') << "-" << setfill(' ')
						<< endl;
			    cout << "| " << setw(22) << "Member Name";
				cout << "| " << setw(7) << "ID";
			    cout << "| " << setw(9) << "Rebate";
			    cout << "|" << endl;
				cout << setw(45) << setfill('-') << "-" << setfill(' ')
						<< endl;

				// Iterates through memberIDMap of Database, outputting rebate info
				for (map<int,member>::iterator it = db.memberIDMapBegin();
						it != db.memberIDMapEnd(); it++)
				{
					// Checks if member is Preferred, if so outputs data for member
					if (it->second.getType())
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(7) << it->second.getID();
					    cout << "| $" << right << setw(8)
					    		<< it->second.getRebate() << left;
					    cout << "|" << endl;
					}
				}

				cout << setw(45) << setfill('-') << "-" << setfill(' ')
						<< endl;
				pause();
				break;

			case DUES_PAID:  // Displays membership dues
				cout << "Printing membership dues sorted by membership "
						"type and then by name:" << endl;

				cout << setw(46) << setfill('-') << "-" << setfill(' ')
						<< endl;
			    cout << "| " << setw(22) << "Member Name";
			    cout << "| " << setw(10) << "Type";
			    cout << "| " << setw(7) << "Dues";
			    cout << "|" << endl;
				cout << setw(46) << setfill('-') << "-" << setfill(' ')
						<< endl;

				// Iterates though membernameMap, outputting dues info
				// for Basic members
				for (map<string,member>::iterator it =
						db.memberNameMapBegin(); it !=
								db.memberNameMapEnd(); it++)
				{
					if (!it->second.getType())
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(10) << "Basic";
						cout << "| $" << setw(6) << right << "60.00"
								<< left;
						cout << "|" << endl;
					}
				}

				// Iterates though membernameMap, outputting dues info
				// for Preferred members
				for (map<string,member>::iterator it =
						db.memberNameMapBegin(); it !=
								db.memberNameMapEnd(); it++)
				{
					if (it->second.getType())
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(10) << "Preferred";
						cout << "| $" << setw(6) << right << "75.00"
								<< left;
						cout << "|" << endl;
					}
				}

				cout << setw(46) << setfill('-') << "-" << setfill(' ')
						<< endl;

				pause();
				break;

			case MEMBERSHIP_EXPIRTATIONS: // Checks membership expirations
				cout << "Enter month to check membership expirations: ";
				month = validInt(1, 12); // input validated month

				cout << "\nMemberships that will expire in chosen month\n";
				cout << setw(73) << setfill('-') << "-" << setfill(' ')
						<< endl;
			    cout << "| " << setw(22) << "Member Name";
			    cout << "| " << setw(10) << "Type";
			    cout << "| " << setw(25) << "Exp. Date";
			    cout << "| " << setw(7) << "Dues";
			    cout << "|" << endl;
				cout << setw(73) << setfill('-') << "-" << setfill(' ')
						<< endl;

				// Iterates through memberNameMap, checking for memberships
				// of basic members that will expire in given month
				for (map<string,member>::iterator it =
						db.memberNameMapBegin(); it !=
								db.memberNameMapEnd(); it++)
				{
					if (!it->second.getType() &&
							it->second.getExpDate().getMonth() == month)
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(10) << "Basic";
						cout << "| " << setw(25) <<
								it->second.getExpDate().toString();
						cout << "| $" << setw(6) << right << "60.00"
								<< left;
						cout << "|" << endl;
					}
				}

				// Iterates through memberNameMap, checking for memberships
				// of preferred members that will expire in given month
				for (map<string,member>::iterator it =
						db.memberNameMapBegin(); it !=
								db.memberNameMapEnd(); it++)
				{
					if (it->second.getType() &&
							it->second.getExpDate().getMonth() == month)
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(10) << "Preferred";
						cout << "| " << setw(25) <<
								it->second.getExpDate().toString();
						cout << "| $" << setw(6) << right << "75.00"
								<< left;
						cout << "|" << endl;
					}
				}

				cout << setw(73) << setfill('-') << "-" << setfill(' ')
						<< endl;

				pause();
				break;

			case UPGRADES: // CALC/OUT - checks for upgrades
				cout << "Checking for members that would benefit from an"
				        " upgrade" << endl;

				cout << setw(49) << setfill('-') << "-" << setfill(' ')
						<< endl;
			    cout << "| " << setw(22) << "Member Name";
				cout << "| " << setw(7) << "ID";
			    cout << "| " << setw(13) << "Exp. Rebate";
			    cout << "|" << endl;
				cout << setw(49) << setfill('-') << "-" << setfill(' ')
						<< endl;

				// Iterates through memberNameMap and checks for upgrades
				for (map<string,member>::iterator it =
						db.memberNameMapBegin(); it !=
								db.memberNameMapEnd(); it++)
				{
					if (!it->second.getType() &&
							it->second.getRebate() > 15)
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(7) << it->second.getID();
					    cout << "| $" << right << setw(12)
					    		<< it->second.getRebate() << left;
						cout << "|" << endl;
					}
				}

				cout << setw(49) << setfill('-') << "-" << setfill(' ')
						<< endl;

				pause();
				break;

			case DOWNGRADES:  // CALC/OUT - checks for downgrades
				cout << "Checking for members that would benefit from an"
				        " downgrade" << endl;

				cout << setw(45) << setfill('-') << "-" << setfill(' ')
						<< endl;
			    cout << "| " << setw(22) << "Member Name";
				cout << "| " << setw(7) << "ID";
			    cout << "| " << setw(9) << "Rebate";
			    cout << "|" << endl;
				cout << setw(45) << setfill('-') << "-" << setfill(' ')
						<< endl;

				// Iterates through memberNameMap and checks for downgrades
				for (map<string,member>::iterator it =
						db.memberNameMapBegin(); it !=
								db.memberNameMapEnd(); it++)
				{
					if (it->second.getType() &&
							it->second.getRebate() < 15)
					{
					    cout << "| " << setw(22) << it->second.getName();
						cout << "| " << setw(7) << it->second.getID();
					    cout << "| $" << right << setw(8)
					    		<< it->second.getRebate() << left;
						cout << "|" << endl;
					}
				}

				cout << setw(45) << setfill('-') << "-" << setfill(' ')
						<< endl;

				pause();
				break;

			case MODIFY_MEMBERS: // Allows user to modify
				cout << "What would you like to do?" << endl;
				for (unsigned int i = 0; i < modifyType.size(); i++)
				{
                    cout << i+1 << ". "<< modifyType.at(i) << endl;
				}

				cout << "Please enter your choice: ";
				menuChoice = validInt(1, 3);
				cout << "You have chosen " << modifyType[menuChoice -1]
				     << endl;

				switch (menuChoice)
				{
				case 1:
				    cout << "Enter the name of the member you would like "
				            "to add: ";
				    getline(cin, name);
				    newMember.setName(name);

				    cout << "Enter the ID of the member you would like to"
				            " add: ";
				    id = validInt(0, 99999);
				    newMember.setID(id);

				    cout << "Is this a preferred member? (Yes or No): ";
				    newMember.setType(validBool());

				    cout << "Enter the date that the membership will "
				            "expire.\n";
	                cout << "Enter month: ";
	                month = validInt(1, 12);
	                cout << "Enter day: ";
	                day = validInt(1, 31);
	                cout << "Enter year: ";
	                year = validInt(1950, 2014);
	                
	                newMember.setExpDate(month, day, year);
	                
	                db.addMember(newMember);

	                cout << "Member Added." << endl;
	                cout << "Add a new purchase to " << name << endl;

	                newPurchase.setMember(db.findMember(id));

	                cout << "\nEnter Item Name: ";
				    getline(cin, name);

				    newPurchase.setItemName(name);

				    cout << "Enter the purchase date." << endl;
	                cout << "Enter month: ";
	                month = validInt(1, 12);
	                cout << "Enter day: ";
	                day = validInt(1, 31);
	                cout << "Enter year: ";
	                year = validInt(1950, 2014);

	                newPurchase.setDate(month, day, year);

	                cout << "Enter the quantity: ";
	                newPurchase.setQuantity(validInt(1,1000));

	                cout << "Enter the unit price: $";
	                cin >> price;
	                cin.ignore(1000, '\n');
	                newPurchase.setUnitPrice(price *
	                		newPurchase.getQuantity());

	                db.addPurchase(newPurchase);

	                cout << "\nPurchase Added." << endl;

	                pause();
	                break;

				case 2:
					bool invalid = true;
					cout << "You may enter either the member name or ID "
							"of the member you wish to delete.\n";
					cout << "1. Enter member name.\n";
					cout << "2. Enter member ID.\n";
					cout << "Please enter your choice: ";
					menuChoice = validInt(1, 2);

					switch(menuChoice)
					{
					case 1:
						while(invalid)
						{
							cout << "Enter the name of the member you want"
									" to delete: ";
							getline(cin, name);

							try
							{
								db.removeMember(name);
								invalid = false;
							    cout << "\nMember deleted." << endl;
							}
							catch(RuntimeException& err)
							{
								cout << err.getMessage();
							}
						}
						pause();
						break;
					case 2:
						while(invalid)
						{
						    cout << "Enter the member ID of the member you"
						            " want to delete: ";
						    id = validInt(0, 99999);

						    try
						    {
							    db.removeMember(id);
							    invalid = false;
							    cout << "\nMember deleted." << endl;
						    }
						    catch(RuntimeException& err)
						    {
						    	cout << err.getMessage();
						    }
						}
						pause();
					    break;
					}

					break;
				}
				break;

			case EXIT:
				cout << "Goodbye";
				exit = true;
				PurchaseWrite(db);
				MemberWrite(db);
				break;
		}
		cout << endl;
	} while (!exit);
	pause();
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

bool validBool()
{
    char input;
    bool choice;
    bool invalid = true;

    while (invalid)
    {
        cin.get(input);
        cin.ignore(1000, '\n');
        input = toupper(input);

        if (input == 'Y')
        {
            choice = true;
            invalid = false;
        }
        else if (input == 'F')
        {
            choice = false;
            invalid = false;
        }
        else
        {
            cout << "Invalid input, try again: ";
        }
    }

    return choice;
}

void printAllPurchases(database& db, int filterType)
{
	set<int> idSet;
	int basicCount = 0, prefCount = 0;
	float totalSales = 0;

	cout << "Printing all sales sorted by member ID:" << endl;
	cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
    cout << "| " << setw(30) << "Item";
    cout << "| " << setw(7) << "Unit";
    cout << "| " << setw(5) << "Qty";
    cout << "| " << setw(22) << "Member Name";
    cout << "| " << setw(7) << "ID";
    cout << "| " << setw(10) << "Type";
    cout << "| " << endl;
    cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;

	for (multimap<int,purchase>::iterator it =
			db.purchaseByIDBegin();
			it!= db.purchaseByIDEnd(); ++it)
	{
		if(((filterType == 1) && !(it->second.getMember()->getType())) ||
				((filterType == 2) && (it->second.getMember()->getType()))
				|| filterType == 3)
	    	{
	       	cout << "| " << setw(30) <<  it->second.getItemName();
	       	cout << "|$" << right << setw(7) << (it->second.getUnitPrice())
	       			/ (it->second.getQuantity()) << left;
	    	cout << "| " << setw(5) << it->second.getQuantity();
	    	cout << "| " << setw(22) <<
	    			(it->second.getMember())->getName();
	    	cout << "| " << setw(7) << (it->second.getMember())->getID();
	    	cout << "| " << setw(10);
	    	totalSales+= (it->second.getUnitPrice());

	    	if (it->second.getMember()->getType())
	    	{
	    		cout << "Preferred";

	    		if (idSet.count(it->second.getMember()->getID()) == 0)
	    		{
	    			idSet.insert(it->second.getMember()->getID());
		    		prefCount++;
	    		}
	    	}
	    	else
	    	{
	    		cout << "Basic";

	    		if (idSet.count(it->second.getMember()->getID()) == 0)
	    		{
	    			idSet.insert(it->second.getMember()->getID());
		    		basicCount++;
	    		}
	    	}
	    	cout << "| " << endl;

	    	}


	    }
	 cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
	    cout << endl << endl;
	    cout << "Total Sales: $" << totalSales << endl;
	    if(filterType != 2)
	    	cout << "Basic Shoppers: " << basicCount << endl;
	    if(filterType != 1)
	    	cout << "Preferred Shoppers: " << prefCount << endl;
}

void printPurchases(database& db, date& day,int  filterType)
{
	set<int> idSet;
	int basicCount = 0, prefCount = 0;
	float totalSales = 0;

	if (db.getPurchases(day).first != db.getPurchases(day).second)
	{
		cout << "\nPurchases for " << day.toString() << ":"
				<< endl;
		cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
		cout << "| " << setw(30) << "Item";
		cout << "| " << setw(7) << "Unit";
		cout << "| " << setw(5) << "Qty";
		cout << "| " << setw(22) << "Member Name";
		cout << "| " << setw(7) << "ID";
		cout << "| " << setw(10) << "Type";
		cout << "| " << endl;
		cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;

		for (multimap<date,purchase>::iterator it =
				db.getPurchases(day).first;
				it!= db.getPurchases(day).second; ++it)
		{
			if(((filterType == 1) && !(it->second.getMember()->getType()))
					|| ((filterType == 2) &&
							(it->second.getMember()->getType()))
							|| filterType == 3)
			{
				cout << "| " << setw(30) <<  it->second.getItemName();
				cout << "|$" << right << setw(7) <<
						(it->second.getUnitPrice()) /
						(it->second.getQuantity()) << left;
				cout << "| " << setw(5) << it->second.getQuantity();
				cout << "| " << setw(22) <<
						(it->second.getMember())->getName();
				cout << "| " << setw(7) <<
						(it->second.getMember())->getID();
				cout << "| " << setw(10);
				totalSales+= (it->second.getUnitPrice());

				if (it->second.getMember()->getType())
				{
					cout << "Preferred";

					if (idSet.count(it->second.getMember()->getID()) == 0)
					{
						idSet.insert(it->second.getMember()->getID());
						prefCount++;
					}
				}
				else
				{
					cout << "Basic";

					if (idSet.count(it->second.getMember()->getID()) == 0)
					{
						idSet.insert(it->second.getMember()->getID());
						basicCount++;
					}
				}
				cout << "| " << endl;
			}
		}

		cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
		cout << endl;
		cout << "Total Sales: $" << totalSales << endl;
		if(filterType != 2)
				cout << "Basic Shoppers: " << basicCount << endl;
		if(filterType != 1)
			cout << "Preferred Shoppers: " << prefCount << endl;
	}
	else
	{
		cout << "\nThere are no purchases recorded for " << day.toString()
				<< endl;
	}
}

void printPurchases(database& db, int id)
{
	if (db.checkMember(id) != 0)
	{
	    cout << "\nPurchases for member #" << id << " - "
	            << db.findMember(id).getName() << ":" << endl;
	    cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
	         cout << "| " << setw(30) << "Item";
	         cout << "| " << setw(7) << "Unit";
	         cout << "| " << setw(5) << "Qty";
	         cout << "| " << setw(14) << "Date";
	         cout << "| " << endl;
	         cout << setw(94) << setfill('-') << "-" << setfill(' ')
	        		 << endl;


	       for (multimap<int,purchase>::iterator it =
	               db.getPurchases(id).first;
	               it!= db.getPurchases(id).second; ++it)
	       {
	           cout << "| " << setw(30) <<  it->second.getItemName();
	           cout << "| " << setw(7) <<  (it->second.getUnitPrice()) /
	        		   (it->second.getQuantity());
	           cout << "| " << setw(5) << it->second.getQuantity();
	           cout << "| " << setw(14) <<
	        		   (it->second.getDate()).toString();

	       	cout << "| " << endl;
	       }
	       cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
	}
	else
	{
		cout << "\nThere are no purchases recorded for member #" << id
				<< endl;
	}
}

void printPurchases(database& db, string name)
{
	if (db.checkMember(name) != 0)
	{
	    int id = db.findMember(name).getID();

	    cout << "\nPurchases for " << name << " - "
	            << id << ":" << endl;
	    cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
	      cout << "| " << setw(30) << "Item";
	      cout << "| " << setw(7) << "Unit";
	      cout << "| " << setw(5) << "Qty";
	      cout << "| " << setw(14) << "Date";
	      cout << "| " << endl;
	      cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;


	    for (multimap<int,purchase>::iterator it =
	            db.getPurchases(id).first;
	            it!= db.getPurchases(id).second; ++it)
	    {
	        cout << "| " << setw(30) <<  it->second.getItemName();
	        cout << "| " << setw(7) <<  (it->second.getUnitPrice()) /
	        		(it->second.getQuantity());
	        cout << "| " << setw(5) << it->second.getQuantity();
	        cout << "| " << setw(14) << (it->second.getDate()).toString();

	    	cout << "| " << endl;
	    }
	    cout << setw(94) << setfill('-') << "-" << setfill(' ') << endl;
	}
	else
	{
		cout << "\nThere are no purchases recorded for " << name
				<< endl;
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
	iFile.open("shop2.txt");

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

		member temp(memberName, memberNum, memTypeBool, month, day, year);

		d.addMember(temp);
	}

	iFile.close();
}

void MemberWrite(database& db)
{
	ofstream oFile;

	oFile.open("shop2.txt");

    for (map<int,member>::iterator it =
            db.memberIDMapBegin();
            it!= db.memberIDMapEnd(); ++it)
    {
    	oFile << it->second.getName() << endl;
    	oFile << it->second.getID() << endl;
    	oFile << (it->second.getType() ? "Preferred" : "Basic") << endl;
    	oFile << setw(2) << setfill('0')
    			<< (it->second.getExpDate()).getMonth() <<"/";
    	oFile << setw(2) << (it->second.getExpDate()).getDay() <<"/";
    	oFile << setw(4) << (it->second.getExpDate()).getYear()
    			<< setfill(' ');
    	if (++it != db.memberIDMapEnd())
    	{
    		oFile << endl;
    		it--;
    	}
    	else
    	{
    		it--;
    	}
    }

    oFile.close();
}

void PurchaseWrite(database& db)
{
	ofstream oFile;

	oFile.open("pur2.txt");


    for (multimap<int,purchase>::iterator it =
            db.purchaseByIDBegin();
            it!= db.purchaseByIDEnd(); ++it)
    {
    	oFile << setw(2) << setfill('0')
    			<< (it->second.getDate()).getMonth() <<"/";
    	oFile << setw(2) << (it->second.getDate()).getDay() <<"/";
    	oFile << setw(4) << (it->second.getDate()).getYear()
    			<< setfill(' ') << endl;
    	oFile << (it->second.getMember())->getID() << endl;
    	oFile << it->second.getItemName() << endl;
    	oFile << (it->second.getUnitPrice())/(it->second.getQuantity())
    			<< " ";
    	oFile << it->second.getQuantity();

    	if (++it != db.purchaseByIDEnd())
    	{
    		oFile << endl;
    		it--;
    	}
    	else
    	{
    		it--;
    	}
    }

    oFile.close();
}

void PurchaseRead(database& d)
{
	ifstream iFile; // INPUT - input stream variable
	string dateStr, itemName;
	float unitPrice;
	int month, day, year, memNum, quantity;

	// PROCESSING - Associates file name with input stream variable
	iFile.open("pur2.txt");

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

		purchase temp(itemName, quantity, (quantity*unitPrice),
				d.findMember(memNum), month, day, year);
		d.addPurchase(temp);
	}

	iFile.close();
}

void pause()
{
	system("pause");
	cin.ignore(1000, '\n');
}
