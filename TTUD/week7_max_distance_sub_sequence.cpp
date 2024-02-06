#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

bool check(int a[], int c, int n, int mid)
{
	int pos = a[0];
	int cnt = 1;
	REP(i, 1, n - 1)
	{
		if(a[i] - pos >= mid)
		{
			pos = a[i];
			++cnt;
			if(cnt == c) return true;
		}
	}
	return false;
}

void solve(int a[], int n, int c)	
{
	sort(a, a + n);
	int left = 1, right = a[n - 1], res = -1;
	while(left < right)
	{
		int mid = left + right >> 1;
		if(check(a, c, n, mid))
		{
			res = max(res, mid);
			left = mid + 1;
		}
		else right = mid;
	}
	cout << res << endl;
}

int main()
{
	faster();
	
	int t; cin >> t;
	while(t--)	
	{
		int n, c; cin >> n >> c;
		int a[n];
		REP(i, 0, n - 1) cin >> a[i];
		solve(a, n, c);
	}
}