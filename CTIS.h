//
// Created by Renaldhi Fahrezi on 03-Dec-21.
//
#ifndef ASSIGNMENT_1_CTIS_H
#define ASSIGNMENT_1_CTIS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // import rand srand
#include <ctime>

using namespace std;

class User;
class CTIS;
class TestCentre;
class CentreOfficer;
class CovidTest;
class Patient;
class TestKit;

/**
 *
 * Class User is an abstract base class for class Patient and class CentreOfficer
 *
 */
class User{
private:
    string username, password, fullname;

public:
    // constructor
    User();
    // constructor with arguments
    User(string inUName, string inPwd, string inFName);

    // destructor
    ~User();
    // setters
    void setUsername(string inUName);
    void setPassword(string inPwd);
    void setFullname(string inFName);
    // getters
    string getUsername();
    string getPassword();
    string getFullname();

    // Method for View Testing History
    // pure virtual function
    virtual string viewTestHistory() = 0;

    // to String method
    string toString();

};

/**
 * Test Centre Class
 */
class TestCentre {
private:
    int centreID;
    string centreName;

public:
    // constructor
    TestCentre();

    // constructor with arguments
    TestCentre(int inCentreID, string inCentreName);

    // destructor
    ~TestCentre();

    // setters
    void setCentreID(int inCentreID);
    void setCentreName(string inCentreName);

    // getters
    int getCentreID();
    string getCentreName();
    // to string
    string toString();
};

/**
 * CovidTest Class
 */
class CovidTest{
private:
    int testID;
    string testDate;
    string result;
    string resultDate;
    string status;

public:
    // constructor
    CovidTest();
    // constructor with arguments
    CovidTest(int inTestID, string inTestDate,string inResult, string inResultDate, string inStatus);

    // destructor
    ~CovidTest();
    // setters
    void setTestID(int inTestID);
    void setTestDate (string inTestDate);
    void setResult (string inResult) ;
    void setResultDate (string inResultDate);
    void setStatus (string inStatus);

    void updateResult(string updatePtnType);
    void updateResultDate(string updatePtnSympt);
    void updateStatus(string updateStatus);
    // getters

    int getTestID();
    string getTestDate();
    string getResult();
    string getResultDate();
    string getStatus();

    // to string
    string toString();
};

/**
 * Centre Officer Class
 */
class CentreOfficer : public User{

private:
    string ofcPosition;
    TestCentre tct;
public:
    // constructor
    CentreOfficer();

    // constructor with arguments
    CentreOfficer(string inUName, string inPwd, string inFName, string inOfcPos, TestCentre tct);

    // destructor
    ~CentreOfficer();
    // setters
    void setOfcPosition(string inOfcPos);
    void setTestCentreOfc(TestCentre tctOfc);

    // getters
    string getOfcPosition();
    TestCentre getTestCentreOfc();

    // to string
    string toString();

    /**
     * Method for View Testing History
     * and overrides the method from the base class (User class)
     */

    string viewTestHistory() override;

};
/**
 * Patient Class
 */
class Patient : public User{

private:
    string patientType, symptoms;
    CovidTest newCovidTest;

public:
    // constructor
    Patient();

    // constructor with arguments
    Patient(string inUName, string inPwd, string inFName, string inPtnType, string inPtnSymp, CovidTest ctPtn);

    // destructor
    ~Patient();

    //setters
    void setPatientType(string);
    void setSymptoms(string);

    void updatePatientType(string);
    void updateSymptoms(string);

    void setCovidTestPtn(CovidTest ctPtn);
    // getters
    string getPatientType();
    string getSymptoms();

    CovidTest getCovidTestPtn();
    // to string
    string toString();

    /**
     * Method for View Testing History
     * and overrides the method from the base class (User class)
     */

    string viewTestHistory() override;
};

/**
 * CTIS Class
 */
class CTIS{
private:
    vector<Patient> patientList;
    vector<CentreOfficer> officerList;
    vector<TestKit> testKitList;
    vector<TestCentre> testCentreList;
    vector<CovidTest> covidTestList;
public:
    // Constructor
    CTIS();

    // destructor
    ~CTIS();

    // setter
    void setPatientList(Patient newPatient);
    void setOfficerList(CentreOfficer newOfficer);
    void setTestKitList(TestKit newTestKit);
    void setTestCentreList(TestCentre newTestCentre);
    void setCovidTestList(CovidTest newCovidTestList);

    // getter
    vector<Patient> getPatientList();
    vector<CentreOfficer> getOfficerList();
    vector<TestKit> getTestKitList();
    vector<TestCentre> getTestCentreList();
    vector<CovidTest> getCovidTestList();

    // getter for object using pointer that points to the index of vector
    CentreOfficer* getOfficerByUsername(string uname);
    TestKit* getTestKitByKitID(int kitID);
    Patient* getPatientByUsername(string ptnName);
    CovidTest* getCovidTestByCTID(int cTestID);

    // other methods
    vector<Patient> showPatientList();

    // generate rand numb
    int randTCID();
    int randKitID();
    int randCTestID();

    // validator for login
    bool isLoginMgrValid(string ofcUser, string ofcPwd);
    bool isLoginTstValid(string tstUser, string tstPwd);
    bool isLoginPtnValid(string ptnUser, string ptnPwd);
    // validator for unique name
    bool isTestCentreRegistered(string ctName);
    bool isTestKitRegistered(string tkName);
    bool isManagerRegistered(string mgrUser);
    bool isTesterRegistered(string tstUser);
    bool isPatientRegistered(string ptnUser);

};

/**
 * TestKit class
 */

class TestKit{
private:
    int kitID, availableKit;
    string testName;

public:
    // constructor
    TestKit();

    // constructor with arguments
    TestKit(int inKitID, int inAvailableKit, string inTestName);

    // destructor
    ~TestKit();

    // setters
    void setKitID(int);
    void setAvailableKit(int);
    void setTestName(string);
    // update stock
    void addStock(int newAdd);

    // getters
    int getKitID();
    int getAvailableKit();
    string getTestName();
    // to string
    string toString();
};
#endif //ASSIGNMENT_1_CTIS_H
