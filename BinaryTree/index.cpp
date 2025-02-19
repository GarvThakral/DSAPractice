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

void inorderTraversal(BinaryTree* head){
    if(head == nullptr){
        return;
    }
    inorderTraversal(head->left);
    cout << head->data << " ";
    inorderTraversal(head->right);
}

void preorderTraversal(BinaryTree* head){
    if(head == nullptr){
        return ;
    }
    cout << head->data << " ";
    preorderTraversal(head->left);
    preorderTraversal(head->right);

}

void postorderTraversal(BinaryTree* head){
    if(head == nullptr){
        return;
    }
    postorderTraversal(head->left);
    postorderTraversal(head->right);
    cout << head->data << " ";
}

int main(){
    BinaryTree* head = nullptr;
    insertNode(head,20);
    insertNode(head,10);
    insertNode(head,30);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,4);
    postorderTraversal(head);
    return 0;
}