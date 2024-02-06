#include <bits/stdc++.h>
using namespace std;

bool check(string S, string T)
{
    if(T.size()>S.size())   return false;
    else if(T.size()==S.size())
        return T==S ? true : false;
    else
    {
        if(S.find(T)!=string::npos)
            return true;
        else return false;
    }
}

int main()
{
    string S, T;
    getline(cin,S);
    getline(cin,T);

    if(check(S, T)) cout << "YES";
    else cout << "NO";
}