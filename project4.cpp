#include <iostream>  // Include standard input-output library
#include <cstdlib>   // Include standard library for functions like rand()
#include <cmath>     // Include cmath library for mathematical functions
#include <bits/stdc++.h>  // Include all standard libraries (for maps, vectors, etc.)
#include <ctime>     // Include ctime for date and time functions

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate;
    string priority;

    Task(string description, string category, string priority, string dueDate) {
        this->description = description;
        this->category = category;
        this->dueDate = dueDate;
        this->priority = priority;
        this->completed = false;
    }
};

vector<Task> NotesAdded;

void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "Please add some task first to view\n";
    } else {
        cout << "\nTasks:\n";
        cout << " " << "Task" << " " << "Category" << " "
             << "Priority" << " " << "DueDate" << " "
             << "Status" << "\n";

        for (int i = 0; i < NotesAdded.size(); i++) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid Task Number\n";
    }
}

void deleteTask() {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1);
    } else {
        cout << "Invalid Task Number\n";
    }
}

void filterTaskByCategory() {
    string category;
    cout << "Enter the category to filter by: ";
    cin.ignore();
    getline(cin, category);

    cout << "\nFiltered Tasks:\n";
    cout << " " << "Task" << " " << "Category" << " "
         << "Priority" << " " << "DueDate" << " "
         << "Status" << "\n";

    for (int i = 0; i < NotesAdded.size(); i++) {
        if (NotesAdded[i].category == category) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

void addTask() {
    string description, category, priority;
    cout << "Enter the description: ";
    cin.ignore();
    getline(cin, description);

    cout << "Enter the category (WORK, PERSONAL, REMIND, BIRTHDAY): ";
    getline(cin, category);

    cout << "Enter task priority (LOW, MEDIUM, HIGH): ";
    getline(cin, priority);

    auto now = time(nullptr);
    tm* current = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);

    Task task(description, category, priority, dueDate);
    NotesAdded.push_back(task);
}

void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Filter Tasks By Category\n"
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
                cout << "Goodbye! Please do the tasks on time.\n";
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

