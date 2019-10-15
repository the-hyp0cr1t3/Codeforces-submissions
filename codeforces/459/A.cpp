#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    if(abs(a-c)==abs(b-d))
        cout<<a<<" "<<d<<" "<<c<<" "<<b;
    else if(a==c)
        cout<<a+abs(b-d)<<" "<<b<<" "<<a+abs(b-d)<<" "<<d;
    else if(b==d)
        cout<<a<<" "<<b+abs(a-c)<<" "<<c<<" "<<b+abs(a-c);
    else
        cout << -1;
    return 0;
}