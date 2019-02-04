void rotate(struct node **head_ref, int k) {
    struct node *temp = *head_ref;
    
    struct node *temp2 = *head_ref;
    int N = 0;
    while (temp2) {
        N++;
        temp2 = temp2->next;
    }
    
    struct node *curNode = temp;
    struct node *starting_p = *head_ref;
    
    k %= N;
    
    if (k == 0) return;
    
    while (k--) {
        if (k == 1) temp = curNode->next;
        if (curNode->next != NULL)
            curNode = curNode->next;
    }
    
    *head_ref = curNode;
    
    while (curNode->next) {
        curNode = curNode->next;
    }
    
    curNode->next = starting_p;
    temp->next = NULL;
}
