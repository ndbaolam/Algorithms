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

void create_list(node **head1, node **head2)
{
	printf("DSLK 1:\n");
	int n; scanf("%d", &n);
	REP(i, 1, n)
	{
		int x; scanf("%d", &x);
		push_back(head1, x);
	}
	printf("DSLK 2:\n");
	scanf("%d", &n);
	REP(i, 1, n)
	{
		int x; scanf("%d", &x);
		push_back(head2, x);
	}
}

void merge(node *head1, node *head2, node **head3)
{
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->val > head2->val)
		{
			push_back(head3, head1->val);
			head1 = head1->next;
		}
		else if(head1->val < head2->val)
		{
			push_back(head3, head2->val);
			head2 = head2->next;
		}
		else
		{
			double a = head1->val + head2->val;
			push_back(head3, a);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	while(head1 != NULL)
	{
		push_back(head3, head1->val);
		head1 = head1->next;
	}
	while(head2 != NULL)
	{
		push_back(head3, head2->val);
		head2 = head2->next;
	}
}

int main()
{
	node *head1 = NULL, *head2 = NULL, *head3 = NULL;
	create_list(&head1, &head2);
	merge(head1, head2, &head3);

	printf("After merge: \n");
	while(head3 != NULL)
	{
		printf("%d ", head3->val);
		head3 = head3->next;
	}
}