/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 7 December 2021
 *
 */

#include "CTIS.h"

// constructor
CTIS::CTIS(){};

// destructor
CTIS::~CTIS(){};

// setter
void CTIS::setPatientList(Patient newPatient){
    patientList.push_back(newPatient);
}

void CTIS::setTesterList(CentreOfficer newTester) {
    testerList.push_back(newTester);
}

void CTIS::setManagerList(CentreOfficer newManager) {
    managerList.push_back(newManager);
}



// getter
vector<Patient> CTIS::getPatientList(){
    return patientList;
}

vector<CentreOfficer> CTIS::getManagerList(){
    return managerList;
}

vector<CentreOfficer> CTIS::getTesterList() {
    return testerList;
}

vector<Patient> CTIS::showPatientList(){
    string strPtnList = "";
    for (int i = 0; i < patientList.size(); i++){
        //cout << patientList[i] << endl;
    }
}

// generate an unique int number from 0 - 10
int CTIS::randTCID(){
    int testID;
    // will generate unique number
    srand((unsigned) time(0));
    // will generate random number 0-1
    testID = (rand() % 10);

    return testID;
}
