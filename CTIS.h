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
class CentreOfficer;
class CovidTest;
class Patient;
class TestCentre;
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
    virtual string viewTestHistory() = 0;

    // to String method
    string toString();

};

/**
 * Centre Officer Class
 */

class CentreOfficer : public User{
private:
    string ofcPosition;

public:
    // constructor
    CentreOfficer();

    // constructor with arguments
    CentreOfficer(string inUName, string inPwd, string inFName, string inOfcPos);

    // destructor
    ~CentreOfficer();
    // setters
    void setOfcPosition(string inOfcPos);

    // getters
    string getOfcPosition();

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

    // getters
    string getPatientType();
    string getSymptoms();
    // to string
    string toString();

    /**
     * Method for View Testing History
     * and overrides the method from the base class (User class)
     */

    string viewTestHistory() override;
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

    // destructormh
    ~CovidTest();
    // setters
    void setTestID(int inTestID);
    void setTestDate (string inTestDate);
    void setResult (string inResult) ;
    void setResultDate (string inResultDate);
    void setStatus (string inStatus);

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
 * CTIS Class
 */
class CTIS{
private:
    vector<Patient> patientList;
    vector<CentreOfficer> officerList;
    vector<TestKit> testKitList;
public:
    // Constructor
    CTIS();

    // destructor
    ~CTIS();

    // setter
    void setPatientList(Patient newPatient);
    void setOfficerList(CentreOfficer newOfficer);
    void setTestKitList(TestKit newTestKit);

    // getter
    vector<Patient> getPatientList();
    vector<CentreOfficer> getOfficerList();
    vector<TestKit> getTestKitList();

    // other methods
    vector<Patient> showPatientList();
    int randTCID();
    int randKitID();
    bool isLoginMgrValid(string ofcUser, string ofcPwd);
    bool isLoginTstValid(string tstUser, string tstPwd);
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
        string setCentreName();
        // to string
        string toString();
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

        // getters
        int getKitID();
        int getAvailableKit();
        string getTestName();
        // to string
        string toString();
        void addStock(int newAdd);

        // other methods

//
//        int getUpdatedKit(){
//            return
//        }
    };
#endif //ASSIGNMENT_1_CTIS_H
