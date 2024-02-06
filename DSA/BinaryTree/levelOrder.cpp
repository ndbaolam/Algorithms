#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = right = NULL;
	}
};

void makeNode(Node *root, int x, int y, char c){
	if(c == 'L'){
		root->left = new Node(y);
	}
	else{
		root->right = new Node(y);
	}
}
void insert(Node *root, int x, int y, char c){
	if(root == NULL) return;
	if(root->data == x){
		makeNode(root, x, y, c);
	}
	else{
		insert(root->left, x, y, c);
		insert(root->right, x, y, c);
	}
}

void levelOrder(Node *root){
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		Node *u = q.front(); q.pop();
		cout << u->data << " ";
		if(u->left != NULL) q.push(u->left);
		if(u->right != NULL) q.push(u->right);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
	int n; cin >> n;
	Node *root = NULL;
	for(int i = 0; i < n; i++){
		int x, y; char c;
		cin >> x >> y >> c;
		if(!root){
			root = new Node(x);
			makeNode(root, x, y, c);
		}
		else{
			insert(root, x, y, c);
		}
	}
	levelOrder(root);
}