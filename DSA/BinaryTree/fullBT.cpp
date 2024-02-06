#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

struct node{
	int val;
	node *left, *right;
	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};

void makeNode(node *root, int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c)
{
	if(root == NULL) return;
	if(root->val == u) makeNode(root, u, v, c);
	else
	{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

bool check = true;
void travel(node *root)
{
	if(root->left and !root->right or root->right and !root->left)
	{
		check = false;
		return;
	}
	else if(root->left and root->right)
	{
		travel(root->left);
		travel(root->right);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	node *root = NULL;
	int n; cin >> n;
	while(n--)
	{
		int u, v; char c; cin >> u >> v >> c;
		if(root == NULL)
		{
			root = new node(u);
			makeNode(root, u, v, c);
		}
		else insertNode(root, u, v, c);
	}
	travel(root);
	if(check) cout << "YES";
	else cout << "NO";
}