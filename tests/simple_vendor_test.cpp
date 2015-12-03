#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "simple_vendor.h"
#include "mock_vendorio.h"

using ::testing::Return;
using ::testing::Eq;

namespace {
    class SimpleVendorTest : public ::testing::Test {
    protected:
        MockVendorIo mvio;
        VendorIo *vio = &mvio;
        char price[3] = "35";
        char *argv[2] = {(char *) "void", price};
        SimpleVendor vendor = SimpleVendor(2, argv, vio);
    };

    TEST_F(SimpleVendorTest, Constructor) {
        ASSERT_EQ(35, vendor.GetPrice());
        ASSERT_EQ(0, vendor.GetBalance());
    }

    TEST_F(SimpleVendorTest, SetBalance) {
        vendor.SetBalance(45);
        ASSERT_EQ(45, vendor.GetBalance());
    }

    TEST_F(SimpleVendorTest, ConstructorFail) {
        EXPECT_CALL(mvio, PrintUsage("void")).Times(3);
        argv[1] = (char *) "0";
        ASSERT_THROW(SimpleVendor(2, argv, vio), std::invalid_argument);
        argv[1] = (char *) "555";
        ASSERT_THROW(SimpleVendor(2, argv, vio), std::invalid_argument);
        argv[1] = (char *) "66";
        ASSERT_THROW(SimpleVendor(2, argv, vio), std::invalid_argument);
    }

    TEST_F(SimpleVendorTest, Vend) {
        EXPECT_CALL(mvio, GetUserInput())
                .Times(6)
                .WillOnce(Return('N'))
                .WillOnce(Return('R'))
                .WillOnce(Return('Z'))
                .WillOnce(Return('D'))
                .WillOnce(Return('Q'))
                .WillOnce(Return('E'));
        EXPECT_CALL(mvio, PrintMoreCoinsNeeded(Eq(30)));
        EXPECT_CALL(mvio, PrintMoreCoinsNeeded(Eq(25)));
        EXPECT_CALL(mvio, PrintMoreCoinsNeeded(Eq(35))).Times(2);
        EXPECT_CALL(mvio, PrintThankYouMessage());
        EXPECT_CALL(mvio, PrintBalance(Eq(0))).Times(2);
        EXPECT_CALL(mvio, PrintBalance(Eq(5)));
        EXPECT_CALL(mvio, PrintBalance(Eq(10)));
        EXPECT_CALL(mvio, PrintBalance(Eq(35)));
        EXPECT_CALL(mvio, PrintChange(Eq(5), Eq(0), Eq(1)));
        EXPECT_CALL(mvio, PrintChange(Eq(0), Eq(0), Eq(0))).Times(2);
        vendor.Vend();
    }
}  // namespace
