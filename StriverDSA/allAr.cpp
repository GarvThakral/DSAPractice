#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


vector<int> twosum(vector<int> nums , int target){
    unordered_map<int , int> num;
    for(int i = 0 ; i < nums.size() ;i++){
        int remainder = target-nums[i];
        if(num.find(remainder) != num.end()){
            return {num[remainder],i};
        }
        num[nums[i]] = i;
    }
    return {};
}

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

ListNode* reverse(ListNode*& head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr!=nullptr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


ListNode* addOne(ListNode*& head){

    ListNode* temp = reverse(head);
    if(temp->val < 9){
        temp->val+=1;
        return reverse(temp);
    }else{
        int carry = 1;
        ListNode* newTemp = temp;
        while(newTemp!=nullptr && newTemp->val == 9){
            newTemp->val = 0;
            newTemp = newTemp->next;
        }
        if(newTemp == nullptr){
            ListNode* final = reverse(temp);
            ListNode* one = new ListNode(1);
            one->next = final;
            return one;
        }
        else{
            newTemp->val += 1;
        }
    }
    return reverse(temp);
    
    
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
    vector<int> nums = {2,2,1,1,1,2,2}; 

    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(9);

    traverse(head);
    ListNode* newHead = addOne(head);
    traverse(newHead);

}