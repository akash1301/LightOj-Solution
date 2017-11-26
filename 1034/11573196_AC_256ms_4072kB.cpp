/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025               *
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
 
vector<int>g[10005],g_r[10005],grp;
int vis[10005];
 
int dfs(int u)
{
    vis[u]=1;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
            dfs(v);
    }
    grp.pb(u);
}
 
int dfs2(int u)
{
    vis[u]=1;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
            dfs2(v);
    }
}
 
int main()
{
   // read();
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        loop(i,e)
        {
            int p,q;
            cin>>p>>q;
            g[p].pb(q);
            g_r[q].pb(p);
        }
        mem(vis,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        mem(vis,0);
        int ans=0;
        reverse(all(grp));
        //for(int i=0;i<grp.size();i++)
         //   cout<<grp[i]<<endl;
        for(int i=0;i<grp.size();i++)
        {
            int x=grp[i];
            if(!vis[x])
            {
                dfs2(x);
                ans++;
            }
        }
        CASE(cas);
        cout<<ans<<endl;
        loop(i,n+2)
        {
            g[i].clear();
            g_r[i].clear();
        }
        grp.clear();
    }
    return 0;
}