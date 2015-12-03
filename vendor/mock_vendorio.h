class MockVendorIo : public VendorIo {
public:
    void PrintErrorMessage(const char *err, ...) {};
    MOCK_METHOD1(PrintUsage, void(const char *name));
    MOCK_METHOD3(PrintChange, void(int balance, int dimes, int nickles));
    MOCK_METHOD0(PrintThankYouMessage, void());
    MOCK_METHOD1(PrintBalance, void(int balance));
    MOCK_METHOD1(PrintMoreCoinsNeeded, void(int amount));
    MOCK_METHOD0(GetUserInput, char());
    MOCK_METHOD1(PrintWelcomeMessage, void(int price));
    MOCK_METHOD0(PrintExitMessage, void());
};
