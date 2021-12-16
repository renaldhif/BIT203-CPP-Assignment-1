/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 6 December 2021
 *
 */

#include "CTIS.h"
// constructor
CovidTest::CovidTest() {
    setTestID(0);
    setTestDate("defaultDate");
    setResult("defaultResult");
    setResultDate("defaultResultDate");
    setStatus("defaultStatus");
}

// constructor with arguments
CovidTest::CovidTest(int inTestID, string inTestDate, string inResult, string inResultDate, string inStatus){
    setTestID(inTestID);
    setTestDate(inTestDate);
    setResult(inResult);
    setResultDate(inResultDate);
    setStatus(inStatus);
}

// destructor
CovidTest::~CovidTest(){};

// setter
void CovidTest::setTestID(int inTestID){
    testID = inTestID;
}

void CovidTest::setTestDate (string inTestDate){
    testDate = inTestDate;
}

void CovidTest::setResult (string inResult){
    result = inResult;
}

void CovidTest::setResultDate (string inResultDate){
    resultDate = inResultDate;
}

void CovidTest::setStatus (string inStatus){
    status = inStatus;
}


void CovidTest::updateResult(string updatePtnType) {
    result = updatePtnType;
}

void CovidTest::updateResultDate(string updatePtnSympt) {
    resultDate = updatePtnSympt;
}

void CovidTest::updateStatus(string updateStatus){
    status = updateStatus;
}

// getters
int CovidTest::getTestID(){
    return testID;
}

string CovidTest::getTestDate(){
    return testDate;
}

string CovidTest::getResult(){
    return result;
}

string CovidTest::getResultDate(){
    return resultDate;
}

string CovidTest::getStatus(){
    return status;
}

// to string

string CovidTest::toString(){
    return to_string(testID) + testDate + result + resultDate + status;
}
