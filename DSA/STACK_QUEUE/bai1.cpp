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
	
	int n; cin >> n;
	vector<string> v;
	while(n--)	
	{
		string s; cin >> s;
		if(s == "top")
		{
			if(v.empty()) cout << "NONE" << endl;
			else
			{ 
				cout << v.back() << endl;
				//v.pop_back();
			}
		}
		else if(s == "push")
		{
			string num; cin >> num;
			v.push_back(num);
		}
		else if(!v.empty()) v.pop_back();
	}
}