#include<bits/stdc++.h>
using namespace std;

int main() {
   int n, k;
   cin >> n >> k;
   int a[n];
   for(int &i : a)
           cin >> i;
    int j=0;
    int ans=0;
    sort(a,a+n);
    multiset<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]);
        while(*st.rbegin()-*st.begin()>k)
        {
            st.erase(st.lower_bound(a[j]));
            j++;
        }
        ans = max(ans,i-j+1);
    }
    cout << ans << endl;
}