//
// Created by konrad on 4/24/24.
//

#include "PasswordManager.h"
#include "../WriteToFile/WriteToFile.h"
#include "../ReadFromFile/ReadFromFile.h"

void PasswordManager::addPassword(const Password *newPassword) {
    WriteToFile writer = *new WriteToFile;
    writer.savePasswordToFile(*newPassword);
    this->passwordsVector.push_back(*newPassword);
}

std::string PasswordManager::getPasswordByID(const int &ID) {
    for(const auto& existingPassword: this->passwordsVector) {
        if(existingPassword.getID() == ID) {
            return existingPassword.getPassword();
        }
    }
    return "404";
}

void PasswordManager::addUser(const User *newUser) {
    WriteToFile writer = *new WriteToFile;
    std::string newUsername = newUser->getUsername();
    //Check for existing users with username;
    for(const auto& existingUser: this->usersVector) {
        if(existingUser.getUsername() == newUsername) {
            return;
        }
    }

    writer.saveUserToFile(*newUser);
    this->usersVector.push_back(*newUser);
}

void PasswordManager::connectTuple(const int &_userID, const int &_passwordID) {
    WriteToFile writer = *new WriteToFile;
    auto thePair = std::make_pair(_userID, _passwordID);
    writer.saveTupleToFile(thePair);
    this->connectedIDs.emplace_back(thePair);
}

std::string PasswordManager::getUserByID(const int &ID) {
    for(const auto& existingUser: this->usersVector) {
        if(existingUser.getUserID() == ID) {
            return existingUser.getUsername();
        }
    }
    return "404";
}

std::string PasswordManager::getPasswordByUserID(const int &_userID) {
    std::string password;
    std::vector<std::string>passwordsConnectedWithUser = {};
    for(auto existingTuple: this->connectedIDs) {
        if(std::get<0>(existingTuple) == _userID) {
            int theID = std::get<1>(existingTuple);
            password = getPasswordByID(theID);
            return password;
        }
    }
    return "404";
}

PasswordManager::PasswordManager() {
    auto *reader = new ReadFromFile();
    this->usersVector = reader->readUsers();
    this->passwordsVector = reader->readPasswords();
    this->connectedIDs = reader->readConnectedIDs();
}

void PasswordManager::createNewPair() {
    auto reader = ReadFromFile();
    std::string newUsername;
    int newUserID;
    std::string newPassword;
    int newPasswordID;

    int newID= reader.lastID() + 1;

    std::cout << "podaj nazwę użytkownika: ";
    std::cin >> newUsername;
    std::cout << "podaj swoje hasło: ";
    std::cin >> newPassword;

    auto *newUserObject = new User(newUsername, newID);
    auto *newPasswordObject = new Password(newPassword, newID);

    addUser(newUserObject);
    addPassword(newPasswordObject);

    connectTuple(newUserObject->getUserID(), newPasswordObject->getID());

}
