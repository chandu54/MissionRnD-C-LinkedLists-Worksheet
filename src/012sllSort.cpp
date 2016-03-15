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

void sll_012_sort(struct node *head){
	struct node* current = head;
	struct node*insertionpointer = current;
	int temp;
	current = current->next;
	while (current != NULL)
	{
		insertionpointer = head;
		while (insertionpointer->next != current)
		{
			if (insertionpointer->data > current->data)
			{
				temp = insertionpointer->data;
				insertionpointer->data = current->data;
				current->data = temp;
			}
			else
				insertionpointer = insertionpointer->next;
		}
		current = current->next;
	}

	
}