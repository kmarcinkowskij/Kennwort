#include <iostream>
#include "Password/Password.h"
#include "PasswordManager/PasswordManager.h"
#include "Account/Account.h"
#include "ReadFromFile/ReadFromFile.h"


int main() {
    std::cout << ReadFromFile::checkMasterAccount() << "\n";
    if(!ReadFromFile::checkMasterAccount()) {
        std::cout << "no master account found!";
        return 0;
    }
    auto *theManager = new PasswordManager();
    theManager->Menu();
    return 0;
}
