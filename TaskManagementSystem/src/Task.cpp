#include <iostream>
#include <sstream>
#include "../include/Task.hpp"

Task::Task()
    : m_task_id(""),m_uid(""),m_description(""),m_deadline(""),m_category(""),m_prio(Priority::LOW),m_status(Status::NOT_STARTED) {}

Task::Task(const std::string& taskId,const std::string& userId,
        const std::string& title,const std::string& description,
        const std::string& deadline, const std::string& category,
        Priority prio)
    : m_task_id(taskId),m_uid(userId),m_title(title),m_description(description),m_deadline(deadline),m_category(category),
      m_prio(prio),m_status(Status::NOT_STARTED)
    {}

Task::Task(const std::string& id, const std::string& title,
           const std::string& description, const std::string& deadline)
    : m_uid(id), m_title(title), m_description(description), m_deadline(deadline) {}

Task::Task(const Task& other)
    : m_task_id(other.m_task_id), m_uid(other.m_uid), m_title(other.m_title),
      m_description(other.m_description), m_deadline(other.m_deadline),
      m_category(other.m_category), m_prio(other.m_prio), m_status(other.m_status) {}


Task::~Task() = default;

Task& Task::operator=(const Task& other) {
    if (this != &other) 
    {
        
        m_task_id = other.m_task_id;
        
        m_uid = other.m_uid;
        
        m_title = other.m_title;
        
        m_description = other.m_description;
        
        m_deadline = other.m_deadline;
        
        m_category = other.m_category;
        
        m_prio = other.m_prio;
        
        m_status = other.m_status;
    }
    
    return *this;
}

Task& Task::operator=(Task&& other) 
{
    if (this != &other) 
    {
        
        m_task_id = std::move(other.m_task_id);
        
        m_uid = std::move(other.m_uid);
        
        m_title = std::move(other.m_title);
        
        m_description = std::move(other.m_description);
        
        m_deadline = std::move(other.m_deadline);
        
        m_category = std::move(other.m_category);
        
        m_prio = other.m_prio;
        
        m_status = other.m_status;
    }
    
    return *this;
}

bool Task::operator==(const Task& other) const 
{
    return m_task_id == other.m_task_id;
}

bool Task::operator!=(const Task& other) const 
{
    return !(*this == other);
}

bool Task::operator<(const Task& other) const 
{
    return m_deadline < other.m_deadline;  // Or compare by priority, etc.
}

bool Task::operator>(const Task& other) const 
{
    return m_deadline > other.m_deadline;
}

Task& Task::operator++() 
{
    if (m_status != Status::COMPLETED)
    {
        m_status = static_cast<Status>(static_cast<int>(m_status) + 1);
    }
    return *this;
}

Status Task::operator++(int) 
{
    Status old = m_status;
    ++(*this);
    return old;
}

Task& Task::operator--() 
{
    if (m_status != Status::NOT_STARTED)
    {
        m_status = static_cast<Status>(static_cast<int>(m_status) - 1);
    }
    return *this;
}

Status Task::operator--(int) 
{
    Status old = m_status;
    --(*this);
    return old;
}

const std::string& Task::getTaskId() const 
{ 
    return m_task_id; 
}

const std::string& Task::getUserId() const 
{ 
    return m_uid; 
}

const std::string& Task::getTitle() const 
{ 
    return m_title; 
}

const std::string& Task::getDeadLine() const 
{ 
    return m_deadline; 
}

const std::string& Task::getDescription() const 
{ 
    return m_description; 
}

Priority Task::getPriority() const 
{ 
    return m_prio; 
}

Status Task::getStatus() const 
{ 
    return m_status; 
}

void Task::edit_task(const std::string& title, const std::string& description, const std::string& deadline) 
{
    m_title = title;
    
    m_description = description;
    
    m_deadline = deadline;
}

void Task::setStatus(Status status) 
{ 
    m_status = status; 
}

void Task::setPriority(Priority priority) 
{ 
    m_prio = priority; 
}

void Task::setDescription(const std::string& description)
{
    m_description = description;
}

void Task::setDeadline(const std::string& deadline)
{
    m_deadline = deadline;
}

void Task::setTitle(const std::string& title)
{
    m_title = title;
}

void Task::display() const 
{
    std::cout << "Task ID: " << m_task_id << "\n"
              << "User ID: " << m_uid << "\n"
              << "Title: " << m_title << "\n"
              << "Description: " << m_description << "\n"
              << "Deadline: " << m_deadline << "\n"
              << "Category: " << m_category << "\n"
              << "Priority: " << static_cast<int>(m_prio) << "\n"
              << "Status: " << static_cast<int>(m_status) << "\n";
}

std::string Task::serialize() const 
{
    return m_task_id + "," + m_uid + "," + m_title + "," + m_description + "," +
           m_deadline + "," + m_category + "," + std::to_string(static_cast<int>(m_prio)) + "," +
           
           std::to_string(static_cast<int>(m_status));
}

void Task::save(std::ofstream& file) const 
{
    file << serialize() << "\n";
}

Task* Task::load(std::ifstream& file) 
{
    std::string line;
    if (!std::getline(file, line)) return nullptr;

    std::istringstream ss(line);
    std::string taskId, userId, title, description, deadline, category;
    int prioInt, statusInt;

    if (std::getline(ss, taskId, ',') &&
        std::getline(ss, userId, ',') &&
        std::getline(ss, title, ',') &&
        std::getline(ss, description, ',') &&
        std::getline(ss, deadline, ',') &&
        std::getline(ss, category, ',') &&
        ss >> prioInt && ss.ignore(1) && ss >> statusInt) {

        Priority prio = static_cast<Priority>(prioInt);
        Status status = static_cast<Status>(statusInt);

        Task* task = new Task(taskId, userId, title, description, deadline, category, prio);
        task->setStatus(status);
        return task;
    }

    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Task& task) 
{
    os << task.serialize();
    return os;
}

std::istream& operator>>(std::istream& is, Task& task) {
    std::string line;
    if (!std::getline(is, line)) return is;

    std::istringstream ss(line);
    std::string taskId, userId, title, description, deadline, category;
    int prioInt, statusInt;

    if (std::getline(ss, taskId, ',') &&
        std::getline(ss, userId, ',') &&
        std::getline(ss, title, ',') &&
        std::getline(ss, description, ',') &&
        std::getline(ss, deadline, ',') &&
        std::getline(ss, category, ',') &&
        ss >> prioInt && ss.ignore(1) && ss >> statusInt) {

        task = Task(taskId, userId, title, description, deadline, category, static_cast<Priority>(prioInt));
        task.setStatus(static_cast<Status>(statusInt));
    }

    return is;
}

