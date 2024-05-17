//
// Created by konrad on 4/24/24.
//

#include <tuple>
#include <sstream>
#include "ReadFromFile.h"
#include "../Crypto/Crypto.h"

std::vector<Account> ReadFromFile::readAccounts() {
    std::vector<Account> users = {};
    std::ifstream reader("accountsStorageFile.txt");

    if(!reader.is_open()) {
        std::cerr << "Something went wrong with the file\n";
    }
    std::string line;
    int id = 0;
    std::string username;
    while(getline(reader, line)) {
        std::tuple<int, std::string> userInfo;
        size_t found = line.find(':');
        if(found != std::string::npos) {
            auto IDtoken = line.substr(0, found);
            id = stoi(IDtoken);
            auto nametoken = line.substr(found+1, line.length());
            username = nametoken;
        }

        Account *newUser = new Account(username, id);
        users.push_back(*newUser);
    }

    return users;
}


std::vector<Password> ReadFromFile::readPasswords() {
    std::vector<Password> passwords = {};
    std::ifstream reader("passwordsTempDecrypted.txt");

    if(!reader.is_open()) {
        std::cerr << "Something went wrong with the file\n";
    }
    std::string line;
    int id = 0;
    std::string password;
    while(getline(reader, line)) {
        std::tuple<int, std::string> userInfo;
        size_t found = line.find(':');
        if(found != std::string::npos) {
            auto IDtoken = line.substr(0, found);
            id = stoi(IDtoken);
            auto nametoken = line.substr(found+1, line.length());
            password = nametoken;
        }

        auto *newPassword = new Password(password, id);
        passwords.push_back(*newPassword);
    }

    return passwords;
}

std::vector<std::tuple<int, int>> ReadFromFile::readConnectedIDs() {
    std::vector<std::tuple<int, int>> connectedIDs = {};
    std::ifstream reader("tuplesStorageFile.txt");

    if(!reader.is_open()) {
        std::cerr << "Something went wrong with the file\n";
    }
    std::string line;
    int userID = 0;
    int passwordID = 0;
    while(getline(reader, line)) {
        std::tuple<int, std::string> userInfo;
        size_t found = line.find(':');
        if(found != std::string::npos) {
            auto IDtoken = line.substr(0, found);
            userID = stoi(IDtoken);
            auto nametoken = line.substr(found+1, line.length());
            passwordID = stoi(nametoken);
        }

        std::tuple<int, int> IDs = std::make_tuple(userID, passwordID);
        connectedIDs.push_back(IDs);
    }

    return connectedIDs;
}

int ReadFromFile::lastID() {
    std::ifstream reader("passwordsTempDecrypted.txt");

    if(!reader.is_open()) {
        std::cerr << "Something went wrong with the file\n";
    }
    std::string line;
    int userID = 404;
    while(getline(reader, line)) {
        std::tuple<int, std::string> userInfo;
        size_t found = line.find(':');
        if(found != std::string::npos) {
            auto IDtoken = line.substr(0, found);
            userID = stoi(IDtoken);
        }
    }

    return userID;
}



bool is_empty(std::fstream& pFile)
{
    pFile.seekg(0, std::ios::end);
    int length = pFile.tellg();
    if(length == 0) {
        return true;
    }
    return false;
}


bool ReadFromFile::checkMasterAccount() {
    std::fstream reader("MasterAccountTempDec.txt", std::fstream::app);

//    reader.open("masterAccount.txt", std::fstream::app);
    if(is_empty(reader)) {
        return false;
    }
    reader.close();
    return true;
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

MasterAccount ReadFromFile::readMasterAccount() {
    std::string usr, pass, master, passSalt;
    auto *accountData = new MasterAccount();


    std::ifstream reader("MasterAccountTempDec.txt");

    if(reader.is_open()) {
        std::string line;

        while(std::getline(reader, line)) {
            size_t found = line.find(':');
            if(found != std::string::npos) {
                std::vector<std::string> tokens = split(line, ':');
                usr = tokens.at(0);
                pass = tokens.at(1);
                passSalt = tokens.at(2);

            }
        }
    }

    accountData->setData(usr, pass, passSalt);

    return *accountData;
}
