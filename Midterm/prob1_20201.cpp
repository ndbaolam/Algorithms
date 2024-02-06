#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int main(){
	int t; cin >> t;
	while(t--){
		set<int> s;
		int n, x, cnt = 0;
		cin >> n;

		REP(i, 1, n){
			cin >> x;
			s.insert(x);
		}
		cin >> n;
		REP(i, 1, n){
			cin >> x;
			if(s.count(x)) ++cnt;
		}
		cout << cnt << endl;
	}
}	