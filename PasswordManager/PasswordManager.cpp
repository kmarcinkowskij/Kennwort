//
// Created by konrad on 4/24/24.
//

#include "PasswordManager.h"
#include "../WriteToFile/WriteToFile.h"
#include "../ReadFromFile/ReadFromFile.h"
#include "../Crypto/Crypto.h"

void PasswordManager::addPassword(const Password *newPassword) {
    WriteToFile writer = *new WriteToFile;
    writer.savePasswordToFile(*newPassword);
    this->passwordsVector.push_back(*newPassword);
}

std::string PasswordManager::getPasswordByID(const int &ID) {
    for(const auto& existingPassword: this->passwordsVector) {
        if(existingPassword.getID() == ID) {
            auto *crypto = new Crypto;
//            size_t encrypted = crypto->encryptPassword(existingPassword);
//            return std::to_string(encrypted);
            return existingPassword.getPassword();
        }
    }
    return "404";
}

void PasswordManager::addUser(const Account *newAccount) {
    WriteToFile writer = *new WriteToFile;
    std::string newUsername = newAccount->getAccountName();
    //Check for existing users with accountName;
    for(const auto& existingUser: this->accountsVector) {
        if(existingUser.getAccountName() == newUsername) {
            return;
        }
    }

    writer.saveAccountToFile(*newAccount);
    this->accountsVector.push_back(*newAccount);
}

void PasswordManager::connectTuple(const int &_userID, const int &_passwordID) {
    WriteToFile writer = *new WriteToFile;
    auto thePair = std::make_pair(_userID, _passwordID);
    writer.saveTupleToFile(thePair);
    this->connectedIDs.emplace_back(thePair);
}

std::string PasswordManager::getUserByID(const int &ID) {
    for(const auto& existingUser: this->accountsVector) {
        if(existingUser.getAccountID() == ID) {
            return existingUser.getAccountName();
        }
    }
    return "404";
}

std::vector<std::string> PasswordManager::getPasswordsByAccountID(const int &_accountID) {
    std::string password;
    std::vector<std::string>passwordsConnectedWithUser = {};
    for(auto existingTuple: this->connectedIDs) {
        if(std::get<0>(existingTuple) == _accountID) {
            int theID = std::get<1>(existingTuple);
            password = getPasswordByID(theID);
            passwordsConnectedWithUser.push_back(password);
        }
    }
    return passwordsConnectedWithUser;
}

PasswordManager::PasswordManager() {
    auto *reader = new ReadFromFile();
    this->accountsVector = reader->readAccounts();
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

    do {
    std::cout << "Account name: ";
    std::cin >> newUsername;
    }while(newUsername.empty() || newUsername == " ");
    do{
    std::cout << "\nAccount Password: ";
    std::cin >> newPassword;
    }while(newPassword.empty() || newPassword == " ");

    if(checkIfAccountExists(newUsername) == 0) {
        std::cout << "New account detected";
        auto *newUserObject = new Account(newUsername, newID);
        auto *newPasswordObject = new Password(newPassword, newID);

        addUser(newUserObject);
        addPassword(newPasswordObject);

        connectTuple(newUserObject->getAccountID(), newPasswordObject->getID());
    } else {
        std::cerr << "That account already exists! Perhaps you meant to update an account?\n";
    }
}

int PasswordManager::checkIfAccountExists(const std::string& _accountName) {
    for(const auto& user: this->accountsVector) {
        if(user.getAccountName() == _accountName) {
            return user.getAccountID();
        }
    }

    return 0;
}

void PasswordManager::Menu() {

    int choice = 0;
    std::string menuString = " --- MENU --- \n1 - Add a password\n2 - View password associated with account";
    std::cout << menuString;

    std::cout << "\nchoose your option (1-3)\n";
    std::cin >> choice;

    switch(choice) {
        case 1: {
            createNewPair();
            break;
        }
        case 2: {
            std::cout << "What account Name do you want to check?\n";
            std::string username;
            do {
                std::cin >> username;
            }while(username.empty() || username == " ");
            if(checkIfAccountExists(username) == 0) {
                std::cerr << "user doesn't exist! Did you want to add a user instead?";
                break;
            }
            int id = getIDbyAccountName(username);
            std::vector<std::string> passwords = getPasswordsByAccountID(id);


            for(auto _password: passwords) {
                std::cout << _password << "\n";
            }
            break;
        }
        default: {
            std::cerr << "wrong action number!\n";
            break;
        }

    }

}

int PasswordManager::getIDbyAccountName(const std::string &_accountName) {
    for(auto user: this->accountsVector) {
        if(user.getAccountName() == _accountName) {
            return user.getAccountID();
        }
    }
    return 0;
}
