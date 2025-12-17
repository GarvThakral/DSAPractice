#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value){
        val = value;
        next = nullptr;
    }
};


int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(11);
    head->next->next = new ListNode(12);
    head->next->next->next = new ListNode(13);
    head->next->next->next->next = new ListNode(14);
    head->next->next->next->next->next = new ListNode(15);

    head = reverseLinkedList(head);

    ListNode* temp = head;
    while(temp!=nullptr){
        cout << temp->val << "\n";
        temp = temp->next;
    }

}