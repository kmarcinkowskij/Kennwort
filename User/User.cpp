//
// Created by konrad on 4/24/24.
//

#include "User.h"

#include <utility>

void User::setUsername(const std::string &_username) {
    this->username = _username;
}

void User::setUserID(const int &_userID) {
    this->userID = _userID;
}

std::string User::getUsername() const {
    return this->username;
}

int User::getUserID() const {
    return this->userID;
}

User::User(std::string _username, int _userID): username(std::move(_username)), userID(_userID) {

}
