//
// Created by konrad on 5/17/24.
//

#include "MasterAccount.h"

#include <utility>
#include <random>
#include "../WriteToFile/WriteToFile.h"
#include "../Crypto/Crypto.h"

std::string generateRandomSalt(int length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string salt;
    for (int i = 0; i < length; ++i) {
        salt += characters[distribution(generator)];
    }

    return salt;
}
bool MasterAccount::authenticateUser() {
    bool _authenticated;
    auto encrypter = new Crypto();
    do {
        std::string userPass, _username, passToCheck;

        std::cout << "\nUsername: ";
        std::cin >> _username;

        std::cout << "Password: ";
        std::cin >> userPass;

        passToCheck = std::to_string(encrypter->encryptPassword(userPass + this->passSalt));

        if (_username == this->username && passToCheck == this->hashedPassword) {
            std::cout << "Welcome " << this->username << "! \n";
            MasterAccount::last_logged_in = time(nullptr);

            std::string dt = ctime(&MasterAccount::last_logged_in);

            std::cout << "Logged in on " << dt << "!";
            return true;
        }

        std::cout << "incorrect username or password!";
    }while(!_authenticated);

    return false;
}

void MasterAccount::createUser() {
    auto *writer = new WriteToFile();
    auto *newAccount = new MasterAccount();
    std::string _username, _passwordUnhashed, _masterSalt, _passwordSalt, _passwordHashed;

    auto *crypter = new Crypto();
    std::cout << "Username: ";
    std::cin >> _username;
    std::cout << "\nPassword: ";
    std::cin >> _passwordUnhashed;

    _masterSalt = generateRandomSalt(6);
    _passwordSalt = generateRandomSalt(6);
    _passwordUnhashed += _passwordSalt;

    _passwordHashed = std::to_string(crypter->encryptPassword(_passwordUnhashed));
    newAccount->username = _username;
    newAccount->hashedPassword = _passwordHashed;
    newAccount->passSalt = _passwordSalt;

    writer->saveMasterAccountToFile(*newAccount);
}

std::string MasterAccount::getUsername() {
    return this->username;
}

std::string MasterAccount::getHashedPassword() {
    return this->hashedPassword;
}


std::string MasterAccount::getPassSalt() {
    return this->passSalt;
}

void MasterAccount::setData(std::string _username, std::string _password, std::string _passSalt) {
    this->username = std::move(_username);
    this->hashedPassword = std::move(_password);
    this->passSalt = std::move(_passSalt);
};
