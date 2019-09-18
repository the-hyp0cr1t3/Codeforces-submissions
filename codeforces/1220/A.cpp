#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,countone=0,countzero=0;
	string str;
	
	cin>>n;
	cin>>str;
	for (int i=0;i<n;i++) {
	    if (str[i] == 'n') countone++;
	    if (str[i] == 'z') countzero++;
	}
	for (int i=0; i<countone;i++)
	    cout<<"1 ";
	for (int i=0; i<countzero;i++)
	    cout<<"0 ";
	return 0;
}
