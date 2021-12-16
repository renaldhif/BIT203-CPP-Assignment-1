/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 * Date created : 6 December 2021
 *
 */
#include "CTIS.h"

// constructor
User::User(){
    setUsername("invalidUsername");
    setPassword("invalidPassword");
    setFullname("invalidFullname");
}

// constructor with arguments
User::User(string inUName, string inPwd, string inFName){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
}

// destructor
User::~User(){};

// setters
void User::setUsername(string inUName){
    username = inUName;
}

void User::setPassword(string inPwd){
    password = inPwd;
}

void User::setFullname(string inFName){
    fullname = inFName;
}

// getters
string User::getUsername(){
    return username;
}

string User::getPassword(){
    return password;
}

string User::getFullname(){
    return fullname;
}

// Method for View Testing History
string User::viewTestHistory(){

}

string User::toString(){
    return username + fullname;
}
