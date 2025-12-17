#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode * deleteAllOccurrences(ListNode*& head, int target) {
    if(head == nullptr){
        return head;
    }

    while (head && head->val == target) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    if(head == nullptr){
        return head;
    }
    
    ListNode* temp = head;

    while(temp!= nullptr){
        if(temp->val == target){
            if(temp->next == nullptr){
                ListNode* prevNode = temp->prev;
                prevNode->next = nullptr;
                delete temp;
                temp = nullptr;
            }else{
                ListNode* prevNode = temp->prev;
                ListNode* nextNode = temp->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete temp;
                temp = nextNode;
            }
        }else{
            temp = temp->next;
        }
    }
    return head;
}


void traverse(ListNode* head){
    while(head!=nullptr){
        cout << head->val ;
        head = head->next;
    }
    cout << endl;
    return;
}

set<vector<int>> findSumPair(ListNode* head,int key){
    unordered_map<int , int> newMap;
    set<vector<int>> answer;
    ListNode* temp = head;
    while(temp!=nullptr){
        int remaining = key-temp->val;
        if(newMap.find(remaining)!=newMap.end()){
            vector<int> tempVec = {remaining,temp->val};
            sort(tempVec.begin(),tempVec.end());
            answer.insert(tempVec);
        }
        newMap[temp->val] = 1;
        temp = temp->next;
    }
    return answer;
}


ListNode* removeDupes(ListNode* head){
    ListNode* temp = head;
    while(temp->next!= nullptr){
        if(temp->val == temp->next->val){
            ListNode* prevNode = temp->prev;
            ListNode* nextNode = temp->next;
            if(prevNode == nullptr){
                head = head->next;
                head->prev = nullptr;
                delete temp;
                temp = head;
            }else{
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete temp;
                temp = nextNode; 
            }
        }else{
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(1);
    ListNode* n6 = new ListNode(2);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    n5->next = n6;
    n6->prev = n5;


    // call your function
    ListNode* newHead = removeDupes(head);

    traverse(newHead);

    return 0;
}
