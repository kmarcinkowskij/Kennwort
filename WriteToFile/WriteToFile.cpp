//
// Created by konrad on 4/24/24.
//

#include <tuple>
#include "WriteToFile.h"

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
    _storageFile = std::ofstream("PasswordsStorageFile.txt", std::ios_base::app);
    if(!_storageFile.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    this->_storageFile << _password.getID()<< ":"<<_password.getPassword() << "\n";
    this->_storageFile.flush();
    this->_storageFile.close();
}

void WriteToFile::saveUserToFile(const User &_user) {
    _storageFile = std::ofstream("usersStorageFile.txt", std::ios_base::app);
    if(!_storageFile.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    this->_storageFile << _user.getUserID()<< ":"<<_user.getUsername() << "\n";
    this->_storageFile.flush();
    this->_storageFile.close();
}
