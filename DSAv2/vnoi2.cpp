#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define supdate pre[A][B]-pre[a-1][B]-pre[A][b-1]+pre[a-1][b-1]
using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int INF = 1e9;
const int MAX = 1e9+5;
const ll mod = 1e9+7;

ll pre[505][505];
int a[505][505];
int m,n,k; 
int x,y,z,t;

void enter()
{
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
}

void update(ll &area, ll &ans, int &a, int &b, int &A, int &B)
{
	area = (A-a+1)*(B-b+1);
	if(ans>area)
	{
		ans=area;
		x=a; y=b; z=A; t=B;
	}
}

void solve()
{
	int a=1, b=1, A, B;
	ll sum,area, ans=INF;
	bool check = false;
	for(A=1;A<=n;A++)
	{
		for(B=1;B<=m;B++)
		{	
			sum = supdate;
			while(sum>=k && a<A && b<B)
			{	
				check=true;
				update(area, ans, a, b, A, B);			
				++a;
				sum = supdate;
				if(sum>k)
				{
					++b;
					sum = supdate;
				}
			}
		}
	}

	if(check)
	{
		cout << ans << endl;
		cout << x << ' ' << y << ' ' << z << ' ' << t;
	}
	else cout << -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	enter();
	solve();
}