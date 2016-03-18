/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void swap(struct node *a, struct node *b){
	int temp;
	temp = a->num;
	a->num = b->num;
	b->num = temp;
}
struct node * sortLinkedList(struct node *head) {

	if (head == NULL)
		return NULL;
	int temp1 = 0;
	int flag = 1;
	struct node *end = NULL, *first;
	while (flag){
		flag = 0;
		first = head;
		while (first->next != end){
			if (first->num > (first->next)->num){
				swap(first, first->next);
				flag = 1;
			}
			first = first->next;
		}
		end = first;
		if (!flag)break;
	}

	return head;
}