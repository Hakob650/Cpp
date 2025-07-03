#include <gtest/gtest.h>
#include "../include/task.hpp"
#include "../include/user.hpp"
#include "../include/taskmanager.hpp"

TEST(TaskTest, CreateAndGettes)
{
    Task task("Test","description","2025-12-31","Work",2,false);

    EXPECT_EQ(task.getTitle(), "Test");
    EXPECT_EQ(task.getDescription(), "description");
    EXPECT_EQ(task.getDeadline(), "2025-12-31");
    EXPECT_EQ(task.getCategory(), "Work");
    EXPECT_EQ(task.getPriority(), 2);
    EXPECT_FALSE(task.isCompleted());
}

TEST(TaskTest, MarkCompleted)
{
    Task task;
    task.markCompleted();
    EXPECT_TRUE(task.isCompleted());
}

TEST(UserTest, AddandSearchTask)
{
    User user("John","password");
    Task* task = new Task("Task1","Desc","2025-31-12","Study",1,false);

    user.addTask(task);
    Task* found = user.searchTask("Task1");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getTitle(), "Task1");
}

TEST(UserTest, DeleteTask)
{
    User user("jane", "1234");
    Task* task = new Task("DeleteMe", "Desc", "2025-01-01", "Work", 2, false);
    user.addTask(task);

    EXPECT_TRUE(user.deleteTask("DeleteMe"));
    EXPECT_EQ(user.searchTask("DeleteMe"), nullptr);
}

TEST(UserTest, PasswordVerification)
{
    User user("test", "mysecret");
    EXPECT_TRUE(user.VerifyPassword("mysecret"));
    EXPECT_FALSE(user.VerifyPassword("wrongpass"));
}

TEST(TaskManagerTest, UserRegistrationAndLogin)
{
    TaskManager manager;

    EXPECT_TRUE(manager.registerUser("user1", "pass1"));
    EXPECT_FALSE(manager.registerUser("user1", "pass2")); // duplicate

    EXPECT_TRUE(manager.login("user1", "pass1"));
    EXPECT_FALSE(manager.login("user1", "wrongpass"));
    EXPECT_TRUE(manager.isLoggedIn());
    manager.logout();
    EXPECT_FALSE(manager.isLoggedIn());
}

TEST(TaskManagerTest, AddEditDeleteTask)
{
    TaskManager manager;
    manager.registerUser("alice", "alice123");
    manager.login("alice", "alice123");

    Task task("T1", "desc", "2025-10-10", "Work", 3, false);
    EXPECT_TRUE(manager.addTaskForUser(task));

    Task updated("T1 Updated", "new desc", "2026-01-01", "Personal", 1, true);
    EXPECT_TRUE(manager.editTaskForUser("T1", updated));
    EXPECT_TRUE(manager.deleteTaskForUser("T1 Updated"));
}



