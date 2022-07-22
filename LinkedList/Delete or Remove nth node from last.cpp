ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* headd=new ListNode();  // To avoid edge case  while checking loop for while(node->next) not required for while(node)  :if only 1 node in linked list
        headd->next=head;                // To avoid edge case  while checking loop for while(node->next) not required for while(node)  :if only 1 node in linked list
        ListNode* fast=headd;            // To avoid edge case  while checking loop for while(node->next) not required for while(node)  :if only 1 node in linked list  
        ListNode* slow=headd;
        for(int i=0;i<n;i++){      //make a difference of n so that fast is always n node far from slow.
            fast=fast->next;
        }
        while(fast->next){   // reaching the node to remove 
            fast=fast->next;
            slow=slow->next;
        }
    
        ListNode* temp = slow->next;         //Code to delete the node slow->next
                                             // If u want to delete slow then :  ListNode*temp=node->next;   node->val = node->next->val;
        slow->next=slow->next->next;         //Code to delete a node
        delete temp;                         //Code to delete a node
     
        return headd->next;          // To avoid edge case : if only 1 node in linked list
}
