#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "task.hpp"

class User {
private:
	std::string username;
	std::string password;
	std::vector<Task*> tasks;

	void copyTasks(const std::vector<Task*>& otherTasks);
	static std::string hashPassword(const std::string& password);

public:
	
	User(const std::string& username, const std::string& password);
	User(const User& other);
	User(User&& other) noexcept;
	~User();

	
	User& operator=(const User& other);
	User& operator=(User&& other) noexcept;


	void addTask(Task* task);
	bool deleteTask(const std::string& title);
	bool editTask(const std::string& title, const Task& updatedTask);
	void listTasks() const;

	
	Task* searchTask(const std::string& title);
	std::vector<Task*> searchTasks(const std::string& keyword) const;

	
	void sortTasksByDeadline();
	void sortTasksByPriority();
	void sortTasksByStatus();

	
	std::vector<Task*> filterTasksByCategory(const std::string& category) const;
	std::vector<Task*> filterTasksByStatus(bool completed) const;

	
	std::vector<Task*> getTasks() const;
	std::string getUsername() const;

	void setPasswordHash(const std::string& hashedPassword);

	
	bool VerifyPassword(const std::string& password) const;
};

#endif 



	 
