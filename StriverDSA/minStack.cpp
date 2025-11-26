#include <iostream>
#include <climits>
using namespace std;




class MinStack {
public:
    ListNode* head ;
    ListNode* min ;          
    MinStack() {
        head = nullptr;
        min = nullptr;
    }

    void push(int val) {
        ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
            min = newNode;
            return;
        }
        else if(min->val > val || min->val == val){
            ListNode* newMin = new ListNode(val);
            newMin->next = min;
            min = newMin;
        }
        newNode->next = head;
        head = newNode;
        return;
    }
    
    void pop() {
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            min = nullptr;
            cout << "Empty";
            return;
        }
        if(top() == min->val){
            if(min->next == nullptr){
                delete min;
                min = nullptr;
            }else{
                ListNode* oldMin = min;
                min = min->next;
                delete oldMin;
            }
        }
        ListNode* oldNode = head;
        head = head->next;
        delete oldNode;
        return;
    }
    
    int top() {
        if(head == nullptr){
            return INT_MIN;
        }
        return head->val;
    }
    
    int getMin() {
        if(min == nullptr){
            return INT_MIN;
        }else{
            return min->val;
        }
    }
};
