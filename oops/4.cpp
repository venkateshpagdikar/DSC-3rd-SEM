#include <iostream.h>

#define MAX_SIZE 100

class Queue {
private:
    int item, i;
    int arr_queue[MAX_SIZE];
    int rear;
    int front;

public:
    Queue() {
        rear = 0;
        front = 0;
    }

    void insert() {
        if (rear == MAX_SIZE)
            cout << "\n## Queue Reached Max!";
        else {
            cout << "\nEnter The Value to be Insert : ";
            cin >> item;
            cout << "\n## Position : " << rear + 1 << " , Insert Value : " << item;
            arr_queue[rear++] = item;
        }
    }

    void removeData() {
        if (front == rear)
            cout << "\n## Queue is Empty!";
        else {
            cout << "\n## Position : " << front + 1 << " , Remove Value : " << arr_queue[front];
            front++;
        }
    }

    void display() {
        cout << "\n## Queue Size : " << (rear - front);
        for (i = front; i < rear; i++) {
            cout << "\n## Position : " << i + 1 << " , Value : " << arr_queue[i];
        }
    }
};

int main() {
    int choice, exit_p = 1;
    Queue obj;

    cout << "\nSimple Queue Example - Class and Member Functions in C++";
    do {
        cout << "\n\nQueue Main Menu";
        cout << "\n1.Insert \n2.Remove \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
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
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

    return 0;
}
