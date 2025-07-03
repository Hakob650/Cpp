#include <iostream>
#include <sstream>
#include <fstream>
#include "../include/User.hpp"
#include "../include/Task.hpp"

User::User()
    : m_id(""),m_name(""),m_passwd(""),is_logged(false) {}

User::User(const std::string& id, const std::string& name,const std::string& passwd)
    : m_id(id),m_name(name),m_passwd(passwd),is_logged(false) {}

User::User(const User& other)
    : m_id(other.m_id),m_name(other.m_name),m_passwd(other.m_passwd),is_logged(other.is_logged)
{
    for(size_t i = 0; i < other.m_tasks.size(); ++i)
    {
        m_tasks.push_back(new Task(*other.m_tasks[i]));
    }
}

User::User(User&& other)
    : m_id(std::move(other.m_id)),
      m_name(std::move(other.m_name)),
      m_passwd(std::move(other.m_passwd)),
      m_tasks(std::move(other.m_tasks)),
      is_logged(other.is_logged) 
{
    other.m_tasks.clear();
}

User::~User() 
{
    for (size_t i = 0; i < m_tasks.size(); ++i) 
    {
        delete m_tasks[i];
    }
    m_tasks.clear();
}

User& User::operator=(User&& other) 
{
    if (this != &other) 
    {
        for (size_t i = 0; i < m_tasks.size(); ++i) 
        {
            delete m_tasks[i];
        }
        m_tasks.clear();

        m_id = std::move(other.m_id);
        m_name = std::move(other.m_name);
        m_passwd = std::move(other.m_passwd);
        m_tasks = std::move(other.m_tasks);
        is_logged = other.is_logged;

        other.m_tasks.clear();
    }
    return *this;
}

bool User::add_task(Task* task) 
{
    if (task) 
    {
        m_tasks.push_back(task);
        return true;
    }
    return false;
}

bool User::delete_task(const std::string& task_id, const std::string& title,
                       const std::string& description, const std::string deadline) 
{
    for (size_t i = 0; i < m_tasks.size(); ++i) 
    {
        Task* task = m_tasks[i];
        if (task->getUserId() == task_id &&
            task->getTitle() == title &&
            task->getDescription() == description &&
            task->getDeadLine() == deadline) {
            delete task;
            m_tasks.erase(m_tasks.begin() + i);
            return true;
        }
    }
    return false;
}

std::vector<Task*> User::listTasks() const 
{
    return m_tasks;
}

std::string User::getName() const 
{
    return m_name;
}

std::string User::getPassword() const 
{
    return m_passwd;
}

const std::string& User::getUserId() const 
{
    return m_id;
}

void User::login() 
{
    is_logged = true;
}

void User::logout() 
{
    is_logged = false;
}

User::operator bool() const 
{
    return is_logged;
}

std::ostream& operator<<(std::ostream& os, const User& user) 
{
    os << user.m_id << '\n'
       << user.m_name << '\n'
       << user.m_passwd << '\n'
       << user.m_tasks.size() << '\n';
    for (size_t i = 0; i < user.m_tasks.size(); ++i) {
        os << user.m_tasks[i]->serialize() << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, User& user) 
{
    size_t taskCount;
    std::getline(is, user.m_id);
    std::getline(is, user.m_name);
    std::getline(is, user.m_passwd);
    is >> taskCount;
    is.ignore();

    for (size_t i = 0; i < user.m_tasks.size(); ++i) 
    {
        delete user.m_tasks[i];
    }
    user.m_tasks.clear();

    for (size_t i = 0; i < taskCount; ++i) 
    {
        Task* task = new Task();
        is >> *task;
        user.m_tasks.push_back(task);
    }
    return is;
}

void User::save(std::ofstream& file) const 
{
    file << serialize();
}

User* User::load(std::ifstream& file) 
{
    if (!file.is_open()) return nullptr;
    User* user = new User();
    file >> *user;
    return user;
}

std::string User::serialize() const 
{
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}


