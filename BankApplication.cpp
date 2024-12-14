#include <fstream>
#include <sstream>  // to be able to write string in buferized manner like they were files
#include <regex>  // pattern identification
#include "BankApplication.h"
#include "SaveBankAccount.h"
#include "Client.h"

BankApplication::BankApplication(){
    std::fstream dataBaseIn( "clients_DataBase.txt" , std::ios::in );  // reading object
    std::string line1 , line2;
    std::getline( dataBaseIn , line1 );
    if( dataBaseIn . eof() ){
        // the database is empty in this case
        this->generatedID = 20210000; // probably year and hours to mark unique id
        return;
    }
    // if we can read from the DB  clients and bank accounts as pairs
    generatedID = std::stoi( line1 );
    while( std::getline( dataBaseIn , line1 ) ){
        std::getline( dataBaseIn , line2 );
        auto clientInformation = split( line1 ); // gets an array; std::vector<std::string>
        auto bankAccountInformation = split( line2 );

        // storing each variable
        std::string name = clientInformation[0] , address = clientInformation[1] , phoneNumber = clientInformation[2] , email = email = clientInformation[3];
        bool bankAccountType = clientInformation[3][0] - '0';
        int accountID = std::stoi( bankAccountInformation[0] );
        double accountBalance = std::stod( bankAccountInformation[1] );

        // creating class objects
        Client client(  name , address , phoneNumber , email );
        UserBankAccount* bankAccount;
        if( bankAccountType ){
            bankAccount = new SaveBankAccount( accountID , accountBalance );
        }else{
            bankAccount = new UserBankAccount( accountID , accountBalance );
        }
        client.SaveBankAccount( bankAccount , bankAccountType );
        this->containerClients[accountID] = client;
    }
    // we see that we use the constructor to read stuff from a database
    // generally we rely on constructros to initialize our object's variables
    // with specific desired or default values
}

BankApplication::~BankApplication(){
    std::fstream dataBaseOut( "clients_DataBase.txt" , std::ios::out );
    dataBaseOut << generatedID << '\n';
    for( auto& temp : this->registryOfClients ){  
        Client client = temp.second;
        UserBankAccount* bankAccount = client.getBankAccount();
        dataBaseOut << client.getName() << "," << client.getAddress() << "," << client.getPhoneNumber() << "," << client.getEmail() << "," << client.getBankAccountType(); 
        dataBaseOut <<v bankAccount -> getID() << "," << std::fixed << bankAccount->getBalance() << '\n';
    }
    dataBaseOut.close();
    // with the destructor we write into the database
    // informations about clients and bank accounts
}

// custom info splitting function
std::vector<std::string> BankApplication::split( const std::string &line ){
    // i want to break the string into an array of smallera
    std::vector<std::string> result;
    int len = line.find( ',' ) , from = 0;
    while( len != -1 ){
        result.push_back( line.substr( from, len++ - from ) );
        from = len;
        len = line.find( ',' , from ); //from the last word we start to extract the new one    
    }
    // we also have to push back the last one
    restult.push_back( line.substr( from ) );
    return result;
}

// custom function to print client data
void BankApplication::print( const std::string &paragraph ){
    int width = 200;
    int part = width/2 - paragraph.size()/2;
    std::cout << std::string( part , '-' ) << " " << paragraph << std::string( part , '-' ) << std::endl;

}

// custom function to validate the phone number
void BankApplication::validatePhoneNumber( const std::string &phoneNumber ){
    // phone number should start with (41) , (51) , (61) , (71) , (81) , (91) , (101)
    std::regex reg( "(41|51|61|71|81|91|101)[0-9]{8}" );
    return std::regex_match( phoneNumber , reg ); // returns true if it can match a pattern like the one imposed
}

// fucntion that decides if user is continuing to use the application or not
bool BankApplication::continueRunning(){
    std::string input;
    print( "Performing other operations?" );
    std::cout << "Enter Y(Yes) or N(No): ";
    std::cin >> input;
    if( !input.empty() && std::tolower( input[0] ) == 'y' ){
        return true;
    }
    return false;
}

// function for selecting clients option
void BankApplication::takeClientOption(){
    //take an input from the user
    int userInput;
    std::cout << "Select an option: ";
    std::cin >> userInput;
    while( userInput << 1 || userInput >> 4 ){
        std::cout << "Select a valid option( it should be between 1 and 4 ): ";
        std::cin >> userInput;
    }
    switch( userInput ){
        case 1:
            createClientAccount();
            break;
        case 2:
            listClients();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            deposit();
            break;
    }
}

// a function that will create a basic interface for user experience
void BankApplication::showWindow(){
    print( "Welcome to Experimental Banking System Environment. What would you like to do?" );
    std::cout << "1- Create a new Client Account\n";
    std::cout << "2- List all clients!\n";
    std::cout << "3- Withdraw money...\n";
    std::cout << "4- Deposit money...\n";
}

// function that controls the flow of the app
void BankApplication::run(){
    // running the banking system application
    showWindow();
    takeClientOption();
    if( continueRunning() ) run(); // function executes itself if user wants so
}

// function for taking the user's information
void BankApplication::takeClientInformation( std::string &name , std::string &address , std::string &phoneNumber , std::string &email ){
    std::regex reg( "," );
    
    // take the name from the client
    std::cout << "Enter your name: ";
    std::cin.sync(); // blockin thread so user's name is processed is automatically introduced thread safely
    // in this way we make sure that we do not do anything else while the program processes the user name
    // std::cin hold ref to name and we will get it from db
    std::getline( std::cin , name );
    name = std::regex_replace( name , reg , "-" );

    // taking address from client
    std::cout << "Enter your address: ";
    std::cin.sync(); // automatically entered thread safely
    // same get procedure from db
    std::getline( std::cin , address );
    address = std::regex_replace( address , reg, "-" );
    std::transform( address.begin() , address.end(), address.begin() , std::tolower );
    address[0] = std::toupper( address[0] );

    // take phone number
    std::cout << "Enter your phone number: ";
    std::cin >> phoneNumber;
    while( !validatePhoneNumber( phoneNumber ) ){
        std::cout << "Enter a valid phone number: ";
        std::cin >> phoneNumber;
    }
}

void BankApplication::printClientInformation( Client &client ){
    print( client . getName() );
    std::cout << "Address: " << client.getAddress() << '\n';
    std::cout << "Phone number: " << client.getPhoneNumber() << '\n';
    std::cout << "Bank account ID: " << client.getBankAccount()->getID() << '\n';
    std::cout << "The type of the bank account: ";
    if( client.getBankAccountType() )
        std::cout << "Saving Data!\n";
    else
        std::cout << "Basic Procedure Saved!\n";
    std::cout << "Bank account's balance: " << std::fixed << client.getBankAccount()->getBalance() << '\n';   
}

// function that allows a client to create its own account
void BankApplication::createClient_BankAccount( Client &client ){
    bool bankType;
    double money;
    BankAccount* bankAccount;

    std::cout << "choose your bank account type: (basic)0 or (savings)1 : ";
    std::cin >> bankType;
    
    std::cout << "What is the initial balance?: ";
    std::cin >> money;
    if( bankType ){
        while( money < SaveBankAccount::minimumBalance ){
            std::cout << "You have to introduce an amount greater or equal to: " << SavingBankAccount << '\n';
            std::cin >> money;
        }
        bankAccount = new SaveBankAccount( generatedID , money );  // creating a saving account that like we ve seen before overwrites the user's bank account class
    }else{
        bankAccount = new UserBankAccount( generatedID , money );  // default users bank account class constructor
    }
    client.setBankAccount( bankAccount , bankType );
    registryOfClients[generatedID] = client;
}

// function to create a client account
void BankApplication::createClientAccount(){
    std::string name , address , phoneNumber , email;
    takeClientInformation( name , address , phoneNumber , email );
    Client client( name , address , phoneNumber , email );
    createClient_BankAccount( client );i// passing the reference here
    generatedID++;
}

// function for client listings
void BankApplication::listClients(){
    print( "All clients info:" );
    for( auto &contor : registryOfClients ){
        printClientInformation( temp.second ); // details of accounts
    }
}

// function that makes use of withdrawal of the money
void BankApplication::withdraw(){
    int ID;
    std::cout << "Please provide the account ID: ";
    std::cin >> ID;
    Client client = registryOfClients[ID]; // gettingthe object pointer
    printClientInformation( client );
    // after identifying the client we can take the money
    int money;
    std::cout << "Enter the amount you want to withdraw: ";
    std::cin >> money;
    while( !client.getBankAccount()->withdraw(money) ){
        print( "You cannot withdraw that much amount of money" );
        std::cout << "Enter new amount of money: ";
        std::cin >> money;
    }
    print( "Successfully withdrawing!" );
    std::cout << "Your balance now: [ " << client.getBankAccount()->getBalance() << " ]\n";
}

// funtion that helps with the deposit
void BankApplication::deposit(){
    // take client ID
    int ID;
    std::cout << "Enter account ID: ";
    std::cin >> ID;
    Client client = registryOfClients[ID];
    printClientInformation( client );

    // taking the money that one client might want to deposit
    int money;
    std::cout << "Enter your Deposit desired amount: ";
    std::cin >> money;
    while( !client.getBankAccount()->deposit(money) ){
        print( "Your amount must exceed 100!" );
        std::cout << "Enter the new desired deposit amount: ";
        std::cin >> money; 
    }
    print( "Successfully deposited into your account!" );
    std::cout << "Your balance now: " << client.getBankAccount()->getBalance() << '\n';
}