#include <bits/stdc++.h>
using namespace std;

int C(int n)
{
	return n*(n-1)*(n-2)/2;
}
int main()
{
    string S; cin >> S;
    map<char,int> mp;
    for(char i : S)
    	mp[i]++;
    unsigned int cnt=0;
    for(auto i : mp)
    	cnt+=C(i.second);
    cout << cnt + S.size();
}