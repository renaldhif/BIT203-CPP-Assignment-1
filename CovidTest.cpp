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
 * This is the default constructor of Covid Test class.
 *
 * It sets the default value for Covid Test attributes, such as
 * testID, testDate, result, resultDate, and status.
 */
CovidTest::CovidTest() {
    setTestID(0);
    setTestDate("defaultDate");
    setResult("defaultResult");
    setResultDate("defaultResultDate");
    setStatus("defaultStatus");
}

// constructor with arguments
/**
 * This is the constructor of Covid Test class.
 *
 * It sets Covid Test attributes by taking
 * inTestID, inTestDate, inResult, inResultDate, inStatus as the arguments.
 *
 */
CovidTest::CovidTest(int inTestID, string inTestDate, string inResult, string inResultDate, string inStatus){
    setTestID(inTestID);
    setTestDate(inTestDate);
    setResult(inResult);
    setResultDate(inResultDate);
    setStatus(inStatus);
}

// destructor
/**
 * This is the destructor of Covid Test class
 */
CovidTest::~CovidTest(){};

// setter
/**
 * This is setter for Covid Test ID.
 * It sets the Covid Test ID
 *
 * @param inTestID as Covid Test ID
 */
void CovidTest::setTestID(int inTestID){
    testID = inTestID;
}

/**
 * This is setter for Covid Test Date.
 * It records the Covid Test's date.
 *
 * @param inTestDate as Covid Test Date
 */
void CovidTest::setTestDate (string inTestDate){
    testDate = inTestDate;
}

/**
 * This is setter for Covid Test Result.
 * It sets the result of the Covid Test.
 *
 * @param inResult as Covid Test result.
 */
void CovidTest::setResult (string inResult){
    result = inResult;
}

/**
 * This is setter for Covid Test result date.
 * It records the date of Covid Test Result.
 *
 * @param inResultDate as the covid test result date.
 */
void CovidTest::setResultDate (string inResultDate){
    resultDate = inResultDate;
}

/**
 * This is setter for Covid Test status.
 * It sets the status of the covid test whether it is "pending" or "completed".
 *
 * @param inStatus as covid test result.
 */
void CovidTest::setStatus (string inStatus){
    status = inStatus;
}

// updater
/**
 * This is setter for new Covid Test result.
 * It updates the result of the Covid Test.
 *
 * @param upRes as new covid test result.
 */
void CovidTest::updateResult(string upRes) {
    result = upRes;
}

/**
 * This is setter for new Covid Test Result Date.
 * It updates the result date of the Covid Test.
 *
 * @param upResDate as new Covid Test Result Date
 */
void CovidTest::updateResultDate(string upResDate) {
    resultDate = upResDate;
}

/**
 * This is setter for new Covid Test status.
 * It updates the status of the Covid Test.
 *
 * @param upStatus as new covid test status.
 */
void CovidTest::updateStatus(string upStatus){
    status = upStatus;
}

// getters
/**
 * This is getter for Covid Test ID.
 *
 * @return Covid Test ID
 */
int CovidTest::getTestID(){
    return testID;
}

/**
 * This is getter for Covid Test Date
 *
 * @return Covid Test Date
 */
string CovidTest::getTestDate(){
    return testDate;
}

/**
 * This is getter for Covid Test Result
 *
 * @return Covid Test Result
 */
string CovidTest::getResult(){
    return result;
}

/**
 * This is getter for Covid Test Result Date
 *
 * @return Covid Test Result Date
 */
string CovidTest::getResultDate(){
    return resultDate;
}

/**
 * This is getter for Covid Test Status
 *
 * @return Covid Test Status
 */
string CovidTest::getStatus(){
    return status;
}