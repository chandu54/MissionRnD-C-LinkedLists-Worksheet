/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stddef.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int K) {
	struct node*temp,*temp1,*temp2;
	int nodecount = 0, i,p,j=1,t=1,count=0;
	temp =temp1= head;
	if (head == NULL || K <=1)
		return NULL;
	else
	{
		while (temp != NULL)
		{
			nodecount++;
			temp = temp->next;
		}
		if (K > nodecount)
			return head;
		while ((K*j)<=nodecount)
		{
				for (p =t ; p < (K*j)-1-count ; p++)
					temp1 = temp1->next;
				t = p;
				temp2 = temp1->next;
				temp1->next = temp2->next;
				free(temp2);
				j++;
				count++;
		}
		return head;
	}
}
