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

void CTIS::setOfficerList(CentreOfficer newOfficer) {
    officerList.push_back(newOfficer);
}

void CTIS::setTestKitList(TestKit newTestKit) {
    testKitList.push_back(newTestKit);
}



// getter
vector<Patient> CTIS::getPatientList(){
    return patientList;
}

vector<CentreOfficer> CTIS::getOfficerList() {
    return officerList;
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


bool CTIS::isLoginMgrValid(string ofcUser, string ofcPwd){
    string posOfc;
    for (int i = 0; i < officerList.size(); i++){
        if (((ofcUser == getOfficerList().at(i).getUsername()) && (ofcPwd == getOfficerList().at(i).getPassword()))){
            posOfc = getOfficerList().at(i).getOfcPosition();
            if (posOfc == "Manager"){
                return true;
            }
        }
    }
    return false;
}

bool CTIS::isLoginTstValid(string tstUser, string tstPwd) {
    string posOfc;
    for (int i = 0; i < officerList.size(); i++){
        if (((tstUser == getOfficerList().at(i).getUsername()) && (tstPwd == getOfficerList().at(i).getPassword()))){
            posOfc = getOfficerList().at(i).getOfcPosition();
            if (posOfc == "Tester"){
                return true;
            }
        }
    }
    return false;
}
