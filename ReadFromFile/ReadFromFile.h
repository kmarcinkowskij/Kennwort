//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_READFROMFILE_H
#define PASSWORDMANAGER_READFROMFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "../User/User.h"
#include "../Password/Password.h"


class ReadFromFile {
private:
    std::ifstream _storageFile;

    ReadFromFile& operator = (const ReadFromFile&);
public:
    ReadFromFile() : _storageFile() {};

    std::vector<User> readUsers();
    std::vector<Password> readPasswords();
    std::vector<std::tuple<int, int>> readConnectedIDs();

    int lastID();

    ReadFromFile(const ReadFromFile&){};
};


#endif //PASSWORDMANAGER_READFROMFILE_H
