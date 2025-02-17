#include <iostream>
using namespace std;

struct BinaryTree{
    int data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void insertNode(BinaryTree*& head , int val){
    if(head == nullptr){
        BinaryTree* newNode = new BinaryTree(val);
        head = newNode;
        return;
    }
    if(head->data > val){
        insertNode(head->left , val);
    }
    if(head->data < val){
        insertNode(head->right , val);
    }
}

void inorderTraversal(BinaryTree*& head){
    if(head == nullptr){
        return;
    }
    inorderTraversal(head->left);
    cout << head->left->data << " ";
    cout << head->data << " ";
    cout << head->right->data << " ";
}

int main(){
    BinaryTree* head = nullptr;
    insertNode(head,20);
    insertNode(head,10);
    insertNode(head,30);
    insertNode(head,5);
    insertNode(head,6);
    inorderTraversal(head);
    return 0;
}