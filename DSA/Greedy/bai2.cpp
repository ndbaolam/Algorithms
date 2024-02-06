#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	string a, b;
	cin >> a >> b;
	ll max_sum, min_sum;

	for(char &x : a)
		if(x=='5') x='6';
	for(char &x : b)
		if(x=='5') x='6';
	max_sum = stoll(a) +stoll(b);

	for(char &x : a)
		if(x=='6') x='5';
	for(char &x : b)
		if(x=='6') x='5';

	min_sum = stoll(a) +stoll(b);

	cout << max_sum << ' ' << min_sum;
}