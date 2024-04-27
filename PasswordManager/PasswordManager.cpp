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

std::vector<std::string> PasswordManager::getPasswordsByUserID(const int &_userID) {
    std::string password;
    std::vector<std::string>passwordsConnectedWithUser = {};
    for(auto existingTuple: this->connectedIDs) {
        if(std::get<0>(existingTuple) == _userID) {
            int theID = std::get<1>(existingTuple);
            password = getPasswordByID(theID);
            passwordsConnectedWithUser.push_back(password);
        }
    }
    return passwordsConnectedWithUser;
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

    if(checkIfUserExists(newUsername) == 0) {
        std::cout << "New user detected, welcome!";
        auto *newUserObject = new User(newUsername, newID);
        auto *newPasswordObject = new Password(newPassword, newID);

        addUser(newUserObject);
        addPassword(newPasswordObject);

        connectTuple(newUserObject->getUserID(), newPasswordObject->getID());
    } else {
        std::cout << "welcome back, " << newUsername << "! Good to see you again!\n";
        int theID = checkIfUserExists(newUsername);
        auto *newUserObject = new User(newUsername, theID);
        auto *newPasswordObject = new Password(newPassword, newID);

        addPassword(newPasswordObject);

        connectTuple(newUserObject->getUserID(), newPasswordObject->getID());
        delete(newUserObject);
        delete(newPasswordObject);
    }
}

int PasswordManager::checkIfUserExists(const std::string& _username) {
    for(const auto& user: this->usersVector) {
        if(user.getUsername() == _username) {
            return user.getUserID();
        }
    }

    return 0;
}

void PasswordManager::Menu() {
    int choice = 0;
    std::string menuString = " --- MENU --- \n1 - Add a password\n2 - Update a password\n3 - View passwords associated with username";
    std::cout << menuString;

    std::cout << "\nchoose your option (1-3)\n";
    std::cin >> choice;

    switch(choice) {
        case 1: {
            createNewPair();
            break;
        }
        case 2: {
//            TODO: add updating functionality
            break;
        }
        case 3: {
            std::cout << "What username do you want to check?\n";
            std::string username;
            std::cin >> username;
            if(checkIfUserExists(username) == 0) {
                std::cerr << "user doesn't exist! Did you want to add a user instead?";
                break;
            }
            int id = getIDbyUsername(username);
            std::vector<std::string> passwords = getPasswordsByUserID(id);


            for(auto _password: passwords) {
                std::cout << _password << "\n";
            }
            break;
        }
        default: {
            std::cerr << "wrong action number!\n";
        }

    }

}

int PasswordManager::getIDbyUsername(const std::string &_username) {
    for(auto user: this->usersVector) {
        if(user.getUsername() == _username) {
            return user.getUserID();
        }
    }
    return 0;
}
