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

int findMin(BinaryTree* head){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return 0;
    }
    while(head->left != nullptr){
        head = head->left;
    }
    return head->data;
}

int findMax(BinaryTree* head){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return 0;
    }
    while(head->right != nullptr){
        head = head->right;
    }
    return head->data;
}

int main(){
    BinaryTree* head = nullptr;
    insertNode(head,20);
    insertNode(head,10);
    insertNode(head,30);
    insertNode(head,32);
    insertNode(head,31);
    insertNode(head,39);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,4);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,1);
    int min = findMax(head);
    cout << min;
    return 0;
}