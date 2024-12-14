#ifndef EXAMPLE_PROJECT_CLIENT_H
#define EXAMPLE_PROJECT_CLIENT_H_1
#include <iostream>
#include "BankAccount.h"
#include <vector>


class Client{
    private:
        std::string name , address , phoneNumber , email;
        // user can open multiple bank accounts of different types
        UserBankAccount* bankAccount{};
        bool bankAccountType{};
    public:
        Client ()= default;  // constructor is intended to behave as default
        // its there its not missing it just assigns user s parameters to the class variables
        Client( std::string& name , std::string& address , std::string& phoneNumber , std::string& email );
        void setBankAccount( UserBankAccount* &account , bool type );
        std::string getName();
        std::string getAddress();
        std::string getPhoneNumber();
        std::string getEmail();
        bool getBankAccountType();
        UserBankAccount* getBankAccount();
}

#endif