cmake_minimum_required(VERSION 3.23)
project(SecurePassGen)

set(CMAKE_CXX_STANDARD 14)



add_executable(SecurePassGen
        src/main.cpp
        src/PasswordGenerator.cpp
        src/CharacterPool.cpp
        src/CharacterPool.cpp

        src/CharacterPool.h
        src/mainwindow.h
        src/PasswordGenerator.h)