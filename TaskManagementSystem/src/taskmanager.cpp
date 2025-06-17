#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/taskmanager.hpp"

TaskManager::TaskManager() : loggedInUser(nullptr) {}

TaskManager::TaskManager(const TaskManager& other) : loggedInUser(nullptr)
{
	copyUsers(other.users);
	if (other.loggedInUser)
	{
		loggedInUser = findUser(other.loggedInUser->getUsername());
	}
}

TaskManager::TaskManager(TaskManager&& other) noexcept
	: users(std::move(other.users)), loggedInUser(other.loggedInUser)
{
	other.users.clear();
	other.loggedInUser = nullptr;
}

TaskManager::~TaskManager()
{
	clearUsers();
}

bool TaskManager::registerUser(const std::string& username, const std::string& password)
{
	if (findUser(username) != nullptr)
	{
		return false;
	}
	users.push_back(new User(username, password));
	return true;
}

bool TaskManager::login(const std::string& username, const std::string& password)
{
	User* user = findUser(username);
	if (user && user->VerifyPassword(password))
	{
		loggedInUser = user;
		return true;
	}
	return false;
}

void TaskManager::logout()
{
	loggedInUser = nullptr;
}

bool TaskManager::isLoggedIn() const
{
	return loggedInUser != nullptr;
}

User* TaskManager::getCurrentUser() const
{
	return loggedInUser;
}

bool TaskManager::addTaskForUser(const Task& task)
{
	if (!isLoggedIn()) return false;

	Task* newTask = new Task(task);
	loggedInUser->addTask(newTask);
	return true;
}

bool TaskManager::deleteTaskForUser(const std::string& title)
{
	return isLoggedIn() && loggedInUser->deleteTask(title);
}

bool TaskManager::editTaskForUser(const std::string& title, const Task& updatedTask)
{
	return isLoggedIn() && loggedInUser->editTask(title, updatedTask);
}

void TaskManager::displayTasksForUser() const
{
	if (isLoggedIn())
		loggedInUser->listTasks();
	else
		std::cout << "No user is logged in.\n";
}

std::vector<Task*> TaskManager::searchTasksForUser(const std::string& keyword) const
{
	if (isLoggedIn())
		return loggedInUser->searchTasks(keyword);
	return {};
}

void TaskManager::sortTasksByDeadlineForUser()
{
	if (isLoggedIn())
		loggedInUser->sortTasksByDeadline();
}

void TaskManager::sortTasksByPriorityForUser()
{
	if (isLoggedIn())
		loggedInUser->sortTasksByPriority();
}

void TaskManager::sortTasksByStatusForUser()
{
	if (isLoggedIn())
		loggedInUser->sortTasksByStatus();
}

std::vector<Task*> TaskManager::filterTasksByCategoryForUser(const std::string& category) const
{
	if (isLoggedIn())
	{
		return loggedInUser->filterTasksByCategory(category);
	}
	return {};
}

std::vector<Task*> TaskManager::filterTasksByStatusForUser(bool completed) const
{
	if (isLoggedIn())
	{
		return loggedInUser->filterTasksByStatus(completed);
	}
	return {};
}

bool TaskManager::saveToFile(const std::string& filename) const
{
	std::ofstream outFile(filename);
	if (!outFile)
	{ 
		return false;
	}

	for (User* user : users)
	{
		outFile << "User " << user->getUsername() << " " << user->VerifyPassword("dummy") << "\n";
		for (const Task* task : user->getTasks())
		{
			outFile << "Task " << user->getUsername() << " "
			        << task->getTitle() << "|"
			        << task->getDescription() << "|"
			        << task->getDeadline() << "|"
			        << task->getCategory() << "|"
			        << task->getPriority() << "|"
			        << task->isCompleted() << "\n";
		}
	}
	outFile.close();
	return true;
}

bool TaskManager::loadFromFile(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile)
	{ 
		return false;
	}

	clearUsers();
	std::string line;

	while (std::getline(inFile, line))
	{
		std::istringstream iss(line);
		std::string type;
		iss >> type;

		if (type == "User")
		{
			std::string username, passwordHash;
			iss >> username >> passwordHash;

			User* user = new User(username, "");
			user->setPasswordHash(passwordHash);
			users.push_back(user);
		}
		else if (type == "Task")
		{
			std::string username, taskData;
			iss >> username;
			std::getline(iss, taskData); // get rest of line after username

			User* user = findUser(username);
			if (!user) continue;

			// Remove leading space
			if (!taskData.empty() && taskData[0] == ' ')
			{
				taskData.erase(0, 1);
			}

			std::vector<std::string> tokens;
			std::stringstream ss(taskData);
			std::string token;

			while (std::getline(ss, token, '|'))
			{
				tokens.push_back(token);
			}

			if (tokens.size() >= 6)
			{
				std::string title = tokens[0];
				std::string description = tokens[1];
				std::string deadline = tokens[2];
				std::string category = tokens[3];
				int priority = std::stoi(tokens[4]);
				bool completed = (tokens[5] == "1");

				Task* task = new Task(title, description, deadline, category, priority, completed);
				user->addTask(task);
			}
		}
	}

	inFile.close();
	return true;
}

User* TaskManager::findUser(const std::string& username) const
{
	for (User* user : users)
	{
		if (user->getUsername() == username)
		{
			return user;
		}
	}
	return nullptr;
}

std::string TaskManager::hashPassword(const std::string& password) const
{
	std::hash<std::string> hasher;
	return std::to_string(hasher(password));
}

void TaskManager::clearUsers()
{
    for (size_t i = 0; i < users.size(); ++i)
    {
        delete users[i];
    }
    users.clear();
    loggedInUser = nullptr;
}

void TaskManager::copyUsers(const std::vector<User*>& otherUsers)
{
    for (size_t i = 0; i < otherUsers.size(); ++i)
    {
        users.push_back(new User(*otherUsers[i]));
    }
}


