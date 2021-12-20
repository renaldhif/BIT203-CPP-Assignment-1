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
 * This is the default constructor of Patient class.
 *
 * It sets the default value for Patient attributes, such as
 * username, password, fullname from User abstract class and Patient type and symptoms.
 */
Patient::Patient(){
    setUsername("defaultUserPatient");
    setPassword("defaultPassPatient");
    setFullname("defaultFNPatient");
    setPatientType("defaultType");
    setSymptoms("defaultSymptoms");
}

// constructor with arguments
/**
 * This is the constructor of Patient class.
 *
 * It sets Patient attributes by taking inPtnType as patient's type and inPtnSymp as patient symptoms,
 * attributes from the abstract class and
 * aggregation from CovidTest as the argument.
 *
 */
Patient::Patient(string inUName, string inPwd, string inFName, string inPtnType, string inPtnSymp){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
    setPatientType(inPtnType);
    setSymptoms(inPtnSymp);
}

// destructor
/**
 * This is the destructor of Patient class
 */
Patient::~Patient(){};

// setters
/**
 * This is setter for Patient type.
 * It sets the patient's type.
 *
 * @param inPatientType as patient's type
 */
void Patient::setPatientType(string inPatientType){
    patientType = inPatientType;
}

/**
 * This is setter for Patient symptoms.
 * It sets the patient's symptoms.
 *
 * @param inSymptoms as patient's symptoms
 */

void Patient::setSymptoms(string inSymptoms){
    symptoms = inSymptoms;
}

// update
/**
 * This is setter for new Patient type.
 * It updates the patient's type.
 *
 * @param inPatientType as new patient's type
 */
void Patient::updatePatientType(string updatePtnType) {
    patientType = updatePtnType;
}

/**
 * This is setter for new Patient Symptoms.
 * It sets the patient's symptoms.
 *
 * @param updatePtnSympt as patient's symptoms
 */
void Patient::updateSymptoms(string updatePtnSympt) {
    symptoms = updatePtnSympt;
}

// setter aggregation
/**
 * This is setter for Patient's Covid Test.
 * It sets the patient's Covid Test.
 *
 * @param ctPtn as Covid Test assigned to the Patient.
 */
void Patient::setAgrCovidTest(CovidTest ctPtn){
    agrCovidTestList.push_back(ctPtn);
}

// getters

/**
 * This is getter for Patient's type.
 *
 * @return the Patient's type.
 */
string Patient::getPatientType(){
    return patientType;
}

/**
 * This is getter for Patient's symptoms
 *
 * @return the Patient's symptoms.
 */
string Patient::getSymptoms(){
    return symptoms;
}

/**
* This is getter for Patient's Covid Test
*
* @return Covid Test assigned to the Patient.
*/
vector<CovidTest> Patient::getAgrCovidTest() {
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
CovidTest* Patient::getCovidTestByCTID(int cTestID){
    for (int i = 0; i < agrCovidTestList.size(); i++){
        if (cTestID == agrCovidTestList[i].getTestID()){
            return &agrCovidTestList[i];
        }
    }
    return NULL;
}

/**
* This is method for viewing the test history.
*
* @return result of the test.
*/
string Patient::viewTestHistory(string usrUname, string usrPwd) {
    string vth = "";

    if((usrUname == getUsername()) && (usrPwd == getPassword())){
        for (int i = 0; i < agrCovidTestList.size(); i++){
            vth = "\nCovid Test ID: " + to_string(getAgrCovidTest()[i].getTestID()) +
                  "\n\tPatient Name: " + getFullname() +
                  "\n\tTest Date: " + getAgrCovidTest()[i].getTestDate() +
                  "\n\tResult: " + getAgrCovidTest()[i].getResult() +
                  "\n\tResult Date: " +  getAgrCovidTest()[i].getResultDate() +
                  "\n\tStatus: " +  getAgrCovidTest()[i].getStatus() + "\n";
        }
    }
    return vth;
}
