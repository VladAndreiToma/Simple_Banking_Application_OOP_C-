cmake_minimum_required(VERSION 3.23)
project(Simple_Banking_App_Project)
set(CMAKE_CXX_STANDARD 20)
add_executable(
    Simple_Banking_App_Project
    main.cpp
    BankAccount.cpp
    BankAccount.h
    Client.cpp
    Client.h
    BankApplication.cpp
    BankApplication.h
    SaveBankAccount.cpp
    SaveBankAccount.h
)