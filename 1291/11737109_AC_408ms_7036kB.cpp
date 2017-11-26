

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
#define getlong(n) scanf("%lld",&n)
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

vector<int>g[10005];
vector<pair<int,int> >bridge;
int vis[10005],bak[10005],dis[10005],n,m,parent[10005],dfs;
map<int, map<int,int> >isbridge;

int find_bridge(int u,int par)
{
    vis[u]=1;
    dfs++;
    bak[u]=dfs;
    dis[u]=dfs;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(v==par)
            continue;
        if(vis[v])
        {
            bak[u]=min(bak[u],dis[v]);
        }
        else
        {
            find_bridge(v,u);
            bak[u]=min(bak[u],bak[v]);
            if(bak[v]>dis[u])
            {
                bridge.pb(mp(u,v));
                isbridge[u][v]=isbridge[v][u]=1;
            }
        }
    }
}


int find(int u)
{
    if(parent[u]==u)
        return u;
    else
        return parent[u]=find(parent[u]);
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
            int p,q;
            sf("%d %d",&p,&q);
            g[p].pb(q);
            g[q].pb(p);
        }
        dfs=0;
        mem(vis,0);
        loop(i,n)
        {
            if(!vis[i])
            {
                find_bridge(i,-1);
            }
        }
        loop(i,n)
            parent[i]=i;

        loop(i,n)
        {
            for(int j=0,k=g[i].size();j<k;j++)
            {
                int v=g[i][j];
                if(isbridge[i][v]!=1)
                {
                    int x=find(i);
                    int y=find(v);
                    if(x!=y)
                    {
                        parent[x]=y;
                    }
                }
            }
        }

        int cnt[10005];
        mem(cnt,0);
        int sz=bridge.size();
        loop(i,sz)
        {
            int x=bridge[i].fr;
            int y=bridge[i].sc;
            int u=find(x);
            int v=find(y);
            cnt[u]++;
            cnt[v]++;
        }
        int ans=0;
        loop(i,n)
        {
            if(cnt[i]==1)
                ans++;
        }
        CASE(cas);
        pf("%d\n",(ans+1)/2);
        bridge.clear();
        isbridge.clear();
        loop(i,10005)
        g[i].clear();

    }
    return 0;
}
