#include <iostream>
using namespace std ;
bool isprime(int x);
int main()
{
    int n ;
    cin >> n ;
    int p[100001];
    p[0] = 2 ;
    int c = 1 ;
    for(int i = 3; i <=  1299721; i += 2)
    {
        if(i % 5 == 0)
            continue ;
        if(isprime(i))
        {
            p[c] = i ;
            c++ ;
        }
    }
    for(int i = 0; i < n; i++)
        cout << p[i] << " " ;
}
bool isprime(int x)
{
    if(x&1)
    {
        for(int i = 3; i*i <= x; i++)
        {
            if(x % i == 0)
                return false ;
        }
        return true ;
    }
    else
        return false ;
}