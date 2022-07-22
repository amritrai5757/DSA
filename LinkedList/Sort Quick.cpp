Node *getTail(Node *cur){
    while (cur && cur->next)cur = cur->next;
    return cur;
}

Node *partition(Node *head, Node *tail, Node **newHead, Node **newTail){
    Node *pivot = tail;
    Node *prev = NULL, *cur = head;
    while (cur != pivot){
        if (cur->data < pivot->data){
            if ((*newHead) == NULL)(*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else{
            if (prev)prev->next = cur->next;
            Node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == NULL)(*newHead) = pivot;
    (*newTail) = tail;
    return pivot;
}

Node *sort(Node *head, Node *tail){
    if (!head)return head;
    Node *newHead = NULL, *newTail = NULL;
    Node *pivot = partition(head, tail, &newHead, &newTail);
    if (newHead != pivot){
        Node *temp = newHead;
        while (temp->next != pivot)temp = temp->next;
        temp->next = NULL;
        newHead = sort(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next =sort(pivot->next, newTail);
    return newHead;
}

Node *quickSort(Node *head){
    head = sort(head,getTail(head));
    return head;
}
