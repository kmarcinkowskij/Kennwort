#include <iostream>
#include "Password/Password.h"
#include "PasswordManager/PasswordManager.h"
#include "Account/Account.h"
#include "ReadFromFile/ReadFromFile.h"
#include "MasterAccount/MasterAccount.h"
#include "Crypto/Crypto.h"


int main() {
    auto *read = new ReadFromFile();
    auto *masterAccount = new MasterAccount();

    if(!ReadFromFile::checkMasterAccount()) {
        std::cout << "no master account found!\n";
        masterAccount->createUser();
        return 0;
    }

    *masterAccount = read->readMasterAccount();
    std::cout << "welcome back!";
    auto *crp = new Crypto;
//    crp->encryptFile(masterAccount->getPassSalt(), "PasswordsStorageFile.txt");

    MasterAccount::authenticated = masterAccount->authenticateUser();



    if(MasterAccount::authenticated) {
        crp->decryptFile(masterAccount->getPassSalt(), "PasswordsStorageFileEnc.txt", "passwordsTempDecrypted.txt");
        auto *theManager = new PasswordManager();
        theManager->Menu();
    }
    crp->encryptFile(masterAccount->getPassSalt(), "passwordsTempDecrypted.txt", "PasswordsStorageFileEnc.txt");
    remove("passwordsTempDecrypted.txt");


    return 0;
}
