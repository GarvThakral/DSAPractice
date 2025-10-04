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
    if(head->val == target && head->next == nullptr){
        return nullptr;
    }
    ListNode* temp = head;
    while( temp!= nullptr){
        if(temp->val == target){
            if(temp->next == nullptr){
                ListNode* prevNode = temp;
                temp->prev->next = nullptr;
                delete prevNode;
            }
            else if(temp->prev == nullptr){
                ListNode* prevTemp = temp;
                temp = temp->next;
                temp->prev = nullptr;
                delete prevTemp;
                head = temp;
            }else{
                ListNode* tempPrev = temp->prev;
                ListNode* tempNext = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = tempPrev;
                temp = tempNext;
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


int main() {
    ListNode* head = new ListNode(10);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(10);
    ListNode* n4 = new ListNode(10);
    ListNode* n5 = new ListNode(6);
    ListNode* n6 = new ListNode(10);

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
    // ListNode* newHead = deleteAllOccurrences(head,10);

    // traverse(newHead);

    set<vector<int>> answer = findSumPair(head , 5);
    for(auto x:answer){
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}
