//
// Created by pavel on 12/1/15.
//

#include "simple_vendor.h"

#define PRICE_MIN 5
#define PRICE_MAX 105
#define SMALLEST_COIN_VALUE 5
#define VALUE_NICKLE 5
#define VALUE_DIME 10
#define VALUE_QUARTER 25

SimpleVendor::SimpleVendor(int argc, char **argv, VendorIo *io) : vio(io), Vendor(argc, argv) {
    if (GetPrice() == 0 || !ValidatePrice()) {
        vio->PrintUsage(argv[0]);
        throw invalid_argument("invalid price");
    }
    vio->PrintWelcomeMessage(GetPrice());
}

/**
 * makes sure the price is between PRICE_MIN and PRICE_MAX as well as a multiple of SMALLEST_COIN_VALUE
 * @return false if fail validation, true if pass
 */
bool SimpleVendor::ValidatePrice() {
    if (GetPrice() < PRICE_MIN || GetPrice() > PRICE_MAX) {
        vio->PrintErrorMessage("Price must be from %d to %d cents inclusive", PRICE_MIN, PRICE_MAX);
        return false;
    } else if (GetPrice() % SMALLEST_COIN_VALUE != 0) {
        vio->PrintErrorMessage("Price must be a multiple of %d", SMALLEST_COIN_VALUE);
        return false;
    }
    return true;

}

void SimpleVendor::DispenseChange() {
    int pending = GetBalance(), nickles = 0;

    if (pending & 1) { // checks if the amount pending is odd, i.e. we need to dispense a nickle
        nickles++;
        pending -= VALUE_NICKLE;
    }

    vio->PrintChange(GetBalance(), pending / VALUE_DIME, nickles);
    SetBalance(0);
}

bool SimpleVendor::ProcessUserInput() {
    switch (vio->GetUserInput()) {
        case 'n':
        case 'N':
            SetBalance(GetBalance() + VALUE_NICKLE);
            break;
        case 'd':
        case 'D':
            SetBalance(GetBalance() + VALUE_DIME);
            break;
        case 'q':
        case 'Q':
            SetBalance(GetBalance() + VALUE_QUARTER);
            break;
        case 'e':
        case 'E':
            DispenseChange();
            vio->PrintExitMessage();
            return false;
        case 'r':
        case 'R':
            DispenseChange();
            break;
        default:
            vio->PrintErrorMessage("Unknown coin - rejected");
    }
    return true;
}

void SimpleVendor::Vend() {
    if (!ProcessUserInput()) return; // if user wants to quit, break out of our recursion
    vio->PrintBalance(GetBalance());
    if (GetBalance() >= GetPrice()) {
        SetBalance(GetBalance() - GetPrice());
        vio->PrintThankYouMessage();
        DispenseChange();
    } else vio->PrintMoreCoinsNeeded(GetPrice() - GetBalance());
    return Vend(); // recursive call
}

