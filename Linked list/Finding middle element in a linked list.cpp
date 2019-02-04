int getMiddle(Node *head)
{
    Node *temp = head;
    int N = 0;
    while (temp) {
        N++;
        temp = temp->next;
    }
    
    int cnt = (N & 1)? (N+1)/2 : (N/2)+1;
    cnt--;
    while (cnt--) {
        head = head->next;
    }
    return head->data;
}
