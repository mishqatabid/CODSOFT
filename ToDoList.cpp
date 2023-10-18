#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Task {
    string title;
    string description;
    string deadline;
    bool completed;
};

vector<Task> todoList;

void AddTask() {
    Task newTask;
    cout << "\n[+] TASK ENTERING" <<endl;
    cout << "ENTER TITLE:";
    cin.ignore();
    getline(cin, newTask.title);
    cout << "\nENTER DESCRIPTION: ";
    getline(cin, newTask.description);
    cout << "\nENTER TASK DEADLINE (YYYY-MM-DD): ";
    cin >> newTask.deadline;
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "\nADDED SUCCESSFULLY!\n";
}

void ViewTasks() {
    if (todoList.empty()) {
        cout << "\nNO TASK IN LIST.\n";
        return;
    }

    cout << "\n[+] ALL TASKS:\n\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        const Task& task = todoList[i];
        cout << "[+] TASK " << i+1 <<endl;
        cout << "  TITLE: " << task.title <<endl;
        cout << "  DESCRIPTION: " << task.description <<endl;
        cout << "  DEADLINE: " << task.deadline <<endl;
        cout << "  STATUS: " << (task.completed ? "COMPLETED" : "PENDING") <<endl;
    }
}

void MarkTaskAsCompleted() {
    ViewTasks();
    if (todoList.empty()) {
        return;
    }

    cout << "[+] ENTER THE TASK NUMBER THAT YOU WANT TO MARK COMPLETE";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(todoList.size())) {
        todoList[taskNumber - 1].completed = true;
        cout << "\nTASK MARKED AS COMPLETED" <<endl;
    } else {
        cout << "INVALID TASK NUMBER" <<endl;
    }
}

void RemoveTask() {
    ViewTasks();
    if (todoList.empty()) {
        return;
    }

    cout << "[+] ENTER THE NUMBER OF THE TASK YOU WANT TO REMOVE: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(todoList.size())) {
        todoList.erase(todoList.begin() + taskNumber - 1);
        cout << "TASK REMOVED SUCCESSFULLY" <<endl;
    } else {
        cout << "INVALID TASK NUMBER" <<endl;
    }
}

int main() {
    int choice;

    do {
        cout << "------ TO-DO LIST MENU ------" <<endl;
        cout << "[+] ADD TASK" <<endl;
        cout << "[+] VIEW TASK" <<endl;
        cout << "[+] MARK AS COMPLETE" <<endl;
        cout << "[+] REMOVE TASK" <<endl;
        cout << "[+] QUIT" <<endl;
        cout << "\nENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddTask();
                break;
            case 2:
                ViewTasks();
                break;
            case 3:
                MarkTaskAsCompleted();
                break;
            case 4:
                RemoveTask();
                break;
            case 5:
                cout << "GOODBYE! SEE YOU SOON :)" <<endl;
                break;
            default:
                cout << "INVALID OPTION :( TRY AGAIN!!" <<endl;
        }
    } while (choice != 5);

    return 0;
}

