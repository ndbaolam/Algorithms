#include<bits/stdc++.h>
using namespace std;


int main()
{
    int N; cin >> N;
    multiset<int> S;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        S.insert(x);
    }

    int T; cin >> T;
    while(T--)
    {
         int cmd, x;
        cin >> cmd >> x;
        if (cmd == 1) {
            S.insert(x);
        }
        else if (cmd == 2) {
            if (S.count(x))
                S.erase(S.lower_bound(x));
        }
        else if (cmd == 3) {
            auto iter = S.lower_bound(x);
            cout << (iter != S.end()? *iter : -1) << "\n";
        }
        else {
            auto iter = S.upper_bound(x);
            --iter;
            if (*iter <= x)
                cout << *iter << "\n";
    }
    }
}