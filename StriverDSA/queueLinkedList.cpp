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



class Queue {
public:
    ListNode* front ;
    ListNode* back ;
    int size;
    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    void enqueue(int x){
        size++;
        ListNode* newNode = new ListNode(x);
        if(front == nullptr){
            front = newNode;
            back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }
    void dequeue(){
        if(front == nullptr){
            cout << "Empty " << endl;
            return;
        }
        size--;
        ListNode* oldNode = front;
        if(front->next == nullptr){
            delete front;
            front = nullptr;
            back = nullptr;
            return;
        }
        front = front->next;
        delete oldNode;
    }

    int top() {
        if(front == nullptr){
            return INT_MIN;
        }
        return front->val;
    }

    int getSize(){
        return size;
    }
    
};
int main(){
    Queue q ;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.top();
    cout << q.getSize();
    q.dequeue();
    cout << q.top();
    cout << q.getSize();

}

