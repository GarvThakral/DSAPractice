#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function prototypes
void reverseStack(stack<int>& s);
void insertReversed(stack<int>& s, int x);

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

    reverseStack(s1);  // Your recursive implementation

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

    reverseStack(s2);  

    cout << "Sorted Stack 2: ";
    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}

void reverseStack(stack<int>& s) {
    if(s.empty()) return;
    int popped = s.top();
    s.pop();
    reverseStack(s);
    insertReversed(s,popped);
}

set<vector<int>> glob;

void recSub(vector<int> temp,vector<int>& nums,int index){
    if(index == nums.size()){
        return ;
    }
    temp.push_back(nums[index]);
    glob.insert(temp);
    recSub(temp,nums,index+1);
    temp.pop_back();
    glob.insert(temp);
    recSub(temp,nums,index+1);

}
vector<vector<int>> subsets(vector<int>& nums) {
    recSub({},nums,0);
    vector<vector<int>> answer (glob.begin(),glob.end());
    return answer;
}

void insertReversed(stack<int>& s, int x) {
    if(s.empty()){
        s.push(x);
        return;
    }    
    int popped = s.top();
    s.pop();
    insertReversed(s,x);
    s.push(popped);
}
