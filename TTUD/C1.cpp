#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[256];
	struct node *left, *right;
} node;
node *root;

node *makeNode(char * name)
{
	node *p = (node*)malloc(sizeof(node));
	strcpy(p->name, name);
	p->left = NULL; p->right = NULL;
	return p;
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
		p = p->right;
	}
	return NULL;
}
//Tim kiem node con tan cung ben trai truoc
//r toi node con ben phai

node *addLast(node *p, char *name)
{
	if(p == NULL) return makeNode(name);
	p->right = addLast(p->right, name);
	return p;
}
// Them vao tan cung ben phai

void addChild(char *name, char *child)
{
	node *r = find(root, name);
	if(r == NULL) return;
	r->left = addLast(r->left, child);
}
//Them node con ben phai vao node con ben trai
// cua node dang xet

void printTree(node *r)
{
	if(r == NULL) return;
	printf("%s: ", r->name);
	node *p = r->left;
	while(p != NULL)
	{
		printf("%s: ", p->name);
		p = p->right;
	}
	printf("\n");
	p = r->left;
	while(p != NULL)	
	{
		printTree(p);
		p = p->right;
	}
}

void printTreeF(node *r, FILE *f)
{
	if(r == NULL) return;
	fprintf(f, "%s: ", r->name);
	node *p = r->left;
	while(p != NULL)
	{
		fprintf(f, "%s: ", p->name);
		p = p->right;
	}
	fprintf(f, " $\n");
	p = r->left;
	while(p != NULL)	
	{
		printTreeF(p, f);
		p = p->right;
	}
}

int main()
{
	FILE *inp = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	char name[256];
	while(fgets(name, sizeof(name), inp))
	{
		//name[strlen(name) - 1] = '\0';
		if(strcmp(name, "$$") ==  0) break;
		char *tok = strtok(name, " ");
		while(tok != NULL)
		{
			if(strcmp(tok, "$\n") == 0) break;
			fprintf(out, "%s ", tok);
			tok = strtok(NULL, " ");
		}
		// fprintf(out, "%s\n", name);
	}
	fclose(inp);
	fclose(out);
}
