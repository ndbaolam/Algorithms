#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[1005], final;

void sinh()
{
	int i=n-1;
	while(i>=1 && a[i]>a[i+1])
		--i;
	if(i==0)
		final=1;
	else
	{
		//sort(a+i+1,a+n+1);
		reverse(a+i+1,a+n+1);
		auto it = lower_bound(a+i+1,a+n+1,a[i]);
		swap(a[i],*it);		
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sinh();
	if(!final)
		for(int i=1;i<=n;i++)
			cout << a[i] << " ";
	else 
		for(int i=1;i<=n;i++)
			cout << i << " ";
	return 0;
}