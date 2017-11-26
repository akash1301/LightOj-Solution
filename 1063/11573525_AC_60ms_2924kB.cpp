/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: Al Mamun Akash                  *
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
 
using namespace std;
 
int vis[10002],art[10002],bak[10002],dis[10002],dfsnum,deg,root,ad;
vector<int>g[20002];
int findart(int u)
{
    vis[u]=1;
    dfsnum++;
    bak[u]=dis[u]=dfsnum;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            findart(v);
            if(u==1)
                deg++;
            if(deg>=2)
                art[1]=1;
           // if(bak[v]<dis[u])
            bak[u]=min(bak[u],bak[v]);
            if(bak[v]>=dis[u]&&u!=1)
                art[u]=1;
        }
        else
            bak[u]=min(dis[v],bak[u]);
    }
}
 
int main()
{
    //read();
    int n,m,t,x=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int p,q;
        loop(i,m)
        {
            cin>>p>>q;
            g[p].pb(q);
            g[q].pb(p);
        }
        mem(art,0);
        mem(vis,0);
        dfsnum=0;
        deg=0;
        findart(1);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(art[i]==1)
                sum++;
        }
        pf("Case %d: %d\n",++x,sum);
        loop(i,20002)
        g[i].clear();
    }
    return 0;
}