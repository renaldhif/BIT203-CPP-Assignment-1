/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 *
 */
#include "CTIS.h"
#include <iostream>
#include <string>

// Declare variables for user input and some variables have initialized values
string usrInFN, usrInLN, usrUname, usrPwd, usrFlName,
        inPtnType, ctNameReg, inPtnSymp, tkNameReg;

int menuOpt = 10, menuOpt2 = 10,
    slcPtnType, tctIDRand, tKitIDRand, availQtyKit, cvdTestIDRand;

char op;

CTIS ctisexec;
TestCentre tct;

int main() {
    while (menuOpt != 0) {
        cout << "\nCTIS System.\nPlease select menu below:" << endl;
        cout << "\t[1] Register for Test Center Manager" << endl;
        cout << "\t[2] Login for Manager" << endl;
        cout << "\t[3] Login for Tester" << endl;
        cout << "\t[4] Login for Patient" << endl;
        cout << "\t[5] Generate Test Report" << endl;
        cout << "\t[0] Exit" << endl;
        cout << "Select menu number: ";
        cin >> menuOpt;

        switch (menuOpt) {
            case 0:
                cout << "Program closed.\nThank you.\nStay safe and stay healthy";
                break; // break case 0

            case 1: {
                cout << "\nRegister a new account for Manager." << endl;
                cout << "Enter First Name: ";
                cin >> usrInFN;

                cout << "Enter Last name: ";
                cin >> usrInLN;

                usrFlName = usrInFN + " " + usrInLN;

                cout << "Enter username: ";
                cin >> usrUname;

                while(ctisexec.isManagerRegistered(usrUname)){
                    cout << "Username has been taken." << endl;
                    cout << "Please try another one." << endl;
                    cout << "\nEnter username: ";
                    cin >> usrUname;
                }

                cout << "Enter password: ";
                cin >> usrPwd;

                // create new object centre officer
                CentreOfficer newManager(usrUname, usrPwd, usrFlName, "Manager",tct);
                ctisexec.setOfficerList(newManager);
                cout << "Manager " << usrFlName << " has successfully registered!" << endl;
            }
                break; // break case 1

            case 2:
                cout << "\nLogin for Test Center Manager." << endl;

                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                // validate if account exists
                if (ctisexec.isLoginMgrValid(usrUname, usrPwd)) {
                    CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);

                    cout << "\nWelcome Test Center Manager, " << usrUname << endl;
                    cout << "Select menu below: " << endl;
                    cout << "\t[1] Register Test Centre" << endl;
                    cout << "\t[2] Record Tester" << endl;
                    cout << "\t[3] Manage Test Kit Stock" << endl;
                    cout << "\t[0] Back" << endl;
                    cout << "Select menu number: ";
                    cin >> menuOpt2;
                    cout << endl;

                    while (!(menuOpt2 >= 0 && menuOpt2 <= 3)) {
                        cout << "Please input valid number!" << endl;
                        cout << "Select menu number: ";
                        cin >> menuOpt2;
                        cout << endl;
                    }

                    switch (menuOpt2) {
                        case 0:
                            break;

                        case 1: {
                            cout << "Register Test Center " << endl;
                            cout << "Input centre name: ";
                            cin.ignore();
                            getline(cin, ctNameReg);

                            tctIDRand = ctisexec.randTCID();
                            while (ctisexec.isTestCentreRegistered(ctNameReg)){
                                cout << "Test Centre name has been registered." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nInput centre name: ";
                                getline(cin, ctNameReg);
                            }
                            TestCentre tct(tctIDRand,ctNameReg);
                            ctisexec.setTestCentreList(tct);
                            ofcLoggedIn->setTestCentreOfc(tct);

                            cout << "Manager " <<  ofcLoggedIn->getFullname()
                                 << " registered at Test Centre " <<  ofcLoggedIn->getTestCentreOfc().getCentreName()
                                 << ", with Test Centre ID: " << tctIDRand
                                 << " has successfully registered." << endl;
                            break;
                        }

                        case 2: {
                            cout << "Record for new Tester ";
                            cout << "\nEnter First Name: ";
                            cin >> usrInFN;

                            cout << "Enter Last name: ";
                            cin >> usrInLN;

                            usrFlName = usrInFN + " " + usrInLN;

                            cout << "Enter username: ";
                            cin >> usrUname;

                            while(ctisexec.isTesterRegistered(usrUname)){
                                cout << "Username has been taken." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nEnter username: ";
                                cin >> usrUname;
                            }

                            cout << "Enter password: ";
                            cin >> usrPwd;

                            // create new object centre officer
                            TestCentre tctTester = ofcLoggedIn->getTestCentreOfc();

                            CentreOfficer newTester(usrUname, usrPwd, usrFlName, "Tester", tctTester);
                            ctisexec.setOfficerList(newTester);

                            cout << "Tester " << usrFlName
                                 << ", with username " << usrUname
                                 << ", assigned to: " << newTester.getTestCentreOfc().getCentreName()
                                 << " has successfully registered." << endl;

                            break;
                        }
                        // record tester

                        case 3: {
                            cout << "Create a new test kit stock?:" << endl;
                            cout << "\t[(Y)es/(N)o]: ";
                            cin >> op;

                            while (!(op == 'Y' || op == 'y' || op == 'N' || op == 'n')) {
                                cout << "Please enter Y/y for yes, and N/n for no" << endl;
                                cout << "\t[(Y)es/(N)o]: ";
                                cin >> op;
                            }

                            if (op == 'Y' || op == 'y') {
                                cout << "\nCreating new test kit..." << endl;

                                cout << "Enter test name: ";
                                cin.ignore();
                                getline(cin, tkNameReg);

                                while (ctisexec.isTestKitRegistered(tkNameReg)){
                                    cout << "Test Kit name has been registered." << endl;
                                    cout << "Please try another one." << endl;
                                    cout << "\nInput Test Kit name: ";
                                    getline(cin, tkNameReg);
                                }

                                cout << "Input available kit stock: ";
                                cin >> availQtyKit;

                                tKitIDRand = ctisexec.randKitID();
                                // create new TestKit object
                                TestKit newTestKit(tKitIDRand, availQtyKit, tkNameReg);
                                ctisexec.setTestKitList(newTestKit);

                                cout << "Test Kit " << tkNameReg
                                     << ", with ID " << tKitIDRand
                                     << " has " << availQtyKit
                                     << " available stock successfully registered." << endl;
                            }
                            else if (op == 'N' || op == 'n') {
                                cout << "Manage Test Kit Stock:" << endl;
                                cout << "Input Kit ID: ";
                                cin >> tKitIDRand;
                                // search kit ID and update stock.
                                for (int i = 0; i < ctisexec.getTestKitList().size(); i++) {
                                    while (tKitIDRand != ctisexec.getTestKitList()[i].getKitID()) {
                                        cout << "No Kit ID found. Please try again." << endl;
                                        cout << "Input Kit ID: ";
                                        cin >> tKitIDRand;
                                    }
                                    if (tKitIDRand == ctisexec.getTestKitList()[i].getKitID()) {
                                        int currentQty, updQty;
                                        TestKit *updTKit = ctisexec.getTestKitByKitID(tKitIDRand);
                                        currentQty = updTKit->getAvailableKit();

                                        cout << "Current available stock is: " << currentQty << endl;
                                        cout << "Update stock: ";
                                        cin >> updQty;
                                        updTKit->addStock(updQty);

                                        cout << "\nStock updated!" << endl;
                                        cout << "Stock after updated: " << updTKit->getAvailableKit() << endl;
                                    }
                                }
                            }
                            break;
                        }

                        default:
                            cout << "Wrong number. Please input valid number";
                    }
                }
                else{
                    cout << "Sorry. No account matched." << endl;
                    cout << "Please input username and password correctly." << endl;
                }
                break; // break for case 2

            case 3:
                cout << "\nLogin for an existing account for Tester." << endl;
                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;
                if (ctisexec.isLoginTstValid(usrUname, usrPwd)) {
                    cout << "\nWelcome Tester, " << usrUname;

                    cout << "\nSelect menu below: ";
                    cout << "\n\t[1] Record New Test" << endl;
                    cout << "\t[2] Update Test Result" << endl;
                    cout << "\t[0] Back" << endl;
                    cout << "Select menu number:: ";
                    cin >> menuOpt2;
                    cout << endl;

                    while (!(menuOpt2 >= 0 && menuOpt2 <= 2)) {
                        cout << "Please input valid number!" << endl;
                        cout << "Select menu number: ";
                        cin >> menuOpt2;
                        cout << endl;
                    }

                    switch (menuOpt2) {
                        case 0:
                            break;

                        case 1: {
                            cout << "Is the patient has taken test before?" << endl;
                            cout << "\t[(Y)es / (N)o]: ";
                            cin >> op;
                            // record some test
                            while (!(op == 'Y' || op == 'y' || op == 'N' || op == 'n')) {
                                cout << "Please enter Y/y for yes, and N/n for no" << endl;
                                cout << "\t[(Y)es/(N)o]: ";
                                cin >> op;
                            }
                            if (op == 'N' || op == 'n') {
                                cout << "\nRecord for new account Patient: " << endl;
                                cout << "Enter First Name: ";
                                cin >> usrInFN;

                                cout << "Enter Last name: ";
                                cin >> usrInLN;

                                usrFlName = usrInFN + " " + usrInLN;

                                cout << "Enter username: ";
                                cin >> usrUname;

                                while(ctisexec.isPatientRegistered(usrUname)){
                                    cout << "Username has been taken." << endl;
                                    cout << "Please try another one." << endl;
                                    cout << "\nEnter username: ";
                                    cin >> usrUname;
                                }

                                cout << "Enter password: ";
                                cin >> usrPwd;

                                cout << "\nWhich type of patient?" << endl;
                                cout << "\t[1]. Returnee\n";
                                cout << "\t[2]. Quarantined\n";
                                cout << "\t[3]. Close contact\n";
                                cout << "\t[4]. Infected\n";
                                cout << "\t[5]. Suspected\n";
                                cout << "Select patient type number: ";
                                cin >> slcPtnType;

                                while (slcPtnType < 1 || slcPtnType > 5) {
                                    cout << "\nPlease input valid number." << endl;
                                    cout << "Select patient type number: ";
                                    cin >> slcPtnType;
                                }

                                switch (slcPtnType) {
                                    case 1:
                                        inPtnType = "Returnee";
                                        break;

                                    case 2:
                                        inPtnType = "Quarantined";
                                        break;

                                    case 3:
                                        inPtnType = "Close contact";
                                        break;

                                    case 4:
                                        inPtnType = "Infected";
                                        break;

                                    case 5:
                                        inPtnType = "Suspected";
                                        break;
                                }

                                cout << "Input symptoms: ";
                                cin.ignore();
                                getline(cin,inPtnSymp);

                                // create covid test
                                // get covid test id
                                cvdTestIDRand = ctisexec.randCTestID();
                                // get date
                                // local time from ctime library
                                time_t locSysTime = time(NULL); // current system date
                                tm* locSysTimePtr = localtime(&locSysTime);
                                char curDateToStr[50];
                                strftime(curDateToStr, 50, "%d %B %Y at %T", locSysTimePtr);

                                CovidTest newCovidTest(cvdTestIDRand,curDateToStr,"No Data", "No Data", "Pending");
                                ctisexec.setCovidTestList(newCovidTest);

                                // create object patient
                                Patient newPatient(usrUname, usrPwd, usrFlName, inPtnType, inPtnSymp, newCovidTest);
                                ctisexec.setPatientList(newPatient);

                                cout << "\nPatient " << usrFlName
                                     << ", Type: " << inPtnType
                                     << ", with username " << usrUname
                                     << ", with symptoms " << inPtnSymp
                                     << " has successfully registered."
                                     << "\nCovid Test ID: " << cvdTestIDRand
                                     << ", registered at " << curDateToStr
                                     << endl;
                            }
                            else if (op == 'Y' || op == 'y'){
                                cout << "Updating data patient..." << endl;
                                cout << "Input patient's username: ";
                                cin >> usrUname;
                                // search kit ID and update stock.
                                for (int i = 0; i < ctisexec.getPatientList().size(); i++) {
                                    while (usrUname != ctisexec.getPatientList()[i].getUsername()) {
                                        cout << "\nUsername not found. Please try again." << endl;
                                        cout << "Input patient's username: ";
                                        cin >> usrUname;
                                    }
                                    if (usrUname == ctisexec.getPatientList()[i].getUsername()) {
                                        string currentPtnType, updatePtnType, currentPtnSympt, updatePtnSympt;
                                        Patient *updatePatient = ctisexec.getPatientByUsername(usrUname);

                                        currentPtnType = updatePatient->getPatientType();
                                        currentPtnSympt = updatePatient->getSymptoms();

                                        cout << "Current patient's type is: " << currentPtnType << endl;
                                        cout << "Current patient's symptoms is: " << currentPtnSympt << endl;

                                        cout << "Update type: " << endl;
                                        cout << "\t[1]. Returnee\n";
                                        cout << "\t[2]. Quarantined\n";
                                        cout << "\t[3]. Close contact\n";
                                        cout << "\t[4]. Infected\n";
                                        cout << "\t[5]. Suspected\n";
                                        cout << "Select update type number: ";
                                        cin >> slcPtnType;

                                        while (slcPtnType < 1 || slcPtnType > 5) {
                                            cout << "\nError!\nPlease input valid number.";
                                            cout << "Select update type number: ";
                                            cin >> slcPtnType;
                                        }

                                        switch (slcPtnType) {
                                            case 1:
                                                updatePtnType = "Returnee";
                                                break;

                                            case 2:
                                                updatePtnType = "Quarantined";
                                                break;

                                            case 3:
                                                updatePtnType = "Close contact";
                                                break;

                                            case 4:
                                                updatePtnType = "Infected";
                                                break;

                                            case 5:
                                                updatePtnType = "Suspected";
                                                break;
                                        }
                                        updatePatient->updatePatientType(updatePtnType);

                                        cout << "Update symptoms: ";
                                        cin >> updatePtnSympt;
                                        updatePatient->updateSymptoms(updatePtnSympt);

                                        cout << "\nData updated!" << endl;
                                        cout << "Type updated: " << updatePatient->getPatientType() << endl;
                                        cout << "Symptoms updated: " << updatePatient->getSymptoms() << endl;

                                        for(int i =0; i < ctisexec.getPatientList().size(); i++) {
                                            cout << "Debug: " << ctisexec.getPatientList()[i].getPatientType() << endl;
                                            cout << "Debug: " << ctisexec.getPatientList()[i].getSymptoms() << endl;
                                        }
                                    }
                                }
                            }
                            break;
                        }

                        case 2:
                            // use case 5
                            cout << "Update test result... " << endl;
                            cout << "Input test ID to retrieve the test details: ";
                            cin >> cvdTestIDRand;
                            for (int i = 0; i < ctisexec.getCovidTestList().size(); i++){
                                while (cvdTestIDRand != ctisexec.getCovidTestList()[i].getTestID()) {
                                    cout << "\nNo Covid Test ID found. Please try again." << endl;
                                    cout << "Input test ID to retrieve the test details: ";
                                    cin >> cvdTestIDRand;
                                }
                                if (cvdTestIDRand == ctisexec.getCovidTestList()[i].getTestID()) {
                                    string upRes, upResDate, upStt;
                                    //TestKit *updTKit = ctisexec.getTestKitByKitID(cvdTestIDRand);
                                    CovidTest *updCvdTest = ctisexec.getCovidTestByCTID(cvdTestIDRand);
                                    cout << "\nData Covid Test ID " << updCvdTest->getTestID() << ": " << endl;
                                    cout << "\tTest Date: " << updCvdTest->getTestDate()<< endl;
                                    cout << "\tResult: " << updCvdTest->getResult() << endl;
                                    cout << "\tResult Date: " << updCvdTest->getResultDate() << endl;
                                    cout << "\tStatus: " << updCvdTest->getStatus() << endl;
                                    cout << "\nUpdate result: ";
                                    cin.ignore();
                                    getline(cin, upRes);
                                    // update
                                    updCvdTest->updateResult(upRes);

                                    time_t locSysTime = time(NULL); // current system date
                                    tm* locSysTimePtr = localtime(&locSysTime);
                                    char curDateToStr[50];
                                    strftime(curDateToStr, 50, "%d %B %Y at %T", locSysTimePtr);

                                    upResDate = curDateToStr;
                                    // update
                                    updCvdTest->updateResultDate(upResDate);

                                    upStt = "Completed";
                                    // update
                                    updCvdTest->updateStatus(upStt);

                                    for(int i =0; i < ctisexec.getCovidTestList().size(); i++) {
                                        cout << "Debug Result: " << ctisexec.getCovidTestList()[i].getResult() << endl;
                                        cout << "Debug Result Date: " << ctisexec.getCovidTestList()[i].getResultDate() << endl;
                                        cout << "Debug Status: " << ctisexec.getCovidTestList()[i].getStatus() << endl;
                                    }

                                    cout << "\nData Test updated!" << endl;
                                    cout << "Covid Test with ID: " << updCvdTest->getTestID()
                                         << ", registered at: " << updCvdTest->getTestDate()
                                         << ", result is " << updCvdTest->getResult()
                                         << ", was updated at " << updCvdTest->getResultDate()
                                         << ", status now " << updCvdTest->getStatus()
                                         << endl;
                                }
                            }
                            break;
                            // update some test here

                        default:
                            cout << "Please input valid number";
                    }
                    break; // break case 4

                    case 4:
                    // use case 6
                    cout << "Login for an existing account for Patient." << endl;
                    cout << "Enter username: ";
                    cin >> usrUname;

                    cout << "Enter password: ";
                    cin >> usrPwd;

                    if (ctisexec.isLoginPtnValid(usrUname, usrPwd)){
                        cout << "\nWelcome patient, " << usrUname;
                        cout << "\nDo you want to view a Test Report?";
                        cout << "\n\t[(Y)es / (N)o]: ";
                        cin >> op;

                        if (op == 'y' || op == 'Y') {
                            cout << "\nTest Report Patient's detail: " << endl;

                            Patient *patientLoggedIn = ctisexec.getPatientByUsername(usrUname);
                            cout << " Patient name: " << patientLoggedIn->getFullname()
                                 << ", has taken a test covid test with ID: " << patientLoggedIn->getCovidTestPtn().getTestID()
                                 << ", registered on: " << patientLoggedIn->getCovidTestPtn().getTestDate()
                                 << ", result is " << patientLoggedIn->getCovidTestPtn().getResult()
                                 << ", was updated on " << patientLoggedIn->getCovidTestPtn().getResultDate()
                                 << ", status now " << patientLoggedIn->getCovidTestPtn().getStatus()
                                 << endl;
                        }
                        else {
                            // exit;
                        }
                    }
                    else{
                        cout << "No account patient matched." << endl;
                    }
                    break; // break case 5

                    case 5:
                        cout << "Report details: " << endl;
                    break;

                    default:
                        cout << "Wrong input. Please enter the valid number." << endl;
                }
                else{
                    cout << "Sorry. No account matched." << endl;
                    cout << "Please input username and password correctly." << endl;
                }
            }
        }
    return 0;
}