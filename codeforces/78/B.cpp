#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
int main()
{
    long long n, i;
    cin >> n;
    string s = "VIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYORVIBGYOR";
	if((n % 7) <= 3 && (n % 7) >= 1)
	{
	    if(n % 7 == 1)
	    {
	        for(i = 0; i < n - 1; i++)
	         cout << s[i];
	       cout << "G";
	    }
	    else if(n % 7 == 2)
	    {
	         for(i = 0; i < n - 2; i++)
	         cout << s[i];
	       cout << "GY";
	    }
	    else if(n % 7 == 3)
	    {
	         for(i = 0; i < n - 3; i++)
	         cout << s[i];
	       cout << "GYO";
	    }
	}
	else
	{
	    for(i = 0; i < n; i++)
	        cout << s[i];
	}
	return 0;
}