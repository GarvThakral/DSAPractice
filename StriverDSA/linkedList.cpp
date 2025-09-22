ListNode* insertAtHead(ListNode* &head, int X) {
    ListNode* newNode = new ListNode(X);
    if(head == nullptr){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}    

ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newNode = new ListNode(X);
        newNode->next = head;
        head->prev  = newNode;
        head = newNode;
        return head;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare!=nullptr && hare->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise;
    }


    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode* , int> newMap;
        while(temp!=nullptr){
            newMap[temp]+=1;
            if(newMap[temp] > 1){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* tortoise = head;
        ListNode* hare = head;
        ListNode* prev = head;
        while(hare!=nullptr && hare->next!=nullptr){
            prev = tortoise;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        if(tortoise->next!=nullptr){
            prev->next = tortoise->next;
        }else{
            prev->next = nullptr;
        }
        return head;
    }
};

bool isPalindrome(ListNode* head) {
    vector<int> list1;
    vector<int> list2;
    ListNode* temp = head;
    while(temp!=nullptr){
        list1.push_back(temp->val);
        list2.push_back(temp->val);
        temp = temp->next;
    }
    reverse(list2.begin(),list2.end());
    return list1 == list2;
}