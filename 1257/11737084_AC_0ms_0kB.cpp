

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


vector<int>g[30005],cost[30005];
int n,c,dis2[30005],dis3[30005];

int bfs(int src)
{
    int dis[n+10];
    mem(dis,63);
    queue<int>qu;
    qu.push(src);
    dis[src]=0;
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        int sz=g[u].size();
        loop(i,sz)
        {
            int v=g[u][i];
            if(dis[u]+cost[u][i]<dis[v])
            {
                dis[v]=dis[u]+cost[u][i];
                qu.push(v);
            }
        }
    }
    int mx=0,node=0;
    for(int i=0;i<n;i++)
    {
        if(dis[i]>mx)
        {
            mx=dis[i];
            node=i;
        }

    }

    return node;
}

int bfs1(int src)
{
    mem(dis2,63);
    queue<int>qu;
    qu.push(src);
    dis2[src]=0;
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        int sz=g[u].size();
        loop(i,sz)
        {
            int v=g[u][i];
            if(dis2[u]+cost[u][i]<dis2[v])
            {
                dis2[v]=dis2[u]+cost[u][i];
                qu.push(v);
            }
        }
    }
}

int bfs2(int src)
{
    mem(dis3,63);
    queue<int>qu;
    qu.push(src);
    dis3[src]=0;
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        int sz=g[u].size();
        loop(i,sz)
        {
            int v=g[u][i];
            if(dis3[u]+cost[u][i]<dis3[v])
            {
                dis3[v]=dis3[u]+cost[u][i];
                qu.push(v);
            }
        }
    }
}


int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        getint(n);
        loop(i,n-1)
        {
            int p,q,w;
            sf("%d %d %d",&p,&q,&w);
            g[p].pb(q);
            g[q].pb(p);
            cost[p].pb(w);
            cost[q].pb(w);
        }
        int x=bfs(0);
        int y=bfs(x);
        bfs1(x);
        bfs2(y);
        CASE(cas);
        loop(i,n)
        {
            pf("%d\n",max(dis2[i],dis3[i]));
        }

        loop(i,30000){
        g[i].clear();
        cost[i].clear();
        }

    }
    return 0;
}
