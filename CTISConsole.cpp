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
        ptnUname, ptnPwd, inPtnType, ctNameReg, inPtnSymp, tkNameReg;

int menuOpt = 10, menuOpt2 = 10,
    slcPtnType, tctIDRand, tKitIDRand, availQtyKit, cvdTestIDRand;

char op;

CTIS ctisexec;
TestCentre tct;

int main()
{
    while (menuOpt != 0)
    {
        cout << "\nCTIS System.\nPlease select menu below:" << endl;
        cout << "\t[1] Register for Test Center Manager" << endl;
        cout << "\t[2] Login for Manager" << endl;
        cout << "\t[3] Login for Tester" << endl;
        cout << "\t[4] Login for Patient" << endl;
        cout << "\t[5] Generate Test Report" << endl;
        cout << "\t[0] Exit" << endl;
        cout << "Select menu number: ";
        cin >> menuOpt;

        switch (menuOpt)
        {
            case 0:
                cout << "Program closed.\nThank you.\nStay safe and stay healthy";
                break; // break case 0

            case 1:
            {
                cout << "\nRegister a new account for Manager." << endl;
                cout << "Enter First Name: ";
                cin >> usrInFN;

                cout << "Enter Last name: ";
                cin >> usrInLN;

                usrFlName = usrInFN + " " + usrInLN;

                cout << "Enter username: ";
                cin >> usrUname;

                // if username has been taken
                while (ctisexec.isManagerRegistered(usrUname))
                {
                    cout << "Username has been taken." << endl;
                    cout << "Please try another one." << endl;
                    cout << "\nEnter username: ";
                    cin >> usrUname;
                }

                cout << "Enter password: ";
                cin >> usrPwd;

                // create new object centre officer as a manager
                CentreOfficer newManager(usrUname, usrPwd, usrFlName, "Manager", tct);
                ctisexec.setOfficerList(newManager);
                cout << "Manager " << usrFlName << " has successfully registered!" << endl;
                break;
            }

            case 2: {
                cout << "\nLogin for Test Center Manager." << endl;

                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                // validate if account exists
                if (ctisexec.isLoginMgrValid(usrUname, usrPwd)) {
                    // get the vector address of CentreOfficer based on username logged in
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
                            cout << "Register Test Centre " << endl;
                            cout << "Input centre name: ";
                            cin.ignore();
                            getline(cin, ctNameReg);

                            while (ctisexec.isTestCentreRegistered(ctNameReg)) {
                                cout << "Test Centre name has been registered." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nInput centre name: ";
                                getline(cin, ctNameReg);
                            }
                            // generate random number
                            tctIDRand = ctisexec.randTCID();

                            TestCentre tct(tctIDRand, ctNameReg);
                            // sets the test centre into the officer
                            ctisexec.setTestCentreList(tct);
                            ofcLoggedIn->setTestCentreOfc(tct);

                            cout << "Manager " << ofcLoggedIn->getFullname()
                                 << " registered at Test Centre " << ofcLoggedIn->getTestCentreOfc().getCentreName()
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

                            // if username has been taken
                            while (ctisexec.isTesterRegistered(usrUname)) {
                                cout << "Username has been taken." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nEnter username: ";
                                cin >> usrUname;
                            }

                            cout << "Enter password: ";
                            cin >> usrPwd;

                            // get the vector address of CentreOfficer's TestCentre
                            TestCentre tctTester = ofcLoggedIn->getTestCentreOfc();

                            // create new object centre officer
                            CentreOfficer newTester(usrUname, usrPwd, usrFlName, "Tester", tctTester);
                            ctisexec.setOfficerList(newTester);

                            cout << "Tester " << usrFlName
                                 << ", with username " << usrUname
                                 << ", assigned to: " << newTester.getTestCentreOfc().getCentreName()
                                 << " has successfully registered." << endl;
                            break;
                        }

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

                                // if Test Kit exists
                                while (ctisexec.isTestKitRegistered(tkNameReg)) {
                                    cout << "Test Kit name has been registered." << endl;
                                    cout << "Please try another one." << endl;
                                    cout << "\nInput Test Kit name: ";
                                    getline(cin, tkNameReg);
                                }

                                cout << "Input available kit stock: ";
                                cin >> availQtyKit;

                                // generate random number for test kit ID
                                tKitIDRand = ctisexec.randKitID();
                                // create new TestKit object
                                TestKit newTestKit(tKitIDRand, availQtyKit, tkNameReg);
                                //ctisexec.setTestKitList(newTestKit);
                                ofcLoggedIn->getTestCentrePtr()->setAgrTestKit(newTestKit);

                                cout << ofcLoggedIn->getTestCentrePtr()->getTestKitByKitID(tKitIDRand)->getAvailableKit()
                                << endl;

                                cout << "Test Kit " << tkNameReg
                                     << ", with ID " << tKitIDRand
                                     << " has " << availQtyKit
                                     << " available stock successfully registered." << endl;
                            } else if (op == 'N' || op == 'n') {
                                cout << "Manage Test Kit Stock:" << endl;
                                cout << "Input Kit ID: ";
                                cin >> tKitIDRand;
                                // search for kit ID and update stock.
                                for (int i = 0; i < ofcLoggedIn->getTestCentreOfc().getAgrTestKit().size(); i++) {
                                    while (tKitIDRand !=
                                           ofcLoggedIn->getTestCentrePtr()->getAgrTestKit()[i].getKitID()) {
                                        cout << "No Kit ID found. Please try again." << endl;
                                        cout << "Input Kit ID: ";
                                        cin >> tKitIDRand;
                                    }
                                    if (tKitIDRand == ofcLoggedIn->getTestCentrePtr()->getAgrTestKit()[i].getKitID()) {
                                        int currentQty, updQty;
                                        // get the vector address of TestKit based on kitID
                                        TestKit *updTKit = ofcLoggedIn->getTestCentrePtr()->getTestKitByKitID(
                                                tKitIDRand);
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
                            break;
                    }
                } else {
                    cout << "Sorry. No account matched." << endl;
                    cout << "Please input username and password correctly." << endl;
                }
                break;
            }
            case 3: {
                cout << "\nLogin for an existing account for Tester." << endl;
                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;
                if (ctisexec.isLoginTstValid(usrUname, usrPwd)) {
                    CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);
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
                                cin >> ptnUname;

                                while (ctisexec.isPatientRegistered(ptnUname)) {
                                    cout << "Username has been taken." << endl;
                                    cout << "Please try another one." << endl;
                                    cout << "\nEnter username: ";
                                    cin >> ptnUname;
                                }

                                cout << "Enter password: ";
                                cin >> ptnPwd;

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
                                getline(cin, inPtnSymp);

                                // generate random number for covid test id
                                cvdTestIDRand = ctisexec.randCTestID();
                                // get date
                                time_t locSysTime = time(NULL); // current system date
                                // local time from ctime library
                                tm *locSysTimePtr = localtime(&locSysTime);
                                char curDateToStr[50];
                                // to string format for date in (Day Month Year, HH:MM)
                                strftime(curDateToStr, 50, "%d %B %Y at %T", locSysTimePtr);

                                // create covid test object
                                CovidTest newCovidTest(cvdTestIDRand, curDateToStr, "No Data", "No Data", "Pending");
                                //ctisexec.setCovidTestList(newCovidTest);

                                // create object patient
                                Patient newPatient(ptnUname, ptnPwd, usrFlName, inPtnType, inPtnSymp);
                                ctisexec.setPatientList(newPatient);

                                Patient *patientAgr = ctisexec.getPatientByUsername(ptnUname);
                                // set to vector
                                patientAgr->setAgrCovidTest(newCovidTest);
                                // debug
                                cout << "Debug size: " << ctisexec.getPatientList().size()<< endl;
                                cout << patientAgr->getAgrCovidTest().size() << endl;
                                cout << " Debug ptr patient username: " << patientAgr->getFullname() << endl;
                                cout << tKitIDRand << endl;

                                ofcLoggedIn->setAgrCovidTest(newCovidTest);

                                for(int i =0; i < ctisexec.getOfficerList().size(); i++){
                                    cout << ctisexec.getOfficerList()[i].getUsername() << endl;
                                    cout << ctisexec.getOfficerList()[i].getOfcPosition() << endl;
                                    if(ctisexec.getOfficerList()[i].getOfcPosition() == "Manager" &&
                                    ctisexec.getOfficerList()[i].getTestCentrePtr()->getCentreName()
                                    == ofcLoggedIn->getTestCentrePtr()->getCentreName()){
                                        string managerUsername = ctisexec.getOfficerList()[i].getUsername();
                                        //string managerPass = ctisexec.getOfficerList()[i].getPassword();

                                        CentreOfficer *manager1 = ctisexec.getOfficerByUsername(managerUsername);
                                        TestKit *updtKit = manager1->getTestCentrePtr()->getTestKitByKitID(tKitIDRand);
                                        updtKit ->decStock();

                                        cout << updtKit->getAvailableKit() << endl;

                                        manager1->setAgrCovidTest(newCovidTest);
                                        cout << manager1->getUsername() << endl;
                                        cout << manager1->getAgrCovidTest().size();
                                    }
                                    cout << "\nName: " << ctisexec.getOfficerList()[i].getFullname()<< endl;
                                    cout << "\nDi vc tst: " << ctisexec.getOfficerList()[i].getAgrCovidTest().size() << endl;
//
                                }




                                // decrement the stock kit after patient is recorded.
//                                TestKit *updTKit = ofcLoggedIn->getTestCentrePtr()->getTestKitByKitID(tKitIDRand);
//                                cout << updTKit->getAvailableKit() << endl;
//                                updTKit->decStock();

                                cout << "\nPatient " << usrFlName
                                     << ", Type: " << inPtnType
                                     << ", with username " << ptnUname
                                     << ", with symptoms " << inPtnSymp
                                     << " has successfully registered."
                                     << "\nCovid Test ID: " << cvdTestIDRand
                                     << ", registered at " << curDateToStr
                                     << endl;
                            } else if (op == 'Y' || op == 'y') {
                                cout << "Updating data patient..." << endl;
                                cout << "Input patient's username: ";
                                cin >> ptnUname;
                                // search kit ID and update stock.
                                for (int i = 0; i < ctisexec.getPatientList().size(); i++) {
                                    while (ptnUname != ctisexec.getPatientList()[i].getUsername()) {
                                        cout << "\nUsername not found. Please try again." << endl;
                                        cout << "Input patient's username: ";
                                        cin >> ptnUname;
                                    }
                                    if (ptnUname == ctisexec.getPatientList()[i].getUsername()) {
                                        string currentPtnType, updatePtnType, currentPtnSympt, updatePtnSympt;
                                        // get the vector address of Patient based on username logged in
                                        Patient *updPtn = ctisexec.getPatientByUsername(ptnUname);

                                        currentPtnType = updPtn->getPatientType();
                                        currentPtnSympt = updPtn->getSymptoms();

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
                                        updPtn->updatePatientType(updatePtnType);

                                        cout << "Update symptoms: ";
                                        cin >> updatePtnSympt;
                                        updPtn->updateSymptoms(updatePtnSympt);

                                        cout << "\nData updated!" << endl;
                                        cout << "Type updated: " << updPtn->getPatientType() << endl;
                                        cout << "Symptoms updated: " << updPtn->getSymptoms() << endl;
                                    }
                                }
                            }
                            break;
                        }
                        case 2: {
                            // use case 5
                            //CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);
                            cout << "Update test result... " << endl;
                            cout << "Input test ID to retrieve the test details: ";
                            cin >> cvdTestIDRand;
                            cout << "Debug test getAgrCovidTest Size: " << ofcLoggedIn->getAgrCovidTest().size() << endl;
                            for (int i = 0; i < ofcLoggedIn->getAgrCovidTest().size(); i++) {
                                while (cvdTestIDRand != ofcLoggedIn->getAgrCovidTest()[i].getTestID()) {
                                    cout << "\nNo Covid Test ID found. Please try again." << endl;
                                    cout << "Input test ID to retrieve the test details: ";
                                    cin >> cvdTestIDRand;
                                }
                                if (cvdTestIDRand == ofcLoggedIn->getAgrCovidTest()[i].getTestID()) {
                                    string upRes, upResDate, upStt;
                                    CovidTest *updCvdTest = ofcLoggedIn->getCovidTestByCTID(cvdTestIDRand);
                                    cout << "\nData Covid Test ID " << updCvdTest->getTestID() << ": " << endl;
                                    cout << "\tTest Date: " << updCvdTest->getTestDate() << endl;
                                    cout << "\tResult: " << updCvdTest->getResult() << endl;
                                    cout << "\tResult Date: " << updCvdTest->getResultDate() << endl;
                                    cout << "\tStatus: " << updCvdTest->getStatus() << endl;
                                    cout << "\nUpdate result: ";
                                    cin.ignore();
                                    getline(cin, upRes);
                                    updCvdTest->updateResult(upRes);

                                    time_t locSysTime = time(NULL);
                                    tm *locSysTimePtr = localtime(&locSysTime);
                                    char curDateToStr[50];
                                    strftime(curDateToStr, 50, "%d %B %Y at %T", locSysTimePtr);

                                    upResDate = curDateToStr;
                                    updCvdTest->updateResultDate(upResDate);

                                    upStt = "Completed";
                                    updCvdTest->updateStatus(upStt);

                                    for(int j = 0; i < ctisexec.getPatientList().size(); i++) {
                                        string usernamePtn;

                                        if (cvdTestIDRand == ctisexec.getPatientList()[j].getAgrCovidTest()[j].getTestID()){
                                            usernamePtn = ctisexec.getPatientList()[j].getUsername();
                                            Patient * updPtn = ctisexec.getPatientByUsername(usernamePtn);

                                            updPtn->getCovidTestByCTID(cvdTestIDRand)->setResult(upRes);
                                            updPtn->getCovidTestByCTID(cvdTestIDRand)->setResultDate(upResDate);
                                            updPtn->getCovidTestByCTID(cvdTestIDRand)->setStatus(upStt);
                                        }
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
                        }
                        default:
                            cout << "Please input valid number";
                            break;
                    }
                }
                else{
                    cout << "Sorry, no account match";
                }
                break;
            }
            case 4: {
                // use case 6
                cout << "Login for an existing account for Patient." << endl;
                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                if (ctisexec.isLoginPtnValid(usrUname, usrPwd)) {
                    Patient *ptnLoggedIn = ctisexec.getPatientByUsername(usrUname);
                    cout << "\nWelcome patient, " << usrUname;
                    cout << "\nDo you want to view a Test Report?";
                    cout << "\n\t[(Y)es / (N)o]: ";
                    cin >> op;
                    while(!(op == 'y' || op == 'Y' || op == 'N' || op == 'n')){
                        cout << "Please enter Y/y for yes, and N/n for no" << endl;
                        cout << "\t[(Y)es/(N)o]: ";
                        cin >> op;
                    }

                    if (op == 'y' || op == 'Y') {
                        cout << "\nTest Report Patient's detail: " << endl;
                        cout << ptnLoggedIn->viewTestHistory(usrUname, usrPwd);
                    }
                    else {
                        // exit;
                    }
                } else {
                    cout << "No account patient matched." << endl;
                }
                break;
            }
            case 5: {
                cout << "Generate report for Centre Officer." << endl;
                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                if (ctisexec.isLoginTstValid(usrUname,usrPwd) || ctisexec.isLoginMgrValid(usrUname,usrPwd)){
                    CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);
                    cout << "Report details: " << endl;
                    cout << ofcLoggedIn->viewTestHistory(usrUname,usrPwd);
                    break;
                }
                else{
                    cout << "Account not found! " << endl;
                }
            }
            default:
                cout << "Wrong input. Please enter the valid number." << endl;
                break;
        } // end of switch case main menu
    } // end of while loop main menu
    return 0;
}