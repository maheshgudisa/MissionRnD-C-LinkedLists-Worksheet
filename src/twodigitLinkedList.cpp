/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};
int pow(struct node *a){
	int temp = (a->digit1) * 10 + a->digit2;
	return temp;
}
int convert_sll_2digit_to_int(struct node *head){
	struct node *curr = head;
	int num1 = 0;
	if (head == NULL)return 0;
	while (curr != NULL){
		num1 = (num1 + pow(curr)) * 100;
		curr = curr->next;
	}
	num1 = num1 / 100;
	free(curr);
	return num1;
}
