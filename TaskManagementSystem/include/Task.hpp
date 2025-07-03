#include <string>
#include <fstream>

#ifndef TASK_HPP
#define TASK_HPP

enum class Priority { LOW, MID, HIGH, URGENT};
enum class Status { NOT_STARTED, IN_PROGRESS, COMPLETED};

class Task
{
private:
    std::string m_task_id;
    std::string m_uid;
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    Priority m_prio;
    Status m_status;
public:
    Task();
    Task(const std::string& taskId,const std::string& userId,
        const std::string& title,const std::string& description,
        const std::string& deadline, const std::string& category,
        Priority prio);
        Task(const std::string& id, const std::string& title,
     const std::string& description, const std::string& deadline);
     Task(int, std::string, std::string, std::string, std::string);

    Task(const Task& other);
    Task(Task&& other);
    ~Task();

    Task& operator=(const Task& other);
    Task& operator=(Task&& other);

    bool operator==(const Task& other) const;
    bool operator!=(const Task& other) const;
    bool operator<(const Task& other) const;
    bool operator>(const Task& other) const;

    Task& operator++();
    Status operator++(int);
    Task& operator--();
    Status operator--(int);

    void edit_task(const std::string& title,const std::string& description,const std::string& deadline);
 
    void setPriority(Priority priority);
    void display() const;

    const std::string& getTaskId() const;
    const std::string& getUserId() const;
    const std::string& getTitle() const;
    const std::string& getDeadLine() const;
    const std::string& getDescription() const;
    Priority getPriority() const;
    Status getStatus() const;

    void setDescription(const std::string& description);
    void setDeadline(const std::string& deadline);
    void setStatus(Status status); 
    void setTitle(const std::string& title); // assuming Status is an enum



    friend std::ostream& operator<<(std::ostream& os, const Task& Task);
    friend std::istream& operator>>(std::istream& is, const Task& Task);

    void save(std::ofstream& file) const;
    static Task* load(std::ifstream& file);
    std::string serialize() const;
};

#endif
