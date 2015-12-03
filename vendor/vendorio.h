//
// Created by pavel on 12/2/15.
//

#ifndef POP_VENDORIO_H
#define POP_VENDORIO_H


class VendorIo {
public:
    virtual void PrintErrorMessage(const char* err, ...) = 0;
    virtual void PrintUsage(const char *name) = 0;
    virtual void PrintChange(int balance, int dimes, int nickles) = 0;
    virtual void PrintBalance(int balance) = 0;
    virtual void PrintThankYouMessage() = 0;
    virtual void PrintMoreCoinsNeeded(int amount) = 0;
    virtual void PrintWelcomeMessage(int price) = 0;
    virtual void PrintExitMessage() = 0;
    virtual char GetUserInput() = 0;
};


#endif //POP_VENDORIO_H
