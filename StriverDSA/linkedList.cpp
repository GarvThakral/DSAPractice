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