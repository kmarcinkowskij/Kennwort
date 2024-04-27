//
// Created by konrad on 5/17/24.
//

#include "MasterAccount.h"

#include <utility>

MasterAccount::MasterAccount(std::string _username, std::string _hashedPassword, std::string _masterSalt, std::string _passSalt) : username(std::move(_username)), hashedPassword(std::move(_hashedPassword)),masterSalt(std::move(_masterSalt)), passSalt(std::move(_passSalt)){}

bool MasterAccount::authenticateUser() {

    return false;
}

void MasterAccount::createUser() {

};
