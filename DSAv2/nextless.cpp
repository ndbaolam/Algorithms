#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

void nextless(vector<int> v, int ans[])
{
	stack<int> st;
	for(int i=v.size()-1;i>=0;i--)
	{	
		while(!st.empty() && st.top() >= v[i])
			st.pop();
		if(st.empty()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(v[i]);
	}
}

int main()
{
	vector<int> nums;
	int x;
	while(cin >> x) nums.push_back(x);
	int n = nums.size();
	int ans[n];
	nextless(nums,ans);
	for(int x : ans)
		cout << x << ' ';
}