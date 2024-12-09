#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::std::string;
using ::testing::Return;
using ::testing::Eq;

// Abstract interface for a simple calculator
class Calculator {
public:
    virtual ~Calculator() = default;
    virtual int add(int a, int b) = 0; // Pure virtual method
};

// Mock class implementing Calculator
class MockCalculator : public Calculator {
public:
    MOCK_METHOD(int, add, (int a, int b), (override)); // Mocked add method
};

TEST(MockClassDemo, BasicMockTest) {
    MockCalculator mock;

    // Set expectation: add(5, 3) should be called once and return 8
    EXPECT_CALL(mock, add(5, 3))
        .WillOnce(Return(8));

    // Invoke the mock method
    int result = mock.add(5, 3);

    // Verify that the result matches the mocked behavior
    ASSERT_EQ(result, 8);
}
