/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/
struct node*SortedInsert(struct node * head, struct node *newNode);
#include <stdio.h>
#include<stddef.h>
struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {
	if (!head || !head->next)
		return head;
	struct node * nextcurrent = head->next;
	struct node * result = head;
	result->next = NULL;
	while (nextcurrent)
	{
		struct node *temp = nextcurrent;
		nextcurrent = nextcurrent->next;
		result = SortedInsert(result, temp);
	}
	return result;
	}
struct node*SortedInsert(struct node * head, struct node *nextnode)
{
	if (head == NULL || head->num >= nextnode->num)
	{
		nextnode->next = head;
		head = nextnode;
		return head;
	}
	struct node *tempptr = head;
	struct node *prev = NULL;
	while (tempptr != NULL && tempptr->num < nextnode->num)
	{
		prev = tempptr;
		tempptr = tempptr->next;
	}
	nextnode->next = tempptr;
	prev->next = nextnode;
	return head;
}