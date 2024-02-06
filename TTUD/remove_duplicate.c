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

int used[10005];

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

void create_list(node **head1)
{
	int n; scanf("%d", &n);
	REP(i, 1, n)
	{
		int x; scanf("%d", &x);
		push_back(head1, x);
	}
}

void remove_duplicate(node* head)
{
    node *tmp1 = head;
    while (tmp1 != NULL && tmp1->next != NULL) 
    {
        node *tmp2 = tmp1;
        while (tmp2->next != NULL) 
        {
            if (tmp1->val == tmp2->next->val) 
            {
                node *p = tmp2->next;
                tmp2->next = tmp2->next->next;
                free(p);
            }
            else tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}

int main()
{
	node *head = NULL;
	create_list(&head);
	remove_duplicate(head);

	while(head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}