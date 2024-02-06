#include <bits/stdc++.h>
using namespace std;


int main()
{
    string S, T;
    getline(cin, S);
    getline(cin, T);
    for(auto &i : S)
    	i=tolower(i);
    for(auto &i : T)
    	i=tolower(i);

    stringstream ss(S), tt(T);
    string temp;

    set<string> s, t;
    while(ss >> temp)
    	s.insert(temp);
    while(tt >> temp)
    	t.insert(temp);

    for(auto i : s)
    	if(t.find(i)!=t.end())
    		cout << i << " ";
}