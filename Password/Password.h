//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_PASSWORD_H
#define PASSWORDMANAGER_PASSWORD_H

#include <iostream>
#include <string>
#include <utility>

class Password {
private:
    std::string passwordUnhashed;
    int passwordID;
public:
    //Constructor
    explicit Password(std::string passwordUnhashed, int passwordID);

    void setPassword(std::string newPassword);

    void setID(int newID);

    [[nodiscard]] std::string getPassword() const;

    [[nodiscard]] int getID() const;

};


#endif //PASSWORDMANAGER_PASSWORD_H
