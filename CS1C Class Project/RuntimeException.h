/**************************************************************************
 * AUTHOR       : Matt Clark & Nate Bailey
 * Class Project: Bulk Club
 * CLASS        : CS1C
 * SECTION      : TTh: 8:30AM - 9:50AM
 * Due Date     : 5/15/2014
 *************************************************************************/
#ifndef RUNTIMEEXCEPTION_H_
#define RUNTIMEEXCEPTION_H_

#include <string>
using namespace std;

/****************************************************************************
 * 			Runtime Exception
 * This class is used for throwing exceptions. It contains an error message
 * that can be used to display with the getMessage functions during a catch.
 ***************************************************************************/
class RuntimeException {
	private:
		string errorMsg;		// OUTPUT - string error message
	public:
		// Constructor for RuntimeException object
		RuntimeException(const string& err) {errorMsg = err;}

		// getMessage - method to return error message
		//	Parameters: none
		//	Returns:    errorMsg - string error message
		string getMessage() const {return errorMsg;}
};

#endif /* RUNTIMEEXCEPTION_H_ */
