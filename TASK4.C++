#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> todoList;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // clear input buffer
    getline(cin, newTask.description);
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < todoList.size(); i++) {
        cout << i + 1 << ". " << todoList[i].description;
        cout << " [" << (todoList[i].completed ? "Completed" : "Pending") << "]\n";
    }
    cout << "-------------------\n";
}

void markTaskCompleted() {
    int index;
    viewTasks();
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= todoList.size()) {
        todoList[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask() {
    int index;
    viewTasks();
    cout << "Enter the task number to remove: ";
    cin >> index;
    if (index >= 1 && index <= todoList.size()) {
        todoList.erase(todoList.begin() + index - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n====== TO-DO LIST MANAGER ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting To-Do List Manager. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
