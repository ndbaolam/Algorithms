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

int n, x[10];
bool used[10];

void in()
{
	for(int i=1;i<=n;i++)
		cout << x[i];
	cout << endl;
}

void ql(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(!used[j] && abs(j-x[i-1])>1)
		{
			x[i]=j;
			used[j]=true;
			if(i==n) in();
			else ql(i+1);
			used[j]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	x[0]=-1;
	ql(1);
}