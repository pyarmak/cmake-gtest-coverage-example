//
// Created by pavel on 12/2/15.
//

#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include "stream_vendorio.h"

/**
 * a wrapper that prefixes formatted output with the string "ERROR: "
 */
void StreamVendorIo::PrintErrorMessage(const char *fmt, ...) {
    va_list args;
    char *formatted;
    va_start(args, fmt);
    vasprintf(&formatted, fmt, args);
    os << "Error: " << formatted << "." << endl;
    va_end(args);
}

void StreamVendorIo::PrintUsage(const char *name) {
    os << "USAGE: " << name << " <price in cents>" << endl;
}

void StreamVendorIo::PrintChange(int balance, int dimes, int nickles) {
    os << "Change given: " << balance << " cents as " << dimes << " dime(s) and " << nickles << " nickle(s)." << endl;
}

char StreamVendorIo::GetUserInput() {
    char input;
    os << "Enter coin (NDQR): ";
    is >> input;
    return input;
}

void StreamVendorIo::PrintBalance(int balance) {
    os << "You have inserted a total of " << balance << " cents." << endl;
}

void StreamVendorIo::PrintMoreCoinsNeeded(int amount) {
    os << "Please insert " << amount << " more cents." << endl;
}

void StreamVendorIo::PrintThankYouMessage() {
    os << "Pop is dispensed. Thank you for you business! Please come again." << endl;
}

void StreamVendorIo::PrintExitMessage() {
    os << "Shutting down. Goodbye." << endl;
}

void StreamVendorIo::PrintWelcomeMessage(int price) {
    os << "Welcome to my C++ pop machine!" << endl <<
           "Pop is " << price << " cents. Please insert any combination of nickels [n or n], dimes [d or d] "
           "or quarters [q or q]. You can also press r or r for coin return." << endl;
}
