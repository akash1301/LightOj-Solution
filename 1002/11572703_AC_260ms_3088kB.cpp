/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
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
#define CASE(n) printf("Case %d:\n",++n)
#define inf 1000000000
#define EPS 1e-9

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

//Bit operation
int SET(int n,int pos){ return n=n | (1<<pos);}
int RESET(int n,int pos){ return n=n & ~(1<<pos);}
int CHECK(int n,int pos){ return (bool) (n & (1<<pos));}


int bigMod(int n,int power,int MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        int ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

int modInverse(int n,int MOD)
{
    return bigMod(n,MOD-2,MOD);
}

int POW(int x, int y)
{
    int res= 1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}

int inverse(int x)
{
    dd p=((dd)1.0)/x;
    return (p)+EPS;
}

int gcd(int a, int b)
{
    while(b) b^=a^=b^=a%=b;
    return a;
}

int nC2(int n)
{
    return n*(n-1)/2;
}

int MOD(int n,int mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

struct node
{
    int p,q,w;
};
vector<node>graph;
vector<int>g[505];
int pr[505],ans,vis[505],des,dis[505][505],n,m;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}

bool comp(node x,node y)
{
    return x.w<y.w;
}

int dfs(int u,int ds)
{
    vis[u]=1;
    if(u==des)
    {
        ans=ds;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            dfs(v,max(ds,dis[u][v]));
        }
    }
}



int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        sf("%d %d",&n,&m);
        loop(i,m)
        {
            int p,q,w;
            sf("%d %d %d",&p,&q,&w);
            node edge;
            edge.p=p;
            edge.q=q;
            edge.w=w;
            graph.pb(edge);
        }
        getint(des);
        for(int i=0;i<505;i++)
            pr[i]=i;
        sort(all(graph),comp);
        int cnt=0;
        mem(dis,0);
        for(int i=0;i<m;i++)
        {
            int u=graph[i].p;
            int v=graph[i].q;
            int uu=find(u);
            int vv=find(v);
            if(uu!=vv)
            {
                pr[uu]=vv;
                cnt++;
                g[u].pb(v);
                g[v].pb(u);
                dis[u][v]=graph[i].w;
                dis[v][u]=graph[i].w;
                if(cnt==n-1)
                    break;
            }
        }
        CASE(cas);
        for(int i=0;i<n;i++)
        {
            if(i==des)
                pf("0\n");
            else
            {
                mem(vis,0);
                ans=-1;
                dfs(i,0);
                if(ans==-1)
                    pf("Impossible\n");
                else
                    pf("%d\n",ans);
            }
        }
        loop(i,505)
        g[i].clear();
        graph.clear();
    }

	return  0;

}
