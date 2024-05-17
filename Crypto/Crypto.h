//
// Created by konrad on 5/17/24.
//

#ifndef PASSWORDMANAGER_CRYPTO_H
#define PASSWORDMANAGER_CRYPTO_H

#include <iostream>
#include <fstream>
#include "../Password/Password.h"
#include "../MasterAccount/MasterAccount.h"

class Crypto {
    std::hash<std::string> hasher;

public:
    std::size_t encryptPassword(const std::string &_password);
    void encryptFile(const std::string& _key, const char* _filename, const char* _newFilename);
    void decryptFile(const std::string& _key, const char* _filename, const char* _newFilename);
    int saltToKey(const std::string& _salt);
};


#endif //PASSWORDMANAGER_CRYPTO_H
