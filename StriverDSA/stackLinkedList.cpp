#include <iostream>
#include <climits>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    } 
};

class StackLL{
public:
    ListNode* head;
    int size;
    StackLL(){
        head = nullptr;
        size = 0;
    }
    void push(int x){
        ListNode* newNode = new ListNode(x);
        size++;
        if(head == nullptr){
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    void pop(){
        if(head == nullptr){
            cout << "Empty stack cannot pop" << endl;
            return;
        }
        size--;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        ListNode* temp = head;
        while(temp->next->next!= nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    int getSize(){
        return size;
    }
    int top(){
        if(head == nullptr){
            cout << "Empty stack";
            return INT_MIN;
        }
        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        return temp->val;
    }
         
};


int main(){
    StackLL newStack;
    newStack.push(10);
    newStack.push(20);
    newStack.push(30);
    newStack.push(40);
    cout << newStack.top();
    newStack.pop();
    cout << newStack.top();
    newStack.pop();
    cout << newStack.top();
    cout << newStack.getSize();
}