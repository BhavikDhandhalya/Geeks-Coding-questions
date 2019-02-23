/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list elements.

Output:
For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

Example:
Input:
1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5

Explanation:
Testcase 2: Since, k = 2. So, we have to reverse everty group of two elements. Modified linked list is as 4, 2, 2, 1, 8, 7, 6, 5.
*/

struct node* rev(struct node *X, struct node *Y) {
	struct node *nextN = X->next;
	struct node *curN = X;
	struct node *prevN = X;

	while (nextN) {
		curN = nextN;
		nextN = nextN->next;
		curN->next = prevN;
		prevN = curN;
		if (curN == Y) break;
	}

	return curN;
}

struct node *reverse (struct node *head, int k) {
  // corner case, what if k == 1
  if (k == 1) return head;
  
	int cnt = 0;
	struct node *starting = head;
	struct node *temp = head;

	temp = starting;
	cnt = 1;

	while (cnt != k) {
		if (temp->next != NULL)
			temp = temp->next;
		else break;
		cnt++;
	}

	struct node *next_elem = temp->next;
	head = rev(starting, temp);

	struct node *nextE = NULL;
	
  // corner case, what if N == K
	if (next_elem == NULL) {
	    starting->next = NULL;
	}

	while (next_elem) {
		temp = next_elem;
		cnt = 1;

		while (cnt != k) {
			if (temp->next != NULL)
				temp = temp->next;
			else break;
			cnt++;
		}

		nextE = temp->next;

		starting->next = rev(next_elem, temp);

		starting = next_elem;

		if (nextE == NULL) next_elem->next = NULL;

		next_elem = nextE;
	}

	return head;
}
