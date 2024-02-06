#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
using ll = long long;
const int MAX = 1e9+5;
ll mod = 1e9+7;

char c;

void runcase2()
{
	string s(3,'A');
	for(int i=0;i<=2;i++) s[i]='B'+i;
	string tmp = s;
	do{
		cout << 'A' << s << endl;
	}while(next_permutation(all(s)));
	s=tmp;
	do{
		cout << s << 'A' << endl;
	}while(next_permutation(all(s)));
}

void runcase1()
{	
	string s(c-'A'-1,'B');
	for(int i=0;i<s.length();i++)
	{
		s[i]='B'+i;
		if(s[i]>='E')
			++s[i];
	}	
	vector<string> res, ans;
	do{
		res.push_back(s);
	}while(next_permutation(all(s)));

	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<s.length()+1;j++)
		{
			string x = "AE";
			do{
				string tmp1 = res[i];
				string tmp2=tmp1.insert(j,x);
				ans.push_back(tmp2);
			}while(next_permutation(all(x)));
		}
		string tmp1 = 'A'+res[i]+'E';
		string tmp2 = 'E'+res[i]+'A';
		ans.push_back(tmp1);
		ans.push_back(tmp2);
	}

	sort(all(ans));
	for(auto i : ans)
		cout << i << endl;
}
int main()
{
	cin >> c;
	if(c>'D')
		runcase1();
	else runcase2();
	
}