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

void CTIS::setTestKitList(TestKit newTestKit) {
    testKitList.push_back(newTestKit);
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

vector<TestKit> CTIS::getTestKitList() {
    return testKitList;
}

// other methods
//vector<Patient> CTIS::showPatientList(){
////    string strPtnList = "";
////    for (int i = 0; i < patientList.size(); i++){
////        //cout << patientList[i] << endl;
////    }
//}

// generate an unique int number from 0 - 10
// for Test Centre ID
int CTIS::randTCID(){
    int genTCID;
    // will generate unique number
    srand((unsigned) time(0));
    // will generate random number 1-10
    genTCID = (rand() % 10) + 1;

    return genTCID;
}


// generate an unique int number from 0 - 50
int CTIS::randKitID() {
    int genKitID;
    // will generate unique number
    srand((unsigned) time(0));
    // will generate random number 1-50
    genKitID = (rand() % 50) + 1;

    return genKitID;
}


bool CTIS::isLoginMgrValid(string mgrUser, string mgrPwd){
    for (int i = 0; i < managerList.size(); i++){
        if (((mgrUser == getManagerList().at(i).getUsername()) && (mgrPwd == getManagerList().at(i).getPassword()))){
            return true;
        }
    }
    return false;
}
