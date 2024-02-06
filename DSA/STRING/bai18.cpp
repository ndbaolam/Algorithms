#include <bits/stdc++.h>
using namespace std;


int main()
{
    string S; cin >> S;
    int index = 0;
    string p = "Python";
    if(S.size()<p.size())
    	cout << "NO";
    else if(S.size()==p.size())
    {
		if(S==p) cout << "YES";
    	else cout <<"NO";
    }
    else
    {
	    for(auto i : S)
	    {
	    	if(i==p[index])
	    		index++;
	    }
	    if(index==6)
	    	cout << "YES";
	    else cout << "NO";
	}
}