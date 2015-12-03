//
// Created by pavel on 12/2/15.
//

#ifndef POP_VENDOR_H
#define POP_VENDOR_H

#include <stdlib.h>

class Vendor {
    const int kPrice;
    int balance_;

protected:
    Vendor(int argc, char* argv[]) : kPrice((argc == 2) ? atoi(argv[1]) : 0) { SetBalance(0); };
    virtual bool ValidatePrice() = 0;

public:
    const int GetPrice() { return kPrice; };
    int GetBalance() { return balance_; };
    void SetBalance(int balance) { balance_ = balance; };
    virtual void Vend() = 0;
};
#endif //POP_VENDOR_H
