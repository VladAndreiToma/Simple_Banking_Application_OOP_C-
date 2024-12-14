// this class aims to make by inheritance copies of the main bank account
// to overwrite the amount of cash via the 2 method withdraw/deposit

#ifndef EXAMPLE_PROJECT_SAVINGBANKACCOUNT_H
#define EXAMPLE_PROJECT_SAVINGBANKACCOUNT_H_1
#include "UserBankAccount.h"

class SaveBankAccount : public UserBankAccount{
    public:
        static double minimumBalance;
        explicit SavingBankAccount( int accountID , double money );
        bool withdraw( double money ) override;
        bool deposit( double money ) override;
}


#endif

