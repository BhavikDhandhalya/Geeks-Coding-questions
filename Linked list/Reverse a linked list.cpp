Node* reverse(Node *head) {
    Node *nextNode = head->next;
    Node *currentNode = head;
    Node *prevNode = head;
    currentNode->next = NULL;
    
    while (nextNode) {
        currentNode = nextNode;
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
    }
    
    return currentNode;
}
