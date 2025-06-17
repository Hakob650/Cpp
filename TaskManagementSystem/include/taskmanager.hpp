#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <string>
#include <vector>
#include "user.hpp"

class TaskManager {
private:
	std::vector<User*> users;
	User* loggedInUser;

	void copyUsers(const std::vector<User*>& otherUsers);
	void clearUsers();

public:
	
	TaskManager();
	TaskManager(const TaskManager& other);
	TaskManager(TaskManager&& other) noexcept;
	~TaskManager();


	bool registerUser(const std::string& username, const std::string& password);
	bool login(const std::string& username, const std::string& password);
	void logout();
	bool isLoggedIn() const;
	User* getCurrentUser() const;

	
	bool addTaskForUser(const Task& task);
	bool deleteTaskForUser(const std::string& title);
	bool editTaskForUser(const std::string& title, const Task& updatedTask);
	void displayTasksForUser() const;
	std::vector<Task*> searchTasksForUser(const std::string& keyword) const;
	void sortTasksByDeadlineForUser();
	void sortTasksByPriorityForUser();
	void sortTasksByStatusForUser();
	std::vector<Task*> filterTasksByCategoryForUser(const std::string& category) const;
	std::vector<Task*> filterTasksByStatusForUser(bool completed) const;

	
	bool saveToFile(const std::string& filename) const;
	bool loadFromFile(const std::string& filename);

	
	User* findUser(const std::string& username) const;
	std::string hashPassword(const std::string& password) const;
};

#endif 

