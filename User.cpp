/**
 *
 * @author      : Renaldhi Fahrezi
 * Student ID   : E1900355
 *
 */
 // include CTIS header
#include "CTIS.h"

// constructor
/**
 * This is the default constructor of User class.
 *
 * It sets the default value for User attributes,
 * such as username, password, and fullname.
 */
User::User(){
    setUsername("invalidUsername");
    setPassword("invalidPassword");
    setFullname("invalidFullname");
}

// constructor with arguments
/**
 * This is the constructor of User class.
 *
 * It sets User attributes
 * by taking inUName as username, inPwd as password, inFName as fullname.
 */
User::User(string inUName, string inPwd, string inFName){
    setUsername(inUName);
    setPassword(inPwd);
    setFullname(inFName);
}

// destructor
/**
 * This is the destructor of User class
 */
User::~User(){};

// setters
/**
 * This is setter for username.
 * It sets the user's username.
 *
 * @param inUName as username
 */
void User::setUsername(string inUName){
    username = inUName;
}

/**
 * This is setter for password.
 * It sets the user's password.
 *
 * @param inUName as password
 */
void User::setPassword(string inPwd){
    password = inPwd;
}

/**
 * This is setter for fullname.
 * It sets the user's fullname.
 *
 * @param inUName as fullname
 */
void User::setFullname(string inFName){
    fullname = inFName;
}

// getters
/**
 * This is getter for username.
 *
 * @return the user's username.
 */
string User::getUsername(){
    return username;
}

/**
 * This is getter for password.
 *
 * @return the user's password.
 */
string User::getPassword(){
    return password;
}

/**
 * This is getter for fullname.
 *
 * @return the user's fullname.
 */
string User::getFullname(){
    return fullname;
}

// Method for View Testing History
/**
 * This is method for viewing the test history.
 *
 * @return result of the test.
 */
string User::viewTestHistory(string usrUname, string usrPwd){

}