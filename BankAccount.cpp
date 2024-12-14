// this code aims to produce the basic structure of the users bank account
// features: using camel case s rule 
//           "this" refers to the context of an eventual object instantiation of this class
// a constructor with no money it will set the user's balance to 0
UserBankAccount::UserBankAccount( int accountID ){
    this->accountID = accountID;
    balance = 0;
}

// constructor with money allocation & user's id
UserBankAccount::UserBankAccount( int accountID , double balance ){
    this->accountID = accountID;
    this->balance = balance;
}

// prepare a method to return user's id
int UserBankAccount::getID(){
    return this->accountID;
}

// prepare a method to extract balance
double UserBankAccount::getBalance(){
    return this->balance;
}

// prepare a function to withdraw some money
bool UserBankAccount::withdraw( double money ){
    // if the amount is in range
    if( balance - money < 0 ){
        return false;
    }
    balance -= money;
    return true; // indicate function executed successfully 
}

// prepare a function to deposit some money
bool UserBankAccount::deposit( double money ){
    balance += money;
    return true; // indicate function executed successfully
}

