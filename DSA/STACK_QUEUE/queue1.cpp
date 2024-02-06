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
	
	deque<int> q;
	int n; cin >> n;
	cin.ignore();
	while(n--)	
	{
		string s; cin >> s;
		if(s == "PUSHFRONT")
		{
			int x; cin >> x;
			q.push_front(x);
		}
		else if(s == "PRINTFRONT")
		{
			if(q.empty()) cout << "NONE" << endl;
			else cout << q.front() << endl;
		}
		else if(s == "POPFRONT" and !q.empty())
			q.pop_front();
		else if(s == "PUSHBACK")
		{
			int x; cin >> x;
			q.push_back(x);
		}
		else if(s == "PRINTBACK")
		{
			if(!q.empty()) cout << q.back() << endl;
			else cout << "NONE" << endl;
		}
		else if(s == "POPBACK" and !q.empty())
			q.pop_back();
	}
}