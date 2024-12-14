#include "SaveBankAccount.h"
using namespace std;

// constructor
SaveBankAccount::SaveBankAccount( int accountID , double money ):UserBankAccount(accountID){
    balance = money;
}

// overwriting withdrawal function
bool SaveBankAccount::withdraw( double money ){
    if( balance - money < minimumBalance ){
        return false;
    }
    balance -= money;
    return true;
}

// overwriting deposit function
bool SaveBankAccount::deposit( double money ){
    // minimum ammount one can deposit is 100
    if( money < 100 ){
        return false;
    }
    balance += money;
    return true;
}

// minimum balance the account must have all the time is 1000
double SaveBankAccount::minimumBalance = 1000;