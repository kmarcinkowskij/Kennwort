//
// Created by konrad on 4/24/24.
//

#ifndef PASSWORDMANAGER_WRITETOFILE_H
#define PASSWORDMANAGER_WRITETOFILE_H

#include <fstream>
#include <iostream>
#include "../Password/Password.h"
#include "../Account/Account.h"

class WriteToFile {
private:
   std::ofstream _storageFile;

    WriteToFile& operator = (const WriteToFile&);
public:
    WriteToFile() : _storageFile() {};

    void saveTupleToFile(std::tuple<int,int> connectedIDs);
    void savePasswordToFile(const Password& _password);
    void saveAccountToFile(const Account& _user);

    WriteToFile(const WriteToFile&){};
};


#endif //PASSWORDMANAGER_WRITETOFILE_H
