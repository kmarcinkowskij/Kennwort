//
// Created by konrad on 4/24/24.
//

#include <tuple>
#include "WriteToFile.h"
#include "../Crypto/Crypto.h"

void WriteToFile::saveTupleToFile(std::tuple<int, int> connectedIDs) {
    _storageFile = std::ofstream("tuplesStorageFile.txt", std::ios_base::app);
    if(!_storageFile.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    this->_storageFile << std::get<0>(connectedIDs) <<":"<<std::get<1>(connectedIDs) << "\n";
    this->_storageFile.flush();
    this->_storageFile.close();
}

void WriteToFile::savePasswordToFile(const Password& _password) {
    _storageFile = std::ofstream("passwordsTempDecrypted.txt", std::ios_base::app);
    if(!_storageFile.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    this->_storageFile << _password.getID()<< ":"<<_password.getPassword() << "\n";
    this->_storageFile.flush();
    this->_storageFile.close();
}

void WriteToFile::saveAccountToFile(const Account &_user) {
    _storageFile = std::ofstream("accountsStorageFile.txt", std::ios_base::app);
    if(!_storageFile.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    this->_storageFile << _user.getAccountID() << ":" << _user.getAccountName() << "\n";
    this->_storageFile.flush();
    this->_storageFile.close();
}

void WriteToFile::saveMasterAccountToFile(MasterAccount _masterAccount) {
    auto *crypto = new Crypto;
    _storageFile = std::ofstream("masterAccount.txt", std::ios_base::app);
    if(!_storageFile.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    this->_storageFile << _masterAccount.getUsername() << ":" << _masterAccount.getHashedPassword() << ":" << _masterAccount.getPassSalt();
    crypto->encryptFile("2137", "masterAccount.txt", "MasterAccountEnc.txt");
    this->_storageFile.flush();
    this->_storageFile.close();
}
