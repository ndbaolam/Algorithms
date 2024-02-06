#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    set<int> s;
    while(N--)
    {
        int x; cin >> x;
        s.insert(x);
    }
    int Q; cin >> Q;
    while(Q--)
    {
        int x; cin >> x;
        if(s.count(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}