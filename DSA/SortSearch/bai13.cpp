#include <iostream>
#include "bits/stdc++.h"
 
using namespace std;
int main(){
	int n,k=0;	
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a, a+n);
	for (int i=0;i<n;i++)
        if (k<=a[i]) k++;
	cout<<k;	        	
}