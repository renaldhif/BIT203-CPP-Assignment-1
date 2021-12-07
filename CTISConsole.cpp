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
string firstname, lastname, username, password, fullname, patientType, ctName, ptnSympt;
int option = 10, option2 = 10, selectType, ctID;
char op;

CTIS ctismain;

int main() {
    while (option != 0){
        cout << "\nCTIS System.\nPlease Select Menu Below:" << endl;
        cout << "\t[1] Register for Test Center Manager" << endl;
        cout << "\t[2] Login for Manager" << endl;
        cout << "\t[3] Login for Tester" << endl;
        cout << "\t[4] Login for Patient" << endl;
        cout << "\t[0] Exit" << endl;
        cout << "Select number: ";
        cin >> option;

        switch(option){
            case 0:
                cout << "Program closed. Thank you.\n Stay Healthy Stay safe.";
                break; // break case 0

            case 1:{
                cout << "\nRegister a new account for Manager." << endl;
                cout << "Enter First Name: ";
                cin >> firstname;

                cout << "Enter Last name: ";
                cin >> lastname;

                fullname = firstname + " " + lastname;

                cout << "Enter username: ";
                cin >> username;

                cout << "Enter password: ";
                cin >> password;

                // create new object centre officer

                CentreOfficer newManager(username,password, fullname, "Manager");
                ctismain.setManagerList(newManager);
                cout << "Manager " << fullname << " has successfully registered!" << endl;
            }
            break; // break case 1

            case 2:
                cout << "\nLogin for Test Center Manager." << endl;

                cout << "Enter username: ";
                cin >> username;

                cout << "Enter password: ";
                cin >> password;

                // if login successful:
                cout << "\nWelcome Test Center Manager, "<<  username << endl;
                cout << "Select menu below: " << endl;
                cout << "\t[1] Register Test Centre" << endl;
                cout << "\t[2] Record Tester" << endl;
                cout << "\t[3] Manage Test Kit Stock" << endl;
                cout << "\t[4] Generate Report" << endl;
                cout << "\t[0] Back" << endl;
                cout << "Input number: ";
                cin >> option2;
                cout << endl;

                while (!(option2 >= 0 && option2 <= 3)){
                    cout << "Please input valid number!" << endl;
                    cout << "Input number: ";
                    cin >> option2;
                    cout << endl;
                }

                switch(option2){
                    case 0:
                        break;

                    case 1:{
                        cout << "Register Test Center " << endl;
                        cout << "Input centre name: ";
                        cin >> ctName;
                        ctID = ctismain.randTCID();

                        TestCentre tct(ctID, ctName);
                        break;
                    }

                    case 2:{
                        cout << "Record for new Tester ";
                        cout << "\nEnter First Name: ";
                        cin >> firstname;

                        cout << "Enter Last name: ";
                        cin >> lastname;

                        fullname = firstname + " " + lastname;

                        cout << "Enter username: ";
                        cin >> username;

                        cout << "Enter password: ";
                        cin >> password;

                        // create new object centre officer

                        CentreOfficer newTester(username,password, fullname, "Tester");
                        ctismain.setTesterList(newTester);
                        break;
                    }

                        // record tester

                    case 3:
                        cout << "Manage Test Kit Stock" << endl;
                        // manage test kit stock
                        break;

                    case 4:
                        cout << "Report details: " << endl;
                        break;

                    default:
                        cout << "Wrong number. Please input valid number";
                }
                break; // break for case 2

            case 3:
                cout << "\nLogin for an existing account for Tester." << endl;
                cout << "Enter username: ";
                cin >> username;

                cout << "Enter password: ";
                cin >> password;

                cout << "\nWelcome Tester, "<<  username;

                cout << "\nSelect menu below: ";
                cout << "\n\t[1] Record New Test" << endl;
                cout << "\t[2] Update Test Result"<< endl;
                cout << "\t[0] Back" << endl;
                cout << "Select number: ";
                cin >> option2;
                cout << endl;

                switch(option2){
                    case 0:
                        break;

                    case 1:
                        cout << "Record for new account?" << endl;
                        cout << "\t[(Y)es / (N)o]: ";
                        cin >> op;
                        // record some test
                        if(op == 'Y' || op == 'y'){
                            cout << "\nRecord for new account: " << endl;
                            cout << "Enter First Name: ";
                            cin >> firstname;

                            cout << "Enter Last name: ";
                            cin >> lastname;

                            fullname = firstname + " " + lastname;

                            cout << "Enter username: ";
                            cin >> username;

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

                            while (selectType < 1 || selectType > 5){
                                cout << "Error!\nPlease input valid number.";
                                cout << "Select number: ";
                                cin >> selectType;
                            }

                            switch(selectType){
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

                            Patient newPatient(username,password,fullname,patientType,ptnSympt);
                            ctismain.setPatientList(newPatient);
                        }

                        break;

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

                cout << "\nWelcome patient, "<<  username;
                cout << "\nDo you want to view a Test Report?";
                cout << "\n\t[(Y)es / (N)o]: ";
                cin >> op;

                if (op == 'y' || op == 'Y'){
                    cout << "\nTest Report Patient's detail: " << endl;
                }
                else {
                    // exit;
                }
                break; // break case 5

            case 9:
                cout << "Debugging!" << endl;
                cout << "Patient List: ";
//                cout << CTIS::showPatientList();
            default:
                cout << "Wrong input. Please enter the valid number.";
        }
    }

    return 0;
}
