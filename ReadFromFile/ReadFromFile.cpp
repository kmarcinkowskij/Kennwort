//
// Created by konrad on 4/24/24.
//

#include <tuple>
#include "ReadFromFile.h"

std::vector<User> ReadFromFile::readUsers() {
    std::vector<User> users = {};
    std::ifstream reader("usersStorageFile.txt");

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

        User *newUser = new User(username, id);
        users.push_back(*newUser);
    }

    return users;
}

std::vector<Password> ReadFromFile::readPasswords() {
    std::vector<Password> passwords = {};
    std::ifstream reader("PasswordsStorageFile.txt");

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
    std::ifstream reader("PasswordsStorageFile.txt");

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
