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

int n, cnt;
int x[100], c[100], d1[100], d2[100];

void back(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(!c[j] && !d1[i-j+n] && !d2[i+j-1])
		{
			x[i]=j;
			c[j]=d1[i-j+n]=d2[i+j-1]=1;
			if(i==n) cnt++;
			else back(i+1);
			c[j]=d1[i-j+n]=d2[i+j-1]=0;
		}
	}
}

int main()
{
	cin >> n;
	back(1);
	cout << cnt;
}