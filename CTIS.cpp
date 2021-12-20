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
 * This is the default constructor of CTIS class.
 *
 * It will be used to create an object
 * that calls all the methods from CTIS class
 */
CTIS::CTIS(){};

// destructor
/**
 * This is the destructor of CTIS class
 */
CTIS::~CTIS(){};

// setter
/**
 * This is setter for adding Patient object.
 * It adds the Patient object to the patientList vector.
 *
 * @param newPatient as patient object
 */
void CTIS::setPatientList(Patient newPatient){
    patientList.push_back(newPatient);
}

/**
 * This is setter for adding CentreOfficer object.
 * It adds the CentreOfficer object to the CentreOfficer vector.
 *
 * @param newOfficer as patient object
 */
void CTIS::setOfficerList(CentreOfficer newOfficer) {
    officerList.push_back(newOfficer);
}

/**
 * This is setter for adding TestCentre object.
 * It adds the TestCentre object to the testCentreList vector.
 *
 * @param newTestCentre as TestCentre object
 */
void CTIS::setTestCentreList(TestCentre newTestCentre) {
    testCentreList.push_back(newTestCentre);
}

// getter

// getters
/**
 * This is getter for patientList vector.
 *
 * @return the patientList vector
 */
vector<Patient> CTIS::getPatientList(){
    return patientList;
}

/**
 * This is getter for CentreOfficer vector.
 *
 * @return the officerList vector
 */
vector<CentreOfficer> CTIS::getOfficerList() {
    return officerList;
}


/**
 * This is getter for TestCentre vector.
 *
 * @return the testCentreList vector
 */
vector<TestCentre> CTIS::getTestCentreList() {
    return testCentreList;
}

/**
 * This method will get the address of vector CentreOfficer at index-i
 * based on CentreOfficer's username.
 *
 * @param ofcUname as the CentreOfficer's username
 * @return the address of vector CentreOfficer if true.
 * Otherwise, it will return NULL.
 */
CentreOfficer* CTIS::getOfficerByUsername(string ofcUname)
{
    for (int i = 0; i < officerList.size(); i++){
        if (ofcUname == officerList[i].getUsername()){
            return &officerList[i];
        }
    }
    return NULL;
}

/**
 * This method will get the address of vector Patient at index-i
 * based on Patient's Name.
 *
 * @param ptnName as the Patient's Name
 * @return the address of vector Patient if true.
 * Otherwise, it will return NULL.
 */
Patient* CTIS::getPatientByUsername(string ptnName) {
    for (int i = 0; i < patientList.size(); i++){
        if (ptnName == patientList[i].getUsername()){
            return &patientList[i];
        }
    }
    return NULL;
}


/**
 * This method generates a random unique number from 1 - 10
 * for Test Centre's ID
 *
 * @return TestCentre's ID
 */
int CTIS::randTCID(){
    int genTCID;
    // will generate unique number
    srand((unsigned) time(0));
    // will generate random number 1-10
    genTCID = (rand() % 10) + 1;

    return genTCID;
}

/**
 * This method generates a random unique number from 1 - 50
 * for TestKit's ID
 *
 * @return TestKit's ID
 */
int CTIS::randKitID() {
    int genKitID;
    // will generate unique number
    srand((unsigned) time(0));
    // will generate random number 1-50
    genKitID = (rand() % 50) + 1;

    return genKitID;
}

/**
 * This method generates a random unique number from 1 - 10.000
 * for CovidTest's ID
 *
 * @return CovidTest's ID
 */
int CTIS::randCTestID(){
    int genCTestID;
    // will generate unique number
    srand((unsigned) time(0));
    // will generate random number 1-10.000
    genCTestID = (rand() % 10000) + 1;

    return genCTestID;
}

/**
 * This method is to validate login session for Centre Officer (Manager)
 * based on the Centre Officer (Manager) username and password.
 *
 * @param ofcUser as Centre Officer(Manager) username
 * @param ofcPwd as Centre Officer(Manager) password
 *
 * @return true if the username and password inputted
 * is equals to the vector list and
 * the Centre Officer's position is "Manager".
 *
 * Otherwise, it will return false.
 */
bool CTIS::isLoginMgrValid(string ofcUser, string ofcPwd){
    string posOfc;
    for (int i = 0; i < officerList.size(); i++){
        // validate username and password
        if (((ofcUser == getOfficerList()[i].getUsername()) && (ofcPwd == getOfficerList()[i].getPassword()))){
            posOfc = getOfficerList()[i].getOfcPosition();
            // validate the Centre Officer position
            if (posOfc == "Manager"){
                return true;
            }
        }
    }
    return false;
}

/**
 * This method is to validate login session for Centre Officer (Tester)
 * based on the Centre Officer (Tester) username and password.
 *
 * @param tstUser as Centre Officer(Tester) username
 * @param tstPwd as Centre Officer(Tester) password
 *
 * @return true if the username and password inputted
 * is equals to the vector list true and
 * if the Centre Officer's position is "Tester".
 *
 * Otherwise, it will return false.
 */
bool CTIS::isLoginTstValid(string tstUser, string tstPwd) {
    string posOfc;
    for (int i = 0; i < officerList.size(); i++){
        if (((tstUser == getOfficerList()[i].getUsername()) && (tstPwd == getOfficerList()[i].getPassword()))){
            posOfc = getOfficerList()[i].getOfcPosition();
            if (posOfc == "Tester"){
                return true;
            }
        }
    }
    return false;
}

/**
 * This method is to validate login session for Patient
 * based on the Patient username and password.
 *
 * @param ptnUser as Patient username
 * @param ptnPwd as Patient password
 *
 * @return true if the username and password inputted
 * is equals to the vector list.
 * Otherwise, it will return false
 */
bool CTIS::isLoginPtnValid(string ptnUser, string ptnPwd) {
    for (int i = 0; i < patientList.size(); i++){
        if ((ptnUser == getPatientList()[i].getUsername()) && (ptnPwd == getPatientList()[i].getPassword())){
            return true;
        }
    }
    return false;
}


/**
 * This method is to validate if the Centre Officer (Manager) has been registered
 * based on the Centre Officer (Manager) username.
 *
 * @param mgrUser as the Centre Officer (Manager) username
 *
 * @return true if the Centre Officer (Manager) name inputted
 * is equals to the vector list and the position is "Manager".
 *
 * Otherwise, it will return false.
 */
bool CTIS::isManagerRegistered(string mgrUser){
    string posOfc = "";
    for (int i = 0; i < getOfficerList().size(); i++){
        if (mgrUser == getOfficerList()[i].getUsername()) {
            posOfc = getOfficerList()[i].getOfcPosition();
            if (posOfc == "Manager"){
                return true;
            }
        }
    }
    return false;
}

/**
 * This method is to validate if the Centre Officer (Tester) has been registered
 * based on the Centre Officer (Tester) username.
 *
 * @param tstUser as the Centre Officer (Tester) username
 *
 * @return true if the Centre Officer (Tester) name inputted
 * is equals to the vector list and the position is "Tester".
 *
 * Otherwise, it will return false.
 */
bool CTIS::isTesterRegistered(string tstUser){
    string posOfc = "";
    for (int i = 0; i < getOfficerList().size(); i++){
        if (tstUser == getOfficerList()[i].getUsername()) {
            posOfc = getOfficerList()[i].getOfcPosition();
            if (posOfc == "Tester"){
                return true;
            }
        }
    }
    return false;
}

/**
 * This method is to validate if the Patient has been registered
 * based on the Patient username.
 *
 * @param ptnUser as the Patient username
 *
 * @return true if Patient name inputted
 * is equals to the vector list.
 *
 * Otherwise, it will return false.
 */
bool CTIS::isPatientRegistered(string ptnUser){
    for (int i = 0; i < patientList.size(); i++){
        if (ptnUser == patientList[i].getUsername()) {
            return true;
        }
    }
    return false;
}

/**
 * This method is to validate if the Test Centre has been registered
 * based on the Test Centre name.
 *
 * @param ctName as the Test Centre name
 *
 * @return true if the Test Centre name inputted
 * is equals to the vector list.
 * Otherwise, it will return false.
 */
bool CTIS::isTestCentreRegistered(string ctName){
    for (int i = 0; i < testCentreList.size(); i++){
        if (ctName == testCentreList[i].getCentreName()) {
            return true;
        }
    }
    return false;
}

/**
 * This method is to validate if the Test Kit has been registered
 * based on the Test Kit name.
 *
 * @param tkName as the Test Kit name
 *
 * @return true if the Test Kit name inputted
 * is equals to the vector list.
 * Otherwise, it will return false.
 */
bool CTIS::isTestKitRegistered(string tkName) {
    TestCentre tc;
    for (int i = 0; i < tc.getAgrTestKit().size(); i++){
        if (tkName == tc.getAgrTestKit()[i].getTestName()) {
            return true;
        }
    }
    return false;
}