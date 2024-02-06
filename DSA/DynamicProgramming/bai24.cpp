#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	vector<int> f(n+1, INT_MAX);
	//f[i] so luong it nhat cac so nho hon i
	// co tong binh phuong = i

	for(int i = 1; i <= n; i++)
	{
		int k = (int)sqrt(i);
		if(k * k == i) f[i] = 1;
		else
		{
			for(int j = 1; j*j <= i; j++)
				f[i] = min(f[i], f[i - j*j] + 1);
		}		
	}
	cout << f[n];
}