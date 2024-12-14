// class client
// allows a user to create an instance with personal data and contact

#include "Client.h"

Client::Client(  std::string& name , std::string& address , std::string& phoneNumber , std::string& email ){
    // contextual attribution
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->email = email;
}

// setting the bankAccount
void Client::setBankAccount( UserBankAccount* &account , bool type ){
    this->bankAccount = account;
    this->bankAccountType = type;
}

// getting info: _name
std::string Client::getName(){
    return this->name;
}

std::string Client::getAddress(){
    return this->address;
}

std::string Client::getPhoneNumber(){
    return this->phoneNumber;
}

std::string Client::getEmail(){
    return this->email;
}

UserBankAccount* Client::getBankAccount(){
    return this->bankAccount;
}

bool Client::getBankAccountType(){
    return this->bankAccountType;
}

#endif