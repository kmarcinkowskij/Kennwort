//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_PASSWORDMANAGER_H
#define PASSWORDMANAGER_PASSWORDMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "../Password/Password.h"
#include "../User/User.h"

class PasswordManager {
private:
    std::vector<Password>passwordsVector = {};
    std::vector<User>usersVector = {};
    std::vector<std::tuple<int, int>>connectedIDs = {};


public:
    PasswordManager();

    void Menu();

    void createNewPair();

    void addUser(const User *newUser);
    void addPassword(const Password *newPassword);

    std::string getPasswordByID(const int& ID);
    std::string getUserByID(const int& ID);
    int getIDbyUsername(const std::string& _username);


    int checkIfUserExists(const std::string& _username);


    std::vector<std::string> getPasswordsByUserID(const int& _userID);

    void connectTuple(const int& _userID, const int& _passwordID);
};


#endif //PASSWORDMANAGER_PASSWORDMANAGER_H
