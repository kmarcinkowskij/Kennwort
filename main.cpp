#include <iostream>
#include "Password/Password.h"
#include "PasswordManager/PasswordManager.h"
#include "User/User.h"
#include "ReadFromFile/ReadFromFile.h"


int main() {
    auto *theManager = new PasswordManager();

    theManager->createNewPair();
    return 0;
}
