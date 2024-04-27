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
#include "../Account/Account.h"

class PasswordManager {
private:
    std::vector<Password>passwordsVector = {};
    std::vector<Account>accountsVector = {};
    std::vector<std::tuple<int, int>>connectedIDs = {};
public:
    PasswordManager();

    void Menu();

    void createNewPair();

    void addUser(const Account *newAccount);
    void addPassword(const Password *newPassword);

    std::string getPasswordByID(const int& ID);
    std::string getUserByID(const int& ID);
    int getIDbyAccountName(const std::string& _accountName);


    int checkIfAccountExists(const std::string& _accountName);


    std::vector<std::string> getPasswordsByAccountID(const int& _accountID);

    void connectTuple(const int& _userID, const int& _passwordID);
};


#endif //PASSWORDMANAGER_PASSWORDMANAGER_H
