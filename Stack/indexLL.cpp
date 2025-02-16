#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr;
Node* stackTop = head;

void push(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        stackTop = newNode;
        cout << "Pushed " << val << " to the stack" << endl;
        return;
    }
    stackTop->next = newNode;
    stackTop = newNode;
    cout << "Pushed " << val << " to the stack" << endl;
}

int pop(){
    if(head == nullptr){
        cout << "The stack is empty" << endl;
        return 0;        
    }
    if(head->next == nullptr){
        int dat = head->data;
        delete head;
        head = nullptr;
        stackTop = nullptr;
        return dat;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    stackTop = temp;
    int dat = stackTop->data;
    delete temp->next;
    temp->next = nullptr;
    return dat;
    
}
int top(){
    if(head == nullptr){
        cout << "The stack is empty" << endl;
        return 0;        
    }
    return stackTop->data;
}

bool isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}   

int size(){
    if(head == nullptr){
        return 0;
    }
    int size = 0;
    Node* temp = head;
    while(temp != nullptr){
        size++;
        temp = temp->next;
    }
    return size;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    pop();
    pop();
    cout << top();
}