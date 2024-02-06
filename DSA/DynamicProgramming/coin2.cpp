/*
Hãy xem xét một hệ thống tiền tệ của ngân hàng XYZ
bao gồm n đồng xu. Mỗi đồng xu có một giá trị nguyên
dương. Nhiệm vụ của bạn là tính số cách riêng biệt
mà bạn có thể tạo ra số tiền x bằng cách sử dụng số
xu có sẵn. Ví dụ: nếu số xu là {2,3,5} và tổng mong
muốn là 9, có 8 cách: 2 + 2 + 5; 2 + 5 + 2;
5 + 2 + 2; 3 + 3 + 3; 2 + 2 + 2 + 3;
2 + 2 + 3 + 2; 2 + 3 + 2 + 2; 3 + 2 + 2 + 2;
*/
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
vector<ll>  f(1000005, 0);

int main()
{
	int n, s; cin >> n >> s;
	vector<int> a(n+1);
	for(int i = 1; i <= n ; i++) 
	{
		cin >> a[i];
		f[a[i]] = 1;
	}

	for(int i = 1; i <= s; i++)
	{
		for(int j =1; j <= n; j++)
		{
			if(i >= a[j] && f[i - a[j]] != 0)
				f[i] += f[i - a[j]];
			f[i] %= mod;
		}
	}	
	cout << f[s];
}