// this is the main function
// it aims to launch the application
// that is to make sure we call all the constructors out there and start
// the continuing function that is run()

# include <iostream>
#include "Bankapplication.h"
int main(){
    BankApplication app; // object creation
    app.run();
}

// running the application no return so we keep the loop open
// but one can introduce keyboard interruption