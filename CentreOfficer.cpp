/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 6 December 2021
 *
 */

#include "CTIS.h"

// constructor
CentreOfficer::CentreOfficer() {
    setUsername("defaultOfcUname");
    setPassword("defaultOfcPass");
    setFullname("defaultOfcFName");
    //aggregation
    setOfcPosition("defaultOfcPost");
}

// constructor with arguments
CentreOfficer::CentreOfficer(string inUName, string inPwd, string inFName, string inOfcPos, TestCentre tct){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
    setOfcPosition(inOfcPos);
    //aggregation
    setTestCentreOfc(tct);
}

// destructor
CentreOfficer::~CentreOfficer(){}

// setters
void CentreOfficer::setOfcPosition (string inOfcPos){
    ofcPosition = inOfcPos;
}

//aggregation
void CentreOfficer::setTestCentreOfc(TestCentre tctOfc){
    tct = tctOfc;
}

// getters
string CentreOfficer::getOfcPosition(){
    return ofcPosition;
}
//aggregation
TestCentre CentreOfficer::getTestCentreOfc(){
    return tct;
}

// to string
string CentreOfficer::toString(){
    return " " + ofcPosition;
}

string CentreOfficer::viewTestHistory() {
    return "view test history from centre officer";
}