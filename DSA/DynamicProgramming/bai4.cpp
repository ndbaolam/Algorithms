#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int n, s, flag;

void back(int i, int pos, int sum, vector<int>& a)
{
	for(int j = pos; j < n; j++)
	{
		if(sum + a[j] <= s)
		{
			sum += a[j];
			if(sum == s){
				flag = 1;
				return;
			}
			back(i+1,j+1,sum,a);
			sum -= a[j];
		}
	}
}

int main()
{	
	cin >> n >> s;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	back(0,0,0,a);
	cout << flag;
}