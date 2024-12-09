#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::std::string;
using ::std::shared_ptr;
using ::testing::Return;
using ::testing::AtLeast;
using ::testing::Sequence;

// **Interface Definitions**
// Service interface to fetch user data
class UserService {
public:
    virtual ~UserService() = default;
    virtual string fetchUserName(int userId) = 0;
    virtual int fetchUserAge(int userId) = 0;
};

// Notification interface
class NotificationService {
public:
    virtual ~NotificationService() = default;
    virtual void sendNotification(const string& message) = 0;
};

// **Mock Definitions**
class MockUserService : public UserService {
public:
    MOCK_METHOD(string, fetchUserName, (int userId), (override));
    MOCK_METHOD(int, fetchUserAge, (int userId), (override));
};

class MockNotificationService : public NotificationService {
public:
    MOCK_METHOD(void, sendNotification, (const string& message), (override));
};

// **System Under Test (SUT)**
class UserProfile {
    UserService& userService;
    NotificationService& notificationService;

public:
    UserProfile(UserService& userService, NotificationService& notificationService)
        : userService(userService), notificationService(notificationService) {}

    string getUserDetails(int userId) {
        string name = userService.fetchUserName(userId);
        int age = userService.fetchUserAge(userId);

        if (age < 0) {
            notificationService.sendNotification("Invalid user age!");
            return "Error: Invalid user age";
        }

        return name + ", Age: " + std::to_string(age);
    }
};

// **Tests**
TEST(UserProfileTest, ValidUserDetails) {
    MockUserService mockUserService;
    MockNotificationService mockNotificationService;

    // Expectations for UserService
    EXPECT_CALL(mockUserService, fetchUserName(1))
        .WillOnce(Return("Alice"));
    EXPECT_CALL(mockUserService, fetchUserAge(1))
        .WillOnce(Return(30));

    // No notification is expected for valid user
    EXPECT_CALL(mockNotificationService, sendNotification(::testing::_)).Times(0);

    // System Under Test
    UserProfile userProfile(mockUserService, mockNotificationService);
    string result = userProfile.getUserDetails(1);

    // Verify the result
    ASSERT_EQ(result, "Alice, Age: 30");
}

TEST(UserProfileTest, InvalidUserAgeTriggersNotification) {
    MockUserService mockUserService;
    MockNotificationService mockNotificationService;

    // Expectations for UserService
    EXPECT_CALL(mockUserService, fetchUserName(2))
        .WillOnce(Return("Bob"));
    EXPECT_CALL(mockUserService, fetchUserAge(2))
        .WillOnce(Return(-1)); // Invalid age

    // Expect a notification for invalid age
    EXPECT_CALL(mockNotificationService, sendNotification("Invalid user age!")).Times(1);

    // System Under Test
    UserProfile userProfile(mockUserService, mockNotificationService);
    string result = userProfile.getUserDetails(2);

    // Verify the result
    ASSERT_EQ(result, "Error: Invalid user age");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
