#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

vector<int> nextGreaterElement(vector<int> nums)
{
	vector<int> ans;
	stack<int> st;
	for(int i = nums.size()-1;i>=0;i--)
	{
		while(!st.empty() && st.top() <= nums[i])
			st.pop();

		if(st.empty()) ans.push_back(-1);
		else ans.push_back(st.top());

		st.push(nums[i]);
	}
	return ans;
}

int main()
{
	vector<int> nums;
	int x;
	while(cin >> x) nums.push_back(x);
	vector<int> res = nextGreaterElement(nums);
	for(auto i = res.rbegin(); i != res.rend(); i++) cout << *i << ' ';
}