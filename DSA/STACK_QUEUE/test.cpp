#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int maxn = (int)1e6;
int prime[maxn +1];

void sieve() {
    fill(prime, prime + maxn, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int bfs(string s, string t)
{
	queue<pair<string,int>> q;
	set<string> used;
	q.push({s, 0});
	used.insert(s);

	while(!q.empty())
	{
		pair<string,int> top = q.front(); q.pop();
		string tmp = top.first;
		int n = top.second;

		if(tmp == t) return n;

		string cur = tmp;
		REP(i, 0, 3)
		{
			REP(j, 0, 9)
			{
				cur[i] = j + '0';
				if(!used.count(cur) and prime[stoi(cur)])
				{
					q.push({cur, n + 1});
					used.insert(cur);
				}
			}
			cur = tmp;
		}
	}
	return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	int n; cin >> n;
	cin.ignore();
	sieve();
	while(n--)
	{
		string s, t; cin >> s >> t;
		cout << bfs(s,t) << endl;
	}
}