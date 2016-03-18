/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int pos =1, len = 0;
	if (head == NULL||K<=0)
		return NULL;
	struct node *curr = head, *prev = NULL;
	while (curr!= NULL){
		curr = curr->next;
		len++;
	}
	if (K>len)return head;
	curr = head;
	while (curr != NULL && pos%K == 0){
		pos++;
		head = curr->next;
		curr = head;
	}
	if (curr == NULL)return head;
	while (curr != NULL){
		while((pos+1)%K==0&&curr!=NULL){
			prev = curr;
			curr = curr->next;
			pos++;
		}
		if (curr == NULL)break;
		prev->next = curr->next;
		curr->next = NULL;
		curr = prev->next;
	}
	return head;
}