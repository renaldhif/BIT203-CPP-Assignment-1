/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 8 December 2021
 *
 */
#include "CTIS.h"
#include <iostream>
#include <string>

// Declare variables for user input and some variables have initialized values
string firstname, lastname, username, password, fullname,
        patientType, ctName, ptnSympt, tkName;
int option = 10, option2 = 10, selectType, ctID, kitID, availQtyKit;
char op;

CTIS ctismain;
TestCentre tct;

int main() {
    while (option != 0) {
        cout << "\nCTIS System.\nPlease Select Menu Below:" << endl;
        cout << "\t[1] Register for Test Center Manager" << endl;
        cout << "\t[2] Login for Manager" << endl;
        cout << "\t[3] Login for Tester" << endl;
        cout << "\t[4] Login for Patient" << endl;
        cout << "\t[0] Exit" << endl;
        cout << "Select number: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << "Program closed.\nThank you.\nStay Healthy Stay safe.";
                break; // break case 0

            case 1: {
                cout << "\nRegister a new account for Manager." << endl;
                cout << "Enter First Name: ";
                cin >> firstname;

                cout << "Enter Last name: ";
                cin >> lastname;

                fullname = firstname + " " + lastname;

                cout << "Enter username: ";
                cin >> username;

                while(ctismain.isManagerRegistered(username)){
                    cout << "Username has been taken." << endl;
                    cout << "Please try another one." << endl;
                    cout << "\nEnter username: ";
                    cin >> username;
                }

                cout << "Enter password: ";
                cin >> password;

                // create new object centre officer
                //CentreOfficer newManager(username, password, fullname, "Manager");
                CentreOfficer newManager(username, password, fullname, "Manager",tct);
                ctismain.setOfficerList(newManager);
                cout << "Manager " << fullname << " has successfully registered!" << endl;
            }
                break; // break case 1

            case 2:
                cout << "\nLogin for Test Center Manager." << endl;

                cout << "Enter username: ";
                cin >> username;

                cout << "Enter password: ";
                cin >> password;

                // validate if account exists
                if (ctismain.isLoginMgrValid(username, password)) {
                    CentreOfficer *ofcLoggedIn = ctismain.getOfficerByUsername(username);

                    cout << "\nWelcome Test Center Manager, " << username << endl;
                    cout << "Select menu below: " << endl;
                    cout << "\t[1] Register Test Centre" << endl;
                    cout << "\t[2] Record Tester" << endl;
                    cout << "\t[3] Manage Test Kit Stock" << endl;
                    cout << "\t[4] Generate Report" << endl;
                    cout << "\t[0] Back" << endl;
                    cout << "Input number: ";
                    cin >> option2;
                    cout << endl;

                    while (!(option2 >= 0 && option2 <= 3)) {
                        cout << "Please input valid number!" << endl;
                        cout << "Input number: ";
                        cin >> option2;
                        cout << endl;
                    }

                    switch (option2) {
                        case 0:
                            break;

                        case 1: {
                            cout << "Register Test Center " << endl;
                            cout << "Input centre name: ";
                            cin.ignore();
                            getline(cin, ctName);

                            ctID = ctismain.randTCID();
                            while (ctismain.isTestCentreRegistered(ctName)){
                                cout << "Test Centre name has been registered." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nInput centre name: ";
                                getline(cin, ctName);
                            }
                            //TestCentre tct(ctID, ctName);
                            TestCentre tct(ctID,ctName);
                            ctismain.setTestCentreList(tct);
                            ofcLoggedIn->setTestCentreOfc(tct);

                            cout << "Manager " <<  ofcLoggedIn->getFullname()
                                 << " registered at Test Centre " <<  ofcLoggedIn->getTestCentreOfc().getCentreName()
                                 << ", with Test Centre ID: " << ctID
                                 << " has successfully registered." << endl;

                            for(int i =0; i < ctismain.getOfficerList().size(); i++) {
                                cout << "check: "<<  ctismain.getOfficerList()[i].getTestCentreOfc().getCentreName();
                            }
                            break;
                        }

                        case 2: {
                            cout << "Record for new Tester ";
                            cout << "\nEnter First Name: ";
                            cin >> firstname;

                            cout << "Enter Last name: ";
                            cin >> lastname;

                            fullname = firstname + " " + lastname;

                            cout << "Enter username: ";
                            cin >> username;

                            while(ctismain.isTesterRegistered(username)){
                                cout << "Username has been taken." << endl;
                                cout << "Please try another one." << endl;
                                cout << "\nEnter username: ";
                                cin >> username;
                            }

                            cout << "Enter password: ";
                            cin >> password;

                            // create new object centre officer
                            TestCentre tctTester = ofcLoggedIn->getTestCentreOfc();
                            CentreOfficer newTester(username, password, fullname, "Tester", tctTester);
                            ctismain.setOfficerList(newTester);

                            //for (int i = 0; i < ctismain.getTestCentreList().size(); i++){
                                cout << "Tester " << fullname
                                     << ", with username " << username
                                     << ", assigned to: " << newTester.getTestCentreOfc().getCentreName()
                                     << " has successfully registered." << endl;
                           // }
                            for(int i =0; i < ctismain.getOfficerList().size(); i++) {
                                if(ctismain.getOfficerList()[i].getOfcPosition() == "Tester")
                                    cout << "check: "<<  ctismain.getOfficerList()[i].getTestCentreOfc().getCentreName();
                            }

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
                                getline(cin, tkName);

                                while (ctismain.isTestKitRegistered(tkName)){
                                    cout << "Test Kit name has been registered." << endl;
                                    cout << "Please try another one." << endl;
                                    cout << "\nInput Test Kit name: ";
                                    getline(cin, tkName);
                                }

                                cout << "Input available kit stock: ";
                                cin >> availQtyKit;

                                kitID = ctismain.randKitID();
                                // create new TestKit object
                                TestKit newTestKit(kitID, availQtyKit, tkName);
                                ctismain.setTestKitList(newTestKit);

                                cout << "Test Kit " << tkName
                                     << ", with ID " << kitID
                                     << " has " << availQtyKit
                                     << " available stock successfully registered." << endl;
                            }
                            else if (op == 'N' || op == 'n') {
                                cout << "Manage Test Kit Stock:" << endl;
                                cout << "Input Kit ID: ";
                                cin >> kitID;
                                // search kit ID and update stock.
                                for (int i = 0; i < ctismain.getTestKitList().size(); i++) {
                                    while (kitID != ctismain.getTestKitList().at(i).getKitID()) {
                                        cout << "No Kit ID found. Please try again." << endl;
                                        cout << "Input Kit ID: ";
                                        cin >> kitID;
                                    }
                                    if (kitID == ctismain.getTestKitList().at(i).getKitID()) {
                                        int currentQty, updQty;
                                        TestKit *updateTestKit = ctismain.getTestKitByKitID(kitID);
                                        currentQty = updateTestKit->getAvailableKit();

                                        cout << "Current available stock is: " << currentQty << endl;
                                        cout << "Update stock: ";
                                        cin >> updQty;
                                        updateTestKit->addStock(updQty);

                                        for(int i =0; i < ctismain.getTestKitList().size(); i++) {
                                            cout << "Debug: " << ctismain.getTestKitList()[i].getAvailableKit();
                                        }

                                        cout << "\nStock updated!" << endl;
                                        cout << "Stock updated: " << updateTestKit->getAvailableKit() << endl;
                                    }
                                }
                            }
                            break;
                        }

                        case 4:
                            cout << "Report details: " << endl;
                            break;

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
                cin >> username;

                cout << "Enter password: ";
                cin >> password;
                if (ctismain.isLoginTstValid(username, password)) {
                    cout << "\nWelcome Tester, " << username;

                    cout << "\nSelect menu below: ";
                    cout << "\n\t[1] Record New Test" << endl;
                    cout << "\t[2] Update Test Result" << endl;
                    cout << "\t[0] Back" << endl;
                    cout << "Select number: ";
                    cin >> option2;
                    cout << endl;

                    switch (option2) {
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
                                cin >> firstname;
                                cout << "Enter Last name: ";
                                cin >> lastname;

                                fullname = firstname + " " + lastname;

                                cout << "Enter username: ";
                                cin >> username;

                                while(ctismain.isPatientRegistered(username)){
                                    cout << "Username has been taken." << endl;
                                    cout << "Please try another one." << endl;
                                    cout << "\nEnter username: ";
                                    cin >> username;
                                }

                                cout << "Enter password: ";
                                cin >> password;

                                cout << "\nWhich type of patient?" << endl;
                                cout << "\t[1]. Returnee\n";
                                cout << "\t[2]. Quarantined\n";
                                cout << "\t[3]. Close contact\n";
                                cout << "\t[4]. Infected\n";
                                cout << "\t[5]. Suspected\n";
                                cout << "Select number: ";
                                cin >> selectType;

                                while (selectType < 1 || selectType > 5) {
                                    cout << "\nError!\nPlease input valid number.";
                                    cout << "Select number: ";
                                    cin >> selectType;
                                }

                                switch (selectType) {
                                    case 1:
                                        patientType = "Returnee";
                                        break;

                                    case 2:
                                        patientType = "Quarantined";
                                        break;

                                    case 3:
                                        patientType = "Close contact";
                                        break;

                                    case 4:
                                        patientType = "Infected";
                                        break;

                                    case 5:
                                        patientType = "Suspected";
                                        break;
                                }
                                cout << "Input symptoms: ";
                                cin >> ptnSympt;

                                Patient newPatient(username, password, fullname, patientType, ptnSympt);
                                ctismain.setPatientList(newPatient);

                                cout << "Patient " << fullname
                                     << ", Type: " << patientType
                                     << ", with username " << username
                                     << ", with symptoms " << ptnSympt
                                     << " has successfully registered." << endl;
                            }
                            else if (op == 'Y' || op == 'y'){
                                cout << "Updating data patient..." << endl;
                                cout << "Input patient's username: ";
                                cin >> username;
                                // search kit ID and update stock.
                                for (int i = 0; i < ctismain.getPatientList().size(); i++) {
                                    while (username != ctismain.getPatientList().at(i).getUsername()) {
                                        cout << "Username not found. Please try again." << endl;
                                        cout << "Input patient's username: ";
                                        cin >> username;
                                    }
                                    if (username == ctismain.getPatientList().at(i).getUsername()) {
                                        string currentPtnType, updatePtnType, currentPtnSympt, updatePtnSympt;
                                        Patient *updatePatient = ctismain.getPatientByUsername(username);

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
                                        cout << "Select update number: ";
                                        cin >> selectType;

                                        while (selectType < 1 || selectType > 5) {
                                            cout << "\nError!\nPlease input valid number.";
                                            cout << "Select update number: ";
                                            cin >> selectType;
                                        }

                                        switch (selectType) {
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

                                        for(int i =0; i < ctismain.getPatientList().size(); i++) {
                                            cout << "Debug: " << ctismain.getPatientList()[i].getPatientType() << endl;
                                            cout << "Debug: " << ctismain.getPatientList()[i].getSymptoms() << endl;
                                        }
                                    }
                                }
                            }
                            break;
                        }


                        case 2:
                            cout << "Update test result: ";
                            break;
                            // update some test here

                        default:
                            cout << "Please input valid number";
                    }
                    break; // break case 4

                    case 4:
                    cout << "Login for an existing account for Patient." << endl;
                    cout << "Enter username: ";
                    cin >> username;

                    cout << "Enter password: ";
                    cin >> password;

                    if (ctismain.isLoginPtnValid(username, password)){
                        cout << "\nWelcome patient, " << username;
                        cout << "\nDo you want to view a Test Report?";
                        cout << "\n\t[(Y)es / (N)o]: ";
                        cin >> op;

                        if (op == 'y' || op == 'Y') {
                            cout << "\nTest Report Patient's detail: " << endl;
                        } else {
                            // exit;
                        }
                    }
                    else{
                        cout << "No account patient matched." << endl;
                        cout << "Please try again" << endl;
                    }

                    break; // break case 5

                    case 9:
                        cout << "Debugging!" << endl;
                    cout << "Patient List: ";
//                cout << CTIS::showPatientList();
                    default:
                        cout << "Wrong input. Please enter the valid number.";
                }
                else{
                    cout << "Sorry. No account matched." << endl;
                    cout << "Please input username and password correctly." << endl;
                }
            }
        }
    return 0;
}