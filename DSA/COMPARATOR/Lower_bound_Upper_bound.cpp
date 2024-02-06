#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a;
    while(n--)
    {
        int b ; cin>>b;
        a.push_back(b);
    }

    auto it = lower_bound(a.begin(),a.end(),x);
    if(it != a.end()){
    cout<< (it-a.begin())<<endl;
    }
    else cout<<"-1"<<endl;
    
    auto it1 = upper_bound(a.begin(),a.end(),x);
    if(it1 != a.end()){
    cout<< (it1-a.begin())<<endl;
    }
    else cout<<"-1"<<endl;
    
    auto it3 = find(a.begin(),a.end(),x);
    if(it3 != a.end()){
    cout<<it3-a.begin()<<endl;
        
    }
    else cout<<"-1"<<endl;


    int ans = -1;
    bool ok =true;
    for(int i = 0 ; i < a.size() ;i++)
    {
        if (a[i] == x) 
        {
            ans = i;
            ok = false;
        }
    }
    if(ok)
    {
        cout<< "-1"<<endl;
    }
    else{
    cout<<ans<<endl;
    }

    if (ok) cout << "0"<<endl;
    else{
    cout<<ans-(it3-a.begin())+1<<endl;}
    





}