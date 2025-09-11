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