//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_ACCOUNT_H
#define PASSWORDMANAGER_ACCOUNT_H
#include <iostream>
#include <string>
#include <vector>

class Account {
private:
    std::string accountName;
    int accountID;
public:
    Account(std::string _username, int _accountID);
    void setAccountName(const std::string& _accountName);
    void setAccountID(const int& _accountID);
    [[nodiscard]] std::string getAccountName() const;
    [[nodiscard]] int getAccountID() const;
};


#endif //PASSWORDMANAGER_ACCOUNT_H
