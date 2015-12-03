#include <iostream>
#include "simple_vendor.h"

using namespace std;

int main(int argc, char* argv[]) {
    try {
        SimpleVendor vendor(argc, argv);
        vendor.Vend();
    } catch (invalid_argument e) {
        return 1;
    }
    return 0;
}
