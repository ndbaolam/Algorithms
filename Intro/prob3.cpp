#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
	faster();
	priority_queue<int, vector<int>, greater<int>> Q;
	string s;
	while(getline(cin, s))	
	{
		stringstream S(s);
		string tmp;
		S >> tmp;
		if(tmp == "PUSH")
		{
			string x;
			S >> x;
			Q.push(stoi(x));
		}
		else if(tmp == "POP")
		{
			cout << Q.top() << endl;
			Q.pop();
		}
		else break;
	}
}
