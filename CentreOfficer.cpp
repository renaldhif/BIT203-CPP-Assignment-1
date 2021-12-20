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

/**
 * This is setter for Centre Officer's Covid Test.
 * It records the Centre Officer's Covid Test to the vector.
 *
 * @param ctOfc as Covid Test assigned to the Centre Officer.
 */
void CentreOfficer::setAgrCovidTest(CovidTest ctOfc){
    agrCovidTestList.push_back(ctOfc);
}


// getters
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
 * This is getter for Centre Officer's Test Centre address.
 *
 * @return address of Test Centre assigned to the Centre Officer.
 */
TestCentre* CentreOfficer::getTestCentrePtr() {
    return &tct;
}

/**
* This is getter for Patient's Covid Test vector
*
* @return vector Covid Test assigned to the Patient.
*/
vector<CovidTest> CentreOfficer::getAgrCovidTest() {
    return agrCovidTestList;
}


/**
 * This method will get the address of vector CovidTest at index-i
 * based on CovidTest's ID.
 *
 * @param cTestID as the CovidTest's ID
 * @return the address of vector CovidTest if true.
 * Otherwise, it will return NULL.
 */
CovidTest* CentreOfficer::getCovidTestByCTID(int cTestID){
    for (int i = 0; i < agrCovidTestList.size(); i++){
        if (cTestID == agrCovidTestList[i].getTestID()){
            return &agrCovidTestList[i];
        }
    }
    return NULL;
}


/**
 * This is method for viewing the test history recorded
 * by centre officer
 *
 * @return data test,
 * such as Covid Test ID, Test Date, Result, Result Date, and status.
 */
string CentreOfficer::viewTestHistory(string usrUname, string usrPwd) {
    string vth = "";

    if((usrUname == getUsername()) && (usrPwd == getPassword())){
        for (int i = 0; i < agrCovidTestList.size(); i++){
            vth += "\nData No: " + to_string(i+1) + ": " +
                  "\nCovid Test ID: " + to_string(agrCovidTestList[i].getTestID()) +
                  "\n\tTest Date: " + agrCovidTestList[i].getTestDate() +
                  "\n\tResult: " + agrCovidTestList[i].getResult() +
                  "\n\tResult Date: " +  agrCovidTestList[i].getResultDate() +
                  "\n\tStatus: " +  agrCovidTestList[i].getStatus() + "\n";
        }
    }
    return vth;
}