cmake_minimum_required(VERSION 3.27)
project(passwordManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(passwordManager main.cpp
        Password/Password.cpp
        Password/Password.h
        User/User.cpp
        User/User.h
        PasswordManager/PasswordManager.cpp
        PasswordManager/PasswordManager.h
        WriteToFile/WriteToFile.cpp
        WriteToFile/WriteToFile.h
        ReadFromFile/ReadFromFile.cpp
        ReadFromFile/ReadFromFile.h)
