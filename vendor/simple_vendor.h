//
// Created by pavel on 12/1/15.
//

#ifndef POP_SIMPLE_VENDOR_H
#define POP_SIMPLE_VENDOR_H

#include <iostream>
#include "vendor.h"
#include "stream_vendorio.h"

using namespace std;

class SimpleVendor : public Vendor {
    void DispenseChange();
    bool ProcessUserInput();
    bool ValidatePrice();
    VendorIo *vio;
public:
    SimpleVendor(int argc, char* argv[], VendorIo *io = new StreamVendorIo());
    void Vend();
};


#endif //POP_SIMPLE_VENDOR_H
