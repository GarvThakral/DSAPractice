#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


ListNode* sortOnes(ListNode* head){


    ListNode* Two = new ListNode();
    ListNode* Zero = new ListNode();
    ListNode* One = new ListNode();

    ListNode* newTwo = Two;
    ListNode* newZero = Zero;
    ListNode* newOne = One;
    
    ListNode* temp = head;

    while(temp!=nullptr){
        if(temp->val == 0){
            newZero->next = temp;
            newZero = newZero->next;
        }else if(temp->val == 1){
            newOne->next = temp;
            newOne = newOne->next;
        }else{
            newTwo->next = temp;
            newTwo = newTwo->next;
        }
        temp = temp->next;
    }
    newZero->next = One->next;
    newOne->next = Two->next;
    newTwo->next = nullptr;  
    return Zero->next;
}


void traverse(ListNode* head){
    while(head!=nullptr){
        cout << head->val ;
        head = head->next;
    }
    cout << endl;
    return;
}



int main(){
     ListNode* head = new ListNode(1);
     head->next = new ListNode(0);
     head->next->next = new ListNode(2);
     head->next->next->next = new ListNode(0);
     head->next->next->next->next = new ListNode(1);

     ListNode* newHead = sortOnes(head);
    traverse(newHead);
    }