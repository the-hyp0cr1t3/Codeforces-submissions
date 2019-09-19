#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a[1001][1001],g;
	cin>>n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin>>a[i][j];
	g=sqrt((a[0][1]*a[0][2])/a[1][2]);
	cout<<g<<" ";
	for (int i=1; i<n; ++i)
		cout<<a[0][i]/g<<" ";
}