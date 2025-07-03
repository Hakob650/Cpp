#include <vector>
#include <string>
#include "User.hpp"
#include "Task.hpp"

#ifndef TEST_MANAGER_HPP
#define TEST_MANAGER_HPP

class TaskManager
{
private:
            std::vector<User*> m_users;
            std::vector<Task*> m_tasks;

            void saveUsers();
            void saveTasks();
            void loadUsers();
            void loadTasks();
public:
            TaskManager() = default;
            ~TaskManager();

            bool registerUser(const std::string& username,const std::string& password);
            User* login(const std::string& username,const std::string& password);
            void logout(User* user);

            bool add_task(User* user, const std::string& title,
                           const std::string& description, const std::string& deadline,
                           const std::string& category, Priority priority);
            bool delete_task(User* user, const std::string& taskId);
            bool edit_task(User* user, const std::string& taskId,
                          const std::string& title, const std::string& description,
                          const std::string& deadline);
            std::vector<Task*> searchTasks(const std::string& keyword) const;
            std::vector<Task*> filterTasks(Priority priority) const;
            std::vector<Task*> filterTasks(Status status) const;
            void displayTask(const std::string& taskId) const;

            TaskManager(const TaskManager&) = delete;
            TaskManager(TaskManager&&) =  delete;
            TaskManager& operator=(const TaskManager&) = delete;
            TaskManager& operator=(TaskManager&&) = delete;
};

#endif