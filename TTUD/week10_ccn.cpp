#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

vector<int> a[100005];
int color[100005];
int n, m;

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	REP(i, 1, m) sort(all(a[i]));
}

int main()
{
	faster();
	
}