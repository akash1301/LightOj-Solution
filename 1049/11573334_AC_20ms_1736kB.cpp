/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025				*
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
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};


vector<int>g[105];
int dis[105][105],vis[105];

int dfs(int u,int x,int &ans)
{
    //vis[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=x&&!vis[v])
        {
            vis[v]=1;
            ans+=dis[u][v];

           //if(v!=1)
            dfs(v,u,ans);
        }
    }
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        loop(i,n)
        {
            int p,q,w;
            cin>>p>>q>>w;
            g[p].pb(q);
            g[q].pb(p);
            dis[q][p]=w;
            dis[p][q]=0;
        }
        int ans1=0;
        int ans2=0;
        mem(vis,0);
        dfs(1,g[1][0],ans1);
        mem(vis,0);
        dfs(1,g[1][1],ans2);
        CASE(cas);
        //cout<<ans1<<" "<<ans2<<" ";
        cout<<min(ans1,ans2)<<endl;
        loop(i,105)
        g[i].clear();
    }
    return 0;
}
