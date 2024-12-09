#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::std::string;
using ::testing::Sequence;

// Task manager interface
class TaskManager {
public:
    virtual ~TaskManager() = default;
    virtual void startTask() = 0;
    virtual void endTask() = 0;
};

// Mock class for TaskManager
class MockTaskManager : public TaskManager {
public:
    MOCK_METHOD(void, startTask, (), (override));
    MOCK_METHOD(void, endTask, (), (override));
};

TEST(SequenceDemo, OrderedMethodCalls) {
    MockTaskManager mock;

    // Define a sequence to enforce call order
    Sequence sequence;

    // Set ordered expectations
    EXPECT_CALL(mock, startTask()).InSequence(sequence);
    EXPECT_CALL(mock, endTask()).InSequence(sequence);

    // Call methods in the correct order
    mock.startTask();
    mock.endTask();

    // Verify that the calls were made in the correct order
    ::testing::Mock::VerifyAndClearExpectations(&mock);
}
