#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

struct node{
	//Sinhvien data;
	int data;
	node* next;
};

node* makeNode(int x)
{
	node* newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void traversal(node* head)
{
	while(head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

int size(node* head)
{
	int cnt = 0;
	while(head != NULL)
	{
		++cnt;
		head = head->next;
	}
	return cnt;
}

void pushFront(node*& head, int x)
{
	node* newNode = makeNode(x);
	newNode->next = head;
	head = newNode;
}

void pushBack(node*& head, int x)
{
	node* tmp = head;
	node* newNode = makeNode(x);
	if(head == NULL) 
	{
		head = newNode; 
		return;
	}
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newNode;
}

void insert(node*& head, int x, int k)
{
	int n = size(head);
	if(k < 1 || k > n + 1) return;
	if(k == 1) pushFront(head, x);

	node* newNode = makeNode(x);
	node* tmp = head;
	for(int i = 1;i <= k-2; i++)
		tmp = tmp->next;
	newNode->next = tmp->next;
	tmp->next = newNode;
}

void popFront(node*& head)
{
	if(head == NULL) return;
	node* tmp = head;
	head = head->next;
	delete tmp;
}

void popBack(node*& head)
{
	if(head == NULL) return;
	node* tmp = head;
	if(tmp->next == NULL)
	{
		head = NULL;
		delete tmp;
		return;
	}
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	node* last = tmp->next;
	tmp->next = NULL;
	delete last;
}

void menu(node* head)
{
	while(true)
	{
		cout << "---------------" << endl;
		cout << "1. PushFront" << endl;
		cout << "2. PushBack" << endl;
		cout << "3. Insert" << endl;
		cout << "4. PopBack" << endl;
		cout << "5. PopFront" << endl;
		cout << "0. Exit" << endl;
		cout << "---------------" << endl;
		cout << "Enter operation: ";
		int n; cin >> n;
		if(n == 1)
		{
			int x; cout << "Enter x: "; cin >> x;
			pushFront(head, x);
			cout << "Particals in Linkedlist:\n--> ";
			traversal(head);
			//cout << endl;
		}
		else if(n == 2)
		{
			int x; cout << "Enter x: "; cin >> x;
			pushBack(head, x);
			cout << "Particals in Linkedlist:\n--> ";
			traversal(head);
			//cout << endl;
		}
		else if(n == 3)
		{
			int x, pos; 
			cout << "Enter x, position: "; 
			cin >> x >> pos;
			insert(head, x, pos);
			cout << "Particals in Linkedlist:\n--> ";
			traversal(head);
			//cout << endl;
		}
		else if(n == 4) 
		{
			popBack(head);
			cout << "Particals in Linkedlist:\n--> ";
			traversal(head);
		}
		else if(n == 5)
		{
			popFront(head);
			cout << "Particals in Linkedlist:\n--> ";
			traversal(head);
		}
		else return;
	}
}

int main()
{
	node* head = NULL;
	srand(time(NULL));
	for(int i = 1; i <= 10; i++)
		pushBack(head, rand()%10);
	menu(head);
	return 0;
}