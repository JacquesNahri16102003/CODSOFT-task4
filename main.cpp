#include "ToDolist.h"
#include <string>

int main() {
    int choice;
    ToDoList list;
    int position;
    int index;
    string task;
    Task t;

    do {
        cout << "\nWelcome to the To Do List program" << endl << endl;
        cout << "Please choose an option:" << endl;
        cout << "1: Add Task At Beginning" << endl;
        cout << "2: Add Task At End" << endl;
        cout << "3: Add Task At Position" << endl;
        cout << "4: Delete Task At Position" << endl;
        cout << "5: Mark Task As Completed" << endl;
        cout << "6: Exit Program" << endl << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Input the task to insert: " << endl;
                cin.ignore();
                getline(cin, task);
                t = {task};
                if (list.addAtBeginning(t)) {
                    cout << "Task was inserted successfully in the beginning of the list" << endl;
                    cout << "The list now is:" << endl;
                    cout << list << endl;
                }
                break;

            case 2:
                cout << "Input the task to insert: " << endl;
                cin.ignore();
                getline(cin, task);
                t = {task};
                if (list.addAtEnd(t)) {
                    cout << "Task was inserted successfully in the end of the list" << endl;
                    cout << "The list now is:" << endl;
                    cout << list << endl;
                }
                break;

            case 3:
                cout << "Please enter the position of the list you would like to insert an element at (any value >= 1):" << endl;
                cin >> position;
                cout << "Input the task to insert: " << endl;
                cin.ignore();
                getline(cin, task);
                t = {task};
                if (list.addAtPosition(t, position - 1)) {
                    cout << "Task was inserted successfully at the specified position in the list" << endl;
                    cout << "The list now is:" << endl;
                    cout << list << endl;
                }
                break;


            case 4:
                cout << "Please enter the position of the element to delete (any value >= 1):" << endl;
                cin >> position;
                if (list.removeAtPosition(position - 1)) {
                    cout << "Task was deleted successfully at position " << position << endl;
                    cout << "The list now is:" << endl;
                    cout << list << endl;
                }
                break;

            case 5:
                cout << "Please enter the task number to mark it complete (any value >= 1):" << endl;
                cin >> position;
                if (list.markCompleted(position - 1)) {
                    cout << "Task " << position << " was marked as completed" << endl;
                    cout << "The list now is:" << endl;
                    cout << list << endl;
                }

                break;
            default:
                break;
        }

    } while (choice != 6);
    cout << "Thank you for using this program";

    return 0;
}
