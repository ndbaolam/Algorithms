#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int b[1005][1005];

int main()
{
	int n; cin >> n;
	vector<pair<int,int>> v;
	vector<int> a[n+1];
	REP(i,1,n) 
	{
		REP(j,1,n) 
		{
			cin >> b[i][j];
			if(b[i][j])
			{
				v.push_back({i,j});
				a[i].push_back(j);
				//a[j].push_back(i);
			}
		}
	}
	for(auto [x,y] : v)
		cout << x << ' ' << y << endl;
	cout << endl;
	REP(i,1,n)
	{
		cout << i << " : ";
		sort(all(a[i]));
		for(int x : a[i])
			cout << x << ' ';
		cout << endl;
	}
}