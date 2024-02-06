#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define DREP(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
const int maxn = 100;

typedef struct node{
	int val;
	struct node* next;
} node;

node *make_node(int v)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->val = v;
	return newnode;
}

void push_front(node **head, int v)
{
	node *newnode = make_node(v);
	if(*head == NULL)
		*head = newnode;
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
}

void push_back(node **head, int v)
{
	node *newnode = make_node(v);
	if(*head == NULL)
		*head = newnode;
	else
	{
		node *tmp = *head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
	}
}



void traversal(node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}
int main()
{
	node *head = NULL;
	REP(i, 1, 10) push_front(&head, i);
	traversal(head);

	printf("\n");
	node *head1 = NULL;
	REP(i, 1, 10) push_back(&head1, i);
	traversal(head1);
}