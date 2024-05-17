//
// Created by konrad on 5/17/24.
//

#ifndef PASSWORDMANAGER_MASTERACCOUNT_H
#define PASSWORDMANAGER_MASTERACCOUNT_H

#include <iostream>
#include "../Crypto/Crypto.h"

class MasterAccount {
private:
    std::string username;
    std::string hashedPassword;
    std::string passSalt;
public:

    inline static bool authenticated;
    inline static time_t last_logged_in;
    MasterAccount()= default;
    void setData(std::string _username, std::string _password, std::string _passSalt);
    bool authenticateUser();
    void createUser();

    std::string getUsername();
    std::string getHashedPassword();
    std::string getPassSalt();
};

#endif //PASSWORDMANAGER_MASTERACCOUNT_H
