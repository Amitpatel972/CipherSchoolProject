#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate;

    Task(string desc, string cat, string date) {
        description = desc;
        category = cat;
        dueDate = date;
        completed = false;
    }
};

vector<Task> NotesAdded;

void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet.\n";
    } else {
        cout << "Tasks:\n";
        for (int i = 0; i < NotesAdded.size(); ++i) {
            cout << i + 1 << ". " << NotesAdded[i].description << " [" << NotesAdded[i].category << "] ";
            cout << "Due Date: " << NotesAdded[i].dueDate << " ";
            cout << (NotesAdded[i].completed ? "(Completed)" : "(Pending)") << "\n";
        }
    }
}

void markTaskAsCompleted() {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= NotesAdded.size()) {
        NotesAdded[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask() {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index > 0 && index <= NotesAdded.size()) {
        NotesAdded.erase(NotesAdded.begin() + index - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void filterTaskByCategory() {
    string category;
    cout << "Enter category to filter by: ";
    cin >> category;

    vector<Task> filteredTasks;
    for (const auto& task : NotesAdded) {
        if (task.category == category) {
            filteredTasks.push_back(task);
        }
    }

    if (filteredTasks.empty()) {
        cout << "No tasks found in category: " << category << "\n";
    } else {
        cout << "Tasks in category [" << category << "]:\n";
        for (int i = 0; i < filteredTasks.size(); ++i) {
            cout << i + 1 << ". " << filteredTasks[i].description << " ";
            cout << "Due Date: " << filteredTasks[i].dueDate << " ";
            cout << (filteredTasks[i].completed ? "(Completed)" : "(Pending)") << "\n";
        }
    }
}

void addTask() {
    string description, category, dueDate;
    cout << "Enter Description: ";
    cin.ignore(); // Ignore any remaining newline character from previous input
    getline(cin, description);
    cout << "Enter Category: ";
    getline(cin, category);
    cout << "Enter Due Date (YYYY-MM-DD): ";
    getline(cin, dueDate);

    Task task(description, category, dueDate);
    NotesAdded.push_back(task);
    cout << "Task added successfully.\n";
}

void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Filter Tasks by Category\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                filterTaskByCategory();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    displayMenu();
    return 0;
}
