#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Function to sort a queue in ascending order without using any extra space
void sortQueue(queue<int>& q) {
    int sz = q.size();
    if (sz <= 1) return; // nothing to sort if queue has 0 or 1 element

    // I’ll repeat this process 'sz' times to gradually fix the smallest elements
    for (int i = 0; i < sz; ++i) {
        int min_val = INT_MAX;  // to store the minimum value
        int min_index = -1;     // to remember where the minimum was
        int curr;

        // Step 1: Find the smallest element among the first (sz - i) elements
        for (int j = 0; j < sz; ++j) {
            curr = q.front();
            q.pop();

            // Only consider the first (sz - i) elements for finding min
            if (j < sz - i && curr <= min_val) {
                min_val = curr;
                min_index = j;
            }

            // I’ll put the element back since I can’t use extra space
            q.push(curr);
        }

        // Step 2: Remove all elements again and skip the one at 'min_index'
        // That’s the element I plan to move to the rear at the end
        for (int j = 0; j < sz; ++j) {
            curr = q.front();
            q.pop();

            if (j != min_index) {
                q.push(curr);
            }
            // If it’s the minimum element, I just skip pushing it now
        }

        // Step 3: Finally, I put the minimum element at the rear of the queue
        q.push(min_val);

        // Now, after each iteration, one smallest element is correctly placed at the rear
    }

    // After repeating the above steps, the entire queue will be sorted
}

int main() {
    queue<int> q;

    // I’m just using some sample data here; you can modify or take input from user
    int arr[] = {11, 5, 4, 21};
    for (int val : arr)
        q.push(val);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // I call my sorting function here
    sortQueue(q);

    // Display the sorted queue
    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
