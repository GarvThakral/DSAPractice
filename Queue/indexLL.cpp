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
Node* tail = head;
void enqueue(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
        cout << value << " has been enqueued" << endl;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    cout << value << " has been enqueued" << endl;
}

int dequeue(){
    if(head == nullptr){
        cout << "The queue is empty" << endl;
        return 0;
    }
    Node* deqNode = head;
    int returnVal = deqNode->data;
    head = head->next;
    delete deqNode;
    return returnVal;
}

int front(){
    if(head == nullptr){
        cout << "The queue is empty" << endl;
        return 0;
    }
    return head->data;
}

int rear(){
    if(head == nullptr){
        cout << "The queue is empty" << endl;
        return 0;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

bool isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}

int size(){
    int size = 0;
    if(head == nullptr){
        return size;
    }
    Node* temp = head;
    while(temp != nullptr){
        size ++;
        temp = temp->next;
    }
    return size;
}

int main(){
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    bool data = isEmpty();
    cout << data;
    return 0;
}

