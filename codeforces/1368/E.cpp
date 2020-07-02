#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> > 
#define vvpi vector<vector<pair<int,int> > >

int n; // number of vertices
vector<vector<int>> adj(200005); // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) 
{
    visited[v] = true;
    for (int u : adj[v]) 
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort() 
{
    visited.assign(n+1, false);
    ans.clear();
    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	vvi revv(200005);
	while(t--)
	{
		int m,i,j,x,y;

		cin >> n >> m;

		for(i=1;i<=n;i++)
		{
			adj[i].clear();
			revv[i].clear();
		}

		while(m--)
		{
			cin >> x >> y;
			adj[x].pb(y);
			revv[y].pb(x);
		}

		topological_sort();

		int isp[n+5]={0};
		vi remm;


		for(auto it : ans)
		{	
			int fl = 0;
			isp[it] = 1;
			for(auto ii : revv[it])
			{
				if(isp[ii])
				{
					if(isp[ii] == 2)
					{
						isp[it] = 0;
						remm.pb(it);
						break;
					}
					if(isp[ii] == 1)
					{
						isp[it] = 2;
					}
				}
			}
		}
		
		// for(i=1;i<=n;i++)
		// {o
		// 	cout << i << " " << isp[i] << endl;
		// }

		cout << remm.size() << endl;
		for(auto it : remm)
		{
			cout << it << " " ;
		}
		cout << endl;
	}
	return 0;
}