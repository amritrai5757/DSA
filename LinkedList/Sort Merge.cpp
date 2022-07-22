Merge Sort is preferred for LinkedList and Quick Sort for arrays   

//Tc=o(nlogn)
Node* Merge2SortedList(Node* head1,Node* head2){
        Node* nodee=new Node(0);  //New node is created whose address is kept in nodee
        Node* temp=nodee;         //New node address is shared with temp and now whatever is added through temp connects to new node
        while(head1 && head2){
            if(head1->data<=head2->data){
                temp->next=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                head2=head2->next;
            }
            temp=temp->next;
        }
        while(head1){
              temp->next=head1;
              temp=temp->next;
              head1=head1->next;
        }
        while(head2){
             temp->next=head2;
             temp=temp->next;
             head2=head2->next;
        }    
        return nodee->next;
}
    


Node* MidofList(Node* head){   
        if(!head)return NULL;
        Node* slow=head;
        Node* fast=head;
        while( fast && fast->next && fast->next->next){  //To get 1st middle if 2 middles are present, use fast->next->next
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;      
}


void MergeSort(Node** head){   
    if (*head==NULL || ((*head)->next)==NULL) return;  //Write (*head)->next while using next with double pointer double pointer is used with &
    Node* a=*head;
    Node* mid=MidofList(*head);
    Node* b=mid->next;
    mid->next=NULL;
    MergeSort(&a);
    MergeSort(&b);
    *head = Merge2SortedList(a, b);
}


Node* mergeSort(Node* head) {
    MergeSort(&head);
    return head;
}
