/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<stddef.h>
struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {
	struct node*current, *nextcurrent, *prev, *temp1, *temp;
	temp1 = NULL;
	if (head == NULL)
		return NULL;
	else
	{
		while (temp1 != head->next)
		{
			current = prev = head;
			nextcurrent = current->next;
			while (current != temp1)
			{
				if (current->num > nextcurrent->num)
				{
					if (current ==head)
					{
						temp = nextcurrent;
						nextcurrent = current;
						current = temp;
						head = nextcurrent;
						prev = nextcurrent;
					}
					else
					{
						temp = nextcurrent;
						nextcurrent = current;
						current = temp;
						prev->next = nextcurrent;
						prev = nextcurrent;
					}
				}
				else
				{
					prev = current;
					current = current->next;
				}
				nextcurrent = current->next;
			}
			if (nextcurrent == temp1)
				temp1 = current;
		}
		return head;
	}
}