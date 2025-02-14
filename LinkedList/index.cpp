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

int listSize(Node*& head){
    int size = 0;
    if(head == nullptr){
        return size;
    } 
    Node* temp = head;
    while(temp != nullptr){
        size += 1;
        temp = temp->next;
    }
    return size;
}

void addToHead(Node*& head , int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    cout << "Added " << value << " to the head " << endl;
}

void addToTail(Node*& head , int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Added "<< value << " to the tail " << endl;
}

void addToNPos(Node*& head , int value , int pos){
    int size = listSize(head);
    if(pos > size+1 || pos <= 0){
        cout << "Index out of bounds" << endl;
        return;
    }
    if(pos == 1){
        addToHead(head,value);
        cout << "Added " << value << " to position" << pos << endl; 
        return;
    }
    if(pos == size+1){
        addToTail(head,value);
        cout << "Added " << value << " to position" << pos << endl; 
        return;
    }
    int i = 1;
    Node* temp = head;
    Node* newNode = new Node(value);
    while(i != pos-1){
        i++;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Added " << value << " to position" << pos << endl; 
}

void deleteFromHead(Node*& head){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return;
    }
    if(head->next == nullptr){
        cout << "Deleted " << head->data << " from the list" << endl;
        delete head;
        head = nullptr;
        return;
    }
    cout << "Deleted " << head->data << " from the list" << endl;
    Node* temp = head;
    head = head->next;
    delete temp; 
}

void deleteFromTail(Node*& head){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return;
    }
    if(head->next == nullptr){
        cout << "Deleted " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    Node* delNode = temp->next->next;
    cout << "Deleted " << temp->next->data << " from the list" << endl;
    temp->next = nullptr;
    delete delNode;

}

void deleteFromNPos(Node*& head , int pos){
    int size = listSize(head);
    if(pos > size || pos <= 0 ){
        cout << "Invalid index" << endl;
        return;
    }
    if(pos == 1){
        deleteFromHead(head);
        return;
    }
    if(pos == size){
        deleteFromTail(head);
        return;
    }
    int i = 1;
    Node* temp = head;
    while(i != pos-1){
        temp = temp->next;
        i++;
    }
    Node* delNode = temp->next;
    Node* nextNode = temp->next->next;
    temp->next = nextNode;
    delete delNode;
}

void reverseList(Node*& head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = head->next;
    while(next != nullptr){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
        curr->next = prev;
    }
    head = curr;
}

void traverse(Node*& head){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(10);
    addToHead(head,9);
    addToHead(head,8);
    addToHead(head,7);
    reverseList(head);
    traverse(head);
    return 0;
}