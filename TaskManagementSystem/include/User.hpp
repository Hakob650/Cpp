#include <string>
#include <vector>
#include <fstream>
#include "Task.hpp"

#ifndef USER_HPP
#define USER_HPP

class User
{
private:
        std::string m_id;
        std::string m_name;
        std::string m_passwd;
        std::vector <Task*> m_tasks;
        bool is_logged;
public:
        User();
        User(const std::string& id, const std::string& name,const std::string& passwd);
        User(const std::string& username, const std::string& email);
        User(const User& other);
        User(User&& other);
        ~User();

        User& operator=(const User& other);
        User& operator=(User&& other);

        bool add_task(Task* task);
        bool delete_task(const std::string& task_id, const std::string& title, 
                        const std::string& description,const std::string deadline);
        std::vector<Task*> listTasks() const;
        Task* searchTask(const std::string& taskId) const;
        std::string getName() const;
        std::string getPassword() const;
        const std::string& getUserId() const; 
        void login();
        void logout();

        friend std::ostream& operator<<(std::ostream& os, const User& user);
        friend std::istream& operator>>(std::istream& is, User& user);

        explicit operator bool() const;

        void save(std::ofstream& file) const;
        static User* load(std::ifstream& file);
        std::string serialize() const;
};

#endif