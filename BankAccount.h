/*
class definition of UserBankAccount
holds the following information:
    - account ID of user and the balance that the user has
    - method of money withdrawal
    - method of money deposit
*/

#ifndef EXAMPLE_PROJECT_BANKACCOUNT_H
#define EXAMPLE_PROJECT_BANKACCOUNT_H_1
#include <iostream>

class UserBankAccount{
    protected:
        // i can see within class's 
        int accountID;
        double balance;
    public: 
        explicit UserBankAccount( int accountID );
        explicit UserBankAccount( int accountID , double balance );
        int getID();       // an integer number within the banking system
        double getBalance();       // the amount of money can be .smth
        virtual bool withdraw( double money );
        virtual bool deposit( double money );
        // virtual allows for different future implementations
};

#endif
