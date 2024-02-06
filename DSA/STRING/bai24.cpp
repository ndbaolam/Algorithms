#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S; cin >> S;
    map<char,int> mp;
    for(char i : S)
    	mp[i]++;
    unsigned long long int cnt=0;
    for(auto i : mp)
    	cnt+=(i.second-1)*i.second/2;
    cout << cnt + S.size();
}