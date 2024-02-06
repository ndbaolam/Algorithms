#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define DREP(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
const int maxn = 256;

typedef struct node{
	char name[maxn];
	struct node *left, *right;
	//left most child
	//right sibling
} node;

node *make_node(char *name)
{
	node *p = (node*)malloc(sizeof(node));
	strcpy(p->name, name);
	p->left = NULL;
	p->right = NULL;
}

node *find(node *r, char *name)
{
	if(r == NULL) return NULL;
	if(strcmp(r->name, name) == 0) return r;
	node *p = r->left;
	while(p != NULL)
	{
		node *q = find(p, name);
		if(q != NULL) return q;
		q = q->right;
	}
}

node *add_last(node *p, char *name)
{
	if(p == NULL) return make_node(name);
	p->right = add_last(p->right, name);
	return p;
}

void add_child(char *name, char *child)
{
	node *r = find(root, name)
	if(r == NULL) return;
	r->left = add_last(r->left, child);
}

void print_tree(node *r)
{
	if(r == NULL) return;
	printf("%s: ", r->name);
	node *p = r->left;
	while(p != NULL)
	{
		printf("%s ", p->name);
		p = p->right;
	}
	printf("\n");
	p = r->left;
	while(p != NULL)
	{
		print_tree(p);
		p = p->right;
	}
}

void print_tree_file(node *r, FILE *f)
{
	if(r == NULL) return;
	fprintf(f, "%s: ", r->name);
	node *p = r->left;
	while(p != NULL)
	{
		printf("%s ", p->name);
		p = p->right;
	}
	fprintf(f, " $\n");
	p = r->left;
	while(p != NULL)
	{
		print_tree(p, f);
		p = p->right;
	}
}


void loadTree(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    root = NULL;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "$$") == 0) break;
        char* token = strtok(line, " ");
        char name[256];
        strcpy(name, token);
        if (root == NULL) {
            root = makeNode(name);
        }
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token == NULL || strcmp(token, "$") == 0) break;
            add_c hild(name, token);
        }
    }
    fclose(f);
}

int main()
{

}