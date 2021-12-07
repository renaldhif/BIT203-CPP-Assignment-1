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
    setOfcPosition("defaultOfcPost");
}

// constructor with arguments
CentreOfficer::CentreOfficer(string inUName, string inPwd, string inFName, string inOfcPos){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
    setOfcPosition(inOfcPos);

}

// destructor
CentreOfficer::~CentreOfficer(){}

// setters
void CentreOfficer::setOfcPosition (string inOfcPos){
    ofcPosition = inOfcPos;
}

// getters
string CentreOfficer::getOfcPosition(){
    return ofcPosition;
}

// to string
string CentreOfficer::toString(){
    return " " + ofcPosition;
}

string CentreOfficer::viewTestHistory() {
    return "view test history from centre officer";
}