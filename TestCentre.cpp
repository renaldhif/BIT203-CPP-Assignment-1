/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 6 December 2021
 *
 */

#include "CTIS.h"
// constructor
TestCentre::TestCentre(){
    setCentreID(0);
    setCentreName("defaultCentreName");
}

// constructor with arguments
TestCentre::TestCentre(int inCentreID, string inCentreName){
    setCentreID(inCentreID);
    setCentreName(inCentreName);
}

// destructor
TestCentre::~TestCentre(){};

// setters
void TestCentre::setCentreID(int inCentreID){
    centreID = inCentreID;
}

void TestCentre::setCentreName(string inCentreName){
    centreName = inCentreName;
}

// getters
int TestCentre::getCentreID(){
    return centreID;
}

string TestCentre::getCentreName(){
    return centreName;
}

// to string
string TestCentre::toString(){
    return "" + to_string(centreID) + centreName;
}
