#Task Management System

## 📦 Features
- User Registration and Login
- Task Creation and Assignment
- Task Listing and Completion Tracking
- Simple file-based storage (no database required)

## 📁 Project Structure
TaskManagementSystem/
├── include/ # Header files
├── src/ # Implementation files
├── googletests/ # GoogleTest unit tests
├── test_exec # (built test binary)
├── main_exec # (built main binary)
├── Makefile # Build automation
└── README.md # Project documentation

## 🛠️ Build Instructions

### 🔧 Prerequisites

- C++17 compatible compiler (`g++`)
- [Google Test](https://github.com/google/googletest) (installed or built manually)

### ⚙️ Build Project

```bash
      make
```

🧪 Run Tests
``` bash
./test_exec
```

🚀 Run Program
```bash 
  ./main_exec
```

📚 Example Usage

  Task Management System
  1. Register
  2. Login
  3. Exit
  Enter your choice: 1
  Enter Username: username
  Enter password: password
  Registration Successful!

  Task Management System
  1. Register
  2. Login
  3. Exit
  Enter your choice: 2
  Enter username: username
  Enter password: password
  User Menu
  1. Add Task
  2. Edit Task
  3. Delete Task
  4. Mark Task as Completed
  5. List All Tasks
  6. Search Tasks
  7. Sort Tasks
  8. Filter Tasks
  9. Logout
 
  Enter your choice:

  And so you can choose operations to perform on your tasks.



