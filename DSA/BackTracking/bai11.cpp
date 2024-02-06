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

int n, a[50], x[50];
vector<string> v;

void back(int i, int pos)
{
	for(int j=pos;j<=n;j++)
	{
		if(a[j]>x[i-1])
		{
			x[i]=a[j];
			if(i>=2)
			{
				string s="";
				for(int u=1;u<=i;u++)
					s+= to_string(x[u])+" ";
				v.push_back(s);
			}
			back(i+1,j+1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	back(1,1);
	sort(all(v));
	for(auto i : v)
		cout << i << endl;
}