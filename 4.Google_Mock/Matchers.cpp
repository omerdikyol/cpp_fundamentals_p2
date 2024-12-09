#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::std::string;
using namespace ::testing;

class MockProcessor {
public:
    MOCK_METHOD(void, process, (int value), ());
    MOCK_METHOD(void, processString, (const std::string& value), ());
};

TEST(MatcherDemo, UsingMatchers) {
    MockProcessor mock;

    // Matchers to validate arguments passed to mock methods
    EXPECT_CALL(mock, process(Gt(0))); // Expects value > 0
    EXPECT_CALL(mock, processString(StrEq("existing movie"))); // Expects string equal to "existing movie"
    EXPECT_CALL(mock, processString(StrNe("non-existing movie"))); // Expects string not equal to "non-existing movie"
    EXPECT_CALL(mock, processString(StrCaseEq("EXISTING MOVIE"))); // Expects string case-insensitive equal to "EXISTING MOVIE"
    EXPECT_CALL(mock, processString(HasSubstr("movie"))); // Expects string containing "movie"
    EXPECT_CALL(mock, processString(StartsWith("exist"))); // Expects string starting with "exist"
    EXPECT_CALL(mock, processString(EndsWith("movie"))); // Expects string ending with "movie"
    EXPECT_CALL(mock, processString(ContainsRegex(".*movie.*"))); // Expects string containing regex pattern ".*movie.*"
    EXPECT_CALL(mock, processString(MatchesRegex(".*movie"))); // Expects string matching regex pattern ".*movie"
    EXPECT_CALL(mock, process(Ge(5))); // Expects value >= 5
    EXPECT_CALL(mock, process(Ref(5))); // Expects reference to value 5
    EXPECT_CALL(mock, process(An<int>())); // Expects an integer
    EXPECT_CALL(mock, process(TypedEq<int>(5))); // Expects integer equal to 5
    EXPECT_CALL(mock, process(AllOf(Ge(5), Le(10)))); // Expects value >= 5 and <= 10
    EXPECT_CALL(mock, process(AnyOf(Eq(5), Eq(10)))); // Expects value equal to 5 or 10
    EXPECT_CALL(mock, process(Not(Eq(5)))); // Expects value not equal to 5

    // Call the methods with valid arguments
    mock.process(10); // Passes because 10 > 0
    mock.processString("existing movie"); // Passes because string equals "existing movie"
    mock.processString("EXISTING MOVIE"); // Passes because string case-insensitive equals "EXISTING MOVIE"
    mock.processString("this is a movie"); // Passes because string contains "movie"
    mock.processString("existing movie"); // Passes because string starts with "exist" and ends with "movie"
    mock.process(7); // Passes because 7 >= 5 and <= 10
    mock.process(10); // Passes because 10 is one of the expected values
    mock.process(6); // Passes because 6 is not equal to 5
}