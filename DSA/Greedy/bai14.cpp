#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    int n, s, m; cin >> n >> s >> m;

    int day = s-s/7;
    if(s*m > n*day) cout << -1;
    else
    {
    	for(int i=1;i<=day;i++)
    	{
    		if(n*i>=s*m)
    		{
    			cout << i;
    			break;
    		}
    	}
    }
}

