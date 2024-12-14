#ifndef EXAMPLE_PROJECT_BANKAPPLICATION_H
#define EXAMPLE_PROJECT_BANKAPPLICATION_H_1
#include <iostream>
#include <vector>
#include <map>
#include "Client.h"
// we need to be able to form client instances
#include "BankAccount.h"


class BankApplication{
    int generatedID;
    std::map<int , Client> registryOfClients; // mmaping here clients and their given tag its like an array of pairs
    void showWindow();
    std::vector<std::string> split( const std::string& line ); // at reading it splits the data into content --> making it an array of content
    bool continueRunning();
    void takeClientOption();
    void print( const std::string& paragraph );
    void takeClientInformation( std::string& name , std::string& address , std::string& phoneNumber , std::string& email );
    void createClientBankAccount( Client& client );
    void printClientInformation( Client& client );
    bool validatePhoneNumber( const std::string&  phoneNumber );
    bool validateEmail( const std::string& email );

    public:
        BankApplication(); // constructor
        ~BankApplication(); // destructor
        void createClientAccount();
        void listClients();
        void withdraw();
        void deposit();
        void run();
};

#endif