ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenHead = even;

        while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        if(odd == nullptr){
            odd = evenHead;
        }else{
            odd->next = evenHead;
        }
        return head;
    }