#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int a[1005][1005];

struct edge{
	int st, ed, wt;
};

int main()
{
	int n; cin >> n;
	vector<edge> v;
	REP(i,1,n) 
	{
		REP(j,1,n)
		{
			cin >> a[i][j];
			if(a[i][j] != 0 && i < j)
				v.push_back({i,j,a[i][j]});
		}
	}
	for(auto [x,y,z] : v)
		cout << x << ' ' << y << ' ' << z << endl;
}