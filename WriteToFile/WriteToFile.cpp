//
// Created by konrad on 4/24/24.
//

#include <tuple>
#include <cstring>
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
    this->_storageFile.flush();
    this->_storageFile.close();
    crypto->encryptFile("2137", "masterAccount.txt", "MasterAccountEnc.txt");
}

void WriteToFile::updateLine(const std::string &_lineID, const std::string _newLine, const char* _filename) {
    auto *crypto = new Crypto;
    auto reader = std::ifstream(_filename, std::ios_base::app);
    auto output = std::ofstream("update_temp.txt", std::ios::trunc);
    if(!reader.is_open()) {
        std::cerr << "Something went wrong with the file!\n";
    }
    std::string line;
    std::string currentID;
    while(std::getline(reader, line)) {
        std::tuple<int, std::string> userInfo;
        size_t found = line.find(':');

        if(found != std::string::npos) {
             currentID = line.substr(0, found);
        }
        if(currentID == _lineID) {
            output << _lineID << ":" << _newLine << "\n";
            continue;
        }

        output << line << "\n";

    }
    reader.close();
    output.close();
    std::cout << _filename << std::endl;
    auto tempReader = std::ifstream("update_temp.txt");
    auto what = std::ofstream(_filename, std::ios::trunc);

    while(std::getline(tempReader, line)) {
        what << line << "\n";
    }

    tempReader.close();
    what.close();

    remove("update_temp.txt");
}



