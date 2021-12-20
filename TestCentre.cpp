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
// setter aggregation
void TestCentre::setAgrTestKit(TestKit tkNew){
    agrTestKitList.push_back(tkNew);
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

/**
 * This is getter for TestKit vector.
 *
 * @return the testKitList vector
 */
vector<TestKit> TestCentre::getAgrTestKit() {
    return agrTestKitList;
}


/**
 * This method will get the address of vector TestKit at index-i
 * based on Kit's ID.
 *
 * @param kitID as the Kit's ID
 * @return the address of vector TestKit if true.
 * Otherwise, it will return NULL.
 */
TestKit* TestCentre::getTestKitByKitID(int kitID){
    for (int i = 0; i < agrTestKitList.size(); i++){
        if (kitID == agrTestKitList[i].getKitID()){
            return &agrTestKitList[i];
        }
    }
    return NULL;
}