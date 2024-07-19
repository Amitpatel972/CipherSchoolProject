#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    int id;
    std::string name;
    std::string description;
    std::string dueDate;
    bool isComplete;

    Task(int id, std::string name, std::string description, std::string dueDate)
        : id(id), name(name), description(description), dueDate(dueDate), isComplete(false) {}
};

class JoDoApp {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    JoDoApp() : nextId(1) {}

    void addTask() {
        std::string name, description, dueDate;
        std::cout << "Enter task name: ";
        std::getline(std::cin, name);
        std::cout << "Enter task description: ";
        std::getline(std::cin, description);
        std::cout << "Enter task due date: ";
        std::getline(std::cin, dueDate);

        tasks.push_back(Task(nextId++, name, description, dueDate));
        std::cout << "Task added successfully.\n";
    }

    void editTask() {
        int id;
        std::cout << "Enter task ID to edit: ";
        std::cin >> id;
        std::cin.ignore();  // To ignore the newline character left in the buffer

        for (auto& task : tasks) {
            if (task.id == id) {
                std::string name, description, dueDate;
                std::cout << "Enter new task name: ";
                std::getline(std::cin, name);
                std::cout << "Enter new task description: ";
                std::getline(std::cin, description);
                std::cout << "Enter new task due date: ";
                std::getline(std::cin, dueDate);

                task.name = name;
                task.description = description;
                task.dueDate = dueDate;

                std::cout << "Task edited successfully.\n";
                return;
            }
        }

        std::cout << "Task not found.\n";
    }

    void deleteTask() {
        int id;
        std::cout << "Enter task ID to delete: ";
        std::cin >> id;
        std::cin.ignore();  // To ignore the newline character left in the buffer

        auto it = tasks.begin();
        while (it != tasks.end()) {
            if (it->id == id) {
                it = tasks.erase(it);
                std::cout << "Task deleted successfully.\n";
                return;
            } else {
                ++it;
            }
        }

        std::cout << "Task not found.\n";
    }

    void markTaskAsComplete() {
        int id;
        std::cout << "Enter task ID to mark as complete: ";
        std::cin >> id;
        std::cin.ignore();  // To ignore the newline character left in the buffer

        for (auto& task : tasks) {
            if (task.id == id) {
                task.isComplete = true;
                std::cout << "Task marked as complete.\n";
                return;
            }
        }

        std::cout << "Task not found.\n";
    }

    void listTasks() {
        for (const auto& task : tasks) {
            std::cout << "ID: " << task.id << "\n"
                      << "Name: " << task.name << "\n"
                      << "Description: " << task.description << "\n"
                      << "Due Date: " << task.dueDate << "\n"
                      << "Status: " << (task.isComplete ? "Complete" : "Incomplete") << "\n\n";
        }
    }

    void showMenu() {
        int choice;
        do {
            std::cout << "1. Add Task\n"
                      << "2. Edit Task\n"
                      << "3. Delete Task\n"
                      << "4. Mark Task as Complete\n"
                      << "5. List Tasks\n"
                      << "6. Exit\n"
                      << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore();  // To ignore the newline character left in the buffer

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    editTask();
                    break;
                case 3:
                    deleteTask();
                    break;
                case 4:
                    markTaskAsComplete();
                    break;
                case 5:
                    listTasks();
                    break;
                case 6:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    JoDoApp app;
    app.showMenu();
    return 0;
}

