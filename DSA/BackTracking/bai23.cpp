#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, k;
int x[10];
vector<vector<int>> res;
int prime[505];

void sieve() {
    memset(prime,1,sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= 505; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 505; j += i) {
                prime[j] = 0;
            }
        }
    }
}

void back(int i, int pos, int sum)
{
	for(int j=pos;j<=500;j++)
	{
		if(prime[j])
		{
			x[i]=j;
			sum+=j;
			if(i<=k && sum <=n)
			{
				if(i==k && sum==n)
				{
					vector<int> tmp(x+1,x+i+1);
					res.push_back(tmp);
				}
				back(i+1,j+1,sum);
				sum-=j;
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	sieve();
	back(1,1,0);
	if(res.empty())
		cout << "NOT FOUND";
	else
	{
		sort(all(res));
		for(vector<int> v : res)
		{
			for(int i=0;i<v.size();i++)
			{
				if(i==v.size()-1)
					cout << v[i];
				else cout << v[i]<< " + ";
			}
			cout << endl;
		}
	}
}