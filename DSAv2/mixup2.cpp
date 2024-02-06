#include<bits/stdc++.h>
#include "E:\Code\Cprograming\debug.h"
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 20;
const ll mod = 1e9 + 7;

int n, k;
int cnt;
vector<int> a(N), x(N);
bool visited[N];

void back(int i, int pos)
{
	debug(x, visited);
	REP(j,pos,n)
	{
		if(abs(a[j] - x[i-1]) > k && !visited[a[j]])
		{
			x[i] = a[j];
			visited[a[j]] = true;
			if(i == n) ++cnt;
			else if(i < n) back(i+1,1);
			visited[a[i]] = false;
		}
	}
}

int main()
{
	cin >> n >> k;
	REP(i,1,n) cin >> a[i];
	back(1,1);
	cout << cnt << endl;
}