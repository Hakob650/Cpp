#include <algorithm>
#include <functional>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "../include/user.hpp"
#include "../include/taskmanager.hpp"

bool compareTasksByDeadline(const Task* a, const Task* b)
{
	return a->getDeadline() < b->getDeadline();
}

bool compareTasksByPriority(const Task* a, const Task* b)
{
	return a->getPriority() > b->getPriority();
}

bool compareTasksByStatus(const Task* a, const Task* b)
{
	if (a->isCompleted() == b->isCompleted())
	{
		return a->getTitle() < b->getTitle();
	}
	return !a->isCompleted() && b->isCompleted();
}


User::User(const std::string& username, const std::string& password)
	: username(username), password(hashPassword(password)) {}

User::User(const User& other)
	: username(other.username), password(other.password)
{
	copyTasks(other.tasks);
}

User::User(User&& other) noexcept
	: username(std::move(other.username)), password(std::move(other.password)), tasks(std::move(other.tasks))
{
	other.tasks.clear();
}


User::~User()
{
	for (Task* task : tasks)
	{
		delete task;
	}
	tasks.clear();
}


void User::addTask(Task* task)
{
	tasks.push_back(task);
}

bool User::deleteTask(const std::string& title)
{
	for (size_t i = 0; i < tasks.size(); ++i)
	{
		if (tasks[i]->getTitle() == title)
		{
			delete tasks[i];
			tasks.erase(tasks.begin() + i);
			return true;
		}
	}
	return false;
}

bool User::editTask(const std::string& title, const Task& updatedTask)
{
	for (Task* task : tasks)
	{
		if (task->getTitle() == title)
		{
			task->setTitle(updatedTask.getTitle());
			task->setDescription(updatedTask.getDescription());
			task->setDeadline(updatedTask.getDeadline());
			task->setCategory(updatedTask.getCategory());
			task->setPriority(updatedTask.getPriority());
			task->setCompleted(updatedTask.isCompleted());
			return true;
		}
	}
	return false;
}

void User::listTasks() const
{
	if (tasks.empty())
	{
		std::cout << "No tasks found.\n";
		return;
	}
	for (const Task* task : tasks)
	{
		task->displayTask();
	}
}

Task* User::searchTask(const std::string& title)
{
	for (Task* task : tasks)
	{
		if (task->getTitle() == title)
		{
			return task;
		}
	}
	return nullptr;
}


std::vector<Task*> User::getTasks() const
{
	return tasks;
}

std::string User::getUsername() const
{
	return username;
}

void User::setPasswordHash(const std::string& hashedPassword)
{
    this->password = hashedPassword;
}


bool User::VerifyPassword(const std::string& password) const
{
	return this->password == hashPassword(password);
}


void User::sortTasksByDeadline()
{
	std::sort(tasks.begin(), tasks.end(), compareTasksByDeadline);
}

void User::sortTasksByPriority()
{
	std::sort(tasks.begin(), tasks.end(), compareTasksByPriority);
}

void User::sortTasksByStatus()
{
	std::sort(tasks.begin(), tasks.end(), compareTasksByStatus);
}


std::vector<Task*> User::filterTasksByCategory(const std::string& category) const
{
    std::vector<Task*> result;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        Task* task = tasks[i];
        if (task->getCategory() == category)
        {
            result.push_back(task);
        }
    }
    return result;
}


std::vector<Task*> User::filterTasksByStatus(bool completed) const
{
    std::vector<Task*> result;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        Task* task = tasks[i];
        if (task->isCompleted() == completed)
        {
            result.push_back(task);
        }
    }
    return result;
}



std::vector<Task*> User::searchTasks(const std::string& keyword) const
{
    std::vector<Task*> result;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        Task* task = tasks[i];
        if (task->getTitle().find(keyword) != std::string::npos ||
            task->getDescription().find(keyword) != std::string::npos)
        {
            result.push_back(task);
        }
    }
    return result;
}



User& User::operator=(const User& other)
{
    if (this != &other)
    {
        username = other.username;
        password = other.password;

        // Delete existing tasks
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            delete tasks[i];
        }
        tasks.clear();

        copyTasks(other.tasks);
    }
    return *this;
}


User& User::operator=(User&& other) noexcept
{
    if (this != &other)
    {
        username = std::move(other.username);
        password = std::move(other.password);

       
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            delete tasks[i];
        }
        tasks.clear();

       
        tasks = std::move(other.tasks);
        other.tasks.clear();
    }
    return *this;
}



void User::copyTasks(const std::vector<Task*>& otherTasks)
{
    for (size_t i = 0; i < otherTasks.size(); ++i)
    {
        tasks.push_back(new Task(*otherTasks[i]));
    }
}


std::string User::hashPassword(const std::string& password)
{
	std::hash<std::string> hasher;
	return std::to_string(hasher(password));
}




	


