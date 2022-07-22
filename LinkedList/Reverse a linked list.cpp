    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head,*next=NULL, *prev = NULL;
        while (cur) {
            next = cur->next;    //next
            cur->next = prev;    //cur->next
            prev = cur;          //prev
            cur = next;          //cur
        }
        return prev;
    }
