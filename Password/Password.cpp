//
// Created by konrad on 4/24/24.
//

#include "Password.h"

#include <utility>

void Password::setPassword(std::string newPassword) {
    this->passwordUnhashed = std::move(newPassword);
}

std::string Password::getPassword() const {
    return this->passwordUnhashed;
}

int Password::getID() const {
    return this->passwordID;
}

void Password::setID(int newID) {
    this->passwordID = newID;
}

Password::Password(std::string _passwordUnhashed, int _passwordID) : passwordUnhashed(std::move(_passwordUnhashed)), passwordID(_passwordID) {}
