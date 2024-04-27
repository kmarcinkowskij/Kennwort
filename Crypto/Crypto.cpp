//
// Created by konrad on 5/17/24.
//

#include "Crypto.h"

std::size_t Crypto::encryptPassword(const Password &_password) {
    std::string _unhashed = _password.getPassword();
    size_t _hashed = this->hasher(_unhashed);
    return _hashed;
}

std::size_t Crypto::encryptPasswordWithSalt(const Password &_password) {
    std::string _unhashed = _password.getPassword();
    //TODO: ADD SALTING WITH SALT PER USER!!!
    size_t _hashed = this->hasher(_unhashed);
    return _hashed;
}
