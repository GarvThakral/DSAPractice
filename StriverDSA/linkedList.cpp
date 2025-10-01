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

ListNode* reverseLinkedList(ListNode*& head){
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

    bool isPalindrome(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare!=nullptr && hare->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        ListNode* reversedMid = reverseLinkedList(tortoise);
        while(reversedMid!=nullptr){
            if(head->val!=reversedMid->val){
                return false;
            }
            reversedMid = reversedMid->next;
            head = head->next;
        }
        return true;
    }

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return nullptr;
        }
        ListNode* hare = head;
        ListNode* tortoise = head;
        int index = 0;
        while (index < n && hare != nullptr) {
            hare = hare->next;
            index++;
        }
        if (hare == nullptr) {
            return head->next;
        }
        while(hare->next!=nullptr){
            hare = hare->next;
            tortoise = tortoise->next;
        }


        tortoise->next = tortoise->next->next;
        return head;
    }
};