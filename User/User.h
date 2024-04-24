//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_USER_H
#define PASSWORDMANAGER_USER_H
#include <iostream>
#include <string>
#include <vector>

class User {
private:
    std::string username;
    int userID;
public:
    User(std::string _username, int _userID);
    void setUsername(const std::string& _username);
    void setUserID(const int& _userID);
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] int getUserID() const;
};


#endif //PASSWORDMANAGER_USER_H
