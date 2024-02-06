#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int main(){
	faster();
	int n; cin >> n;
	int mod = 1e9 + 7;
	int f0[n + 1], f1[n + 1], f2[n + 1];
	f0[1] = f1[1] = f2[1] = 1;
	for(int i = 2; i <= n; i++){
		f0[i] = f2[i - 1] + f1[i - 1];
		f1[i] = f2[i - 1] + f0[i - 1];
		f2[i] = f2[i - 1] + f1[i - 1] + f0[i - 1];
	}
	cout << (f2[n] + f1[n] + f0[n]) % mod;
}