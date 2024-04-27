//
// Created by konrad on 4/24/24.
//

#include "Account.h"

#include <utility>

void Account::setAccountName(const std::string &_accountName) {
    this->accountName = _accountName;
}

void Account::setAccountID(const int &_accountID) {
    this->accountID = _accountID;
}

std::string Account::getAccountName() const {
    return this->accountName;
}

int Account::getAccountID() const {
    return this->accountID;
}

Account::Account(std::string _username, int _accountID): accountName(std::move(_username)), accountID(_accountID) {

}
