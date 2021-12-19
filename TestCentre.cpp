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
 * This is the default constructor of Test Centre class.
 *
 * It sets the default value for Test Centre attributes,
 * such as Centre ID, and Centre Name.
 */
TestCentre::TestCentre(){
    setCentreID(0);
    setCentreName("defaultCentreName");
}

// constructor with arguments
/**
 * This is the constructor of Test Centre class.
 *
 * It sets Test Centre attributes
 * by taking inCentreID as Centre ID, and inCentreName as Centre Name.
 */
TestCentre::TestCentre(int inCentreID, string inCentreName){
    setCentreID(inCentreID);
    setCentreName(inCentreName);
}

// destructor
/**
 * This is the destructor of Test Centre class
 */
TestCentre::~TestCentre(){};

// setters
/**
 * This is setter for Centre ID.
 * It sets the Centre's ID.
 *
 * @param inCentreID as centre ID
 */
void TestCentre::setCentreID(int inCentreID){
    centreID = inCentreID;
}

/**
 * This is setter for Centre Name.
 * It sets the Centre's Name.
 *
 * @param inCentreName as Centre Name
 */
void TestCentre::setCentreName(string inCentreName){
    centreName = inCentreName;
}

// getters
/**
 * This is getter for Centre ID.
 *
 * @return the Centre ID.
 */
int TestCentre::getCentreID(){
    return centreID;
}

/**
 * This is getter for Centre Name.
 *
 * @return the Centre's name.
 */
string TestCentre::getCentreName(){
    return centreName;
}