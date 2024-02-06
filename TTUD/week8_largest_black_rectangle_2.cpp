#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int c[1005][1005];
int n, m;

void first_left_smaller(int a[], int n, int d[])
{
	stack<int> st;
	DREP(i, n, 1)
	{
		while(!st.empty() and a[st.top()] > a[i])
		{
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		d[st.top()] = 0;
		st.pop();
	}
}

void first_right_smaller(int a[], int n, int d[])
{
	stack<int> st;
	REP(i, 1, n)
	{
		while(!st.empty() and a[st.top()] > a[i])
		{
			d[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		d[st.top()] = n + 1;
		st.pop();
	}
}

void solve(int a[], int &ans, int n)
{
	int left[n], right[n];
	first_left_smaller(a, n, left);
	first_right_smaller(a, n, right);
	REP(i, 1, n)
		ans = max(ans, (right[i] - left[i] - 1) * a[i]);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	cin >> m >> n;
	REP(i, 1, m) REP(j, 1, n) cin >> c[i][j];
	int ans = 0;

	REP(i, 1, m)
	{
		REP(j, 1, n)
			c[i][j] = (c[i][j] == 0) ? 0 : c[i - 1][j] + 1;
		solve(c[i], ans, n);
	}
	cout << ans;
}