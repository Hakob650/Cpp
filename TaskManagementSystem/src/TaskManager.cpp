#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/TaskManager.hpp"

TaskManager::~TaskManager()
{
    for(size_t i = 0; i < m_users.size(); ++i)
    {
        delete m_users[i];
    }
    m_users.clear();

    for(size_t i = 0; i < m_tasks.size(); ++i)
    {
        delete m_tasks[i];
    }
    m_tasks.clear();
}

bool TaskManager::registerUser(const std::string& username,const std::string& password)
{
    for(size_t i = 0; i < m_users.size(); ++i)
    {
        if(m_users[i]->getName() == username)
        {
            std::cout<<"User already exists";
            return false;
        }
    }
    User* new_user = new User(username,username,password);
    m_users.push_back(new_user);

    saveUsers();
    return true;
}

User* TaskManager::login(const std::string& username,const std::string& password)
{
    for(size_t i = 0; i < m_users.size(); ++i)
    {
        if(m_users[i]->getName() == username && m_users[i]->getPassword() == password)
        {
            m_users[i]->login();
            return m_users[i];
        }
    }
    return nullptr;
}

void TaskManager::logout(User* user)
{
    if(user)
    {
        user->logout();
    }
}

#include <sstream> // For generating taskId

bool TaskManager::add_task(User* user, const std::string& title,
                           const std::string& description, const std::string& deadline,
                           const std::string& category, Priority priority)
{
    if (!user || !(*user)) {
        return false;
    }

    // Generate a simple taskId (could be improved to UUID or global counter)
    static int taskCounter = 0;
    std::stringstream ss;
    ss << "task_" << ++taskCounter;
    std::string taskId = ss.str();


    std::string userId = user->getUserId();

    Task* new_task = new Task(taskId, userId, title, description, deadline, category, priority);

    m_tasks.push_back(new_task);

    return user->add_task(new_task);
}

bool TaskManager::delete_task(User* user,const std::string& taskId)
{
    if(!user || !user->operator bool())
    {
        return false;
    }

    Task* task = user->searchTask(taskId);
    if(!task)
    {
        return false;
    }

    if(!user->delete_task(task->getTaskId(),task->getTitle(),task->getDescription(),task->getDeadLine()))
    {
        return false;
    }

    for(size_t i = 0; i < m_tasks.size(); ++i)
    {
        if(m_tasks[i] == task)
        {
            delete[] m_tasks[i];
            m_tasks.erase(m_tasks.begin() + i);
            break;
        }
    }
    return true;
}

bool TaskManager::edit_task(User* user, const std::string& taskId,
                          const std::string& title, const std::string& description,
                          const std::string& deadline)
{
    if(!user || user->operator bool())
    {
        return false;
    }

    Task* task = user->searchTask(taskId);
    if(!task)
    {
        return false;
    }

    task->setTitle(title);
    task->setDescription(description);
    task->setDeadline(deadline);

    saveTasks();
    return true;
}

std::vector<Task*> TaskManager::searchTasks(const std::string& keyword) const {
    std::vector<Task*> results;
    for (size_t i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->getTitle().find(keyword) != std::string::npos ||
            m_tasks[i]->getDescription().find(keyword) != std::string::npos) 
        {
            results.push_back(m_tasks[i]);
        }
    }
    return results;
}

std::vector<Task*> TaskManager::filterTasks(Priority priority) const {
    std::vector<Task*> results;
    for (size_t i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->getPriority() == priority) {
            results.push_back(m_tasks[i]);
        }
    }
    return results;
}

std::vector<Task*> TaskManager::filterTasks(Status status) const {
    std::vector<Task*> results;
    for (size_t i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->getStatus() == status) {
            results.push_back(m_tasks[i]);
        }
    }
    return results;
}

void TaskManager::displayTask(const std::string& taskId) const {
    for (size_t i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->getTaskId() == taskId) {
            std::cout << *(m_tasks[i]) << std::endl;
            return;
        }
    }
    std::cout << "Task not found\n";
}

void TaskManager::saveUsers() {
    std::ofstream outFile("users.txt");
    if(!outFile)
    {
        std::cout<<"File opening failed";
        return;
    }

    for(size_t i = 0; i < m_users.size(); ++i)
    {
        outFile<<m_users[i]->serialize();
    }
    outFile.close();
}

void TaskManager::saveTasks() {
    std::ofstream outFile("tasks.txt");
    if (!outFile) {
        std::cerr << "Error: Could not open tasks.txt for writing.\n";
        return;
    }

    for (size_t i = 0; i < m_tasks.size(); ++i) {
        outFile << m_tasks[i]->serialize() << '\n';
    }

    outFile.close();
}

void TaskManager::loadUsers() {
    std::ifstream inFile("users.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open users.txt for reading.\n";
        return;
    }

    m_users.clear(); 

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string username, email;

        if (std::getline(ss, username, ',') && std::getline(ss, email)) {
            m_users.push_back(new User(username, email));
        } else {
            std::cerr << "Warning: Skipped user entry: " << line << '\n';
        }
    }
    inFile.close();
}

void TaskManager::loadTasks() {
    std::ifstream inFile("tasks.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open tasks.txt for reading.\n";
        return;
    }

    m_tasks.clear();
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string taskId, userId, title, description, dueDate, category;
        int prioInt, statusInt;

        if (std::getline(ss, taskId, ',') &&
            std::getline(ss, userId, ',') &&
            std::getline(ss, title, ',') &&
            std::getline(ss, description, ',') &&
            std::getline(ss, dueDate, ',') &&
            std::getline(ss, category, ',') &&
            ss >> prioInt && ss.ignore(1) && ss >> statusInt) {

            Priority prio = static_cast<Priority>(prioInt);
            Status status = static_cast<Status>(statusInt);

            Task* task = new Task(taskId, userId, title, description, dueDate, category, prio);
            task->setStatus(status);
            m_tasks.push_back(task);
        } else {
            std::cerr << "Warning: Skipped malformed task entry: " << line << '\n';
        }
    }
}





