#include <iostream>
#include <limits>
#include "../include/taskmanager.hpp"
#include "../include/task.hpp"
void displayMainMenu()
{
    std::cout << "\nTask Management System\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void displayUserMenu()
{
    std::cout << "\nUser Menu\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Edit Task\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Mark Task as Completed\n";
    std::cout << "5. List All Tasks\n";
    std::cout << "6. Search Tasks\n";
    std::cout << "7. Sort Tasks\n";
    std::cout << "8. Filter Tasks\n";
    std::cout << "9. Logout\n";
    std::cout << "Enter your choice: ";
}

void displaySortMenu()
{
    std::cout << "\nSort Tasks By\n";
    std::cout << "1. Deadline\n";
    std::cout << "2. Priority\n";
    std::cout << "3. Status\n";
    std::cout << "Enter your choice: ";
}

void displayFilterMenu()
{
    std::cout << "\nFilter Task By\n";
    std::cout << "1. Category\n";
    std::cout << "2. Completed Status\n";
    std::cout << "3. Pending Status\n";
    std::cout << "Enter your choice: ";
}

Task createTaskFromInput()
{
    std::string title, description, deadline, category;
    int priority;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // flush newline from input buffer

    std::cout << "Enter task title: ";
    std::getline(std::cin, title);

    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    std::cout << "Enter deadline (YYYY-MM-DD): ";
    std::getline(std::cin, deadline);

    std::cout << "Enter category (Work, Personal, Study, etc.): ";
    std::getline(std::cin, category);

    std::cout << "Enter priority (1=Low, 2=Medium, 3=High): ";
    std::cin >> priority;

    return Task(title, description, deadline, category, priority, false);
}

int main()
{
    TaskManager taskmanager;
    const std::string filename = "tasks.dat";

    if (!taskmanager.loadFromFile(filename))
    {
        std::cout << "No existing data found. Starting with empty database.\n";
    }

    bool running = true;
    while (running)
    {
        if (!taskmanager.isLoggedIn())
        {
            displayMainMenu();
            int choice;
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    std::string username, password;
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;

                    if (taskmanager.registerUser(username, password))
		    {
                        std::cout << "Registration successful!\n";
		    }
                    else
		    {
                        std::cout << "Username already exists.\n";
		    }
                    break;
                }
                case 2:
                {
                    std::string username, password;
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;

                    if (taskmanager.login(username, password))
		    {
                        std::cout << "Login successful!\n";
		    }
                    else
		    {
                        std::cout << "Invalid username or password.\n";
		    }
                    break;
                }
                case 3:
                {
                    running = false;
                    break;
                }
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        }
        else
        {
            displayUserMenu();
            int choice;
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    Task newTask = createTaskFromInput();
                    if (taskmanager.addTaskForUser(newTask))
                        std::cout << "Task added successfully!\n";
                    else
                        std::cout << "Failed to add task.\n";
                    break;
                }
                case 2:
                {
                    std::string title;
                    std::cout << "Enter title of task to edit: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, title);

                    Task updatedTask = createTaskFromInput();
                    if (taskmanager.editTaskForUser(title, updatedTask))
		    {
                        std::cout << "Task updated successfully!\n";
		    }
                    else
		    {
                        std::cout << "Task not found or failed to update.\n";
		    }
                    break;
                }
                case 3:
                {
                    std::string title;
                    std::cout << "Enter title: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, title);

                    if (taskmanager.deleteTaskForUser(title))
		    {
                        std::cout << "Task deleted successfully!\n";
		    }
                    else
		    {
                        std::cout << "Task not found or deletion failed.\n";
		    }
                    break;
                }
                case 4:
                {
                    std::string title;
                    std::cout << "Enter title: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, title);

                    Task* task = taskmanager.getCurrentUser()->searchTask(title);
                    if (task)
                    {
                        task->markCompleted();
                        std::cout << "Task marked as completed!\n";
                    }
                    else
                    {
                        std::cout << "Task not found.\n";
                    }
                    break;
                }
                case 5:
                    taskmanager.displayTasksForUser();
                    break;
                case 6:
                {
                    std::string keyword;
                    std::cout << "Enter search keyword: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, keyword);

                    std::vector<Task*> results = taskmanager.searchTasksForUser(keyword);
                    if (results.empty())
		    {
                        std::cout << "No tasks found matching your search.\n";
		    }
                    else
                    {
                        std::cout << "Search results:\n";
                        
						for (size_t i = 0; i < results.size(); ++i)
						{
    						results[i]->displayTask();
						}
		    }
                    break;
                }
                case 7:
                {
                    displaySortMenu();
                    int sortChoice;
                    std::cin >> sortChoice;

                    switch (sortChoice)
                    {
                        case 1:
                            taskmanager.sortTasksByDeadlineForUser();
                            std::cout << "Tasks sorted by deadline.\n";
                            break;
                        case 2:
                            taskmanager.sortTasksByPriorityForUser();
                            std::cout << "Tasks sorted by priority.\n";
                            break;
                        case 3:
                            taskmanager.sortTasksByStatusForUser();
                            std::cout << "Tasks sorted by status.\n";
                            break;
                        default:
                            std::cout << "Invalid choice.\n";
                    }
                    break;
                }
                case 8:
                {
                    displayFilterMenu();
                    int filterChoice;
                    std::cin >> filterChoice;

                    std::vector<Task*> results;

                    switch (filterChoice)
                    {
                        case 1:
                        {
                            std::string category;
                            std::cout << "Enter category to filter by: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::getline(std::cin, category);
                            results = taskmanager.filterTasksByCategoryForUser(category);
                            break;
                        }
                        case 2:
                            results = taskmanager.filterTasksByStatusForUser(true);
                            break;
                        case 3:
                            results = taskmanager.filterTasksByStatusForUser(false);
                            break;
                        default:
                            std::cout << "Invalid choice.\n";
                            continue;
                    }

                    if (results.empty())
		    {
                        std::cout << "No tasks found for your filter.\n";
		    }
                    else
                    {
                        std::cout << "Filter results:\n";
                        
						for (size_t i = 0; i < results.size(); ++i)
						{
   							 results[i]->displayTask();
						}
					}
                    break;
                }
                case 9:
                    taskmanager.logout();
                    std::cout << "Logged out successfully!\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        }
    }

    if (taskmanager.saveToFile(filename))
    {
        std::cout << "Data saved successfully!\n";
    }
    else
    {
        std::cout << "Failed to save data.\n";
    }

    return 0;
}
