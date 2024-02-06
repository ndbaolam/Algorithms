#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    multiset<unsigned int> s;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    int Q; cin >> Q;
    while(Q--)
    {
        int x; cin >> x;
        if(x==1)
        {
            unsigned int num; cin >> num;
            s.insert(num);
        }
        else if(x==2)
        {
            unsigned del; cin >> del;
            if(s.find(del)!=s.end())
                s.erase(s.find(del));
        }
        else 
        {
            unsigned int num; cin >> num;
            if(s.find(num)!=s.end())
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
