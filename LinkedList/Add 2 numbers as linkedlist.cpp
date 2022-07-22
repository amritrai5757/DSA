   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(), *curr=l3;
        int carry=0;
        while(l1||l2||carry)
        {
            if(l1){
                carry+=l1->val;
                l1=l1->next;
            }
            if(l2){
                carry+=l2->val;
                l2=l2->next;
            }
            curr->next=new ListNode(carry%10);
            carry/=10;
            curr=curr->next;
        }
        return l3->next;
   }
