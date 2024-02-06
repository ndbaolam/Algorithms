#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
vector<int> a[1005];
int b[1005][1005];
int main()
{
    int n; cin >> n;
    REP(i,1,n)
    	REP(j,1,n)
    		cin >> b[i][j];

    REP(i,1,n)
    {
    	REP(j,1,n)
    	{
    		if(b[i][j] && i > j)
    			cout << i << ' ' << j << endl;
    	}
    }
    cout << endl;
    REP(i,1,n)
    {
    	REP(j,1,n)
    	{
    		if(b[i][j])
    			a[i].push_back(j);
    	}
    }
    REP(i,1,n)
    {
    	cout << i << " : ";
    	REP(j,0,(int)a[i].size() - 1)
    		cout << a[i][j] << ' ';
    	cout << endl;
    }
}