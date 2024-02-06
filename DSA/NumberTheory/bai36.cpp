#include<iostream>
using namespace std;
using ll = long long;

ll m[105][105];

ll C(int k, int n) {
	ll mod = 1e9+7;
	if (k == 0 || k == n) 
		m[k][n]=1;
	else{
		if(m[k][n] == 0)
		{
	 		m[k][n] = C(k - 1, n - 1) + C(k, n - 1);
	 		m[k][n]%=mod;
		}
	}
	return m[k][n];
}
int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {		
		for (int j = 0; j <= i; j++) {
			cout << C(j, i) << " ";
		}
		cout << endl;
	}
	return 0;
}