#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
// f[51][17][17][2][2]
// f[n][c3][c6][f1][f2]
// n: position
// c3: count the numbers of 3
// c6: count the numbers of 6
// f1: 1 if c3 = c6 = c9 0 if not
// f2: tight
int f[51][17][17][17][2];
vector<int> num;

int count(int pos, int c3, int c6, int c9, int t)
{
	if(pos == num.size())
	{
		if(c3 == c6 and c3 == c9)
			return 1;
		else return 0;
	}
	if(c3 != c6 or c3 != c9 or c6 != c9)
		return 0;

	if(f[pos][c3][c6][c9][t] != -1)
		return f[pos][c3][c6][c9][t];
	int res = 0;
	int k = (t)? num[pos] : 9;
	REP(i,0,k)
	{
		if(i == 3) ++c3;
		if(i == 6) ++c6;
		if(i == 9) ++c9;
		int new_t = (num[pos] == i)? f : 0;
		res += count(i+1, c3, c6, c9, new_t);
		res %= mod;
	}
	if(!t) f[pos][c3][c6][c9][t] = res;
	return res;
}

int solve(string a)
{
	num.clear();
	REP(i,0,a.size()-1)
		num.push_back(s[i] - '0');
	reverse(all(num));
	int res = count();
	return res;
}

void decrease(string& a, int idx)
{
	if(a[idx] != '0')
	{
		int tmp = a[idx] - '0' - 1;
		a[idx] = tmp + '0';
		if(idx == -1)
			a.erase(0,1);
		return;
	}
	else 
	{
		a[idx] = '9';
		decrease(a,idx-1);
	}
}

int main()
{
	memset(f,-1,sizeof(f));
	string a, b; cin >> a >> b;
	decrease(a, a.size()-1);
	int res = solve(b) - solve(a);
	cout << res << endl;
}
// pos: 1 2 3 4 5 6
// num: 5 7 2 3 6 1 (572361)
// seq: {- - - -} - -