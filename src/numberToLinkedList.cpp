/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	int i = 0, x;
	struct node *first = NULL, *temp;
	if (N == 0){
		first = (struct node *)malloc(sizeof(struct node));
		first->num = 0;
		first->next = NULL;
		return first;
	}
	if (N < 0)N = -N;
	while (N>0){
		x = N % 10;
		N = N / 10;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->num = x;
		if (first == NULL){
			first = temp;
			first->next = NULL;
		}
		else{
			temp->next = first;
			first = temp;
		}

	}
	return first;
}