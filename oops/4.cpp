#include <iostream>
#include <cstdlib>
#define MAX_SIZE 100
using namespace std;

class Queue {
private:
    int item;
    int arr_queue[MAX_SIZE];
    int rear;
    int front;

public:
    // Constructor to initialize queue
    Queue() : rear(0), front(0) {}

    // Function to insert an element into the queue
    void insert() {
        if (rear == MAX_SIZE) {
            cout << "\n## Queue Reached Max!";
        } else {
            cout << "\nEnter the value to be inserted: ";
            cin >> item;
            arr_queue[rear++] = item;
            cout << "\n## Position: " << rear << " , Inserted Value: " << item;
        }
    }

    // Function to remove an element from the queue
    void removeData() {
        if (front == rear) {
            cout << "\n## Queue is Empty!";
        } else {
            cout << "\n## Position: " << front + 1 << " , Removed Value: " << arr_queue[front];
            front++;
        }
    }

    // Function to display the queue elements
    void display() {
        if (front == rear) {
            cout << "\n## Queue is Empty!";
        } else {
            cout << "\n## Queue Size: " << (rear - front);
            for (int i = front; i < rear; i++) {
                cout << "\n## Position: " << i + 1 << " , Value: " << arr_queue[i];
            }
        }
    }
};

int main() {
    int choice;
    Queue obj;
    cout << "\nSimple Queue Example - Class and Member Functions in C++";

    do {
        cout << "\n\nQueue Main Menu";
        cout << "\n1. Insert \n2. Remove \n3. Display \n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.removeData();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout << "\nExiting Program.";
            exit(0);
        default:
            cout << "\nInvalid Choice! Please try again.";
        }
    } while (true);

    return 0;
}
