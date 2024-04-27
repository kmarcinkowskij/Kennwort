//
// Created by konrad on 5/17/24.
//

#ifndef PASSWORDMANAGER_CRYPTO_H
#define PASSWORDMANAGER_CRYPTO_H

#include <iostream>
#include "../Password/Password.h"

class Crypto {
    std::hash<std::string> hasher;

public:
    std::size_t encryptPassword(const Password& _password);
    std::size_t encryptPasswordWithSalt(const Password& _password);
};


#endif //PASSWORDMANAGER_CRYPTO_H
