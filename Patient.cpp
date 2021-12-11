/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 6 December 2021
 *
 */
#include "CTIS.h"
// constructor
Patient::Patient(){
    setUsername("defaultUserPatient");
    setPassword("defaultPassPatient");
    setFullname("defaultFNPatient");
    setPatientType("defaultType");
    setSymptoms("defaultSymptoms");
}

// constructor with arguments
Patient::Patient(string inUName, string inPwd, string inFName, string inPtnType, string inPtnSymp){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
    setPatientType(inPtnType);
    setSymptoms(inPtnSymp);
}

// destructor
Patient::~Patient(){};

// setters
void Patient::setPatientType(string inPatientType){
    patientType = inPatientType;
}

void Patient::setSymptoms(string inSymptoms){
    symptoms = inSymptoms;
}


void Patient::updatePatientType(string updatePtnType) {
    patientType = updatePtnType;
}

void Patient::updateSymptoms(string updatePtnSympt) {
    symptoms = updatePtnSympt;
}

// getters
string Patient::getPatientType(){
    return patientType;
}

string Patient::getSymptoms(){
    return symptoms;
}

// to string
string Patient::toString(){
    return "" + patientType + symptoms;
}

string Patient::viewTestHistory() {
    return "view test history from patient";
}
