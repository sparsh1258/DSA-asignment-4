#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue to move new element to front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Top Element: " << q.front() << endl;
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    int choice, val;

    do {
        cout << "\n--- Stack using One Queue ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.top();
            break;
        case 4:
            st.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
