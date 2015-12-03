//
// Created by pavel on 12/2/15.
//

#ifndef POP_STREAMVENDORIO_H
#define POP_STREAMVENDORIO_H

#include <iostream>
#include "vendorio.h"

using namespace std;

class StreamVendorIo : public VendorIo {
    ostream &os;
    istream &is;
public:
    StreamVendorIo() : os(cout), is(cin) {}
    StreamVendorIo(ostream& o, istream &i) : os(o), is(i) {}
    void PrintErrorMessage(const char* err, ...);
    void PrintUsage(const char *name);
    void PrintChange(int balance, int dimes, int nickles);
    void PrintThankYouMessage();
    void PrintMoreCoinsNeeded(int amount);
    void PrintBalance(int balance);
    void PrintWelcomeMessage(int price);
    void PrintExitMessage();
    char GetUserInput();
};


#endif //POP_STREAMVENDORIO_H
