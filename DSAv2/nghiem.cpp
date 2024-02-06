#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
vector<vector<int>> res;
vector<int> tmp;

void back(int i, int sum, int& cnt)
{
	if(i <= 3)
	{
		int a[3] = {2,3,5};
		for(int j = 1; j <= 24; j++)
		{
			if(sum + j * a[i-1] <= 48)
			{
				sum += j * a[i-1];
				tmp.push_back(j);
				if(i == 3 && sum == 48 && tmp[0] <= 5)
				{
					++cnt;
					res.push_back(tmp);
				}
				back(i+1, sum, cnt);
				sum -= j * a[i-1];
				tmp.pop_back();
			}
		}
	}
}

int main()
{
	int cnt = 0;
	back(1,0,cnt);
	cout << cnt << endl;
	for(vector<int> x : res)
	{
		for(int i : x)
			cout << i << ' ';
		cout << endl;
	}
}