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
#include<stddef.h>
struct node* head;

struct node {
	int num;
	struct node *next;
};
void insert(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = x;
	temp->next = head;
	head = temp;
}
struct node * numberToLinkedList(int N) {
	int x;
	head = NULL;
	if (N == 0)
		insert(0);
	if (N < 0)
		N = N*(-1);
		while (N != 0)
		{
			x = N %10;
			N = N / 10;
			insert(x);
		}
		return head;
}