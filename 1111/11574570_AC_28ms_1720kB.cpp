/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025                           *
*  Spoj:akash_kuet                      *
*  Khulna,Bangladesh.                   *
*****************************************/
 
 
 
#include <bits/stdc++.h>
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define pf printf
#define sf scanf
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define getlong scanf("%lld",&n)
#define CASE(n) printf("Case %d: ",++n)
#define inf 1000000000
 
using namespace std;
 
int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};
 
vector<int>g[1005];
int vis[1005],grp[1005],s,ans,k,data[105];
 
int dfs(int u)
{
    vis[u]=1;
    grp[u]++;
    if(grp[u]==k)
        ans++;
    for(int i=0;i<g[u].size();i++)
    {
        if(!vis[g[u][i]])
            dfs(g[u][i]);
    }
}
 
int main()
{
    //read();
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>k>>n>>m;
        loop(i,k)
        {
            cin>>data[i];
        }
        loop(i,m)
        {
            int p,q;
            cin>>p>>q;
            g[p].pb(q);
        }
        mem(grp,0);
        ans=0;
        loop(i,k)
        {
            mem(vis,0);
            dfs(data[i]);
        }
        CASE(cas);
        cout<<ans<<endl;
        loop(i,n)
        g[i].clear();
    }
    return 0;
}