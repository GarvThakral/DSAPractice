#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function prototypes
void sortStack(stack<int>& s);
void insertSorted(stack<int>& s, int x);

int main() {
    // Test Case 1
    stack<int> s1;
    s1.push(3);
    s1.push(1);
    s1.push(4);
    s1.push(2);

    cout << "Original Stack 1: ";
    stack<int> temp1 = s1;
    while(!temp1.empty()) {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    sortStack(s1);  // Your recursive implementation

    cout << "Sorted Stack 1: ";
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl << endl;

    // Test Case 2
    stack<int> s2;
    s2.push(10);
    s2.push(5);
    s2.push(15);
    s2.push(0);

    cout << "Original Stack 2: ";
    stack<int> temp2 = s2;
    while(!temp2.empty()) {
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout << endl;

    sortStack(s2);  

    cout << "Sorted Stack 2: ";
    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}

void sortStack(stack<int>& s) {
    if(s.empty()) return;
    int popped = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,popped);
}

void insertSorted(stack<int>& s, int x) {
    if(s.empty()){
        s.push(x);
        return;
    }
    if(x >= s.top()){
        s.push(x);
        return;
    }
    int bigger = s.top();
    s.pop();
    insertSorted(s,x);
    s.push(bigger);

}
