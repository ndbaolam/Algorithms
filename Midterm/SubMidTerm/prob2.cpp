#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 25;

int n, cnt, obj;
int a[N];

void back(int k, int pos, int sum){
	if(sum >= obj && sum % 5 == 0) ++cnt;
	REP(i, pos, n){
		back(k + 1, i + 1, sum + a[i]);
	}
}

int main(){
	faster();
	cin >> n;
	REP(i, 1, n) cin >> a[i];
	cin >> obj;
	back(1, 1, 0);
	cout << cnt;
}