#include <iostream>
#include "../include/task.hpp"
#include "../include/taskmanager.hpp"

Task::Task()
	: title(" "), description(" "), deadline(" "), category(" "), priority(1), completed(false) {}

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority, bool completed)
	: title(title), description(description), deadline(deadline), category(category), priority(priority), completed(completed) {}

Task::Task(const Task& other)
	: title(other.title), description(other.description), deadline(other.deadline), category(other.category),
	  priority(other.priority), completed(other.completed) {}

Task::Task(Task&& other) noexcept
	: title(std::move(other.title)), description(std::move(other.description)),
	  deadline(std::move(other.deadline)), category(std::move(other.category)),
	  priority(other.priority), completed(other.completed)
{
	other.priority = 1;
	other.completed = false;
}

Task::~Task() {}

void Task::markCompleted()
{
	completed = true;
}

void Task::editTask(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline,
					const std::string& newCategory, int newPriority)
{
	title = newTitle;
	description = newDescription;
	deadline = newDeadline;
	category = newCategory;
	priority = newPriority;
}

void Task::displayTask() const
{
	std::cout << "Title: " << title << "\n";
	std::cout << "Description: " << description << "\n";
	std::cout << "Deadline: " << deadline << "\n";
	std::cout << "Category: " << category << "\n";
	std::cout << "Priority: ";
	switch (priority)
	{
	case LOW: 
	{
		std::cout << "Low"; 
		break;
	}
	case MID:
	{
		std::cout << "Medium"; 
		break;
	}
	case HIGH:
	{
		std::cout << "High"; 
		break;
	}
	default: 
		std::cout << "Unknown";
	}
	std::cout << "\nStatus: " << (completed ? "Completed" : "Pending") << "\n\n";
}

std::string Task::getTitle() const
{
	return title;
}

std::string Task::getDescription() const
{
	return description;
}

std::string Task::getDeadline() const
{
	return deadline;
}

std::string Task::getCategory() const
{
	return category;
}

int Task::getPriority() const
{
	return priority;
}

bool Task::isCompleted() const
{
	return completed;
}

void Task::setTitle(const std::string& t)
{
	title = t;
}


void Task::setDescription(const std::string& desc)
{
	description = desc;
}

void Task::setDeadline(const std::string& dline)
{
	deadline = dline;
}

void Task::setCategory(const std::string& cat)
{
	category = cat;
}

void Task::setPriority(int pri)
{
	priority = pri;
}

void Task::setCompleted(bool comp)
{
	completed = comp;
}

Task& Task::operator=(const Task& other)
{
	if (this != &other)
	{
		title = other.title;
		description = other.description;
		deadline = other.deadline;
		category = other.category;
		priority = other.priority;
		completed = other.completed;
	}
	return *this;
}

Task& Task::operator=(Task&& other) noexcept
{
	if (this != &other)
	{
		title = std::move(other.title);
		description = std::move(other.description);
		deadline = std::move(other.deadline);
		category = std::move(other.category);
		priority = other.priority;
		completed = other.completed;

		other.priority = 1;
		other.completed = false;
	}
	return *this;
}

