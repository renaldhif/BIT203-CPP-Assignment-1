/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 *
 */

// include CTIS header
#include "CTIS.h"

// constructor
/**
 * This is the default constructor of Centre Officer class.
 *
 * It sets the default value for centre officer attributes, such as
 * username, password, fullname from User abstract class and centre officer position.
 */
CentreOfficer::CentreOfficer() {
    setUsername("defaultOfcUname");
    setPassword("defaultOfcPass");
    setFullname("defaultOfcFName");
    setOfcPosition("defaultOfcPost");
}

// constructor with arguments
/**
 * This is the constructor of Centre Officer class.
 *
 * It sets Centre Officer attributes by taking inOfcPos as Centre Officer position,
 * attributes from the abstract class and
 * aggregation from TestCentre as the argument.
 *
 */
CentreOfficer::CentreOfficer(string inUName, string inPwd, string inFName, string inOfcPos, TestCentre tct){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
    setOfcPosition(inOfcPos);
    //aggregation
    setTestCentreOfc(tct);
}

// destructor
/**
 * This is the destructor for the CentreOfficer
 */
CentreOfficer::~CentreOfficer(){}

/**
 * This is setter for Centre Officer's position.
 * It sets the Centre Officer position.
 *
 * @param inOfcPos as Centre Officer's position.
 */
void CentreOfficer::setOfcPosition (string inOfcPos){
    ofcPosition = inOfcPos;
}

//aggregation
/**
 * This is setter for Centre Officer's Test Centre.
 * It sets the Centre Officer Test Centre.
 *
 * @param tctOfc as Test Centre assigned to the Centre Officer
 */
void CentreOfficer::setTestCentreOfc(TestCentre tctOfc){
    tct = tctOfc;
}

// ers
/**
 * This is getter for Centre Officer's position.
 *
 * @return the position of the Centre Officer.
 */
string CentreOfficer::getOfcPosition(){
    return ofcPosition;
}

//aggregation
/**
 * This is getter for Centre Officer's Test Centre
 *
 * @return Test Centre assigned to the Centre Officer.
 */
TestCentre CentreOfficer::getTestCentreOfc(){
    return tct;
}

/**
 * This is method for viewing the test history.
 *
 * @return result of the test.
 */
string CentreOfficer::viewTestHistory() {
    return "view test history from centre officer";
}