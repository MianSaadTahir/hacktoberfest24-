#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the to-do list." << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Removing task: " << tasks[index - 1] << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    ToDoList todo;
    int choice;

    do {
        cout << "\n--- To-Do List Menu ---" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character after the integer input

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter a task: ";
                getline(cin, task);
                todo.addTask(task);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todo.removeTask(taskNumber);
                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
