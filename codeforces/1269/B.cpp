#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(x,n) for (int i=x;i<n;i++)

int main()
{
      IOS;
      long long int n,m;
      cin>>n>>m;
      vector<long long int> a(n),b(n),d(n),c(n);
      for (int i=0;i<n;i++)
      {
             cin>>a[i];
      }
      for (int i=0;i<n;i++)
      {
             cin>>b[i];
      }
      for (int i=0;i<n;i++)
      {
             long long int x;
             x=(b[0]-a[i]+m)%m;
             c[i]=x;
      }      
      sort(c.begin(),c.end());
      sort(b.begin(),b.end());
      
      for (int i=0;i<n;i++)
      {
            for (int j=0;j<n;j++)
            {
                   d[j]=(a[j]+c[i])%m;
            }

            sort(d.begin(),d.end());

            int count=0;
        
            for(int j=0;j<n;j++)
            {
              if(d[j]==b[j])
                count++;
              else break;
            }

            if(count==n)
            {
              cout<<c[i];
              return 0;
            }

            
      }
      
      
      
  return 0;
}