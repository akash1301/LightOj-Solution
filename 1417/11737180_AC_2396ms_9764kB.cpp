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

int nP2(int n)
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

vector<int>finish,g[50005],g_r[50005];
int vis[50005],cnt,n;

int dfs_1(int u)
{
    vis[u]=1;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
            dfs_1(v);
    }
    finish.pb(u);
}

int dfs_2(int u)
{
    vis[u]=1;
    for(int i=0,j=g_r[u].size();i<j;i++)
    {
        int v=g_r[u][i];
        if(!vis[v])
            dfs_2(v);
    }
}

int dfs_3(int u)
{
    vis[u]=1;
    cnt++;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
            dfs_3(v);
    }
}

int dfs_4(int u)
{
    vis[u]=0;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(vis[v])
            dfs_4(v);
    }
}

void clr()
{
    finish.clear();
    loop(i,50005)
    {
        g[i].clear();
        g_r[i].clear();
    }
}



int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        clr();
        cin>>n;
        loop(i,n)
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
                dfs_1(i);
        }
        mem(vis,0);
        vector<int>SCC;
        for(int i=finish.size()-1;i>=0;i--)
        {
            int x=finish[i];
            if(!vis[x])
            {
                SCC.pb(x);
                dfs_2(x);
            }
        }
        int ans=-1,node;
        mem(vis,0);
        for(int i=SCC.size()-1;i>=0;i--)
        {
            int x=SCC[i];
            if(!vis[x])
            {
                cnt=0;
                dfs_3(x);
                if(cnt>ans)
                {
                    ans=cnt;
                    node=x;
                }
                dfs_4(x);
            }
        }
        CASE(cas);
        cout<<node<<endl;
    }

    return 0;
}
