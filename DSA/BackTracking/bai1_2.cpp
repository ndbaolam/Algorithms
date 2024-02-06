#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int INF = 1e9;
const int MAX = 1e9+5;
const ll mod = 1e9+7;

int n, k, s;
int x[25];
int sum, cnt;

void ql(int i, int sum, int pos)
{
	for(int j=pos;j<=n;j++)
	{
		if(sum+j <= s)
		{
			x[i]=j;
			if(i==k)
			{
				if(sum+x[i]==s) cnt++;
			}
			else ql(i+1,sum+x[i],j+1);
		}
	}
}

int main()
{
	cin >> n >> k >> s;
	ql(1,0,1);
	cout << cnt;
}