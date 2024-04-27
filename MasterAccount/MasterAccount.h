//
// Created by konrad on 5/17/24.
//

#ifndef PASSWORDMANAGER_MASTERACCOUNT_H
#define PASSWORDMANAGER_MASTERACCOUNT_H

#include <iostream>

class MasterAccount {
private:
    std::string username;
    std::string hashedPassword;
    std::string masterSalt;
    std::string passSalt;
public:

    MasterAccount(std::string _username, std::string _hashedPassword, std::string _masterSalt, std::string _passSalt);

    bool authenticateUser();
    void createUser();
};

#endif //PASSWORDMANAGER_MASTERACCOUNT_H
