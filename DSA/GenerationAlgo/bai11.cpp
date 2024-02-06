#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, X[100]; // lưu cấu hình
int cnt; //Lưu sl số hạng trong phân tích
bool final = false; // check cấu hình cuối
int ans;

void init(){
	cnt = 1;
	X[1] = n;
}

void sinh(){
	int i = cnt;
	while(i >= 1 && X[i] == 1){
		--i;
	}
	if(i == 0){
		final = true;
	}
	else{
		int tmp = cnt - i + 1;
		--X[i];
		cnt = i;
		int q = tmp / X[i];
		int r = tmp % X[i];
		if(q != 0){
			for(int j = 1; j <= q; j++){
			X[i + j] = X[i];
		}
	cnt += q;
	}
	if(r != 0){
		++cnt;
		X[cnt] = r;
		}
	}
}

int main()
{
	cin >> n;
	init();
	vector<vector<int>> res;

	while(!final)
	{
		++ans;
		vector<int> tmp(X+1,X+cnt+1);
		res.push_back(tmp);
		sinh();
	}
	cout << ans << endl;

	for(int j=0;j<res.size();j++)
	{
		cout << res[j][0];
			for(int i=1;i<res[j].size();i++)
				cout << "+" << res[j][i];
		cout << endl;
	}
	return 0;
}