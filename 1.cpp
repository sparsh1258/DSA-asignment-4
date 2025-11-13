#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = val;
        cout << val << " inserted." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " removed." << endl;
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is Empty!" << endl;
        else
            cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
            break;
        case 6:
            cout << (q.isFull() ? "Queue is Full" : "Queue is Not Full") << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 7);
    return 0;
}
