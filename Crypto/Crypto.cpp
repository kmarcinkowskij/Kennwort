//
// Created by konrad on 5/17/24.
//

#include "Crypto.h"

#include <utility>


std::size_t Crypto::encryptPassword(const std::string &_password) {
    std::string _unhashed = _password;
    size_t _hashed = this->hasher(_unhashed);
    return _hashed;
}

void Crypto::encryptFile(const std::string& _key, const char* _filename, const char* _newFilename) {
    char character;
    std::fstream fin, fout;
    int key = saltToKey(_key);
    fin.open(_filename, std::fstream::in);
    fout.open(_newFilename, std::fstream::out);

    while(fin >> std::noskipws >> character) {
        int temp = (character + key);

        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

void Crypto::decryptFile(const std::string &_key, const char *_filename, const char* _newFilename) {
    char character;
    std::fstream fin, fout;
    int key = saltToKey(_key);
    fin.open(_filename, std::fstream::in);
    fout.open(_newFilename, std::fstream::out);

    while(fin >> std::noskipws >> character) {
        int temp = (character - key);

        fout << (char)temp;
    }

    fin.close();
    fout.close();
}




int Crypto::saltToKey(const std::string& _salt) {
    std::string salt;
    for(char character: _salt) {
        if(std::isalpha(character)) {
            if(tolower(character)) {
                int temp = character % '0';
                std::string toAdd = std::to_string(temp);
                salt += toAdd;
            }
        } else if (std::isalnum(character)) {
            salt += (char)character;
        }

    }


    return std::stoi(salt);

}

