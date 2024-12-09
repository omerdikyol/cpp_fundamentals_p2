#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::std::string;
using ::testing::Matcher;
using ::testing::MatchResultListener;
using ::testing::Not;

// Define a custom matcher to validate even numbers
MATCHER(IsEven, "Checks if the number is even") {
    return arg % 2 == 0;
}

TEST(CustomMatcherDemo, ValidateEvenNumbers) {
    EXPECT_THAT(4, IsEven());      // Passes: 4 is even
    EXPECT_THAT(5, IsEven()); // Passes: 5 is not even
}
