#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	cin.ignore();
	vector<pair<int,int>> v;
	REP(i,1,n)
	{
		string s; getline(cin, s);
		stringstream S(s);
		string tmp;
		while(S >> tmp)
			v.push_back({i,stoi(tmp)});
	}
	sort(all(v));
	for(auto [x,y] : v)
		cout << x << ' ' << y << endl;
}