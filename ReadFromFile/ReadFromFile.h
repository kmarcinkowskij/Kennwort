//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_READFROMFILE_H
#define PASSWORDMANAGER_READFROMFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <map>
#include "../Account/Account.h"
#include "../Password/Password.h"
#include "../MasterAccount/MasterAccount.h"


class ReadFromFile {
private:
    std::ifstream _storageFile;

    ReadFromFile& operator = (const ReadFromFile&);
public:
    ReadFromFile() : _storageFile() {};

    static bool checkMasterAccount();
    std::vector<Account> readAccounts();
    std::vector<Password> readPasswords();
    std::vector<std::tuple<int, int>> readConnectedIDs();
    MasterAccount readMasterAccount();

    int lastID();

    ReadFromFile(const ReadFromFile&){};
};


#endif //PASSWORDMANAGER_READFROMFILE_H
