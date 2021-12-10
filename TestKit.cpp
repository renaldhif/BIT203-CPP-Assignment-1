/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 6 December 2021
 *
 */

#include "CTIS.h"

// Constructor
TestKit::TestKit(){
    setKitID(0);
    setAvailableKit(0);
    setTestName("defaultTestName");
}

// Constructor with arguments
TestKit::TestKit(int inKitID, int inAvailableKit, string inTestName){
    setKitID(inKitID);
    setAvailableKit(inAvailableKit);
    setTestName(inTestName);
}

// destructor
TestKit::~TestKit(){};

// setters
void TestKit::setKitID(int inKitID){
    kitID = inKitID;
}

void TestKit::setAvailableKit(int inAvailableKit){
    availableKit = inAvailableKit;
}

void TestKit::setTestName(string inTestName){
    testName = inTestName;
}

// getters
int TestKit::getKitID() {
    return kitID;
}

int TestKit::getAvailableKit() {
    return availableKit;
}

string TestKit::getTestName() {
    return testName;
}

void TestKit::addStock(int updQty) {
    availableKit = availableKit + updQty;
}

string TestKit::toString() {
    return "kit ID: " + to_string(kitID) +
            ", available kit: " + to_string(availableKit) +
            ",test name: " + testName;
}
