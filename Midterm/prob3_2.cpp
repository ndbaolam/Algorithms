#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int d[N];
bool used[N];

int sovle(){
	int n; cin >> n;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int top = q.front(); q.pop();
		if(top == 0) return d[top];
		if(top >= 5 && !used[top - 5]) {
			q.push(top - 5);
			d[top - 5] = d[top] + 1;
			used[top - 5] = true;
		}
		if(top <= 1e4 && !used[top + 2]){ 
			q.push(top + 2);
			d[top + 2] = d[top] + 1;
			used[top + 2] = true;
		}
	}
	return -1;
}

int main(){
	cout << sovle();
}