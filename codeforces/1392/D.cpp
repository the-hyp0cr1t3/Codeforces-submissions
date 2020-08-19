// testing :/
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define MAX_SIZE 1000005
#define IN 1000000000
#define MOD 1000000007
#define PB push_back
#define mp make_pair
#define vl vector<ll>
#define sl set<ll>
#define slg set<ll,greater<ll>>
#define f(a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define sz(x) (int)x.size() 
#define watch(x) cout << #x << " = " << x << endl
#define debug(args...) cerr << "["#args"] = ["; dbg,args; cerr << "]" << endl;
struct debugger 
{
    template<typename T> debugger& operator , (const T& v) {    
        cerr<<v<<" ";    
        return *this;
    }
} dbg;

pair<ll, ll> fibo(ll n) 
{
    if (n == 0)
        return {0, 1};

    auto p = fibo(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = (p.first * p.first) + (p.second * p.second);
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
struct Test // Custom set for user defined types
{ 
    int id; 
      
    // This function is used by set to order 
    // elements of Test. 
    bool operator<(const Test& t) const
    { 
        return (this->id < t.id); 
    } 
};
bool isPrime(ll n)  
{  
    // Corner cases  
    if (n <= 1)  return false;  
    if (n <= 3)  return true;  
    
    // This is checked so that we can skip   
    // middle five numbers in below loop  
    if (n%2 == 0 || n%3 == 0) return false;  
    
    for (int i=5; i*i<=n; i=i+6)  
        if (n%i == 0 || n%(i+2) == 0)  
           return false;  
    
    return true;  
}  
void SieveOfEratosthenes(vector<int> &primes)  
{  
    // Create a boolean array "IsPrime[0..MAX_SIZE]" and  
    // initialize all entries it as true. A value in  
    // IsPrime[i] will finally be false if i is  
    // Not a IsPrime, else true.  
    bool IsPrime[MAX_SIZE];  
    memset(IsPrime, true, sizeof(IsPrime));  
    
    for (int p = 2; p * p < MAX_SIZE; p++)  
    {  
        // If IsPrime[p] is not changed, then it is a prime  
        if (IsPrime[p] == true)  
        {  
            // Update all multiples of p greater than or   
            // equal to the square of it  
            // numbers which are multiple of p and are  
            // less than p^2 are already been marked.   
            for (int i = p * p; i <  MAX_SIZE; i += p)  
                IsPrime[i] = false;  
        }  
    }  
    // Store all prime numbers  
    for (int p = 2; p < MAX_SIZE; p++)  
       if (IsPrime[p])  
            primes.push_back(p); 
             
}
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
// Function to return a vector containing divisors of a number 
vector<ll> printDivisors(ll n) 
{ 
    vector<ll> divisor;
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                divisor.PB(i); 
  
            else // Otherwise print both 
            {
                divisor.PB(i);
                divisor.PB((n/i));
            } 
        } 
    } 
    return divisor;
}
// function to find first index >= x 
ll lowerIndex(ll arr[], ll n, ll x) 
{ 
    int l = 0, h = n - 1; 
    while (l <= h) { 
        int mid = (l + h) / 2; 
        if (arr[mid] >= x) 
            h = mid - 1; 
        else
            l = mid + 1; 
    } 
    return l; 
}
// function to find last index <= y 
ll upperIndex(ll arr[], ll n, ll y) 
{ 
    int l = 0, h = n - 1; 
    while (l <= h) { 
        int mid = (l + h) / 2; 
        if (arr[mid] <= y) 
            l = mid + 1; 
        else
            h = mid - 1; 
    } 
    return h; 
}
// Binary Search 
ll binarySearch(ll arr[], ll l, ll r, ll x) 
{ 
    if (r >= l) 
    { 
        ll mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid;  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x);  
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
}

ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        {
            result*=a;
        }
        a*=a;
        b/=2;
    }
    return result;
}
ll power_mod(ll a,ll b, ll m)
{
    a=a%m;
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        {
            result=(result%m*a%m)%m;
        }
        a=((a%m)*(a%m))%m;
        b/=2;
    }
    return result;
}

// If m and a are coprime, use Extended Euclidean Algorithm
// Modular Inverse exists only if a nd m are coprime
ll mod_inverse(ll a,ll m)  // m is a prime 
{
    return power_mod(a,m-2,m);
}

vector<ll> all_mod_inverse(ll m)
{
    vector<ll> temp(m);
    temp[1]=1;
    for(int i=2;i<m;i++)
    {
        temp[i]=(m-(m/i)*(temp[m%i])%m)%m;
    }
    return temp;
}


ll n,t,q;
ll a[200005];
string s;
ll dp[2][2][2][2][200005];
int cost(int n1,int n2)
{
    int val=0;
    if(n1!=a[0])val++;
    if(n2!=a[1])val++;
    return val;
}
bool fine(ll twoback,ll back,ll cur)
{
    if((twoback==1)&&(back==1)&&(cur==1))
    {
        return false;
    }
    if((twoback==0)&&(back==0)&&(cur==0))
    {
        return false;
    }
    return true;
}
ll calc(ll twoback,ll back,ll first,ll sec,ll pos)
{

    if(dp[twoback][back][first][sec][pos]!=-1)
    {
        return dp[twoback][back][first][sec][pos];
    }
    if(pos==n) // Check 2 overlaps (last,first,second) & (secondlast,last,first)
    {
        if(!fine(twoback,back,first)) 
            return IN;
        if(!fine(back,first,sec)) 
            return IN;
        return 0; //Both the cyclic overlaps are fine
    }
    ll val=IN;
    if(fine(twoback,back,0))
    {
        ll addi=(a[pos]==1?1:0);
        val=min(val,(addi+calc(back,0,first,sec,pos+1))); //element 0
    }
    if(fine(twoback,back,1))
    {
        ll addi=(a[pos]==0?1:0);
        val=min(val,(addi+calc(back,1,first,sec,pos+1))); //element 1
    }
    // cout<<pos<<' '<<val<<endl;
    return dp[twoback][back][first][sec][pos]=val;
}
void solve()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        a[i]=((s[i]=='R')?1:0);
    }
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            for(int k=0;k<2;k++) {
                for(int l=0;l<2;l++) {
                    for(int i2=0;i2<=n;i2++) {
                        dp[i][j][k][l][i2]=-1;
                    }
                }
            }
        }
    }

    // All possible moves for first two elements
    int ans=IN;
    ans=min(ans,(cost(0,0)+calc(0,0,0,0,2)));
    ans=min(ans,(cost(0,1)+calc(0,1,0,1,2)));
    ans=min(ans,(cost(1,0)+calc(1,0,1,0,2)));
    ans=min(ans,(cost(1,1)+calc(1,1,1,1,2)));
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}