/**
 *
* @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 *
 */

// include CTIS header
#include "CTIS.h"

// Constructor
/**
 * This is the default constructor of TestKit class.
 *
 * It sets the default value for Test Kit attributes,
 * such as Kit ID, availableKit, and testName.
 */
TestKit::TestKit(){
    setKitID(0);
    setAvailableKit(0);
    setTestName("defaultTestName");
}

// Constructor with arguments
/**
 * This is the constructor of TestKit class.
 *
 * It sets Test Centre attributes
 * by taking inKitID as kitID,
 * inAvailableKit as availableKit, and inTestName as testName.
 */
TestKit::TestKit(int inKitID, int inAvailableKit, string inTestName){
    setKitID(inKitID);
    setAvailableKit(inAvailableKit);
    setTestName(inTestName);
}

// destructor
/**
* This is the destructor of Test Kit class
*/
TestKit::~TestKit(){};

// setters
/**
 * This is setter for kitID.
 * It sets the Kit's ID.
 *
 * @param inKitID as kitID
 */
void TestKit::setKitID(int inKitID){
    kitID = inKitID;
}

/**
 * This is setter for available kit.
 * It sets the quantity of available kit.
 *
 * @param inAvailableKit as availableKit
 */
void TestKit::setAvailableKit(int inAvailableKit){
    availableKit = inAvailableKit;
}

/**
 * This is setter for testName.
 * It sets the Test Kit's Name.
 *
 * @param inTestName as Test Kit's name
 */
void TestKit::setTestName(string inTestName){
    testName = inTestName;
}

/**
 * This method is for updating the stock of available kit quantity.
 * It updates the stock by current quantity available + added stock.
 *
 * @param updQty as new added stock
 */
void TestKit::addStock(int updQty) {
    availableKit = availableKit + updQty;
}

/**
 * This method is for updating the stock of available kit quantity.
 * It updates the stock by current quantity available - 1
 * after the tester successfully records new test for the patient.
 */
void TestKit::decStock(){
    availableKit = availableKit - 1;
}

// getters
/**
 * This is getter for Kit ID.
 *
 * @return the Kit ID.
 */
int TestKit::getKitID() {
    return kitID;
}

/**
 * This is getter for available kit.
 *
 * @return the quantity of available kit.
 */
int TestKit::getAvailableKit() {
    return availableKit;
}

/**
 * This is getter for Test Name.
 *
 * @return the Test Kit name.
 */
string TestKit::getTestName() {
    return testName;
}

// aggregation getter
/**
* This is getter for Patient's Covid Test
*
* @return Covid Test assigned to the Patient.
*/
vector<CovidTest> TestKit::getAgrCovidTest() {
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
CovidTest* TestKit::getCovidTestByCTID(int cTestID){
    for (int i = 0; i < agrCovidTestList.size(); i++){
        if (cTestID == agrCovidTestList[i].getTestID()){
            return &agrCovidTestList[i];
        }
    }
    return NULL;
}