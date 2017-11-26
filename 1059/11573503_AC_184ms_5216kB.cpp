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
#define CASE(n) printf("Case %d: ",++n)
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
    int p,q;
    ll w;
};

bool comp(node x,node y)
{
    return x.w<y.w;
}


vector<node>graph;
int pr[10005],n,e,vis[10005];
vector<int>g[10005];
ll air;

int find(int r)
{
    if(pr[r]==r)
        return r;
    return find(pr[r]);
}

ll mst()
{
    ll ans=0;
    int cnt=0;
    for(int i=0;i<graph.size();i++)
    {
        if(graph[i].w>=air)
            break;
        int uu=graph[i].p;
        int vv=graph[i].q;
        g[uu].pb(vv);
        g[vv].pb(uu);
        int u=find(graph[i].p);
        int v=find(graph[i].q);
        if(u!=v)
        {
            pr[u]=v;
            ans+=graph[i].w;
            cnt++;
            if(cnt==n)
                break;
        }
    }
    return ans;
}

int dfs(int u)
{
    vis[u]=1;
    loop(i,g[u].size())
    {
        int v=g[u][i];
        if(!vis[v])
            dfs(v);
    }
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        sf("%d %d %lld",&n,&e,&air);
        loop(i,e)
        {
            int p,q;
            ll w;
            sf("%d %d %lld",&p,&q,&w);
            node edge;
            edge.p=p;
            edge.q=q;
            edge.w=w;
            graph.pb(edge);
        }
        sort(all(graph),comp);
        for(int i=1;i<=n;i++)
            pr[i]=i;
        ll ans=mst();
        mem(vis,0);
        int xx=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                ans+=air;
                xx++;
            }
        }

        CASE(cas);
        pf("%lld %d\n",ans,xx);
        graph.clear();
        loop(i,10005)
        g[i].clear();
    }

	return  0;

}
