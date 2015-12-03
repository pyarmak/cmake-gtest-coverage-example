//
// Created by pavel on 12/3/15.
//

#include <sstream>
#include "gtest/gtest.h"
#include "stream_vendorio.h"

namespace {
    class StreamVendorIoTest : public testing::Test {
    protected:
        ostringstream os;
        istringstream is;
        StreamVendorIo svio = StreamVendorIo(os, is);
    };

    TEST_F(StreamVendorIoTest, PrintWelcomeMessage) {
        svio.PrintWelcomeMessage(10);
        string message = "Welcome to my C++ pop machine!\n"
           "Pop is 10 cents. Please insert any combination of nickels [n or n], dimes [d or d] "
           "or quarters [q or q]. You can also press r or r for coin return.\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintExitMessage) {
        svio.PrintExitMessage();
        string message = "Shutting down. Goodbye.\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintThankYouMessage) {
        svio.PrintThankYouMessage();
        string message = "Pop is dispensed. Thank you for you business! Please come again.\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintMoreCoinsNeeded) {
        svio.PrintMoreCoinsNeeded(40);
        string message = "Please insert 40 more cents.\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintBalance) {
        svio.PrintBalance(55);
        string message = "You have inserted a total of 55 cents.\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintChange) {
        svio.PrintChange(15, 1, 1);
        string message = "Change given: 15 cents as 1 dime(s) and 1 nickle(s).\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintUsage) {
        svio.PrintUsage("test");
        string message = "USAGE: test <price in cents>\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, PrintErrorMessage) {
        svio.PrintErrorMessage("Testing error %s", "wrapper");
        string message = "Error: Testing error wrapper.\n";
        ASSERT_EQ(message, os.str());
    }

    TEST_F(StreamVendorIoTest, GetUserInput) {
        is.str("E");
        char res = svio.GetUserInput();
        string message = "Enter coin (NDQR): ";
        ASSERT_EQ(message, os.str());
        ASSERT_EQ('E', res);
    }
} // namespace