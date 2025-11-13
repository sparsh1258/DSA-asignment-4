#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    unordered_map<char, int> freq;

    cout << "Output: ";
    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        // Remove characters from front until first non-repeating found
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Input: " << s << endl;
    firstNonRepeating(s);

    return 0;
}
