/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void swap1(struct node *a, struct node *b){
	int temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
}
void sll_012_sort(struct node *head){
	int temp1 = 0;
	int flag = 1;
	struct node *end = NULL, *first = head;
	while (flag){
		flag = 0;
		while (first->next != end){//since for every iteration last element is sorted,so no need to sort that one again
			if (first->data > (first->next)->data){
				swap1(first, first->next);
				flag = 1;
			}
			first = first->next;
		}
		end = first;
		first = head;//should point to start to contine with iterations
	}
}