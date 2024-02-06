#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
    int a[n];
    for(int &i : a)
        cin >> i;

    int sum=0;
    set<int> res;

    for(int i=0;i<n;i++)
    {
        vector<int> v;

        for(int j=i;j<n;j++)
        {
            if(sum<k)
            {
                v.push_back(a[j]);
                sum+=a[j];
                if(sum==k)
                {
                    res.insert(v.size());
                    break;
                }
            }
            else break;
        }
        sum=0;
    }
    if(res.empty()) cout << -1;
    else cout << *res.begin();
}