/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 *
 */

// include guards
#ifndef ASSIGNMENT_1_CTIS_H
#define ASSIGNMENT_1_CTIS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // import rand srand
#include <ctime> // import time library

using namespace std;

// classes declaration
class User;
class CTIS;
class TestCentre;
class CentreOfficer;
class CovidTest;
class Patient;
class TestKit;

/**
 *
 * Class User is an abstract and base class
 * that inherits class Patient and class CentreOfficer
 * as derived classes.
 *
 * It has username, password, and fullname attributes,
 * prototype constructor and constructor with arguments,
 * prototype setter and getter method for each attributes,
 * and prototype pure virtual function
 * for view test history.
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

    // pure virtual function
    virtual string viewTestHistory(string usrUname, string usrPwd) = 0;
};

/**
 * Test Centre Class.
 *
 * It has centreID and centreName attributes,
 * prototype constructor and constructor with arguments,
 * prototype setter and getter method for each attributes
 */
class TestCentre {
private:
    int centreID;
    string centreName;
    vector<TestKit> agrTestKitList;

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
    // setter aggregation
    void setAgrTestKit(TestKit tkNew);

    // getters
    int getCentreID();
    string getCentreName();
    //getter aggregation
    vector<TestKit> getAgrTestKit();
    TestKit* getTestKitByKitID(int kitID);
};

/**
 * CovidTest Class
 *
 * It has testID, testDate,
 *          result, resultDate,
 *          and status attributes,
 * prototype constructor and constructor with arguments,
 * prototype setter and getter method for each attributes,
 * and prototype additional method for updating attributes
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

    // additional methods for updating attributes
    void updateResult(string updatePtnType);
    void updateResultDate(string updatePtnSympt);
    void updateStatus(string updateStatus);

    // getters
    int getTestID();
    string getTestDate();
    string getResult();
    string getResultDate();
    string getStatus();
};

/**
 * Centre Officer Class is a derived class from User class.
 *
 * It has User class attributes,
 *          ofcPosition and TestCentre aggregation attribute,
 * prototype constructor and constructor with arguments,
 * prototype setter and getter method for each attributes,
 * and prototype viewTestHistory.
 */
class CentreOfficer : public User{

private:
    string ofcPosition;
    vector<CovidTest> agrCovidTestList;
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
    void setAgrCovidTest(CovidTest ctPtn);

    // getters
    string getOfcPosition();
    TestCentre getTestCentreOfc();
    TestCentre* getTestCentrePtr();
    vector<CovidTest> getAgrCovidTest();
    CovidTest* getCovidTestByCTID(int cTestID);


    /**
     * Method for View Test History
     * and overrides the method from the base class (User class)
     */
    string viewTestHistory(string usrUname, string usrPwd) override;

};

/**
 * Patient Class is a derived class from User class.
 *
 * It has User class attributes,
 *          patientType, symptoms, and CovidTest aggregation attribute,
 * prototype constructor and constructor with arguments,
 * prototype setter and getter method for each attributes,
 * and prototype viewTestHistory.
 */
class Patient : public User{

private:
    string patientType, symptoms;
    vector<CovidTest> agrCovidTestList;

public:
    // constructor
    Patient();

    // constructor with arguments
    Patient(string inUName, string inPwd, string inFName, string inPtnType, string inPtnSymp);

    // destructor
    ~Patient();

    //setters
    void setPatientType(string);
    void setSymptoms(string);

    void updatePatientType(string);
    void updateSymptoms(string);
    // setter aggregation
    void setAgrCovidTest(CovidTest ctPtn);

    // getters
    string getPatientType();
    string getSymptoms();
    // getter aggregation
    vector<CovidTest> getAgrCovidTest();
    CovidTest* getCovidTestByCTID(int cTestID);

    /**
     * Method for View Testing History
     * and overrides the method from the base class (User class)
     */
    string viewTestHistory(string usrUname, string usrPwd) override;
};

/**
 * CTIS Class.
 *
 * It has vectors attribute from other classes such as
 * patientList, officerList, testKitList, testCentreList, and covidTestList,
 * prototype constructor,
 * prototype setter and getter method for each attributes,
 * prototype additional getter methods for getting the memory address of each vectors,
 * prototype additional methods for generating random numbers,
 * validator for login, and validator unique name.
 *
 */
class CTIS{
private:
    vector<Patient> patientList;
    vector<CentreOfficer> officerList;
    //vector<TestKit> testKitList; // ga perlu
    vector<TestCentre> testCentreList;
    //vector<CovidTest> covidTestList; // ga perlu
public:
    // Constructor
    CTIS();

    // destructor
    ~CTIS();

    // setter
    void setPatientList(Patient newPatient);
    void setOfficerList(CentreOfficer newOfficer);
    //void setTestKitList(TestKit newTestKit);
    void setTestCentreList(TestCentre newTestCentre);
    //void setCovidTestList(CovidTest newCovidTestList);

    // getter
    vector<Patient> getPatientList();
    vector<CentreOfficer> getOfficerList();
    //vector<TestKit> getTestKitList();
    vector<TestCentre> getTestCentreList();
    //vector<CovidTest> getCovidTestList();

    // getter for object using pointer that points to the index of vector
    CentreOfficer* getOfficerByUsername(string uname);
    // TestKit* getTestKitByKitID(int kitID);
    Patient* getPatientByUsername(string ptnName);
    //CovidTest* getCovidTestByCTID(int cTestID);

    // generate random numbers
    // for TestCentre ID, Kit ID, and CovidTest ID
    int randTCID();
    int randKitID();
    int randCTestID();

    // validator for login Centre Officer (Manager/Tester) and Patient.
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
 * Test Kit Class.
 *
 * It has kitID, availableKit, and testName attributes,
 * prototype constructor and constructor with arguments,
 * prototype setter and getter method for each attributes,
 * and additional methods for updating the attributes.
 */
class TestKit{
private:
    int kitID, availableKit;
    string testName;
    vector<CovidTest> agrCovidTestList;

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
    // setter aggregation
    void setAgrCovidTest(CovidTest cvdTest);

    // update stock
    void addStock(int newAdd);
    void decStock();

    // getters
    int getKitID();
    int getAvailableKit();
    string getTestName();
    // aggregation getter
    vector<CovidTest> getAgrCovidTest();
    CovidTest* getCovidTestByCTID(int cTestID);
};
#endif //ASSIGNMENT_1_CTIS_H
