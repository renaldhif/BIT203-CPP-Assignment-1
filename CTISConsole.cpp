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
            // exit menu
            case 0:
                cout << "Program closed.\nThank you.\nStay safe and stay healthy";
                break;

            // register tc manager
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
                // set the object manager
                ctisexec.setOfficerList(newManager);
                cout << "Manager " << usrFlName << " has successfully registered!" << endl;
                break;
            }

            // login manager
            case 2:
            {
                cout << "\nLogin for Test Center Manager." << endl;

                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                // validate if account exists
                if (ctisexec.isLoginMgrValid(usrUname, usrPwd))
                {
                    // get the vector address of CentreOfficer based on username logged in
                    CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);

                    cout << "\nWelcome Test Centre Manager, " << usrUname << endl;
                    cout << "Select menu below: " << endl;
                    cout << "\t[1] Register Test Centre" << endl;
                    cout << "\t[2] Record Tester" << endl;
                    cout << "\t[3] Manage Test Kit Stock" << endl;
                    cout << "\t[0] Back" << endl;
                    cout << "Select menu number: ";
                    cin >> menuOpt2;
                    cout << endl;

                    // prevents user inputs a number outside the menu
                    while (!(menuOpt2 >= 0 && menuOpt2 <= 3))
                    {
                        cout << "Please input valid number!" << endl;
                        cout << "Select menu number: ";
                        cin >> menuOpt2;
                        cout << endl;
                    }

                    switch (menuOpt2)
                    {
                        // back
                        case 0:
                            break;

                        // register test centre
                        case 1:
                        {
                            cout << "Register Test Centre " << endl;
                            cout << "Input centre name: ";
                            cin.ignore();
                            getline(cin, ctNameReg);

                            // validate if test centre exists
                            while (ctisexec.isTestCentreRegistered(ctNameReg))
                            {
                                cout << "Test Centre name has been registered." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nInput centre name: ";
                                getline(cin, ctNameReg);
                            }
                            // generate random number
                            tctIDRand = ctisexec.randTCID();
                            // create new test centre object
                            TestCentre tct(tctIDRand, ctNameReg);
                            // add new test centre to vector
                            ctisexec.setTestCentreList(tct);
                            // sets the test centre into the officer
                            ofcLoggedIn->setTestCentreOfc(tct);

                            cout << "Manager " << ofcLoggedIn->getFullname()
                                 << " registered at Test Centre " << ofcLoggedIn->getTestCentreOfc().getCentreName()
                                 << ", with Test Centre ID: " << tctIDRand
                                 << " has successfully registered." << endl;
                            break;
                        }

                        case 2:
                        {
                            cout << "Record for new Tester ";
                            cout << "\nEnter First Name: ";
                            cin >> usrInFN;

                            cout << "Enter Last name: ";
                            cin >> usrInLN;

                            usrFlName = usrInFN + " " + usrInLN;

                            cout << "Enter username: ";
                            cin >> usrUname;

                            // validate if username has been taken
                            while (ctisexec.isTesterRegistered(usrUname))
                            {
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
                            // add new tester object to the vector
                            ctisexec.setOfficerList(newTester);

                            cout << "Tester " << usrFlName
                                 << ", with username " << usrUname
                                 << ", assigned to: " << newTester.getTestCentreOfc().getCentreName()
                                 << " has successfully registered." << endl;
                            break;
                        }

                        // create new test kit stock
                        case 3:
                        {
                            cout << "Create a new test kit stock?:" << endl;
                            cout << "\t[(Y)es/(N)o]: ";
                            cin >> op;

                            // if users input other Y and N
                            while (!(op == 'Y' || op == 'y' || op == 'N' || op == 'n'))
                            {
                                cout << "Please enter Y/y for yes, and N/n for no" << endl;
                                cout << "\t[(Y)es/(N)o]: ";
                                cin >> op;
                            }

                            // if user inputs y
                            if (op == 'Y' || op == 'y')
                            {
                                cout << "\nCreating new test kit..." << endl;

                                cout << "Enter test name: ";
                                cin.ignore();
                                getline(cin, tkNameReg);

                                // validate if Test Kit exists
                                while (ctisexec.isTestKitRegistered(tkNameReg))
                                {
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
                                // set new test kit
                                ofcLoggedIn->getTestCentrePtr()->setAgrTestKit(newTestKit);

                                cout << "\nTest Kit " << tkNameReg
                                     << ", with ID " << tKitIDRand
                                     << ", has " << availQtyKit
                                     << " available stock successfully registered." << endl;

                            }
                            // if user inputs n
                            else if (op == 'N' || op == 'n')
                            {
                                cout << "Manage Test Kit Stock:" << endl;
                                cout << "Input Kit ID: ";
                                cin >> tKitIDRand;
                                // search for kit ID and update stock.
                                for (int i = 0; i < ofcLoggedIn->getTestCentreOfc().getAgrTestKit().size(); i++)
                                {
                                    // while kit ID inputted is not equals to the kit ID in the vector
                                    while (tKitIDRand != ofcLoggedIn->getTestCentrePtr()->getAgrTestKit()[i].getKitID())
                                    {
                                        cout << "No Kit ID found. Please try again." << endl;
                                        cout << "Input Kit ID: ";
                                        cin >> tKitIDRand;
                                    }
                                    // if kit ID inputted is equals
                                    if (tKitIDRand == ofcLoggedIn->getTestCentrePtr()->getAgrTestKit()[i].getKitID())
                                    {
                                        int currentQty, updQty;
                                        // get the vector address of TestKit based on kitID
                                        TestKit *updTKit = ofcLoggedIn->getTestCentrePtr()->getTestKitByKitID(tKitIDRand);
                                        // get quantity stock of kit
                                        currentQty = updTKit->getAvailableKit();

                                        cout << "Current available stock is: " << currentQty << endl;
                                        // update stock
                                        cout << "Update stock: ";
                                        cin >> updQty;
                                        // add new stock
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
                }
                else
                {
                    cout << "Sorry. No account matched." << endl;
                    cout << "Please input username and password correctly." << endl;
                }
                break;
            }
            case 3:
            {
                cout << "\nLogin for an existing account for Tester." << endl;
                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;
                // if username and password tester inputted is valid
                if (ctisexec.isLoginTstValid(usrUname, usrPwd))
                {
                    // get the vector address of CentreOfficer based on username logged in
                    CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);

                    cout << "\nWelcome Tester, " << usrUname;
                    cout << "\nSelect menu below: ";
                    cout << "\n\t[1] Record New Test" << endl;
                    cout << "\t[2] Update Test Result" << endl;
                    cout << "\t[0] Back" << endl;
                    cout << "Select menu number: ";
                    cin >> menuOpt2;
                    cout << endl;

                    // prevents user input number other than the menu
                    while (!(menuOpt2 >= 0 && menuOpt2 <= 2))
                    {
                        cout << "Please input valid number!" << endl;
                        cout << "Select menu number: ";
                        cin >> menuOpt2;
                        cout << endl;
                    }

                    switch (menuOpt2)
                    {
                        // back
                        case 0:
                            break;

                        // record new test
                        case 1:
                        {
                            cout << "Is the patient has taken test before?" << endl;
                            cout << "\t[(Y)es / (N)o]: ";
                            cin >> op;

                            // if user inputs other than y and n
                            while (!(op == 'Y' || op == 'y' || op == 'N' || op == 'n'))
                            {
                                cout << "Please enter Y/y for yes, and N/n for no" << endl;
                                cout << "\t[(Y)es/(N)o]: ";
                                cin >> op;
                            }
                            // if user inputs n
                            if (op == 'N' || op == 'n')
                            {

                                cout << "\nRecord for new account Patient: " << endl;
                                cout << "Enter First Name: ";
                                cin >> usrInFN;

                                cout << "Enter Last name: ";
                                cin >> usrInLN;

                                usrFlName = usrInFN + " " + usrInLN;

                                cout << "Enter username: ";
                                cin >> ptnUname;

                                // validate if username patient exists
                                while (ctisexec.isPatientRegistered(ptnUname))
                                {
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

                                // prevents the user input outside the menu number
                                while (slcPtnType < 1 || slcPtnType > 5)
                                {
                                    cout << "\nPlease input valid number." << endl;
                                    cout << "Select patient type number: ";
                                    cin >> slcPtnType;
                                }
                                // patient type switch
                                switch (slcPtnType)
                                {
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

                                // create object patient
                                Patient newPatient(ptnUname, ptnPwd, usrFlName, inPtnType, inPtnSymp);
                                // add object patient to the vector
                                ctisexec.setPatientList(newPatient);

                                // get the vector address of patient based on username logged in
                                Patient *patientAgr = ctisexec.getPatientByUsername(ptnUname);
                                // set patient to vector covid test
                                patientAgr->setAgrCovidTest(newCovidTest);
                                ofcLoggedIn->setAgrCovidTest(newCovidTest);

                                for(int i =0; i < ctisexec.getOfficerList().size(); i++)
                                {
                                    if((ctisexec.getOfficerList()[i].getOfcPosition() == "Manager")
                                        && (ctisexec.getOfficerList()[i].getTestCentrePtr()->getCentreName())
                                        == ofcLoggedIn->getTestCentrePtr()->getCentreName())
                                    {
                                        // get manager's username
                                        string mgrTstUname = ctisexec.getOfficerList()[i].getUsername();
                                        // get the vector address of manager based on username manager
                                        CentreOfficer *mgrTst = ctisexec.getOfficerByUsername(mgrTstUname);
                                        // get test kit by vector address of test centre of officer
                                        TestKit *updtKit = mgrTst->getTestCentrePtr()->getTestKitByKitID(tKitIDRand);
                                        // decrement the stock kit after patient is recorded.
                                        updtKit ->decStock();
                                        // set covid test to the vector
                                        mgrTst->setAgrCovidTest(newCovidTest);
                                    }
                                }
                                cout << "\nPatient " << usrFlName
                                     << ", Type: " << inPtnType
                                     << ", with username " << ptnUname
                                     << ", with symptoms " << inPtnSymp
                                     << " has successfully registered."
                                     << "\nCovid Test ID: " << cvdTestIDRand
                                     << ", registered at " << curDateToStr
                                     << endl;
                            }
                            // if user inputs y (update data patient)
                            else if (op == 'Y' || op == 'y') {
                                cout << "Updating data patient..." << endl;
                                cout << "Input patient's username: ";
                                cin >> ptnUname;
                                // search kit ID and update stock.
                                for (int i = 0; i < ctisexec.getPatientList().size(); i++)
                                {
                                    // if patient's username inputted is not equals to the patient vector
                                    while (ptnUname != ctisexec.getPatientList()[i].getUsername())
                                    {
                                        cout << "\nUsername not found. Please try again." << endl;
                                        cout << "Input patient's username: ";
                                        cin >> ptnUname;
                                    }
                                    // if patient's username inputted is equals
                                    if (ptnUname == ctisexec.getPatientList()[i].getUsername())
                                    {
                                        string currentPtnType, updatePtnType, currentPtnSympt, updatePtnSympt;
                                        // get the vector address of Patient based on username logged in
                                        Patient *updPtn = ctisexec.getPatientByUsername(ptnUname);
                                        // get current patient type and symptoms
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
                                        // if user inputs number outside the menu number
                                        while (slcPtnType < 1 || slcPtnType > 5)
                                        {
                                            cout << "\nError!\nPlease input valid number.";
                                            cout << "Select update type number: ";
                                            cin >> slcPtnType;
                                        }
                                        // update patient type switch case
                                        switch (slcPtnType)
                                        {
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
                                        // add update patient type
                                        updPtn->updatePatientType(updatePtnType);

                                        cout << "Update symptoms: ";
                                        cin >> updatePtnSympt;
                                        // add update patient symptoms
                                        updPtn->updateSymptoms(updatePtnSympt);

                                        cout << "\nData updated!" << endl;
                                        cout << "Type updated: " << updPtn->getPatientType() << endl;
                                        cout << "Symptoms updated: " << updPtn->getSymptoms() << endl;
                                    }
                                }
                            }
                            break;
                        }

                        // update test result
                        case 2:
                        {
                            cout << "Update test result... " << endl;
                            cout << "Input test ID to show the test details: ";
                            cin >> cvdTestIDRand;

                            for (int i = 0; i < ofcLoggedIn->getAgrCovidTest().size(); i++)
                            {
                                // if covid test id inputted is not equal to the vector covid test
                                while (cvdTestIDRand != ofcLoggedIn->getAgrCovidTest()[i].getTestID())
                                {
                                    cout << "\nNo Covid Test ID found. Please try again." << endl;
                                    cout << "Input test ID to retrieve the test details: ";
                                    cin >> cvdTestIDRand;
                                }
                                // if covid test id inputted is equal
                                if (cvdTestIDRand == ofcLoggedIn->getAgrCovidTest()[i].getTestID())
                                {
                                    string upRes, upResDate, upStt;
                                    // get the address of vector covid test based on the covid test ID
                                    CovidTest *updCvdTest = ofcLoggedIn->getCovidTestByCTID(cvdTestIDRand);

                                    cout << "\nData Covid Test ID " << updCvdTest->getTestID() << ": " << endl;
                                    cout << "\tTest Date: " << updCvdTest->getTestDate() << endl;
                                    cout << "\tResult: " << updCvdTest->getResult() << endl;
                                    cout << "\tResult Date: " << updCvdTest->getResultDate() << endl;
                                    cout << "\tStatus: " << updCvdTest->getStatus() << endl;
                                    cout << "\nUpdate result: ";
                                    cin.ignore();
                                    getline(cin, upRes);
                                    // add update test result
                                    updCvdTest->updateResult(upRes);

                                    // get date
                                    time_t locSysTime = time(NULL); // current system date
                                    // local time from ctime library
                                    tm *locSysTimePtr = localtime(&locSysTime);
                                    char curDateToStr[50];
                                    // to string format for date in (Day Month Year, HH:MM)
                                    strftime(curDateToStr, 50, "%d %B %Y at %T", locSysTimePtr);
                                    upResDate = curDateToStr;

                                    // add update result date
                                    updCvdTest->updateResultDate(upResDate);

                                    upStt = "Completed"; // update status to complete
                                    // add update status
                                    updCvdTest->updateStatus(upStt);

                                    for(int j = 0; i < ctisexec.getPatientList().size(); i++)
                                    {
                                        string uNamePtn;

                                        if (cvdTestIDRand == ctisexec.getPatientList()[j].getAgrCovidTest()[j].getTestID())
                                        {
                                            // get patient username
                                            uNamePtn = ctisexec.getPatientList()[j].getUsername();
                                            // get the address of patient vector based on patient' username
                                            Patient* updPtn = ctisexec.getPatientByUsername(uNamePtn);
                                            // update the result, result date, and status
                                            // by getting the covid test address and set the updates
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
                else
                {
                    cout << "Sorry, no account match";
                }
                break;
            }
            case 4:
            {
                cout << "Login for an existing account for Patient." << endl;
                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                // validates if patient login is valid
                if (ctisexec.isLoginPtnValid(usrUname, usrPwd))
                {
                    // get the vector address of patient based on patient username
                    Patient *ptnLoggedIn = ctisexec.getPatientByUsername(usrUname);

                    cout << "\nWelcome patient, " << usrUname;
                    cout << "\nDo you want to view a Test Report?";
                    cout << "\n\t[(Y)es / (N)o]: ";
                    cin >> op;

                    // while user input other than y and n
                    while(!(op == 'y' || op == 'Y' || op == 'N' || op == 'n'))
                    {
                        cout << "Please enter Y/y for yes, and N/n for no" << endl;
                        cout << "\t[(Y)es/(N)o]: ";
                        cin >> op;
                    }
                    // if user inputs y
                    if (op == 'y' || op == 'Y')
                    {
                        cout << "\nTest Report Patient's detail: " << endl;
                        cout << ptnLoggedIn->viewTestHistory(usrUname, usrPwd);
                    }
                    // if user inputs other than y
                    else
                    {
                        // exit;
                    }
                }
                // if patient login is invalid
                else
                {
                    cout << "No account patient matched." << endl;
                }
                break;
            }
            // generate report for centreofficer
            case 5:
            {
                cout << "Generate report for Centre Officer." << endl;

                cout << "Enter username: ";
                cin >> usrUname;

                cout << "Enter password: ";
                cin >> usrPwd;

                // if centre officer login (manager or tester) is valid
                if (ctisexec.isLoginTstValid(usrUname,usrPwd)
                    || ctisexec.isLoginMgrValid(usrUname,usrPwd))
                {
                    // get the vector address of centre officer based on username
                    CentreOfficer *ofcLoggedIn = ctisexec.getOfficerByUsername(usrUname);

                    cout << "Report details: " << endl;
                    // print the test history
                    cout << ofcLoggedIn->viewTestHistory(usrUname,usrPwd);
                    break;
                }
                // if centre officer login is invalid
                else
                {
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